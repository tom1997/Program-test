#ifndef SEQSTACK_H
#define SEQSTACK_H
template<class T>
struct Node{
	T data;
	Node<T> *next;
};
template<class T>
class LinkStack{
public:
	LinkStack(){top=NULL;}
	~LinkStack(){
		Node<T> *p;
		p=top;
		while(top!=NULL){
			top=p->next;
			delete p;
			p=top;
		}
	};
	void Push (T x);
	T Pop();
	T GetTop(){if(top!=NULL) return top->data;
	else return -1;}
	int Empty(){if(top!=NULL)
	return 0;
	else return 1;}
private:
	Node<T> *top;
};
template<class T>
void LinkStack<T>::Push (T x){
	Node<T> *s;
	s=new Node<T>;s->data=x;
	if(top==NULL){
		top=s;
		top->next=s;
	}
	else{
	s->next=top->next;
	top->next=s;
	top=s;
	}
};
template<class T>
T LinkStack<T>::Pop (){
	try{
		if(top==NULL) throw "����";
	}
	catch(char *str){
		cout<<str<<endl;
		return 0;
		}
	Node<T> *p;
	p=top->next;
	if(p==top)top==NULL;
	else top->next=p->next;
	delete p;
}

#endif