#!/bin/sh

rm original result err;
./asm "$1.s" 2>> err;
./AsmX "$1.s" 2>> err;
od -x result.cor >> result;
od -x  "$1.cor"  >> original;
cat err >> result
echo -e "\033[2J"

_file=err
[ $# -eq 0 ] && { echo "Usage: $0 filename"; exit 1; }
[ ! -f "$_file" ] && { echo "Error: $0 file not found."; exit 2; }
 
if [ -s "$_file" ]
then
    cat err
else 
    colordiff -s original result;

echo "













"
fi
rm err
