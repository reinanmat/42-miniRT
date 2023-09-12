#!/bin/bash

extension="_bonus"
new_extension="$1"

for file in *"$extension"; do
    new_name="${file%$extension}$new_extension"
    mv "$file" "$new_name"
done
