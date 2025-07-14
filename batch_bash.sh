#!/bin/bash

# filepath: /path/to/script.sh

# Directory containing the input files
INPUT_DIR="apis"

# Path to your Python script
PYTHON_SCRIPT="./tools/md_from_h_generator/generate_md_from_header.py"

# Loop through all files in the input directory
for FOLDER in "$INPUT_DIR"/*; do
    for FILE in "$FOLDER"/*.h; do
        if [ -f "$FILE" ]; then
            python3 "$PYTHON_SCRIPT" "$FILE"
            echo "Processed $FILE"
        fi
    done
done