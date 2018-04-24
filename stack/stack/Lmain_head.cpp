#include <iostream>         //引用输入输出流
using namespace std;
#include "SeqStack.h"       //引入成员函数文件
int main( )
{    
    LinkStack<int>S;      //创建模板类的实例
 if (S.Empty()==1)
  cout<<"栈为空"<<endl;
 else
        cout<<"栈非空"<<endl;
    cout<<"对15 7 10执行入栈操作"<<endl;
 S.Push(15);
 S.Push(7);
 S.Push(10);   
 cout<<"栈顶元素为:"<<endl;   //取栈顶元素
 cout<<S.GetTop( )<<endl;  
 cout<<"执行一次出栈操作"<<endl;
 cout<<S.Pop()<<endl;          //执行出栈操作
 cout<<"栈顶元素为:"<<endl;
    cout<<S.GetTop( )<<endl; 
 S.Pop();
 cout<<"栈顶元素为:"<<endl;
    cout<<S.GetTop( )<<endl; //-1即不存在
 S.Pop();
  S.Pop();
    cout<<"栈顶元素为:"<<endl;
    cout<<S.GetTop( )<<endl; 
 system("pause");
 return 0;
}


 