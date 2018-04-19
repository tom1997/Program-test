#include <iostream>
#include <string>
using namespace std;
class teacher{
public:
	teacher(string tname,int tage,string ttitle){
		name1=tname;
		age1=tage;
		title1=ttitle;
		}
	string getname(){
	return name1;}
	int getage(){
		return age1;}
	string gettitle(){
		return title1;}
private:
	string name1;
	int age1;
	string title1;
};
class student{
public:
	student(string sname,int sage,int sscore){
	name1=sname;
	age1=sage;
	score1=sscore;}
	string getname(){
	return name1;}
	int getage(){
	return age1;}
	int getscore(){
	return score1;}
private:
string name1;
int age1;
int score1;
};
class graduate:public student,public teacher{
public:
	graduate(string name,int age,int score,string title,int wage):student(name,age,score),teacher(name,age,title),member1(name,age,score),member2(name,age,title){
		this->wage=wage;
	};
	void display(){cout<<member1.getname()<<" "<<member1.getage()<<" "<<member1.getscore()<<" "<<member2.gettitle()<<" "<<wage;}
private:
	int wage;
	student member1;
	teacher member2;
};
int main(){
	graduate zhang("zhang",35,100,"professer",5000);
	zhang.display();
	getchar();

}