#!/bin/bash
if [ $# -eq 3 ]
then
  if [ $2 -gt 12 -o $2 -le 0 ]
  then
    echo "$2 deve essere il mese."
    exit 1
  fi
else
  echo "Errato numero parametri: inserire $0 PID"
  exit 1
fi
echo "Elaboro.."
echo $1 > tmp.txt
echo $(ncal $2 $3 | $(echo ./es03.awk))
exit 0
