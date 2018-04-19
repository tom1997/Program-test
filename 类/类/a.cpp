#include <iostream>

using namespace std;

class shape

{

protected:

       virtual float area() {return 0;}//������Ƿ��ظ������ȽϺ���

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

       void shapename() {cout<<"����Բ��"<<endl;}

       float area(){return 3.14*r*r;}

};

class rectangle:public shape

{

protected:

       int x,y;

public:

       rectangle(){x=0;x=0;}

       rectangle(int a,int b){x=a,y=b;}

       void shapename(){cout<<"���ǳ����ΰ�"<<endl;}

       float area(){return x*y;}

};

class triangle:public shape

{

protected:

       int h,x;

public:

       triangle(){h=0;x=0;}

       triangle(int a,int b){h=a;x=b;}

       void shapename(){cout<<"���������ΰ�"<<endl;}

       float area(){return 1.0*h*x/2;}//Ϊʹ�䷵����ȷ�ĸ�������������ʱ��һ��1.0*

};

void printarea(circle c,rectangle r,triangle t)//������������Ǵ�ӡ��Ϣ��û��Ҫ����һ����������������ȥ��Ȼ�����ٶ�̳�...ֻ��Ҫ����д��һ����ͨ��ȫ�ֺ�������

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

       printarea(c,r,t);//���ݲ�����printarea����

}