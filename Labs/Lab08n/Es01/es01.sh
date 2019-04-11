#!/bin/bash
# NULL Script
if test $# -ne 3
then
echo "Errato numero parametri"
exit -1
fi

echo "Numero argomenti inseriti $#"
echo "Cartella $1";echo "Funzione: $2";
echo "Output: $3"
rigafile=1;
find $1 -type f | grep -n "$2" *.* | sort -t ':' -k 1 -k 2rn > $3

exit 0
