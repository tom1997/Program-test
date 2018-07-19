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
	cout<<"请输入您需要计算单词个数的文章："<<endl;
	getline(cin, a);
	cout<<"单词个数为："<<Counting(a)<<endl;
	system("pause");
    return 0;
}