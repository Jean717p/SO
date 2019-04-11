#!/bin/bash
if [ $# -ne 1 ]
then
  echo -n "Inserire File: "; read file; echo ;
else
  file=$1
fi
if [ ! -f $file ]
then
  echo "File inesistente"
  exit 1
else
  echo "Elaboro.."
fi
lines=0
wmax=0
while read str
do
  let lines=lines+1
  var=$(echo $str | wc -m)
  if [ $var -gt $wmax ]
  then
    strmax=$str
    wmax=$var
  fi
done <$file
echo "Righe: $lines, riga più lunga con $wmax caratteri: $strmax"
exit 0
