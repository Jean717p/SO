#!/usr/bin/awk -f
BEGIN{
  print"BEGIN\n"
  system("ps -el > file.txt");
  print "BODY\n"
}
{
  while(getline < "file.txt"){ #b
    if($2=="R"||$2=="R+"){
      if(v[$4]=="")
        v[$4]=$(14);
    }
  }
  for(i in v){
    if(v[i]!="")
      print "PID "i" Nome: "v[i]"\n";
    v[i]="";
  }
}
END{

}
