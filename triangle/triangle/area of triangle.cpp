#include <math.h>
#include <stdio.h>
#include <iostream>
using namespace std;
class Triangle{
public:
	Triangle(double na,double nb,double nc);
	void Area(double a,double b,double c);

private:
	double a;
	double b;
	double c;
	

};
Triangle::Triangle(double na,double nb,double nc){
	a=na;
	b=nb;
	c;nc;

};
void Triangle::Area(double a,double b,double c){
	double s;
	s=(a+b+c)/2;
	cout<<"Area: "<<sqrt(s*(s-a)*(s-b)*(s-c));
}
int main(void){
	double a,b,c;
	cin>>a>>b>>c;
	if(a<=0||b<=0||c<=.0)
		cout<<"This is not a triangle";
	else 
		if(a+b>c&&a+c>b&&c+b>a){
	Triangle E(a,b,c);
	E.Area(a,b,c);
	}
		else
			cout<<"This is not a triangle";
	getchar();
}
