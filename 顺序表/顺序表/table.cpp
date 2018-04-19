#include<iostream>
using namespace std;
#include "tabl.h"

int main(){
	int a[7];
	int b[8];
	for(int i=0;i<7;i++){
		a[i]=rand()%10;
		cout<<a[i]<< "  ";
	}
	cout<<endl;
	for(int i=0;i<8;i++){
		b[i]=rand()%10;
		cout<<b[i]<<"  ";
	}
	cout<<endl;
	cout<<"============================================"<<endl;
	SeqList first(a,7); //构造Set first
	SeqList second(b,8);//构造Set second
	Intersection(first,second); //作交	
	first.Insert(2,3);
	first.PrintList();
	cout<<endl;
	first.Delete(2);
	first.Delete(5000); //抛出异常测试
	cout<<endl;
	cout<<"============================================"<<endl;
	first.Insert(-554,9);//抛出异常测试
	first.PrintList();
	cout<<endl;
	Union(first,second);
	cout<<endl;
	Intersection(first,second);
	cout<<endl<<"====================================="<<endl;
	add(first,second);

	system("pause");

}
