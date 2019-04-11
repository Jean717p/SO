#!/usr/bin/awk -f
BEGIN{
  getline var < "tmp.txt"
  system("rm tmp.txt");
}
{
  for(i=2;i<=NF;i++){
    if($i==var){
      print $1;
      exit 1
    }
  }
}
END{
}
