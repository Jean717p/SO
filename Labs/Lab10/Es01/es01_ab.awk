#!/usr/bin/awk -f
#1.1 ps -el | awk '$4==1 {print "Nome: "$14"PID $4"}'
BEGIN{
  print"BEGIN\n"
  system("ps -el > file.txt");
  print "BODY\n"
}
{
  while(getline < "file.txt"){ #b
    else if($2=="R"||$2=="R+") 
      print "Nome " $(14) " PID "$4"\n"
  }
}
END{

}
