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
tot=0
for parola in $(cat $file)
do
  n=0
  while [ $n -lt $tot ]
  do
    if [ "$parola" = "${vet[$n]}" ]
    then
      let rip[n]=rip[n]+1
      break
    else
      let n=n+1
    fi
  done
  if [ $n -ge $tot ]
  then
    let tot=tot+1
    vet[$tot-1]="$parola"
    rip[$tot-1]=1
  fi
done
n=0
while [ $n -lt $tot ]
  do
    echo "${vet[$n]}  - ${rip[$n]}"
    let n=n+1
  done
exit 0
