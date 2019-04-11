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

for f in 'find $1 -type f'
do
  grep -n "$2 *(.*)" | sort -r -t ':' -k 1 -k 2n > $3
done
exit 0
