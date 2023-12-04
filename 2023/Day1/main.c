#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main(int argc,char*argv[]){char nl[][6]={"one","two","three","four","five","six","seven","eight","nine"};FILE*f=fopen(argv[1], "r");char l[150];char s[6];int i,j,k,r,t,v;while(fgets(l,150,f)!=NULL){j=k=0;for(i=0;l[i]!='\0';i++){if(isdigit(l[i])){(j>0)?(k=l[i]-'0'):(j=l[i]-'0');}else{for(t=0,v=i;t<5;t++,v++){if(isdigit(l[v])&&t<3){(j>0)?(k=l[v]-'0'):(j=l[v]-'0');s[0]='\0';break;}else{if(l[v]!='\0'){s[t]=l[v];}else{break;}}}if(s[0]!='\0'){s[5]='\0';for(t=0;t<9;t++){if(strstr(s,nl[t])){(j>0)?(k=t+1):(j=t+1);break;}}}}}(k==0)?(r+=(j*10)+j):(r+=(j*10)+k);}printf("%d",r);}
