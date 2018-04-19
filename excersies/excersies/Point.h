#ifndef _POINT_H
#define _POINT_H
#include <iostream>
using namespace std;

class Point {	//��Ķ���
 public:	  	//�ⲿ�ӿ�
    Point(){    
    }; //�޲ι��캯��
    Point(int x, int y){
    };  //�вι��캯��
	~Point(){
	};  //�����캯��
    Point(const Point &p) : x(p.x), y(p.y) {	}//���ƹ��캯��);
    Point & operator=(Point& p){
		x=p.x;
		y=p.y;
		return p ;
    };//���ظ�ֵ�����
    friend ostream & operator << (ostream &out, Point&p){
		out<<"The point P coordinate is ("<<p.x<<","<<p.y<<")"<<endl;
		return out;
    };		//�����<<����
    friend istream & operator >> (istream &in,  Point &p){
		cout<<"Please enter the coordinate of x-point of P"<<endl;
		in>>p.x;
		cout<<endl;
		cout<<"Please enter the coordinate of y-point of P"<<endl;
		in>>p.y;
		return in;
    };		//�����<<����
	void move(int newX,int newY);
	int getX() const { return x; }
	int getY() const { return y; }
  private:				//˽�����ݳ�Ա
	int x, y;
};
#endif	//_POINT_H