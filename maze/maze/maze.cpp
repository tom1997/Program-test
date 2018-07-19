#include<iostream>
#include<stack>
#include <windows.h>
#include<stdio.h>

using namespace std;
int main(){
	cout<<"此为迷宫"<<endl;
	int a[][15]={
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,2,0,0,1,0,1,1,0,0,0,1,0,1,1},
		{1,0,1,1,0,1,0,0,0,1,0,0,1,1,1},
		{1,0,1,1,0,1,1,0,1,0,1,1,0,1,1},
		{1,1,0,0,0,0,1,1,0,1,0,1,0,0,1},
		{1,0,1,1,0,1,0,1,1,1,0,1,1,0,1},
		{1,0,1,1,0,1,1,0,0,1,0,1,0,0,1},
		{1,0,1,0,0,1,1,1,0,1,1,0,1,3,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},

	};
	int b[][15]={
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,2,0,0,1,0,1,1,0,0,0,1,0,1,1},
		{1,0,1,1,0,1,0,0,0,1,0,0,1,1,1},
		{1,0,1,1,0,1,1,0,1,0,1,1,0,1,1},
		{1,1,0,0,0,0,1,1,0,1,0,1,0,0,1},
		{1,0,1,1,0,1,0,1,1,1,0,1,1,0,1},
		{1,0,1,1,0,1,1,0,0,1,0,1,0,0,1},
		{1,0,1,0,0,1,1,1,0,1,1,0,1,3,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},

	};
	stack<int> A;
	A.push(0);
	int x1,y1,x2,y2;
	for(int i=0;i<9;i++){
		for(int j=0;j<15;j++){
			if(a[i][j]==1){
				cout<<" + ";
			}
			else if(a[i][j]==2){
				x1=j,y1=i;
				cout<<" I ";
			}
			else if(a[i][j]==3){
				x2=j;y2=i;
				cout<<" U ";
			}
			else
				cout<<"   ";
		}
		cout<<endl<<endl;
	}
	int j=x1;
	int i=y1;
	int i1;
	int j1;
	cout<<"以下演示迷宫算法的历程。"<<endl;
	system("pause");
	system("cls");
	while(j!=x2 || i!=y2){
		if(a[i1=i+1][j]!=1){
			A.push(1);	
			i++;
			a[i][j]=1;
			b[i][j]=4;
		} //下
		else if(a[i1=i+1][j1=j+1]!=1){
			A.push(2);
			i++;
			j++;
			a[i][j]=1;
			b[i][j]=4;
		} //右下
		else if(a[i1=i-1][j1=j+1]!=1){
			A.push(3);
			i--;
			j++;
			a[i][j]=1;
			b[i][j]=4;
		} //右上
		else if(a[i1=i-1][j]!=1){
			A.push(4);
			i--;
			a[i][j]=1;
			b[i][j]=4;
		} //上
		else if(a[i1=i-1][j1=j-1]!=1){
			A.push(5);
			i--;
			j--;
			a[i][j]=1;
			b[i][j]=4;
		} //左上
		else if(a[i1=i+1][j1=j-1]!=1){
			i++;
			j--;
			A.push(6);
			a[i][j]=1;
			b[i][j]=4;
		} //左下	
		else if(a[i][j1=j-1]!=1){
			j--;
			A.push(7);
			a[i][j]=1;
			b[i][j]=4;
		} //左	
		else if(a[i][j1=j+1]!=1){
			j++;
			A.push(8);
			a[i][j]=1;
			b[i][j]=4;
		} //右
		else{
			if(A.top()==1){
				b[i][j]=0;
				a[--i][j];
				
			}
			else if(A.top()==2){
				b[i][j]=0;
				a[--i][--j];
				
			}
			else if(A.top()==3){
				b[i][j]=0;
				a[++i][--j];
				
			}
			else if(A.top()==4){
				b[i][j]=0;
				a[++i][j];
				
			}
			else if(A.top()==5){
				b[i][j]=0;
				a[++i][++j];
				
			}
			else if(A.top()==6){
				b[i][j]=0;
				a[--i][++j];

			}
			else if(A.top()==7){
				b[i][j]=0;
				a[i][++j];
			}
			else if(A.top()==8){
				
				b[i][j]=0;
				a[i][--j];
			}
			else {
				cout<<"无路可走"<<endl;
				break;
			}
			A.pop();
			
			
		}
		for(int i=0;i<9;i++){
			for(int j=0;j<15;j++){
				if(b[i][j]==1){
					cout<<" + ";
				}
				else if(b[i][j]==2){
					cout<<" I ";
				}
				else if(a[i][j]==3){
					cout<<" U ";
				}
				else if(b[i][j]==4){
					cout<<" & ";
				}
				else
					cout<<"   ";
			}
			cout<<endl<<endl;
		}
			Sleep(250);
			system("cls");
	
	}
	if(j==x2 && i==y2){
		cout<<"迷宫解为："<<endl;
		for(int i=0;i<9;i++){
			for(int j=0;j<15;j++){

				if(b[i][j]==1){
					cout<<" + ";
				}
				else if(b[i][j]==2){
					cout<<" I ";
				}
				else if(a[i][j]==3){
					cout<<" U ";
				}
				else if(b[i][j]==4){
					cout<<" & ";
				}
				else
					cout<<"   ";
			}
			cout<<endl<<endl;
		}
	}

	system("pause");
	
}