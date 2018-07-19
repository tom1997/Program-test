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
int main(){
	int n;
	stack<double> A;
	stack<char> B;
	B.push('#');
	string str;
	cin>>str;
	n=str.size();
	//istringstream is(str);
	const char *a=str.data();
	cout<<a<<endl;
	int i=2;
	//下列内容是可以读取两位数字以上，但本人无法写出
/*	while (is>>ch){  
        if (ch>='0'&&ch<='9')  
        {  
            is.putback(ch);//将ch放回到输入流中，这样后面用is>>i可以完整的读入数字  
            is>>n1;  
            cout<<" i: "<<n1<<endl<<endl; 
			A.push(n1);
			k++;
			i++;
        }
	}*/
if(size(a[0])<6){
	A.push(a[0]-'0');
}
else
	B.push(a[0]);
	do{
		if(i<n+1){
		 if(a[i-1]>=33&&a[i-1]<=47){
			 if(size(a[i-1])>size(B.top()) && size(B.top())<6){
				 B.push(a[i-1]);
				 i++;
			 }
			 else if (size(a[i-1])<=size(B.top())&& size(B.top())<6){
				 double x=A.top();
				 A.pop();
				 double y=A.top();
				 A.pop();
				 A.push(sum(B.top(),y,x));
				 B.pop();
				 B.push(a[i-1]);
				 i++;
			 }
			 else if(size(B.top())==6){
				 B.push(a[i-1]);
				 i++;
			 }
			 else if(size(B.top())==7){
				 double x=A.top();
				 A.pop();
				 double y=A.top();
				 A.pop();
				 A.push(sum(B.top(),y,x));
				 B.pop();
				 i++;
			 }
		 }
		 else{
			 A.push(a[i-1]-'0');
			 i++;
		 }
		}
		 if(i>=n+1){
			 if(size(B.top())!=6){
				 double x=A.top();
				 A.pop();
				 double y=A.top();
				 A.pop();
				 A.push(sum(B.top(),y,x));
				 B.pop();
			 }
			 else //消除括弧
				 B.pop();
		 }
		 
}while(B.top()!='#');
	cout<<"运算结果为"<<A.top()<<endl;
	system("pause");

}