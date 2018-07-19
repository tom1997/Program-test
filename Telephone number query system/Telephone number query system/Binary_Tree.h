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
	cout<<"����������"<<endl;
	cin>>name;
	cout<<"������̶��绰����"<<endl;
	cin>>phone;
	cout<<"�������ƶ��绰����"<<endl;
	cin>>mobile;
	cout<<"�������������"<<endl;
	cin>>email;
	s=j++;
}
void TeleNumber::display(){
	cout<<"������"<<name<<'\t'<<"�̶����룺"<<phone<<'\t'<<"�ƶ��绰����:"<<mobile<<'\t'<<"�������䣺"<<email<<endl;
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
		cout<<"�绰ϵͳ��û���κκ���"<<endl;
	else{
		while(!in.eof()){
			end->ReadFile(in);
			if(end->name.data()[0]=='\0')
				break;
			end->next=new TeleNumber;
			end=end->next;
		}
		in.close();
		cout<<"��ȡ�绰����ϵͳ�ɹ�"<<endl;
	}
	cout<<"����������ĸ����"<<endl;
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
	cout<<"����ɹ�"<<endl;
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
	cout<<endl<<"����ɹ�"<<endl;
}
void TeleMessage::Remove(){
	string name;
	TeleNumber *p=new TeleNumber,
	*temp=NULL;
	cout<<"������Ҫɾ���˵�����:"<<endl;
	cin>>name;
	char *x=(char *)name.data();
	p->next=Search(x);
	if(Search(x)){
		temp=p->next;
		delete temp;
		cout<<"ɾ���ɹ���"<<endl;
	}
	else{
		cout<<"û���ҵ�"<<endl;
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
			cout<<"���޴���"<<endl;
		}
		return 0;
	}
}
void TeleMessage::Change(){
	string name;
	cout<<"������Ҫ�޸ĵ��˵�����";
	cin>>name;
	if(Search((char*)name.data())){
		cout<<"���ҵ����˵���Ϣ���������µ���Ϣ��"<<endl;
		Search((char*)name.data())->input();
		cout<<"�޸ĳɹ���"<<endl;
	}
	else{
		cout<<"û���ҵ�"<<endl;
	}
}
void TeleMessage::Show(){
	for(TeleNumber *p=head->next;p!=end;p=p->next){
		p->display();
	}
}