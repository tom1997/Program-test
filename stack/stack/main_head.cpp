#include <iostream>         //�������������
using namespace std;
#include "SeqStack.h"       //�����Ա�����ļ�
int main( )
{    
    LinkStack<int>S;      //����ģ�����ʵ��
 if (S.Empty()==1)
  cout<<"ջΪ��"<<endl;
 else
        cout<<"ջ�ǿ�"<<endl;
    cout<<"��15 7 10ִ����ջ����"<<endl;
 S.Push(15);
 S.Push(7);
 S.Push(10);   
 cout<<"ջ��Ԫ��Ϊ:"<<endl;   //ȡջ��Ԫ��
 cout<<S.GetTop( )<<endl;  
 cout<<"ִ��һ�γ�ջ����"<<endl;
 cout<<S.Pop()<<endl;          //ִ�г�ջ����
 cout<<"ջ��Ԫ��Ϊ:"<<endl;
    cout<<S.GetTop( )<<endl; 
 S.Pop();
 cout<<"ջ��Ԫ��Ϊ:"<<endl;
    cout<<S.GetTop( )<<endl; //-1��������
 S.Pop();
  S.Pop();
    cout<<"ջ��Ԫ��Ϊ:"<<endl;
    cout<<S.GetTop( )<<endl; 
 system("pause");
 return 0;
}


 