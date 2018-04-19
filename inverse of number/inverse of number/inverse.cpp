 #include<iostream>
using namespace std;
int main (){
	cout<<"please input a double bit integer." <<endl;
	int x;
	int   y;
	int   z;
	cin>>x;
	if(x>10&&x<99){
	y=x/10;
	z=x-(10*y);
	cout<<(10*z)+y<<endl;
	getchar();
	getchar();
	}
	else
		cout<<"wrong number"<<endl;


}