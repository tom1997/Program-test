#include <iostream>
using namespace std;
class Boat{
public:
	float boatweight(float bweight){
	weight=bweight;
	return 0;}
	float getweight(){return weight;}
private:
float weight;};
class Car{
public:
	 float carweight(float cweight){
	weight=cweight;
	 return 0;}
	 friend float gettotalweight(Boat &p, Car &e){
			float x=p.getweight();
			float y=e.getweight();
			return (x+y);}

		float getweight(){return weight;}
private:
float weight;};

int main(){
	Car a;
	Boat b;
	float x,y;
	cin>>x>>y;
	a.carweight(x);
	b.boatweight(y);
	cout<<gettotalweight(b,a);
	getchar();
}
