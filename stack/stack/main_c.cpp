#include <iostream>         //引用输入输出流
using namespace std;
#include "LinkQueue_c.H"       //引入成员函数文件
int main( )
{    
    CirQueue<int>S;      //创建模板类的实例
	int n;
	cout<<"输入你想入栈的数字的个数,其中会每个数字会按顺序入栈"<<endl;
	cin>>n;
	for(int i=1;i<=n;i++){
		S.EnQueue(i);
	}
	if (S.Empty()==1)
		cout<<"栈为空"<<endl;
	else
		cout<<"栈非空"<<endl;
	cout<<"栈顶元素为:"<<endl;   //取栈顶元素
	cout<<S.GetQueue()<<endl;  
	cout<<"执行一次出栈操作"<<endl;
	cout<<S.DeQueue()<<endl;          //执行出栈操作
	cout<<"栈顶元素为:"<<endl;
    cout<<S.GetQueue()<<endl;
	cout<<"执行一次出栈操作"<<endl;
	S.DeQueue();
	cout<<"栈顶元素为:"<<endl;
    cout<<S.GetQueue()<<endl; 
	cout<<"执行一次出栈操作"<<endl;
	S.DeQueue();
    cout<<"栈顶元素为:"<<endl;
    cout<<S.GetQueue()<<endl; //-1即不存在
	system("pause");
	return 0;
}


 