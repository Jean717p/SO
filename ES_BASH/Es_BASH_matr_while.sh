#!/bin/bash
#Creare una matrice di elementi crescenti da 0
#ricevendo o chiedendo riga e colonna
if [ $# -gt 2 ]
then
  echo errato numero parametri: ./$0 n_righe n_colonne;
  exit 1
elif [ $# -eq 0 ]
then
  echo inserire n_righe; read righe;
  echo inserire n_col; read col;

else
  righe=$1
  col=$2
fi
n=0
k=0
t=$col
echo "Matrice con $righe righe e $col colonne:"
while [ $righe -gt $k ]
do
  let righe=righe-1
  col=$t
  while [ $col -gt $k ]
  do
    let col=col-1
    echo -n "$n "
    let n=n+1
  done
  echo
done

exit 0
