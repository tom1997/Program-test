#include <iostream>
#include <cmath>
using namespace std;
#include "table_f.h"


int main(){
	int a1,b1;
	cout<<"Please enter the length of two arrays"<<endl;
	cin>>a1>>b1;
	cout<<endl;
	int *a=new int[a1];
	int *b=new int[b1];
	for(int i=0;i<a1;i++)
	{
		a[i]=rand()%10;
	}
		for(int i=0;i<b1;i++)
	{
		b[i]=rand()%10;
	}
	for(int i=a1-1;i>=0;i--)
	{
		cout<<a[i];
	}
	cout<<endl;
	for(int i=b1-1;i>=0;i--)
	{
		cout<<b[i];
	}
	cout<<endl;
	SeqList a_sq(a,a1);
	SeqList b_sq(b,b1);
	//a_sq.PrintList();
	cout<<endl;
	//b_sq.PrintList();
	cout<<endl;
	add(a_sq,b_sq);//¼Ó
	
	minus(a_sq,b_sq); //²î
		cout<<endl;
		cout<<endl;
	multiple(a_sq,b_sq);

	system("pause");
}