pipeline {
    agent any

    environment {
        GITHUB_REPO = 'azerom960_comcast/entservices-apis'
        BRANCH = 'main'
        USER_EMAIL = 'azerom960@cable.comcast.com'
        USER_NAME = 'azerom'
        APIS_FOLDER = 'apis' // Folder containing the files to process
        DOCS_FOLDER = 'docs/apis_from_h' // Folder to store the generated docs
        GENERATED_DOCS_FOLDER = 'generated_docs' // Temporary folder to store generated docs
        GITHUB_CREDS = credentials('GenerateDocsUsernamePAT') // Replace with your credential ID
    }

    stages {
        stage('Checkout') {
            steps {
                script {
                    retry(3) {
                        sh '''
                        # Initialize a new Git repository
                        git init entservices-apis
                        cd entservices-apis

                        # Configure sparse checkout
                        git config core.sparseCheckout true
                        echo "${APIS_FOLDER}" >> .git/info/sparse-checkout
                        echo "${DOCS_FOLDER}" >> .git/info/sparse-checkout

                        # Add the remote repository
                        git remote add origin https://$GITHUB_CREDS_PSW@github.com/${GITHUB_REPO}.git

                        # Fetch the latest changes and reset the working directory
                        git fetch origin ${BRANCH}
                        git reset --hard origin/${BRANCH}
                        '''
                    }
                }
            }
        }
        stage('Check for Changes') {
            steps {
                script {

                    def changedFiles = sh(script: '''
                        cd entservices-apis

                        # Find .h files changed in the last week
                        git log --since='8 days ago' --pretty=format: --name-only | grep "^${APIS_FOLDER}/.*\\.h$" || true
                    ''', returnStdout: true).trim()

                    if (changedFiles) {
                        echo "Changed .h files in the last week:\n${changedFiles}"
                        env.CHANGED_FILES = changedFiles
                    } else {
                        echo "No .h files changed in the last week."
                        currentBuild.result = 'SUCCESS'
                        return
                    }
                }
            }
        }
        stage('Process Changed Files') {
            when {
                expression { return env.CHANGED_FILES }
            }
            steps {
                script {
                    sh 'mkdir -p logs'
                    sh 'mkdir -p jenkins_generated_docs'
                    def files = env.CHANGED_FILES.split('\n')
                    def failedFiles = []
                    for (file in files) {
                        try {
                            echo "Processing file: ${file}"
                            sh "python3 tools/md_from_h_generator/generate_md_from_header.py ${file}"
                        } catch (Exception e) {
                            echo "Failed to process file: ${file}"
                            failedFiles.add(file)
                        }
                    }
                    if (failedFiles) {
                        echo "The following files failed to process:\n${failedFiles.join('\n')}"
                        writeFile file: 'logs/failed_files.log', text: failedFiles.join('\n')
                    }
                }
            }
        }
        stage('Archive Artifacts') {
            steps {
                archiveArtifacts artifacts: 'jenkins_generated_docs/**/*.md', allowEmptyArchive: true
            }
        }
        stage('Create Pull Request') {
            when {
                expression { return env.CHANGED_FILES }
            }
            steps {
                script {
                    sh '''
                    cd entservices-apis

                    # Copy the generated .md files to the docs folder
                    cp -r ../jenkins_generated_docs/*.md ${DOCS_FOLDER}/ || echo "No files to copy."

                    git config --global user.email ${USER_EMAIL}
                    git config --global user.name ${USER_NAME}
                    git checkout -b update-docs
                    git add ${DOCS_FOLDER}/*
                    git commit -m "Automated update of documentation" || echo "Nothing to commit."
                    git push -f https://$GITHUB_CREDS_PSW@github.com/${GITHUB_REPO}.git update-docs || echo "Push failed."

                    curl -X POST -H "Authorization: token $GITHUB_CREDS_PSW" \
                        -H "Accept: application/vnd.github.v3+json" \
                        https://api.github.com/repos/${GITHUB_REPO}/pulls \
                        -d '{
                            "title": "Automated update of documentation",
                            "body": "This is an automated pull request to update the documentation.",
                            "head": "update-docs",
                            "base": "${BRANCH}"
                        }'
                    '''
                }
            }
        }
    }

    post {
        always {
            echo 'Pipeline completed.'
            deleteDir()
        }
        success {
            echo 'Build succeeded!'
        }
        failure {
            echo 'Build failed!'
        }
    }
}