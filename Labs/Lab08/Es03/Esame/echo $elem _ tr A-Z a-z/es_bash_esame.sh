#!/bin/bash
#ricevuti 4 param dir1-2-3 (cartelle) e n intero deve:
#trovare in dir1-2 tutti i file con lo stesso nome in .txt con più di n righe
#creare in dir3 una versione di questi file con estensione:
#.eq in cui vengono memorizzate le righe uguali
#.dif che memorizza le righe diverse
#.cat una concatenazione dei due file
if [ $# -ne 4 ]
then
  echo "Errato numero parametri, inserire: $0 dir1 dir2 dir3 n"
  exit 1
elif [ ! -d $1 -o ! -d $2 ]
then
  echo "Direttori inesistenti"
  exit 1
elif [ -d $3 ]
then
  rm -r $(pwd)/$3
  mkdir $3
  echo "Creata di nuovo $3"
else
  mkdir $3
  echo "Creata nuova $3/"
fi
flag=0
for f1 in $(ls $1/*.txt) #F-1
do
  #echo "F-1 $f1"
  name=$(basename $f1 ".txt")
  if [ -f $2/$name".txt" ] #3-1
  then
    f2=$2/$name".txt"
    #echo "3-1 $f1 $f2"
    if [ $(wc -l $f1 | cut -f1 -d' ') -gt $4 ] #1-1
    then
      #echo "1-1 ok $f1"
      if [ $(wc -l $f2 | cut -f1 -d' ') -gt $4 ] #2-1
      then
        #echo "2-1 Lung_Ok $f1 $f2"
        while read line1 #1-2
        do
          #echo "-----$line1"
          while read line2 && flag=0 #2-2
          do
            if [ "$line1" = "$line2" ]
            then
              echo $line2 >>$3/$name".eq"
              #echo "-----$line2"
              flag=1;
              break;
            fi
          done <$f2 #2-2
          if [ $flag -eq 0 ]
          then
            echo "$f1 $line1" >>$3/$name".dif"
          fi
          flag=0
        done <$f1 #1-2
        while read line2 #dif f2
        do
          while read line1 && flag=0
          do
            if [ "$line2" = "$line1" ]
            then
              flag=1
              break
            fi
          done <$3/$name".eq"
          if [ $flag -eq 0 ]
          then
            echo "$f2 $line2" >>$3/$name".dif"
          fi
          flag=0
        done <$f2 #dif f2
        cat -s $f1 $f2 >$3/$name".cat"
      fi #2-1
    fi #1-1
  fi #3-1
done #F-1

exit 0
