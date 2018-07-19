#include <iostream>  
using namespace std;  
const int max=10;
int x=0;
char a;
int j=1;
struct TeleNumber{
	string name;
	string phone;
	string mobile;
	string email;
	int s;
	TeleNumber *next;
	void ReadFile(istream &in);
	void input();
	void display();

};
void TeleNumber::ReadFile(istream &in){
	in>>name>>phone>>mobile>>email;
}
void TeleNumber::input(){
	cout<<"请输入姓名"<<endl;
	cin>>name;
	cout<<"请输入固定电话号码"<<endl;
	cin>>phone;
	cout<<"请输入移动电话号码"<<endl;
	cin>>mobile;
	cout<<"请输入电子邮箱"<<endl;
	cin>>email;
	s=j++;
}
void TeleNumber::display(){
	cout<<"姓名："<<name<<'\t'<<"固定号码："<<phone<<'\t'<<"移动电话号码:"<<mobile<<'\t'<<"电子邮箱："<<email<<endl;
}

class TeleMessage{
public:
	TeleMessage();
	~TeleMessage();
	void Save();
	TeleNumber *Search(char*);
	void Sort();
	void Insert();
	void Remove();
	void Change();
	void Show();
	void Swap(TeleNumber *,TeleNumber *);
private:
	TeleNumber *end,*head;
	ifstream in;
	ofstream out;
};
TeleMessage::TeleMessage(){
	head=new TeleNumber;
	head->next=new TeleNumber;
	end=head->next;
	in.open("TeleNumber.txt");
	if(!in)
		cout<<"电话系统中没有任何号码"<<endl;
	else{
		while(!in.eof()){
			end->ReadFile(in);
			if(end->name.data()[0]=='\0')
				break;
			end->next=new TeleNumber;
			end=end->next;
		}
		in.close();
		cout<<"读取电话号码系统成功"<<endl;
	}
	cout<<"输入任意字母继续"<<endl;
	cin>>a;
}
TeleMessage::~TeleMessage(){
	TeleNumber *temp;
	while(head->next!= end){
		temp=head->next;
		head=head->next;
		delete temp;
	}
	delete head,end;
}
void TeleMessage::Save(){
	out.open("TeleNumber.txt");
	TeleNumber *p=head->next;
	while(p!=end){
		out<<p->name<<"\t"<<p->phone<<"\t"<<p->mobile<<"\t"<<p->email<<endl;
		p=p->next;
	}
	
	out.close();
	cout<<"保存成功"<<endl;
}
void TeleMessage::Swap(TeleNumber *p1,TeleNumber *p2){
	TeleNumber *temp=new TeleNumber;
//	strcpy(temp->name,p1->name);
	temp->name=p1->name;
	//strcpy(temp->email,p1->email);
	temp->email=p1->email;
	temp->mobile=p1->mobile;
	temp->phone=p1->phone;
	temp->s=p1->s;
	//strcqy(p2->name,temp->name);
	temp->name=p2->name;
	//strcpy(p2->name,temp->email);
	temp->email=p2->email;
	p2->mobile=temp->mobile;
	p2->phone=temp->phone;
	p2->s=temp->s;
}
void TeleMessage::Sort(){
	TeleNumber *p=NULL,*q=NULL;
	int exchange=j-1;
	int i,bound;
	while(exchange){
		bound =exchange;
		exchange=0;
		for(p=head->next,i=1;i<bound;i++,p=p->next)
			if(p->mobile>p->next->mobile){
				swap(p,p->next);
				exchange=p->s;
			}
	}
	Show();
}
void TeleMessage::Insert(){
	end->input();
	end->next=new TeleNumber;
	end=end->next;
	cout<<endl<<"插入成功"<<endl;
}
void TeleMessage::Remove(){
	string name;
	TeleNumber *p=new TeleNumber,
	*temp=NULL;
	cout<<"请输入要删除人的姓名:"<<endl;
	cin>>name;
	char *x=(char *)name.data();
	p->next=Search(x);
	if(Search(x)){
		temp=p->next;
		delete temp;
		cout<<"删除成功！"<<endl;
	}
	else{
		cout<<"没有找到"<<endl;
	}

}
TeleNumber *TeleMessage::Search(char *name){
	for(TeleNumber *p=head->next;p!=end;p=p->next){
		if(!strcmp((const char *)p->name.data(),(const char*)name)){
			if(x==4){
				p->display();
				return p;
			}
			else
				return p;
		}
		if(x==4){
			cout<<"查无此人"<<endl;
		}
		return 0;
	}
}
void TeleMessage::Change(){
	string name;
	cout<<"请输入要修改的人的姓名";
	cin>>name;
	if(Search((char*)name.data())){
		cout<<"已找到个人的信息，请输入新的信息！"<<endl;
		Search((char*)name.data())->input();
		cout<<"修改成功！"<<endl;
	}
	else{
		cout<<"没有找到"<<endl;
	}
}
void TeleMessage::Show(){
	for(TeleNumber *p=head->next;p!=end;p=p->next){
		p->display();
	}
}