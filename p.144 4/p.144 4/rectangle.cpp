#include <iostream>
using namespace std;
class rectangle{
public:
	void area(double x1,double y1,double x2,double y2){
		x=x1;
		y=y1;
	f=x2;
	g=y2;
		double p;
		p=(x-f)*(y-g);
		if(p<0)
		cout<<-p;
		else
			cout<<p;
	};
private:
	double x,y,f,g;
};
int main(){
	double a,b,c,d;
	cin>>a>>b>>c>>d;
	rectangle e;
	e.area(a,b,c,d);
	getchar();
	getchar();
	getchar();
}

	
	