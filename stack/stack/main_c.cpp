#include <iostream>         //�������������
using namespace std;
#include "LinkQueue_c.H"       //�����Ա�����ļ�
int main( )
{    
    CirQueue<int>S;      //����ģ�����ʵ��
	int n;
	cout<<"����������ջ�����ֵĸ���,���л�ÿ�����ֻᰴ˳����ջ"<<endl;
	cin>>n;
	for(int i=1;i<=n;i++){
		S.EnQueue(i);
	}
	if (S.Empty()==1)
		cout<<"ջΪ��"<<endl;
	else
		cout<<"ջ�ǿ�"<<endl;
	cout<<"ջ��Ԫ��Ϊ:"<<endl;   //ȡջ��Ԫ��
	cout<<S.GetQueue()<<endl;  
	cout<<"ִ��һ�γ�ջ����"<<endl;
	cout<<S.DeQueue()<<endl;          //ִ�г�ջ����
	cout<<"ջ��Ԫ��Ϊ:"<<endl;
    cout<<S.GetQueue()<<endl;
	cout<<"ִ��һ�γ�ջ����"<<endl;
	S.DeQueue();
	cout<<"ջ��Ԫ��Ϊ:"<<endl;
    cout<<S.GetQueue()<<endl; 
	cout<<"ִ��һ�γ�ջ����"<<endl;
	S.DeQueue();
    cout<<"ջ��Ԫ��Ϊ:"<<endl;
    cout<<S.GetQueue()<<endl; //-1��������
	system("pause");
	return 0;
}


 