#include<iostream>   //引用输入输出流库函数的头文件
using namespace std;
#include"Link.h"  //引用单链表类的声明和定义

void main( )
{
	cout<<"以下操作为逆序输出，利用prior从尾部输出"<<endl;     
  int r[5]={1, 2, 3, 4, 5};
  LinkList<int> L(r, 5);
  cout<<"执行插入操作前数据为："<<endl;
  L.PrintList( );                  //显示链表中所有元素
  try
  {
    L.Insert(1, 3);
  }
  catch (char *s)
  {
    cout<<s<<endl;
  }
  cout<<"执行插入操作后数据为："<<endl;
  L.PrintList( );                  //显示链表中所有元素
  cout<<"值为5的元素位置为:";
  cout<<L.Locate(5)<<endl;        //查找元素5，并返回在单链表中位置
  cout<<"执行删除操作前数据为："<<endl;     
  L.PrintList( );                  //显示链表中所有元素
  try
  {
    L.Delete(4);                    //删除元素4
 L.Delete(1);                    //删除元素4
  }
  catch (char *s)
  {
    cout<<s<<endl;
  }
  cout<<"执行删除操作后数据为："<<endl;     
  L.PrintList( );                  //显示链表中所有元素
  system("pause");
}