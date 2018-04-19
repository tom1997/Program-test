#include <iostream>
using namespace std;
const double pi=3.1415926535;
class Circle{
public:
	Circle(int r){
		radius=r;
	}
	void getArea(){
		cout<<(radius*radius*pi);
	}
	void a(Circle p){
	radius=p.radius;}
	
private:
	int radius;
};

int main(){
	Circle a(6);
	Circle b(a);
	a.getArea();
	getchar();
}
