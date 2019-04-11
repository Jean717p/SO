#!/usr/bin/awk -f
BEGIN{
  printf "Begin\n";
  nparole=1;
  printf "Body\n";
}
{
  for(i=1;i<NF;i++){
    if(length($i)==5){
      found=0;
      if(match($i,".*a.*")>0)
        found++;
      if(match($i,".*e.*")>0)
        found++;
      if(match($i,".*i.*")>0)
        found++;
      if(match($i,".*o.*")>0)
        found++;
      if(match($i,".*u.*")>0)
        found++;
      if(found>=2){
        if(vet[$i]==0){
          par[nparole]=$i;
          nparole++;
        }
        vet[$i]++
      }
    }
  }
}
END{
  printf "End... \n";
  for(i=1;i<nparole;i++){
    printf "%s ",par[i];
    for(j=vet[par[i]];j>=0;j--){
      printf "#";
    }
    printf "\n";
  }
}
