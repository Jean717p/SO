#!/usr/bin/awk -f
BEGIN{
  i=0
  while(getline var < "tmp.txt"){
    if(i==2){
      if(vett[1]==3){
        vett[6]=var
        getline var < "tmp.txt"
      }
    }
    vett[i++]=var
  }
  prm=vett[0]
  opz=vett[1]
  i=0
  system("rm tmp.txt");
  while(getline < vett[2] ){
    long=""
    short=""
    c=1
    while($0!='#'){
      if(vett[1]==2){
        voc[i++]=
      }
      if(vett[1]==3&&c==vett[6]){
        voc[i++]=$0
        break;
      }
      if(length($0)>length(long) && vett[1]==0)
        long=$0
      if(length($0)<length(short) && vett[1]==1)
        short=$0
      getline < vett[2]
    }
    if(vett[1]==0)
      voc[i++]=long
    else if(vett[1]==1)
      voc[i++]=short

  }
}
{

}
END{
}
