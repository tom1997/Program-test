
#include<iostream>   //��������������⺯����ͷ�ļ�
using namespace std;
#include"LinkList_j.h"  //���õ�������������Ͷ���

void main( )
{
	int m,n;
	cout<<"����������"<<endl;
	cin>>n;

	cout<<"��������"<<endl;
	cin>>m;
	LinkList<int> a(n);
	a.PrintList();
	cout<<endl;
	cout<<a.Joseph(m);

  system("pause");
}



