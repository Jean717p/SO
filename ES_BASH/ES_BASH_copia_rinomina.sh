#!/bin/bash
#copia il file e cambia estensione, aggiungendo conteggio parole e righe
if [ $# -ne 1 ]
then
  echo "usare $0 file"
  exit 1
elif [ -f $1 ]
then
  echo "Elaboro.."
else
  echo "$1 non è un file/non esiste"
  exit 1
fi
file=$(basename $1 ".txt")".xyz"
rm $file
echo $file
nrows=0
while read row
do
  echo -n "$(echo $row | wc -w) "
  echo $row
  let nrows=nrows+1
done <$1 >tmp.txt
cat tmp.txt | sort -k 1 -n >$file
rm tmp.txt
echo $nrows >>$file
exit 0
