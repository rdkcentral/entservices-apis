#!/usr/bin/env python3

# If not stated otherwise in this file or this component's LICENSE file the
# following copyright and licenses apply:

# Copyright 2024 RDK Management

# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at

# http://www.apache.org/licenses/LICENSE-2.0

# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

# Generating and postprocessing the md files
# Place the file under rdkservices/docs folder
import shutil
import os
import glob
import time
import sys
#from pathlib import Path, PureWindowsPath

# Fetching the json files from each plugin to generate md files
# Under docs/apis folder
def convert_json_to_md():
    print()
    print("*****   Generating md files under docs/apis   *****")
    print()
    dirname = os.path.dirname(__file__)
    print("Directory path:", dirname)
    print()
    filename = os.path.join(dirname, r"../json_generator/output/*/*Plugin.json")
    flist = glob.glob(os.path.join(filename))
    jsongenpath ="python3 ./json2md/generator_json.py"

    for file in flist:
        os.system(r"{} --docs "
                   r"{} -o ../../docs/apis --no-interfaces-section".format(jsongenpath, file))
    print()
    print("*****   Generated md files under docs/apis   *****")

# Replacing the given strings in md files to fix the linking issues
def postprocess_md():
    print()
    flist = glob.glob(os.path.join(r"./../../docs/apis/*Plugin.md"))

    # Loop and replace the given words
    for file in flist:
        # Open and Read the file
        with open(file, "r") as file_rd:
            rplce_file = file_rd.read()
            rplce_file_Org = rplce_file
            list_rplce = (" [<sup>method</sup>](#head.Methods)",
                          " [<sup>event</sup>](#head.Notifications)",
                          " [<sup>property</sup>](#head.Properties)",
                          "head.", "method.", "acronym.", "term.", "event.", "ref.", "property.")
            print("postprocessing filename:", file)

           # replace the words
            for word in list_rplce:
                rplce_file = rplce_file.replace(word, "")

            # Replace the file only if, the original file and
            # current file are different
            if rplce_file != rplce_file_Org:
               print("link fixing filename:", file)
               with open(file, "w") as file_wr:
                    file_wr.writelines(rplce_file)
    print()
    print("********************   Postprocessing completed   ********************")

def main():
    start = time.time()
    count = 0
    convert_json_to_md()
    print()
    print()
    postprocess_md()
    print()
    print()
    end = time.time()
    print("The time taken to execute the above program is :", end - start)
    if os.path.exists("./json2md/__pycache__"):
        os.system('rm -rf "./json2md/__pycache__"')

if __name__ == "__main__":
    main()

