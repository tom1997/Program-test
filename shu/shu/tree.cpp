#include <iostream>
using namespace std;
class tree{
public:
	void a(int x){
	ages=x;}
	void grow(int years){
	ages+=years;}
	int age(){
	return ages;}

private:
	int ages;
	
};
int main(){
	tree a;
	a.a(5);
	a.grow(2);
	cout<<	a.age()<<endl;
	getchar();

}

	
	