#include <iostream>
using namespace std;
double Legendrpolynomials(int n,double x){
	if(n>3)
		return (((((2*n)-1)*Legendrpolynomials(n-1,x))-(((n-1)*Legendrpolynomials(n-2,x))))/n);
	else if(n==3)
		return (((((2*n)-1)*Legendrpolynomials(n-1,x))-(((n-1)*x)))/n);
	else if(n==2)
		return (((((2*n)*x)-1)-(((n-1))))/n);
	else if(n==1)
		return x;
	else if(n==0)
		return 1;
}
int main(){
	int a;
	double b;
	cout<<"Enter a integer and float."<<endl;
	cin>>a>>b;
	cout<<"Legendr polynomials when n="<<a<<" x="<<b<<endl<<" Answer is "<<Legendrpolynomials(a,b);
	getchar();
	getchar();
	return 0;
}
