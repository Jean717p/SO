#!/bin/bash
if [ $# -ne 1 -o ! -d $1 ]
then
  echo -n "Inserire: $0 path_directory ";
  exit 1
else
  echo "Elaboro.."
fi
for elem in $(ls $1)
do
  mv $1/$elem $1/$(echo "$elem" | tr '[:upper:]' '[:lower:]')
done
