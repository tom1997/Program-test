#include<iostream>
using namespace std;
int main()

{
	char a; 
int n=0;
do{
	cout<<"现在在下雨吗?"<<endl;
cout<<"请输入Y/N"<<endl;
cin>>a;

if(a=='Y'){
	cout<<"正在下雨";
n++;
getchar();
getchar();
}
else if (a=='N') {
	cout<<"现在没有下雨";
n++;
getchar();
getchar();
}
}
while (n!=1);
}