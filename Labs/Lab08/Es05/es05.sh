#!/bin/bash
if [ $# -ne 2 ]
then
  echo -n "Inserire:$0 Pocesso Intervallo "; exit 1
fi
Z=0
while [[ : ]]; do
  riga="$(ps -el | grep $1)"
  if [ $? -eq 0 ]
  then
    pid="$(echo $riga | cut -d " " -f 2)"
    stato="$(echo $riga | cut -d " " -f 10)"
    echo $stato
    if [ "$stato" = "Z" ]
    then
      let Z=Z+1
      if [ $Z -eq 5 ]
      then
        kill -9 $pid
        echo "Processo Zombie $pid ucciso."
        exit 0
    else
      Z=0
    fi
  else
    exit 1
  fi
  sleep $2
done
