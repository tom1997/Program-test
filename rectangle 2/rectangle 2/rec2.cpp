#include <iostream>
using namespace std;
class rectangle{
public:
	void area(double x1,double y1 ){
		x=x1;
		y=y1;
	 
		double p;
		p=x*y;
		if(p<0)
		cout<<-p;
		else
			cout<<p;
	};
private:
	double x,y 
};
int main(){
	double a,b ;
	cin>>a>>b ;
	rectangle e;
	e.area(a,b  );
	getchar();
	getchar();
	getchar();
}

	
	