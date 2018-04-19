#include <iostream>
using namespace std;
class SimpleCircle{
public:
	SimpleCircle(int *Radius){
		itsRadius=Radius;
	};
	int getr(){
	return *itsRadius;}
private:
	int *itsRadius;
};
int main(){
	int r;
	cin>>r;
	SimpleCircle C1(&r);
	cout<<C1.getr();
	getchar();
	getchar();
}