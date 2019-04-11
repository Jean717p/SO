#!/bin/bash
if [ $# -eq 1 ]
then
  echo "Elaboro.."
else
  echo "Errato numero parametri: inserire $0 PID"
  exit 1
fi
echo $1 > tmp.txt
echo $(ps -el | $(echo ./es02.awk))
exit 0
