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
import argparse
#from pathlib import Path, PureWindowsPath


def generate_md(logfile=None):
    print("*****   Generating md files under docs/apis   *****")
    apis_dir = os.path.abspath(os.path.join(os.path.dirname(__file__), "../../apis"))
    plugin_folders = [f for f in os.listdir(apis_dir) if os.path.isdir(os.path.join(apis_dir, f))]
    used_json_method = False

    for plugin in plugin_folders:
        plugin_path = os.path.join(apis_dir, plugin)
        h_files = glob.glob(os.path.join(plugin_path, "I*.h"))
        if h_files:
            print(f"Found I*.h files in {plugin_path}: {h_files}")
            convert_h_to_md(plugin_path, logfile)
            print(f"[TOOL] Would generate md from {h_files} using the required tool.")
        else:
            print(f"No I*.h files found in {plugin_path}, using convert_json_to_md.")
            json_plugin_path = os.path.abspath(os.path.join(os.path.dirname(__file__), f"../json_generator/output/{plugin}"))
            convert_json_to_md(json_plugin_path)
            used_json_method = True

    if not used_json_method:
        print("No plugin folders required convert_json_to_md().")
    print("*****   MD generation completed   *****")

def convert_json_to_md(plugin_path):
    print(f"*****   Generating md files under docs/apis for {plugin_path}   *****")
    jsongenpath = os.path.abspath(os.path.join(os.path.dirname(__file__), "json2md/generator_json.py"))
    flist = glob.glob(os.path.join(plugin_path, "*Plugin.json"))
    for file in flist:
        os.system(f"python3 {jsongenpath} --docs {file} -o ../../../../docs/apis --no-interfaces-section")
    print(f"*****   Generated md files under docs/apis for {plugin_path}   *****")

def convert_h_to_md(plugin_path, logfile=None):
    print(f"*****   Generating md files from headers under docs/apis for {plugin_path}   *****")
    output_dir = os.path.abspath(os.path.join(os.path.dirname(__file__), "../../docs/apis"))
    script_path = os.path.abspath(os.path.join(os.path.dirname(__file__), "h2md/generate_md_from_header.py"))

    cmd = f"python3 {script_path} -i {plugin_path} -o {output_dir}"
    if logfile:
        cmd += f" --logfile {logfile}"

    print(f"Running: {cmd}")
    os.system(cmd)
    print(f"*****   Header-based md generation completed for {plugin_path}   *****")

def postprocess_md():
    print("Postprocessing md files...")
    flist = glob.glob(os.path.join(r"./../../docs/apis/*Plugin.md"))

    for file in flist:
        with open(file, "r") as file_rd:
            rplce_file = file_rd.read()
            rplce_file_Org = rplce_file
            list_rplce = (" #head.Methods", " #head.Notifications", " #head.Properties", "head.", "method.", "acronym.", "term.", "event.", "ref.", "property.")

            print("postprocessing filename:", file)
            for word in list_rplce:
                rplce_file = rplce_file.replace(word, "")

            if rplce_file != rplce_file_Org:
                print("link fixing filename:", file)
                with open(file, "w") as file_wr:
                    file_wr.writelines(rplce_file)
    print("********************   Postprocessing completed   ********************")

def main():
    parser = argparse.ArgumentParser(description="Generate and postprocess md files.")
    parser.add_argument("--logfile", "-l", help="Optional log file path for header-based generation.")
    args = parser.parse_args()

    start = time.time()
    generate_md(args.logfile)
    print()
    postprocess_md()
    print()
    update_sidebar_path = os.path.abspath(os.path.join(os.path.dirname(__file__), 'update_sidebar.py'))
    os.system(f'python3 "{update_sidebar_path}"')
    end = time.time()
    print("The time taken to execute the above program is:", end - start)

    if os.path.exists("./json2md/__pycache__"):
        os.system('rm -rf "./json2md/__pycache__"')

if __name__ == "__main__":
    main()


