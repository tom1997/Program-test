#include <iostream>

using namespace std;

class shape

{

protected:

       virtual float area() {return 0;}//面积还是返回浮点数比较合适

       virtual void shapename() = 0;

};

class circle:public shape

{

protected:

       int x;

       int y;

       int r;

public:

       circle(){x=0;y=0;r=0;}

       circle(int a,int b,int c){x=a;y=b;r=c;}

       void shapename() {cout<<"我是圆啊"<<endl;}

       float area(){return 3.14*r*r;}

};

class rectangle:public shape

{

protected:

       int x,y;

public:

       rectangle(){x=0;x=0;}

       rectangle(int a,int b){x=a,y=b;}

       void shapename(){cout<<"我是长方形啊"<<endl;}

       float area(){return x*y;}

};

class triangle:public shape

{

protected:

       int h,x;

public:

       triangle(){h=0;x=0;}

       triangle(int a,int b){h=a;x=b;}

       void shapename(){cout<<"我是三角形啊"<<endl;}

       float area(){return 1.0*h*x/2;}//为使其返回正确的浮点数，在运算时加一个1.0*

};

void printarea(circle c,rectangle r,triangle t)//这个函数仅仅是打印信息，没必要声明一个类来将它包含进去，然后又再多继承...只需要把它写成一个普通的全局函数即可

       {
		   cout<<"circlearea is "<<c.area()<<endl;
		   cout<<"rectanglearea is "<<r.area()<<endl;
		   cout<<"trianglearea is "<<t.area()<<endl;

       } 

void main()

{

       circle c(1,1,1);

       rectangle r(1,1);

       triangle t(1,1);

       printarea(c,r,t);//传递参数给printarea函数

}