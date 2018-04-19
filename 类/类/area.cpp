#include <iostream>
#include <math.h>
using namespace std;
class Shape{
protected:
       virtual double area() {return 0;}
};
class Triangle:public Shape{
public:
	Triangle(){double x=0; double y=0; double z=0;}
	Triangle(double a,double b,double c){
		x=a;
		y=b;
		z=c;
	};
	
	double area(){
		double p=(x+y+z)/2;
		return sqrt(p*(p-x)*(p-y)*(p-z));
	}

protected:
double x,y,z;
};
class Circle:public Shape{
public:
	Circle(){double r=0;};
	Circle(double ra){
		r=ra;};
		double area(){
		return r*r*3.14;}
protected:
	double r;


};
class Rectangle:public Shape{
public:
	Rectangle(){double x=0; double y=0;};
	Rectangle(double a,double b){
	x=a;
	y=b;
	};
	double area(){
		return x*y;}

protected:
	double x,y;


};
void printarea(Triangle x, Circle y,Rectangle z){
	cout<<"三角形的面积是" <<x.area()<<endl;
		cout<<"圆的面积是" <<y.area()<<endl;
			cout<<"长方体的面积是" <<z.area()<<endl;
}

int main(){
Circle a(2);
Triangle b(1,1,1);
Rectangle c(2,1);

printarea(b,a,c);

system("pause");

}