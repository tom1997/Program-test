#include <iostream>
using namespace std;
void fn1(){
	static int n;
 n++;}int main(){
	for(int x=0;x<10;x++){
		fn1();
	};
	cout<<fn1;
	getchar();

}
