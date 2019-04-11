#!/bin/bash
#leggere un insieme indefinito di numeri, terminare quando leggo 0
#visualizzare quindi il vettore in ordine inverso
echo "inserire numeri, 0 per terminare"
index=0
vett[index]=1
read vett[index]
while [ ${vett[index]} -ne 0 ]
do
  let index=index+1
  read vett[index]
done
echo "Inizio stampa al contrario..."
while [ $index -ge 0 ]
do
  echo ${vett[index]}
  let index=index-1
done
echo "Termino...."
exit 0
