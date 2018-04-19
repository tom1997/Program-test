#include <iostream>
using namespace std;
int Fibonacci(int n){
	if(n>4)
	 return Fibonacci(n-1)+Fibonacci(n-2);
	else if(n==4)
		return Fibonacci(3)+1;
	else if(n==3)
		return 2;
	else if(n==2)
		return 1;
	else if(n==1)
		return 1;
	else if(n==0)
		return 0;


}
int main(){
	cout<<"Enter a number"<<endl;
	int n;
	cin>>n;
		cout<<"Term "<<n<<" of Fibonacci sequence is "<<Fibonacci(n);
		getchar();
		getchar();
}