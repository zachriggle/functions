#!/usr/bin/env bash
cat missing.txt | while read line; do
REGEX="(?s)       (?!return)\w+ $line\([^\)][^;]+\);\n" ;
    man 2 "$line" | grep -Pzo "$REGEX"  | sed -E 's|\x00|\n|';
done | cpp | clang-format
