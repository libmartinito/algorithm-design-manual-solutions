#!/bin/bash

if [ "$#" -ne 2 ]; then
  echo "Usage: $0 <chapter number> <solution number>"
  exit 1
fi

CHAPTER_NUMBER="$1"
SOLUTION_NUMBER="$2"

declare -A chapter_map=(
  [3]="03-data-structures"
)

DIRECTORY_NAME="${chapter_map[$CHAPTER_NUMBER]}"

if [ -z "$DIRECTORY_NAME" ]; then
  echo "Invalid chapter number: $CHAPTER_NUMBER"
  exit 1
fi

g++ -std=c++11 -O2 -Wall "${DIRECTORY_NAME}/${SOLUTION_NUMBER}".cpp -o "${DIRECTORY_NAME}/${SOLUTION_NUMBER}"

if [ $? -eq 0 ]; then
  ./"${DIRECTORY_NAME}/${SOLUTION_NUMBER}"
else
  echo "Compilation failed"
  exit 1
fi
