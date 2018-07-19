#include<string>
#include<iostream>
#include<stack> 
using namespace std;
double sum(char c, double d1, double d2)  {  
    switch (c){  
    case '+':  
        return d1 + d2;  
        break;  
    case '-':  
        return d1 - d2;  
        break;  
    case '*':  
        return d1 * d2;  
        break;  
    case '/':  
        return d1 / d2;  
        break;  
    default:  
        break;  
    }  
}  
int size(char p){
	if(p=='('||p==')'){
		return 6;
	}	
	if(p==')'){
		return 7;
	}
	else if(p=='*'){
		return 5;
	}
	else if(p=='/'){
		return 4;
	}
	else if(p=='+'){
		return 3;
	}
	else if(p=='-'){
		return 2;
	}
	else
		return 1;
}
void post(char *b,int n){
	stack<double> B;
	//B.push(-1);
	if(b[0]>='0'&&b[0]<='9'){
		B.push(b[0]-'0');
	}
	for(int i=1;i<n;i++){
		if(b[i]>='0'&& b[i]<='9'){
			B.push(b[i]-'0');
		}
		else if(b[i]>= 37&& b[i]<=47){
			double x=B.top();
			B.pop();
			double y=(sum(b[i],B.top(),x));
			B.pop();
			B.push(y);

		}
	}
/*	while(B.top()!=-1){	
		double x=B.top();
		B.pop();
		double y=(sum(b[i],x,B.top()));
			B.pop();
			B.push(y);
	}*/
	cout<<endl<<"运行结果为"<<B.top()<<endl;
	delete []b;
}
int main(){
	int n,k;
	stack<char> A;
	A.push('#');
	string str;
	cin>>str;
	n=str.size();
	const char *a=str.data();
	char *b=new char [str.size()];
	cout<<a<<endl;
	int i=2;
	k=1;
	if(a[0]>='0'&&a[0]<='9'){
		cout<<a[0];
		b[0]=a[0];
	}
	else
		exit(-1);
	for(;i<=2*n;i++){
		if(a[i-1]>='0'&&a[i-1]<='9'){
			cout<<a[i-1];
			b[k]=a[i-1]; //用于infix和postfi char之间的转换
			k++;

		}
		else if(a[i-1]>=37&&a[i-1]<=47 && size(a[i-1])>size(A.top())){
			A.push(a[i-1]);
		}
		else if(a[i-1]>=37&&a[i-1]<=47 && size(a[i-1])<size(A.top())){
			cout<<A.top();
			b[k]=A.top();
			k++;
			A.pop();
			A.push(a[i-1]);
		}
		else if(a[i-1]>=37&&a[i-1]<=47 && size(a[i-1])==size(A.top())){
			cout<<A.top();
			A.pop();
			b[k]=A.top();
			k++;
			A.push(a[i-1]);
		}
		
	}
	while(A.top()!='#'){
		cout<<A.top();
		b[k]=A.top();
		A.pop();
		k++;
	}
	post(b,n);
	system("pause");
	return 0;
}
