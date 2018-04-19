#include <iostream>
using namespace std;
int main(){
	int a;
	int *p;
	int &r=a;
	p=&a;
	*p=10;
	cout<<a<<endl;
	r=5;
	cout<<a<<endl;
	getchar();
}


