#include<iostream>   //��������������⺯����ͷ�ļ�
using namespace std;
#include"Link.h"  //���õ�������������Ͷ���

void main( )
{
	cout<<"���²���Ϊ�������������prior��β�����"<<endl;     
  int r[5]={1, 2, 3, 4, 5};
  LinkList<int> L(r, 5);
  cout<<"ִ�в������ǰ����Ϊ��"<<endl;
  L.PrintList( );                  //��ʾ����������Ԫ��
  try
  {
    L.Insert(1, 3);
  }
  catch (char *s)
  {
    cout<<s<<endl;
  }
  cout<<"ִ�в������������Ϊ��"<<endl;
  L.PrintList( );                  //��ʾ����������Ԫ��
  cout<<"ֵΪ5��Ԫ��λ��Ϊ:";
  cout<<L.Locate(5)<<endl;        //����Ԫ��5���������ڵ�������λ��
  cout<<"ִ��ɾ������ǰ����Ϊ��"<<endl;     
  L.PrintList( );                  //��ʾ����������Ԫ��
  try
  {
    L.Delete(4);                    //ɾ��Ԫ��4
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