#ifndef _POINT_H
#define _POINT_H
#include <iostream>
using namespace std;

class Point {	//类的定义
 public:	  	//外部接口
    Point(){    
    }; //无参构造函数
    Point(int x, int y){
    };  //有参构造函数
	~Point(){
	};  //析构造函数
    Point(const Point &p) : x(p.x), y(p.y) {	}//复制构造函数);
    Point & operator=(Point& p){
		x=p.x;
		y=p.y;
		return p ;
    };//重载赋值运算符
    friend ostream & operator << (ostream &out, Point&p){
		out<<"The point P coordinate is ("<<p.x<<","<<p.y<<")"<<endl;
		return out;
    };		//运算符<<重载
    friend istream & operator >> (istream &in,  Point &p){
		cout<<"Please enter the coordinate of x-point of P"<<endl;
		in>>p.x;
		cout<<endl;
		cout<<"Please enter the coordinate of y-point of P"<<endl;
		in>>p.y;
		return in;
    };		//运算符<<重载
	void move(int newX,int newY);
	int getX() const { return x; }
	int getY() const { return y; }
  private:				//私有数据成员
	int x, y;
};
#endif	//_POINT_H