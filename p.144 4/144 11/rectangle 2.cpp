#include <iostream>
using namespace std;
class rectangle{
public:
	void area(double xx,double yy){
		x=xx;
		y=yy;
	
		double p;
		p=x*y;
		if(p<0)
		cout<<"Area = "<<-p;
		else
			cout<<"Area = "<<p;
	};
private:
	double x,y;
};
int main(){
	double a,b;
	cin>>a>>b;
	rectangle e;
	e.area(a,b);
	getchar();
	getchar();
	getchar();
}

	
	