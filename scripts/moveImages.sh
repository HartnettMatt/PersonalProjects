#!/bin/bash

# Define image extensions
EXTENSIONS="jpg jpeg png gif bmp tiff webp svg heic"

# Get the script's directory (main folder)
MAIN_FOLDER="$(pwd)"

# Loop through each extension and find images in subfolders
for ext in $EXTENSIONS; do
    find "$MAIN_FOLDER" -mindepth 2 -type f -iname "*.$ext" | while read -r file; do
        # Get just the filename
        filename=$(basename "$file")

        # Define the destination path
        dest="$MAIN_FOLDER/$filename"

        # If the filename already exists in the main folder, rename it
        if [[ -e "$dest" ]]; then
            count=1
            while [[ -e "$MAIN_FOLDER/${filename%.*}_$count.${filename##*.}" ]]; do
                ((count++))
            done
            dest="$MAIN_FOLDER/${filename%.*}_$count.${filename##*.}"
        fi

        # Move the file
        mv "$file" "$dest"
        echo "Moved: $file → $dest"
    done
done

# Delete all README.md files in subdirectories
find "$MAIN_FOLDER" -mindepth 2 -type f -name "README.md" -exec rm -v {} \;

echo "All images moved and README.md files deleted successfully!"
