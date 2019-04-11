#!/bin/bash
#cerca tutti i file.sh che contengono la stringa "POSIX"
str="POSIX"
for file in $(ls *.sh)
do
  if grep --quiet $str $file
  then
    echo $file
  fi
done
#alternativa cd $(pwd);grep -l "POSIX" *.sh
