#!/bin/bash
echo $# > tmp.txt
echo $# $1
if [ $# le 0 -o $# -ge 6 ]
then
  echo "Errato numero parametri: inserire $0 [opzioni] voc.txt file.txt output.txt"
  exit 1
fi
if [ $1 = "-n" -a -f $2 ]
then
  echo "Errore"
  $1="-h"
elif [ $1 = "-n" -a $# -le 4 ]
then
  echo "Errore"
  $1="-h"
fi
if [ $1 = "-h" -o $1 = "--help" ]
then
  echo "* il primo parametro (vocabolario) specifica il nome di un
  file contenemte un vocabolario con il formato precedente
  * il secondo parametro (fileDaTradurre) indica il nome di
  un file contenente il testo da tradurre
  * il terzo parametro (fileProdotto) indica il nome del
  file contenente la traduzione del testo seguendo il
  vocabolario indicato
  * le opzioni sono le seguenti
  * -h | --help
    deve stampare un messaggio con la spiegazione della
    sintassi e uscire;
  * -l | --longest
    lo script deve sostituire ogni parola del secondo
    file con la traduzione piu' lunga che si trova nel
    primo file (questo e' anche il comportamento di
    default)
  * -s | --shortest
    lo script deve sostituire ogni parola del secondo
    file con la traduzione piu' corta che si trova nel
    primo file
  * -n Num
    lo script deve sostituire ogni parola del secondo
    file con la traduzione di posizione Num che si trova
    nel primo file
  * -v | --verbose
    per ogni parola di cui non si trova una traduzione lo
    script deve riscriverla non tradotta.
    Nel caso sia specificata quest'opzione, lo
    script deve stampare a video un messaggio di warning
    (di default invece non stampa niente).";
    exit 0;
fi
if [ $1 = "-l" ]
then
  echo 0 >> tmp.txt
elif [ $1 = "-s" ]
then
  echo 1 >> tmp.txt
elif [ $1 = "-v" ]
then
  echo 2 >> tmp.txt
elif [ $1 = "-n" ]
then
  echo 3 >> tmp.txt
else
  echo 0 >> tmp.txt
  echo "-l" >> tmp.txt
fi
for i in $*
do
  echo $i >> tmp.txt
done
