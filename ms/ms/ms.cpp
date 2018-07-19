#include<iostream>
using namespace std;
void square(int a[9][9], int n){
	int i=0;
	int j=n/2;
	a[i][j]=1;
	int itemp;
	int jtemp;

	for(int k=2;k<=n*n;k++){
		itemp=i;
		jtemp=j;
		i=(i-1+n)%n;
		j=(j-1+n)%n;
		if(a[i][j]>0){
			i=(itemp+1)%n;
			j=jtemp;
		}
		a[i][j]=k;
	}
}

int main(){
	int n=9;
	int a[9][9];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			a[i][j]=0;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	square(a,n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	system("pause");


}