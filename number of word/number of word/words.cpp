#include <iostream>
#include<string>
using namespace std;
int count=0;
int Counting(string str)
{
	const char* p = str.data();
    int i=0;
    count=0;
	int state=1;
	while (p[i]!='!')
	{
		if(p[i]!=' ')
		  {
		  state =1;
		  }
		else 
		 {  
		    if(state==1){
		 	state=0;
		 	count++;
		 }
		 }
		 i++;
	}
	return count;
}

int main()
{   
    string a;
	cout<<"����������Ҫ���㵥�ʸ��������£�"<<endl;
	getline(cin, a);
	cout<<"���ʸ���Ϊ��"<<Counting(a)<<endl;
	system("pause");
    return 0;
}