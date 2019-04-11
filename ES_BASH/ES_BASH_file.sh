#!/bin/bash
#leggendo un file a terne visualizzare i risultati di f(x)=3*x^2+4*y+5*z
if [ $# -eq 1 ]
then
  if [ -f $1 ]
  then
    echo "Elaboro.."
  else
    echo "Inserire $0 file"
    exit 1
  fi
else
  echo "Errato numero parametri: inserire ./$0 file"
  exit 1
fi
file=$1
while read n1 n2 n3
do
  let n1=n1*n1*3+n2*4+n3*5
  echo $n1
done < $file
exit 0
#POSIX
