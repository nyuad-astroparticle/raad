#!/bin/bash

# Specify the directory containing the CSV files
directory="."

# Change directory to the specified directory
cd "$directory"

# Create a new file to store the merged CSV data
merged_file="merged.csv"
> "$merged_file" # Empty the file if it already exists

# Loop through all CSV files in the directory
for file in *.csv; do
  # Skip the merged file itself
  if [ "$file" == "$merged_file" ]; then
    continue
  fi

  # Count the number of lines in the file
  num_lines=$(wc -l < "$file")

  # Check if the file has at least 15 lines
  if [ "$num_lines" -ge 16 ]; then
    # Extract data from the 15th line onwards
    tail -n +16 "$file" >> "$merged_file"
    echo "Merged data from $file"
  else
    echo "Skipped $file as it has less than 16 lines"
  fi
done

echo "Merged CSV files into $merged_file"