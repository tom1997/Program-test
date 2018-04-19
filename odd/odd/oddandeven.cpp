#include<iostream>
using namespace std;
void evenodd(int *a,int n){
	int *b=new int[n];
	int i=0;
	int j=1;
	for(int i=0;i<=n-1;i++){
		if(a[i]%2==0){
			
			b[n-j]=a[i];
			j++;
			cout<<"even number is at "<<i<<endl;
		}
	}
	for(int j=0;j<=n-1;j++){
		if(a[j]%2!=0){
		
		b[i]=a[j];
		i++;
		cout<<"odd number is at "<<j<<endl;
		}
	}

	for(int i=0;i<=n-1;i++){
		cout<<b[i]<<endl;
	};
	
}

int main(){
	int n;
	cin>>n;
	int *a=new int[n];
	for(int i=0;i<=n;i++){
	a[i]=rand()%100;
	cout<<a[i]<<endl;
	};
	cout<<endl;
	evenodd(a,n);
	system("pause");
}