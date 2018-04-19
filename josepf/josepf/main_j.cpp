
#include<iostream>   //引用输入输出流库函数的头文件
using namespace std;
#include"LinkList_j.h"  //引用单链表类的声明和定义

void main( )
{
	int m,n;
	cout<<"请输入总数"<<endl;
	cin>>n;

	cout<<"请输入间隔"<<endl;
	cin>>m;
	LinkList<int> a(n);
	a.PrintList();
	cout<<endl;
	cout<<a.Joseph(m);

  system("pause");
}



