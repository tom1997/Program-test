#include <iostream>
#include <math.h>
using namespace std;
class Shape{
public:
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
class Square:public Shape{
public:
	Square(){double x=0;};
	Square(double a){
	x=a;
	};
	double area(){
		return x*x;}

protected:
	double x;


};
class Trapezoid:public Shape{
public:
	Trapezoid(){double x=0; double y=0;double z=0;};
	Trapezoid(double a,double b,double c){
	x=a;
	y=b;
	z=c;
	};
	double area(){
		return (x+y)*z/2;}

protected:
	double x,y,z;


};
void printarea(Triangle x, Circle y,Rectangle z,Square d,Trapezoid e){
	cout<<"三角形的面积是" <<x.area()<<endl;
		cout<<"圆的面积是" <<y.area()<<endl;
		cout<<"长方体的面积是" <<z.area()<<endl;
		cout<<"正方形的面积是" <<d.area()<<endl;
		cout<<"梯体的面积是" <<e.area()<<endl;


}
void point(Shape *ps){
	ps->area();
	cout<<ps->area()<<endl;
}
int main(){
Circle a(2);
point(&a);
Triangle b(1,1,1);
point(&b);
Rectangle c(2,1);
point(&c);
Square d(3);
point(&d);
Trapezoid e(3,2,0.5);
point(&e);


printarea(b,a,c,d,e);

system("pause");

}