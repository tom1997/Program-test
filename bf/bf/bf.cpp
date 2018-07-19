#include<iostream>
using namespace std;
int BF(char s[],char t[]){
 int i,j;
 i=0;j=0;
 while((s[i]!='\0') && (t[j]!='\0')){
  if(s[i]==t[j]){i++;j++;}
  else{i=i-j+1;j=0;}
 }
 if (t[j]=='\0') return (i-j+1);
 else return 0;
}
int main(){
 char *s="baabaaaaaaaaaa";
 char *t="aaaaa";
 cout<<BF(s,t);
 system("pause");

}