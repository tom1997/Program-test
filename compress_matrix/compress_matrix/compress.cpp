#include<iostream>
using namespace std;
int main(){
	int n;
	cout<<"Please enter the size of matrix"<<endl; 
	cin>>n;
	int i,j;
	int** a = new int *[n];
	for(int i=0; i<n; ++i) {
		a[i] = new int[n];
	}
	int *sa=new int [n*(n+1)/2];
	for(int i=0;i<n;i++){
		for (int j=0;j<i;j++){
			a[i][j]=a[j][i]=i+j;
		}
	}
	for(int i=0;i<n;i++){
		for (int j=0;j<i;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	for(int i=0;i<n;i++){
		for (int j=0;j<i;j++){
			sa[i*(i-1)/2+j]=a[i][j];
		}
	}
	cout<<"Please enter row and colume:"<<endl;
	cin>>i>>j;
	
	cout<<"The number in row "<<i<<" and colume "<<j<<" is "<<endl;
	if(i>=j){
		j--;
		cout<<sa[i*(i-1)/2+j]<<endl;
	}
	else
		cout<<sa[j*(j-1)/2+i]<<endl;
	system("pause");
	return 0;

}