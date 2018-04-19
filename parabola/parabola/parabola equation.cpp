#include <iostream>
#include <math.h>
using namespace std;
int main(){
	double a,b,c;
	cout<<"Please enter three real number for parabola equation ax^2+bx+c=0"<<endl;
	cin>>a>>b>>c;
	double d;
	int q=-1;
	d=(b*b)-4*a*c;
	if(d<0)
		cout<<"There is no any real root."<<sqrt(c*q);
	else if(d>0)
		cout<<"There are two real roots, one is "<<(-b+sqrt(d))/2/a<<", other one is "<<(-b-sqrt(d))/2/a;
	else 
		cout<<"There is only one real root "<<-b/2/a;
	getchar();getchar();
}