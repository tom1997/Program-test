#include<iostream>   //��������������⺯����ͷ�ļ�
using namespace std;
#include"LinkList.h"  //���õ�������������Ͷ���

void main( )
{
  int r[6]={1, 2, 3, 4, 5, 7};
  LinkList<int> L(r, 6);
  cout<<"ִ�в������ǰ����Ϊ��"<<endl;
  L.PrintList( );                  //��ʾ����������Ԫ��
  try
  {
    L.Insert(2, 3);
  }
  catch (char *s)
  {
    cout<<s+1<<endl;
  }
  cout<<"ִ�в������������Ϊ��"<<endl;
  L.PrintList( );                  //��ʾ����������Ԫ��
  cout<<"ֵΪ5��Ԫ��λ��Ϊ:";
  cout<<L.Locate(5)<<endl;        //����Ԫ��5���������ڵ�������λ��
  cout<<"ִ��ɾ������ǰ����Ϊ��"<<endl;     
  L.PrintList( );                  //��ʾ����������Ԫ��
  try
  {
    L.Delete(1);                    //ɾ��Ԫ��4
  }
  catch (char *s)
  {
    cout<<s<<endl;
  }
  cout<<"ִ��ɾ������������Ϊ��"<<endl;     
  L.PrintList( );                  //��ʾ����������Ԫ��
  system("pause");
}

