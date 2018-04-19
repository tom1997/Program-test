#include <iostream>
using namespace std;
int i;
class rectangle{
public:
	void volume(double nwidth,double nlenght,double nheight){
		width=nwidth;
	lenght=nlenght;
	height=nheight;}
	void print();
	double getwidth(){return width;};
	double getlenght(){return lenght;};
	double getheight(){return height;};
private:
	double width;
	double lenght;
	double height;
};
void rectangle::print(){
cout<<"The volume of rectangle is "<<width*lenght*height<<endl;}
int main(){while(i<3){
	rectangle V1;
	double a,b,c;
	cout<<"Please enter three number which perform a rectangle"<<endl;
	cin>>a>>b>>c;
	V1.volume(a,b,c);
	V1.print();
	getchar();
	i++;

}
}