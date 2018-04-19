#include <iostream>
using namespace std;

class Cat{
	
public:
	Cat(double weight){};
	
	Cat(Cat &p){weight=p.weight;cat++;};
	static void getNumofCats(){cout<<cat;};

private:
		static int cat;
	double weight;
};
int Cat::cat=1;
int main(){
	Cat a(5);
	Cat b(a);
	a.getNumofCats();
		getchar();
}


