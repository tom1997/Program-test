#include<iostream>   //引用输入输出流库函数的头文件
using namespace std;
#include"LinkList.cpp"  //引用单链表类的声明和定义


void main( )
{
  int r[5]={1, 2, 3, 4, 9};
  int c[8]={1, 2, 3, 4, 5,7,9,6};
  int d[8]={1, 2, 3, 4, 5,7,9,6};
  LinkList<int> L(r, 5);
  LinkList<int> Lb(d, 8);
  LinkList<int> Lc(c, 8);
  Lc.PrintList();
  cout<<"上为L1，下为L2,将L2的值赋进L1"<<endl;
  L.PrintList();
  Lc=L;
  cout<<"运算符重载演示"<<endl;
  Lc.PrintList( );
  cout<<"执行插入操作前数据为："<<endl;
  L.PrintList( );                  //显示链表中所有元素
  try
  {
    L.Insert(2, 3);
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
  cout<<L.length()<<endl;

  try
  {
    L.Delete(1);                    //删除元素4
  }
  catch (char *s)
  {
    cout<<s<<endl;
  }
  cout<<"执行删除操作后数据为："<<endl;     
  L.PrintList( );                  //显示链表中所有元素
 L.Increase();
 L.Reverse();
 L.PrintList();
 cout<<endl;
 cout<<IsEqual(L,Lb)<<endl;
 Interception(L,Lb);
 cout<<endl;
 // Union(L,Lb); //暂时无法完成的任务，未知哪里出错
  L.PrintList();
  system("pause");
}