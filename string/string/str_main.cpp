#include<iostream>
#include "str.h"
using namespace std;

int main(){
	char ch[8]="I love ", *str="China!";
	cout<<strlen(ch)<<endl;
	cout<<strlen(str)<<endl;
	cout<<strcmp(ch,str)<<endl;
	cout<<strcmp(str,ch)<<endl;
	strcat(ch,str);
	for (int i=0;ch[i]!='\0';i++){
		cout<<ch[i];
	}
	cout<<endl;
	system("pause"); // 会出现内存溢出的问题，未找到相应的解决方法

	return 0;
}