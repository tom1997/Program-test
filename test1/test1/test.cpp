#include <iostream>
using namespace std;
int main(){
	float x=2.5;
	float y=4.7;
	int a=7;
	cout<<"func(1)="<<x+a%3*(int)(x+y)%2/4<<endl;//����һ�����ҵĴ���1��ԭ������Ϊ���Ե������������Ҳ�һ����
	getchar ();
	float i=3.5;
	float j=2.5;
	int k=2;
	int b=3;
	cout<<"func(2)="<<float(k+b)/2+(int)i%(int)j<<endl;//����һ�����ҵĴ���2.5��ԭ������Ϊ���Ե������������Ҳ�һ����
	getchar ();
}

