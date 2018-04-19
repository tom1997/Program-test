#include<iostream>
using namespace std;
template <class T x>
void moveleft(T *a,int n,int k){
	T temp=a[0];
	for(int i=1;i<=n-1;i++){
	a[i-1]=a[i];
	};
	a[n-1]=temp;
	for(int i=0;i<=n-1;i++){
	cout<<a[i]<<endl;
	};
};

int main(){
	int n,k;
	cout<<"Please enter the number of array"<<endl;
	cin>>n;
	cout<<"Please enter the number that position move left forward"<<endl;
	cin>>k;

	int *a=new int[n-1];
	for(int i=0;i<=n-1;i++){
	a[i]=rand()%100;
	cout<<a[i]<<endl;
	};
	cout<<endl;
	moveleft (a,n,k);
	moveleft()
	system("pause");
}