#!/usr/bin/env bash

check_file_exists()
{
    if [ ! -f "$1" ]; then
        echo "File $1 not found."
        exit 84
    fi
}

count_lines()
{
    local file=$1

    wc -l < "$file"
}

display_info()
{
    local file=$1

    check_file_exists "$file"
    chmod 777 "$file"
    cat "$file"
    num_lines=$(count_lines "$file")
    echo ""
    echo "$file has $num_lines lines"
    chmod 000 "$file"
}

save_file="../.save"
display_info "$save_file"
