#!/usr/bin/awk -f
#mancano i file in ingresso
BEGIN{
  fout=ARGV[3];
  ARGV[3]="";
  system("rm $fout");
  while(getline < ARGV[1]){
    q[$1]+=$2;
  }
  while(getline < ARGV[2]){
    n[$1]++;
    p[$1]+=$2;
  }
}
{}
END{
  for(i in p){
    p[i]=p[i]/n[i];
    if(!(i in q))
      print "Warning: product "i" has no quantity!"
  }
  for(i in q){
    if(!(i in p))
      print "Warning: product "i" has no price!"
  }
  for(i in q){
    if(i in p){
      print i " " q[i] " " p[i] " " q[i]*p[i] >>fout
    }
  }
}
