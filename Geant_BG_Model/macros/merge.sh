#!/bin/bash

# Input directory containing files to be concatenated
input_dir="."

# Loop over files in the input directory
for file in "$input_dir"/*; do
  # Extract the filename without extension
  filename="$(basename "$file")"
  filename_without_extension="${filename%.*}"

  # Extract the common prefix up to the last underscore
  common_prefix="${filename_without_extension##*_}"

  # Create an array to store file contents
  file_contents=()

  # Read first 5 lines of the file
  IFS=$'\n' read -r -d '' -a file_lines < < (head -n 15 "$file")

  # Append remaining lines to the array
  for ((i=15; i<${#file_lines[@]}; i++)); do
    file_contents+=("${file_lines[$i]}")
  done

  # Concatenate the file contents to the output file
  echo "Appending contents of $file to $common_prefix"
  echo "${file_contents[@]}" >> "$input_dir/concat/${common_prefix}.txt"
done

echo "Files concatenated successfully!"
