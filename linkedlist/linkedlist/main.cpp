#include<iostream>   //��������������⺯����ͷ�ļ�
using namespace std;
#include"LinkList.cpp"  //���õ�������������Ͷ���


void main( )
{
  int r[5]={1, 2, 3, 4, 9};
  int c[8]={1, 2, 3, 4, 5,7,9,6};
  int d[8]={1, 2, 3, 4, 5,7,9,6};
  LinkList<int> L(r, 5);
  LinkList<int> Lb(d, 8);
  LinkList<int> Lc(c, 8);
  Lc.PrintList();
  cout<<"��ΪL1����ΪL2,��L2��ֵ����L1"<<endl;
  L.PrintList();
  Lc=L;
  cout<<"�����������ʾ"<<endl;
  Lc.PrintList( );
  cout<<"ִ�в������ǰ����Ϊ��"<<endl;
  L.PrintList( );                  //��ʾ����������Ԫ��
  try
  {
    L.Insert(2, 3);
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
  cout<<L.length()<<endl;

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
 L.Increase();
 L.Reverse();
 L.PrintList();
 cout<<endl;
 cout<<IsEqual(L,Lb)<<endl;
 Interception(L,Lb);
 cout<<endl;
 // Union(L,Lb); //��ʱ�޷���ɵ�����δ֪�������
  L.PrintList();
  system("pause");
}