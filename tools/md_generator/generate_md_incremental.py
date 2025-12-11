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

"""
Script to generate documentation for specific plugins based on changed files.
This is used by the automated documentation workflow.
"""

import os
import sys
import glob
import argparse
from pathlib import Path


def normalize_file_path(file_path):
    """Normalize file path to be relative to repository root."""
    script_dir = os.path.dirname(os.path.abspath(__file__))
    repo_root = os.path.abspath(os.path.join(script_dir, "../.."))
    
    if os.path.isabs(file_path):
        try:
            normalized = os.path.relpath(file_path, repo_root)
            print(f"[DEBUG] Normalized absolute path: {file_path} -> {normalized}")
            return normalized
        except ValueError:
            print(f"[DEBUG] Could not normalize absolute path: {file_path}")
            return file_path
    
    normalized = os.path.normpath(file_path)
    if normalized.startswith('..'):
        abs_path = os.path.abspath(file_path)
        try:
            result = os.path.relpath(abs_path, repo_root)
            print(f"[DEBUG] Normalized relative path: {file_path} -> {result}")
            return result
        except ValueError:
            print(f"[DEBUG] Could not normalize relative path: {file_path}")
            return normalized
    
    print(f"[DEBUG] Path already normalized: {file_path}")
    return normalized


def get_plugin_from_path(file_path):
    """Extract plugin name from a file path."""
    normalized = normalize_file_path(file_path)
    parts = Path(normalized).parts
    
    print(f"[DEBUG] Extracting plugin from path: {file_path}")
    print(f"[DEBUG]   Normalized: {normalized}")
    print(f"[DEBUG]   Parts: {parts}")
    
    # For apis/PluginName/...
    if 'apis' in parts:
        apis_idx = parts.index('apis')
        if len(parts) > apis_idx + 1:
            plugin = parts[apis_idx + 1]
            print(f"[DEBUG]   Found plugin: {plugin}")
            return plugin
    
    # For tools/md_generator/json/PluginName/...
    if 'json' in parts and 'md_generator' in parts:
        json_idx = parts.index('json')
        if len(parts) > json_idx + 1:
            plugin = parts[json_idx + 1]
            print(f"[DEBUG]   Found plugin in json path: {plugin}")
            return plugin
    
    print(f"[DEBUG]   No plugin found")
    return None


def validate_json_changes(changed_files):
    """
    Validate that JSON changes in apis/ have corresponding output files in tools/md_generator/json/.
    Returns (is_valid, missing_plugins)
    """
    apis_json_changes = [f for f in changed_files if f.startswith('apis/') and f.endswith('.json')]
    
    if not apis_json_changes:
        return True, []
    
    missing_plugins = []
    
    for json_file in apis_json_changes:
        plugin = get_plugin_from_path(json_file)
        if not plugin:
            continue
        
        # Check if corresponding output file exists in changed files OR on filesystem
        output_in_changes = any(
            f.startswith(f'tools/md_generator/json/{plugin}/') and f.endswith('.json')
            for f in changed_files
        )
        
        if not output_in_changes:
            # Also check if it exists on disk (for cases where output wasn't changed but exists)
            output_pattern = f"tools/md_generator/json/{plugin}/*Plugin.json"
            output_files = glob.glob(output_pattern)
            if not output_files:
                missing_plugins.append(plugin)
    
    return len(missing_plugins) == 0, missing_plugins


def get_plugins_to_process(changed_files):
    """
    Determine which plugins need documentation regeneration.
    Returns dict with plugin names as keys and file types as values.
    """
    plugins = {}
    
    print("\n[DEBUG] Processing changed files to identify plugins...")
    for file_path in changed_files:
        normalized = normalize_file_path(file_path)
        plugin = get_plugin_from_path(file_path)
        if not plugin:
            print(f"[DEBUG] Skipping file (no plugin found): {file_path}")
            continue
        
        # Determine file type
        if normalized.startswith('apis/') and normalized.endswith('.h'):
            file_type = 'header'
            print(f"[DEBUG] Detected header file for {plugin}: {file_path}")
        elif normalized.startswith('tools/md_generator/json/') and normalized.endswith('.json'):
            file_type = 'json_output'
            print(f"[DEBUG] Detected JSON output file for {plugin}: {file_path}")
        elif normalized.startswith('apis/') and normalized.endswith('.json'):
            file_type = 'apis_json'
            print(f"[DEBUG] Detected APIs JSON file for {plugin}: {file_path}")
        else:
            print(f"[DEBUG] Skipping file (unknown type): {file_path}")
            continue
        
        if plugin not in plugins:
            plugins[plugin] = set()
        plugins[plugin].add(file_type)
        print(f"[DEBUG] Added {file_type} to plugin {plugin}")
    
    return {k: list(v) for k, v in plugins.items()}


def generate_docs_for_plugin(plugin_name, file_types, logfile=None):
    """Generate documentation for a specific plugin."""
    # Skip JSON-based documentation generation for 'common' plugin
    if plugin_name.lower() == 'common' and 'json_output' in file_types:
        print(f"\n{'='*60}")
        print(f"Skipping JSON-based documentation for plugin: {plugin_name}")
        print(f"Reason: 'common' plugin does not require JSON documentation")
        print(f"{'='*60}\n")
        return True
    
    print(f"\n{'='*60}")
    print(f"Generating documentation for plugin: {plugin_name}")
    print(f"File types changed: {', '.join(file_types)}")
    print(f"{'='*60}\n")
    
    apis_dir = os.path.abspath(os.path.join(os.path.dirname(__file__), "../../apis"))
    plugin_path = os.path.join(apis_dir, plugin_name)
    output_dir = os.path.abspath(os.path.join(os.path.dirname(__file__), "../../docs/apis"))
    
    # Check if we should generate from headers
    if 'header' in file_types:
        h_files = glob.glob(os.path.join(plugin_path, "I*.h"))
        if h_files:
            print(f"Found header files ({len(h_files)}):")
            for hf in h_files:
                print(f"  - {hf}")
            
            # Check output file before generation
            output_file = os.path.join(output_dir, f"{plugin_name}.md")
            print(f"\n[DEBUG] Output documentation file: {output_file}")
            if os.path.exists(output_file):
                print(f"[DEBUG] Output file exists, will be updated")
                # Get file modification time
                import time
                mtime = os.path.getmtime(output_file)
                print(f"[DEBUG] Current modification time: {time.ctime(mtime)}")
            else:
                print(f"[DEBUG] Output file does not exist, will be created")
            
            script_path = os.path.abspath(os.path.join(os.path.dirname(__file__), "h2md/generate_md_from_header.py"))
            cmd = f"python3 {script_path} -i {plugin_path} -o {output_dir}"
            if logfile:
                cmd += f" --logfile {logfile}"
            print(f"\n[DEBUG] Executing command: {cmd}")
            result = os.system(cmd)
            
            if result != 0:
                print(f"\n{'!'*60}")
                print(f"ERROR: Failed to generate docs from headers for {plugin_name}")
                print(f"Command exit code: {result}")
                print(f"{'!'*60}\n")
                return False
            
            # Check output file after generation
            if os.path.exists(output_file):
                import time
                mtime = os.path.getmtime(output_file)
                print(f"\n[DEBUG] Documentation generated successfully")
                print(f"[DEBUG] New modification time: {time.ctime(mtime)}")
                # Show file size
                size = os.path.getsize(output_file)
                print(f"[DEBUG] File size: {size} bytes")
                
                # Show a sample of generated content for debugging
                print(f"\n[DEBUG] Searching for 'getStorageDetails' in generated documentation...")
                try:
                    with open(output_file, 'r') as f:
                        content = f.read()
                        # Find and print the getStorageDetails section
                        if 'getStorageDetails' in content:
                            lines = content.split('\n')
                            for i, line in enumerate(lines):
                                if '## *getStorageDetails*' in line:
                                    print(f"[DEBUG] Found getStorageDetails at line {i+1}")
                                    print(f"[DEBUG] Showing next 40 lines:")
                                    print("\n".join(lines[i:min(i+40, len(lines))]))
                                    break
                            # Also search for quotaKb to show type
                            for i, line in enumerate(lines):
                                if 'quotaKb' in line or 'quotaKB' in line:
                                    print(f"\n[DEBUG] Found quotaKb reference at line {i+1}: {line}")
                                    if i > 0:
                                        print(f"[DEBUG] Previous line: {lines[i-1]}")
                                    if i < len(lines) - 1:
                                        print(f"[DEBUG] Next line: {lines[i+1]}")
                        else:
                            print(f"[DEBUG] 'getStorageDetails' not found in documentation")
                except Exception as e:
                    print(f"[DEBUG] Error reading output file: {e}")
            else:
                print(f"\n[WARNING] Output file not created: {output_file}")
            
            print(f"✓ Successfully generated docs from headers for {plugin_name}")
            return True
    
    # Check if we should generate from JSON output
    if 'json_output' in file_types or 'apis_json' in file_types:
        json_plugin_path = os.path.abspath(os.path.join(os.path.dirname(__file__), f"../md_generator/json/{plugin_name}"))
        json_files = glob.glob(os.path.join(json_plugin_path, "*Plugin.json"))
        
        if json_files:
            print(f"Found JSON output files: {json_files}")
            jsongenpath = os.path.abspath(os.path.join(os.path.dirname(__file__), "json2md/generator_json.py"))
            
            for json_file in json_files:
                cmd = f"python3 {jsongenpath} --docs {json_file} -o {output_dir} --no-interfaces-section"
                print(f"Running: {cmd}")
                print(f"Input file exists: {os.path.exists(json_file)}")
                print(f"Output dir exists: {os.path.exists(output_dir)}")
                result = os.system(cmd)
                if result != 0:
                    print(f"\n{'!'*60}")
                    print(f"ERROR: Failed to generate docs from JSON for {plugin_name}")
                    print(f"Command exit code: {result}")
                    print(f"JSON file: {json_file}")
                    print(f"Generator script: {jsongenpath}")
                    print(f"{'!'*60}\n")
                    # Try to show what went wrong
                    print("Attempting to run with error output:")
                    os.system(f"python3 {jsongenpath} --docs {json_file} -o {output_dir} --no-interfaces-section 2>&1")
                    return False
            print(f"✓ Successfully generated docs from JSON for {plugin_name}")
            return True
        else:
            print(f"WARNING: No JSON output files found for {plugin_name} in {json_plugin_path}")
            return False
    
    return True


def postprocess_md():
    """Postprocess generated markdown files."""
    print("\n" + "="*60)
    print("Postprocessing markdown files...")
    print("="*60 + "\n")
    
    script_dir = os.path.dirname(os.path.abspath(__file__))
    apis_dir = os.path.abspath(os.path.join(script_dir, "../../docs/apis"))
    flist = glob.glob(os.path.join(apis_dir, "*.md"))

    for file in flist:
        with open(file, "r") as file_rd:
            rplce_file = file_rd.read()
            rplce_file_Org = rplce_file
            list_rplce = (" [<sup>method</sup>](#head.Methods)",
                          " [<sup>event</sup>](#head.Notifications)",
                          " [<sup>property</sup>](#head.Properties)",
                          "head.", "method.", "acronym.", "term.", "event.", "ref.", "property.")

            for word in list_rplce:
                rplce_file = rplce_file.replace(word, "")

            if rplce_file != rplce_file_Org:
                with open(file, "w") as file_wr:
                    file_wr.writelines(rplce_file)
    
    print("✓ Postprocessing completed\n")


def update_sidebar():
    """Update the sidebar with new documentation."""
    print("="*60)
    print("Updating sidebar...")
    print("="*60 + "\n")
    
    update_sidebar_path = os.path.abspath(os.path.join(os.path.dirname(__file__), 'update_sidebar.py'))
    result = os.system(f'python3 "{update_sidebar_path}"')
    
    if result == 0:
        print("✓ Sidebar updated\n")
    else:
        print("ERROR: Failed to update sidebar\n")
    
    return result == 0


def main():
    parser = argparse.ArgumentParser(description="Generate documentation for specific plugins based on changed files.")
    parser.add_argument("--changed-files", nargs='+', help="List of changed file paths")
    parser.add_argument("--validate-only", action='store_true', help="Only validate, don't generate docs")
    parser.add_argument("--logfile", "-l", help="Optional log file path for header-based generation")
    args = parser.parse_args()

    if not args.changed_files:
        print("ERROR: No changed files provided")
        sys.exit(1)

    print("="*60)
    print("INCREMENTAL DOCUMENTATION GENERATION")
    print("="*60)
    print(f"\nChanged files ({len(args.changed_files)}):")
    for f in args.changed_files:
        print(f"  - {f}")
    print()

    # Step 1: Validate JSON changes
    is_valid, missing_plugins = validate_json_changes(args.changed_files)
    
    if not is_valid:
        print("\n" + "!"*60)
        print("VALIDATION FAILED")
        print("!"*60)
        print("\nThe following plugins have JSON changes in apis/ but no corresponding")
        print("output files in tools/md_generator/json/:")
        for plugin in missing_plugins:
            print(f"  - {plugin}")
        print("\nPlease ensure the JSON files exist in tools/md_generator/json/ directory.")
        print()
        sys.exit(1)
    
    if args.validate_only:
        print("✓ Validation passed")
        sys.exit(0)

    # Step 2: Determine which plugins to process
    plugins_to_process = get_plugins_to_process(args.changed_files)
    
    if not plugins_to_process:
        print("No plugins found to process")
        sys.exit(0)
    
    print(f"\nPlugins to process: {len(plugins_to_process)}")
    for plugin, file_types in plugins_to_process.items():
        print(f"  - {plugin}: {', '.join(file_types)}")
    print()

    # Step 3: Generate documentation for each plugin
    success = True
    for plugin, file_types in plugins_to_process.items():
        if not generate_docs_for_plugin(plugin, file_types, args.logfile):
            success = False
    
    if not success:
        print("\n" + "!"*60)
        print("DOCUMENTATION GENERATION FAILED FOR SOME PLUGINS")
        print("!"*60 + "\n")
        sys.exit(1)

    # Step 4: Post-process and update sidebar
    postprocess_md()
    update_sidebar()

    print("="*60)
    print("✓ DOCUMENTATION GENERATION COMPLETED SUCCESSFULLY")
    print("="*60 + "\n")
    
    # Clean up pycache
    if os.path.exists("./json2md/__pycache__"):
        os.system('rm -rf "./json2md/__pycache__"')


if __name__ == "__main__":
    main()
