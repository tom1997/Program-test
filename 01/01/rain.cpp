#include<iostream>
using namespace std;
int main()

{
	char a; 
int n=0;
do{
	cout<<"������������?"<<endl;
cout<<"������Y/N"<<endl;
cin>>a;

if(a=='Y'){
	cout<<"��������";
n++;
getchar();
getchar();
}
else if (a=='N') {
	cout<<"����û������";
n++;
getchar();
getchar();
}
}
while (n!=1);
}