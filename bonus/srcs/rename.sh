#!/bin/bash

RENAME_PATH=$1

for file in $RENAME_PATH/*.c; do
    mv "$file" "${file%.c}_bonus.c"
done
