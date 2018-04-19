#include <iostream>
using namespace std;
void reverse(int a[3][3]){
	int n,k;
	for(n=0;n<3;n++){
		cout<<endl;
		for(k=0;k<3;k++)
			cout<<a[k][n]<<" ";
	}
};
void main(){
	int a[3][3];
	int i=0;
	int j=0;
	
	for(i=0;i<=2;i++){
		for(j=0;j<=2;j++){
			cin>>a[i][j];}
		j=0;
	}
	i=0;
	j=0;
	for(i=0;i<=2;i++){
		cout<<endl;
		for(j=0;j<=2;j++){
			cout<<a[i][j]<<" ";}
		j=0;
	}
	cout<<endl;
	
	reverse(a);
	getchar();
	getchar();
}

