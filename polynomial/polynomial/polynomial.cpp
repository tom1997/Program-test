#include<iostream>   //引用输入输出流库函数的头文件
using namespace std;
#include <cmath>
#include"LinkList.h"  //引用单链表类的声明和定义

void main( )
{
  float power[6]={0, 2, 3, 4, 5, -7};
  float coe[6]={1.00, 2, 3, -3, 5, 7};
  float power1[6]={0, 2, 3, -4, 5, -7};
  float coe1[6]={1, -2, -3, -3, -5, -7};
  LinkList<float> L(coe,power, 6);
  LinkList<float > L1(coe1,power1, 6);
  LinkList<float>C;
  cout<<"执行插入操作前数据为："<<endl;
  cout<<"数组A为："<<endl;
  L.PrintList( );                  //显示链表中所有元素
  cout<<"数组B为："<<endl;
  L1.PrintList( ); 
  cout<<"请输入测试数字"<<endl;
  float x;
  cin>>x;
  L.alge(x);
  cout<<endl;
  cout<<"以下为A与B两个多项式的相加的数组C"<<endl;
  
  C=add(L,L1);
    cout<<endl;
	cout<<"数组C为："<<endl;
	C.PrintList();
	cout<<"请输入测试数字"<<endl;
	
	cin>>x;
	C.alge(x);
	cout<<endl;

  system("pause");
}

