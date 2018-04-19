#include  <iostream>
using namespace std;
class student{
public:
	int plusid(){id++;}
	int getid(){
		return id;}
	string getname(){
		return name;}
	char getperformance(){
		return performance;}
private:
	static int id;
	string name;
	char performance;
}

int main(){
	int a[5]={1,2,3,4,5};
	student f,b,c,d,e;
	cout<<f.getid();

}
