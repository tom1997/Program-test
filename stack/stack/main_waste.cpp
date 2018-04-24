#include <iostream>         //引用输入输出流
using namespace std;
#include "SeqStack_waste.h"       //引入成员函数文件
int main( )
{    int num,x;
	cout<<"请输入数字:"<<endl;
	cin>>num;
	cout<<endl<<"请输入进制:"<<endl;
	cin>>x;
	Decimaltor<int>(num,x);
	system("pause");
	return 0;
}


 