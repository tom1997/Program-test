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
	LinkList( );                     //�޲ι��캯��������ֻ��ͷ���Ŀ�����
	LinkList(T a[ ], T b[ ], int n);      //�вι��캯����������n��Ԫ�صĵ�����      
	~LinkList( );                    //��������
	int Locate(T x);           //��ֵ���ҡ��ڵ������в���ֵΪx��Ԫ�����
	void Insert(int i, T x);      //�����������i��λ�ò���Ԫ��ֵΪx�Ľ��
	T Delete(int i);           //ɾ���������ڵ�������ɾ����i�����
	void PrintList( );                 //������������������������Ԫ��
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
	Node<T> *first;                     //�������ͷָ��
};


template <class T>
LinkList<T> :: LinkList( )
{
	first = new Node<T>;                        //����ͷ���
	first->next = first;                      //ͷ����ָ�����ÿ�
}

template <class T>  
LinkList<T> :: LinkList(T a[ ], T b[ ], int n)
{
	Node<T> *r, *s;
	first = new Node<T>;                    //����ͷ���
	r = first;                            //βָ���ʼ��
	for (int i = 0; i < n; i++)
	{ 
		s = new Node<T>; s->data1 = a[i]; s->data2=b[i];      //Ϊÿ������Ԫ�ؽ���һ�����
		r->next = s; s->prior=r;
		r = s;                 //�����s���뵽�ն˽��֮��
		
	}
	r->next = first;        //����������ϣ����ն˽���ָ�����ÿ�
	first->prior=r;
}

template <class T>
LinkList<T> :: ~LinkList( )
{
	Node<T> *q;
	while (first != first)        //�ͷŵ������ÿһ�����Ĵ洢�ռ�
	{
		q = first;                 //�ݴ汻�ͷŽ��
		first = first->next;         // firstָ���ͷŽ�����һ�����
		delete q;    
	}
}

template <class T>  
void LinkList<T> :: Insert(int i, T x)
{
	Node<T> *p = first->next, *s;
	int count = 0;               //����ָ��pӦָ��ͷ���
    while (p != first && count < i - 1)  //���ҵ�i - 1�����
    {
		p = p->next;                   //����ָ��p����
		count++;
    }
    if (p == first) throw "λ��";      //û���ҵ���i - 1�����
    else {
		s = new Node<T>;  s->data1 = x;     //����һ�����s����������Ϊx
		s->next = p->next; p->next = s;   //�����s���뵽���p֮��
    }
}

template <class T>  
T LinkList<T> :: Delete(int i)
{
	Node<T> *p, *q;
	T x;
	int count = 0; 
	p = first;               //ע�⹤��ָ��pҪָ��ͷ���
	while (p != first && count < i - 1)  //���ҵ�i-1�����
	{
		p = p->next;
		count++;
	}
	if (p->next == first)  //���p�����ڻ�p�ĺ�̽�㲻����
		throw "λ��"; 
	else {
		q = p->next; x = q->data1;         //�ݴ汻ɾ���
		p->next = q->next;              //ժ��
		delete q; 
		return x;
	}
}

template <class T>  
int LinkList<T> :: Locate(T x) 
{
	Node<T> *p = first->next;
	int count = 1;         //����ָ��p���ۼ���count��ʼ��
	while (p != first)    
	{
		if (p->data2 == x) return count;     //���ҳɹ��������������������
		p = p->next;                   
		count++;
	}
	return 0;                        //�˳�ѭ����������ʧ��
}

template <class T>
void LinkList<T> :: PrintList( )
{
	Node<T> *p = first->next;                 //����ָ��p��ʼ��
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
		p = p->next;                 //����ָ��p���ƣ�ע�ⲻ��д��p++
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

	cout<<"��x="<<x<<"ʱ��"<<"����ʽΪ"<<y;
}


#endif

