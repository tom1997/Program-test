#ifndef LinkList_H
#define LinkList_H

template <class T>
struct Node
{
      T data1;
	  T data2;
      Node<T> *next;  
	  Node<T> *prior;  
};

template <class T>
class LinkList
{
public:
	LinkList( );                     //无参构造函数，建立只有头结点的空链表
	LinkList(T a[ ], T b[ ], int n);      //有参构造函数，建立有n个元素的单链表      
	~LinkList( );                    //析构函数
	int Locate(T x);           //按值查找。在单链表中查找值为x的元素序号
	void Insert(int i, T x);      //插入操作，第i个位置插入元素值为x的结点
	T Delete(int i);           //删除操作，在单链表中删除第i个结点
	void PrintList( );                 //遍历操作，按序号依次输出各元素
	void alge(float x);
	template <class T>
	friend LinkList add(LinkList<T> &a, LinkList<T> &b){
		Node<T> *q, *r;
		Node<T> *s;
		Node<T> *p;
		p=a.first->next;
		Node<T> *t;Node<T> *rp;
		LinkList c;
		c.first=new Node<T>;
		r=c.first;
		while(p!=a.first){
			t=new Node<T>;
			t->data1=p->data1;
			t->data2=p->data2;
			r->next=t;
			t->prior=r;
			p=p->next;
			r=r->next;
		}
		r->next=c.first;
		r->next=c.first;
		p=a.first->next;
		q=b.first->next;
		r=c.first->next;
		s=c.first->next;
		while(s->next!=c.first){
			s=s->next;
		}
		while(r!=c.first){
			while(q!=b.first){
				if(b.Locate(p->data2)!=0){
				if(r->data2==q->data2){
					if(p->data1==-(q->data1)){
						rp=r;
						r->prior->next=r->next;
						r->next->prior=r->prior;
						r=rp->prior;
						delete rp;
					}
					else if(p->data1!=-(q->data1)){
						r->data1+=q->data1;
					}
					break;
				}
				}
				else if(b.Locate(r->data2)==0){
					if(r->data2!=q->data2 && a.Locate(q->data2)==0){
						t=new Node<T>;
						t->data1=q->data1;
						t->data2=q->data2;
						t->next=s->next;
						s->next=t;
						t->prior=s;
						s=t;
						rp=q;
						q->prior->next=q->next;
						q->next->prior=q->prior;
						q=q->next;
						delete rp;
						break;
					}
				}
				else
					break;
				q=q->next;
			}
			q=b.first->next;
			p=p->next;
			r=r->next;
		}
		return c;
	}
private:
	Node<T> *first;                     //单链表的头指针
};


template <class T>
LinkList<T> :: LinkList( )
{
	first = new Node<T>;                        //生成头结点
	first->next = first;                      //头结点的指针域置空
}

template <class T>  
LinkList<T> :: LinkList(T a[ ], T b[ ], int n)
{
	Node<T> *r, *s;
	first = new Node<T>;                    //生成头结点
	r = first;                            //尾指针初始化
	for (int i = 0; i < n; i++)
	{ 
		s = new Node<T>; s->data1 = a[i]; s->data2=b[i];      //为每个数组元素建立一个结点
		r->next = s; s->prior=r;
		r = s;                 //将结点s插入到终端结点之后
		
	}
	r->next = first;        //单链表建立完毕，将终端结点的指针域置空
	first->prior=r;
}

template <class T>
LinkList<T> :: ~LinkList( )
{
	Node<T> *q;
	while (first != first)        //释放单链表的每一个结点的存储空间
	{
		q = first;                 //暂存被释放结点
		first = first->next;         // first指向被释放结点的下一个结点
		delete q;    
	}
}

template <class T>  
void LinkList<T> :: Insert(int i, T x)
{
	Node<T> *p = first->next, *s;
	int count = 0;               //工作指针p应指向头结点
    while (p != first && count < i - 1)  //查找第i - 1个结点
    {
		p = p->next;                   //工作指针p后移
		count++;
    }
    if (p == first) throw "位置";      //没有找到第i - 1个结点
    else {
		s = new Node<T>;  s->data1 = x;     //申请一个结点s，其数据域为x
		s->next = p->next; p->next = s;   //将结点s插入到结点p之后
    }
}

template <class T>  
T LinkList<T> :: Delete(int i)
{
	Node<T> *p, *q;
	T x;
	int count = 0; 
	p = first;               //注意工作指针p要指向头结点
	while (p != first && count < i - 1)  //查找第i-1个结点
	{
		p = p->next;
		count++;
	}
	if (p->next == first)  //结点p不存在或p的后继结点不存在
		throw "位置"; 
	else {
		q = p->next; x = q->data1;         //暂存被删结点
		p->next = q->next;              //摘链
		delete q; 
		return x;
	}
}

template <class T>  
int LinkList<T> :: Locate(T x) 
{
	Node<T> *p = first->next;
	int count = 1;         //工作指针p和累加器count初始化
	while (p != first)    
	{
		if (p->data2 == x) return count;     //查找成功，结束函数并返回序号
		p = p->next;                   
		count++;
	}
	return 0;                        //退出循环表明查找失败
}

template <class T>
void LinkList<T> :: PrintList( )
{
	Node<T> *p = first->next;                 //工作指针p初始化
	if(p->data2==0){
	cout << p->data1<<" ";
	}
	else
		cout << p->data1<<"x"<<"^"<<p->data2<<" ";
	p = p->next;
	while (p!= first)
	{
		if(p->data1>0.00001){
			if(p->data2==0){
				cout<<"+"<< p->data1<<" ";
			}
			else
				cout <<"+"<< p->data1<<"x"<<"^"<<p->data2<<" ";
		}
		else if (p->data1<0.00001){
			if(p->data2==0){
				cout << p->data1<<" ";
			}
			else
				cout << p->data1<<"x"<<"^"<<p->data2<<" ";
		}
		p = p->next;                 //工作指针p后移，注意不能写作p++
	}
	cout<<endl;
}
template <class T>
void LinkList<T> :: alge(float x){
	Node<T> *p = first->next;
	float y=0;
	float z;
	while (p->next!= first){

		if(p->data2==0){
			z=p->data1;
		}
		else
			z=pow(x,p->data2)*p->data1;
		y=y+z;
		p=p->next;
	}
	if(p->data2==0){
			z=p->data1;
		}
		else
			z=pow(x,p->data2)*p->data1;
		y=y+z;
		p=p->next;

	cout<<"当x="<<x<<"时，"<<"多项式为"<<y;
}


#endif

