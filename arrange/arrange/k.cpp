#include<iostream>
using namespace std;
template<typename T>
void moveleft(T *a,int n,int k){
	T *temp=new T[k];
for(int i=0;i<=k-1;i++){
	temp[i]=a[i];

	};
	for(int i=k;i<=n-1;i++){
	a[i-k]=a[i];
	
	};
	for(int i=0;i<=k-1;i++){
	a[n-k+i]=temp[i];
	};
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
	double *b=new double[n-1];
	for(int i=0;i<=n-1;i++){
	a[i]=rand()%100;
	cout<<a[i]<<endl;
	};
	cout<<endl;
	moveleft (a,n,k);
	cout<<"Testing real number##############################################################################################"<<endl;
	for(int i=0;i<=n-1;i++){
	b[i]=rand()%10000*0.01;
	cout<<b[i]<<endl;
	};
	cout<<endl;
	moveleft (b,n,k);
	system("pause");
}