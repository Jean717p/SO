#!/bin/bash
echo $# $1
no_options=0;
if [ $# -eq 3 -o $# -eq 4 -o $# -eq 5 ]
then
  if [ ! -f $2 -a $# -ne 5 ]
  then
    echo "File(s) inesistente - 1"
    exit 1
  elif [ $# -eq 4 -a ! -f $3 ]
  then
    echo "File(s) inesistente - 2"
    exit 1
  elif [ ! -f $3 -a $# -eq 3 ]
  then
    echo "File(s) inesistente - 3"
    exit 1
  elif [ $# -eq 3 -a -f $1 ]
  then
    no_options=1;
  elif [ $1 != "-l" -a $1 != "-s" -a $1 != "-n" -a $1 != "-v" ]
  then
    if [ $1 != "-h" ]
    then
      echo "Errato utilizzo delle opzioni: usare $0 -h per visualizzarle"
      exit 1
    fi
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
  elif [ $# -eq 4 -a -f $4 -a $ ]
  then
    no_options=4;
  elif [ $# -eq 5 ]
  then
    if [ $1 != "-n" ]
    then
      echo "Try $0 -n |1-6| voc.txt file.txt output.txt"
      exit 1
    elif [ $2 -le 0 -o $2 -ge 7 ]
    then
      echo "Try $0 -n |1-6| voc.txt file.txt output.txt"
      exit 1
    fi
  else
    echo "errore. try $0 -h for help."
    exit 1
  fi
elif [ $# -eq 1 -a $1 = "-h" ]
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
  exit 0
elif [ $# -eq 2 ]
then
  if [ ! -f $1 -o ! -f $2 ]
  then
    echo "File(s) inesistente - 4"
    exit 1
  fi
else
  echo "Errato numero parametri: inserire $0 [opzioni] voc.txt file.txt output.txt"
  exit 1
fi
echo "Elaboro.."
echo ""
echo $# > tmp.txt
echo $1 >> tmp.txt
echo $2 >> tmp.txt
if [ $# -eq 5 ]
then
  echo $3 >> tmp.txt
  echo $4 >> tmp.txt
  echo $5 >> tmp.txt
  echo $4 | $(echo ./es04.awk)
elif [ $# -eq 4 ]
then
  echo $3 >> tmp.txt
  echo $4 >> tmp.txt
  echo $4 | $(./es04.awk)
elif [ $# -eq 3 ]
then
  echo $3 >> tmp.txt
  echo $3 | $(./es04.awk)
else
  echo $2 | $(./es04.awk)
fi


exit 0
