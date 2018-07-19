#include<iostream>
#include <string>
#include<fstream>
#include "Binary_Tree.h"
using namespace std;

int main(){
	bool flag=true;
	TeleMessage tele;
	string name;
	while(flag){
		system("cls");
		cout<<"简单个人电话号码查询系统"<<endl;
		cout<<"1.增加电话号码"<<endl;
		cout<<"2.显示电话号码"<<endl;
		cout<<"3.排序个人电话"<<endl;
		cout<<"4.查找个人电话"<<endl;
		cout<<"5.删除个人信息"<<endl;
		cout<<"6.修改个人信息"<<endl;
		cout<<"7.保存个人信息"<<endl;
		cout<<"请选择：";
		cin>>x;
		switch(x){
		case 0:
			flag=false;
			break;
		case 1:
			tele.Insert();
			break;
		case 2:
			tele.Show();
			break;
		case 3:
			tele.Sort();
			break;
		case 4:
			cout<<"请输入欲查找认得姓名"<<endl;
			cin>>name;
			tele.Search((char*) name.data());
			break;
		case 5:
			tele.Remove();
			break;
		case 6:
			tele.Change();
			break;
		case 7:
			tele.Save();
			break;
		default:
			cout<<"请输入正确号码"<<endl;
			break;
		}
		

		cout<<"请输入任意字母返回"<<endl;
		cin>>a;
	}
	return 0;
}