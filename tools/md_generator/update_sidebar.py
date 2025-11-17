#!/usr/bin/env python3
import os

def update_sidebar():
    apis_dir = os.path.abspath(os.path.join(os.path.dirname(__file__), '../../docs/apis'))
    sidebar_path = os.path.abspath(os.path.join(os.path.dirname(__file__), '../../docs/_sidebar.md'))
    if not os.path.exists(sidebar_path):
        print(f"sidebar.md not found at {sidebar_path}")
        return

    # Get all .md files in apis_dir (not recursive)
    md_files = [f for f in os.listdir(apis_dir) if f.endswith('.md')]
    md_files_sorted = sorted(md_files, key=lambda x: x.lower())

    # Read sidebar.md
    with open(sidebar_path, 'r', encoding='utf-8') as f:
        sidebar_lines = f.readlines()

    # Find the section for apis (look for a marker or a list start)
    # For simplicity, assume all plugin .md links are in a contiguous block
    # and are of the form: - [PluginName](apis/PluginName.md)
    new_sidebar_lines = []
    in_apis_section = False
    for line in sidebar_lines:
        if 'apis/' in line and line.strip().startswith('- '):
            if not in_apis_section:
                in_apis_section = True
                # We'll insert the new block here
                new_sidebar_lines.append('__INSERT_MD_LIST__\n')
            # Skip old apis entries
            continue
        elif in_apis_section and (not line.strip().startswith('- ') or 'apis/' not in line):
            in_apis_section = False
        new_sidebar_lines.append(line)

    # If no apis section found, append at the end
    if '__INSERT_MD_LIST__\n' not in new_sidebar_lines:
        new_sidebar_lines.append('\n__INSERT_MD_LIST__\n')

    # Build new apis md list
    md_links = [f"  - [{os.path.splitext(f)[0].replace('Plugin', '')}](apis/{f})\n" for f in md_files_sorted]
 
    # Replace marker with new list
    final_sidebar = []
    for line in new_sidebar_lines:
        if line == '__INSERT_MD_LIST__\n':
            final_sidebar.extend(md_links)
        else:
            final_sidebar.append(line)

    # Write back
    with open(sidebar_path, 'w', encoding='utf-8') as f:
        f.writelines(final_sidebar)
    print(f"Updated sidebar.md with {len(md_links)} API markdown files.")

if __name__ == '__main__':
    update_sidebar()
