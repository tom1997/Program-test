#include <iostream>
#include<string>
using namespace std;
int min(int min,int min2,int min3){
	if(min <min2 && min< min3)
		return min;
	else if(min2<min3)
		return min2;
	else 
		return min3;
}
int ASM(const char p[],const char t[],int m,int n,int k){
   //����ռ�
    int **a =  new int* [m+1];    
    for(int i = 0; i <=m; i++){
        a[i] = new int[n];
	}

    //ʹ�ÿռ�
	for(int j=0;j<=n;j++){
		a[0][j]=0;
	}
	for(int i=0;i<=m;i++){
		a[i][0]=i;
	}
	for(int j=1;j<=n;j++){
		for(int i=1;i<=m;i++){
		if(p[i]==t[i]){
			a[i][j]=min(a[i-1][j-1],a[i-1][j]+1,a[i][j-1]+1);
			cout<<"a["<<i<<"]["<<j<<"]="<<a[i][j]<<endl;
		}
		else{
			a[i][j]=min(a[i-1][j-1]+1,a[i-1][j]+1,a[i][j-1]+1);
			cout<<"a["<<i<<"]["<<j<<"]="<<a[i][j]<<endl;
		}
		
		}
		if(a[m][j]<=k) return j;
	}
}
int main(){
	string p1="hallo";
	const char *p;
	const char *s;
	cout<<"����������"<<endl;
	//getline(cin, p1);
	cout<<"������ƥ�����"<<endl;
	string s1="hello";
	//getline(cin, s1);
	p=p1.data();
	s=s1.data();
	cout<<"��������ƶ�"<<endl;
	int k=1;
	//cin>>k;
	int n=p1.size();
	int m=s1.size();
	cout <<"�״γ������ƶ�ƥ����ַ�λ��"<<ASM(p,s,n,m,k)<<endl;
	system("pause");
	return 0;
}