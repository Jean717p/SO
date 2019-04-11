#!/usr/bin/awk -f
BEGIN{
  print"BEGIN\n"
  getline var < "tmp.txt"
  system("rm tmp.txt");
  print "BODY "var"\n"
}
{
  for(i=1;i<NR;i++){
    if($4==var){
      print "Nome: "$(14)"  PID: "$4"  Stato: "$2"\n";
      exit 1
    }
  }
}
END{
}
