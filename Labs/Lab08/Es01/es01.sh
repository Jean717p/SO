#!/bin/bash
if [ $# -ne 3 ]
then
  echo "errato numero parametri: ./$0 dir f(x) output"
  exit 1
elif [ ! -d $1 ]
then
  echo "$1 non è una directory"
  exit 1
elif [ -f $3 ]
then
  rm $3
else
  echo "Elaboro.."
fi
for file in $(find $1 -type f)
do
  grep -Hn "$2" $file
done >$3
sort --quiet -k 1 -k 2 $3
exit 0
