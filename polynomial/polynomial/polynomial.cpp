#include<iostream>   //��������������⺯����ͷ�ļ�
using namespace std;
#include <cmath>
#include"LinkList.h"  //���õ�������������Ͷ���

void main( )
{
  float power[6]={0, 2, 3, 4, 5, -7};
  float coe[6]={1.00, 2, 3, -3, 5, 7};
  float power1[6]={0, 2, 3, -4, 5, -7};
  float coe1[6]={1, -2, -3, -3, -5, -7};
  LinkList<float> L(coe,power, 6);
  LinkList<float > L1(coe1,power1, 6);
  LinkList<float>C;
  cout<<"ִ�в������ǰ����Ϊ��"<<endl;
  cout<<"����AΪ��"<<endl;
  L.PrintList( );                  //��ʾ����������Ԫ��
  cout<<"����BΪ��"<<endl;
  L1.PrintList( ); 
  cout<<"�������������"<<endl;
  float x;
  cin>>x;
  L.alge(x);
  cout<<endl;
  cout<<"����ΪA��B��������ʽ����ӵ�����C"<<endl;
  
  C=add(L,L1);
    cout<<endl;
	cout<<"����CΪ��"<<endl;
	C.PrintList();
	cout<<"�������������"<<endl;
	
	cin>>x;
	C.alge(x);
	cout<<endl;

  system("pause");
}

