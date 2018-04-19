#ifndef LinkList_j_H
#define LinkList_j_H

template <class DataType>
struct Node
{
      DataType data;
      Node<DataType> *next;  
};

template <class DataType>
class LinkList
{
public:
	LinkList( );                     //�޲ι��캯��������ֻ��ͷ���Ŀ�����
	LinkList(int n1);      //�вι��캯����������n��Ԫ�صĵ�����
	~LinkList( );                    //��������
	int Locate(DataType x);           //��ֵ���ҡ��ڵ������в���ֵΪx��Ԫ�����
	void Insert(int i, DataType x);      //�����������i��λ�ò���Ԫ��ֵΪx�Ľ��
	DataType Delete(int i);           //ɾ���������ڵ�������ɾ����i�����
	void PrintList( );                 //������������������������Ԫ��
	int Joseph(int m);
private:
	Node<DataType> *first;                     //�������ͷָ��
	int n;
};

template <class DataType>
LinkList<DataType> :: LinkList( )
{
	first = new Node<DataType>;                        //����ͷ���
	first->next = first;                      //ͷ����ָ�����ÿ�
}

template <class DataType>  
LinkList<DataType> :: LinkList(int n1)
{
	Node<DataType> *r, *s;
	n=n1;
	first = new Node<DataType>;                    //����ͷ���
	r = first;                            //βָ���ʼ��
	first->data=1;
	for (int i = 1; i < n; i++)
	{ 
		s = new Node<DataType>; s->data = i+1;        //Ϊÿ������Ԫ�ؽ���һ�����
		r->next = s; r = s;                 //�����s���뵽�ն˽��֮��
	}
	r->next = first;        //����������ϣ����ն˽���ָ�����ÿ�
}

template <class DataType>
LinkList<DataType> :: ~LinkList( )
{
	Node<DataType> *q;
	while (first != first)        //�ͷŵ������ÿһ�����Ĵ洢�ռ�
	{
		q = first;                 //�ݴ汻�ͷŽ��
		first = first->next;         // firstָ���ͷŽ�����һ�����
		delete q;    
	}
}

template <class DataType>  
void LinkList<DataType> :: Insert(int i, DataType x)
{
	if(i<=0) throw "̫ǰ";
	Node<DataType> *p = first, *s;
	int count = 1;               //����ָ��pӦָ��ͷ���
	if(i==1){
		s=first;
		p=first;
			while(p->next!=first){
					p=p->next;		
		}
		first = new Node<DataType>;  first->data = x;     //����һ�����s����������Ϊx
		first->next=s;   //�����s���뵽���p֮��
		p->next=first;

	}
	else {
    while (p->next!=first&&count < i-1)  //���ҵ�i - 1�����
    {
		p = p->next;                   //����ָ��p����
		count++;
    }
	s = new Node<DataType>;  s->data = x;     //����һ�����s����������Ϊx
		s->next = p->next; p->next = s;   //�����s���뵽���p֮��
}

}
template <class DataType>  
DataType LinkList<DataType> :: Delete(int i)
{
	if(i<=0) throw "̫ǰ";

	Node<DataType> *p, *q;
	DataType x;
	int count = 0; 
	p = first;
	q=p;
	if(i==1){
		while(p->next!=first){
					p=p->next;		
		}
		first=first->next;
		q->next=first;
		x=q->data;
		p->next=first;
		delete q; 
		return x;
		
	}
			

	else{
	p = first;               //ע�⹤��ָ��pҪָ��ͷ���
	
	while (p->next!= first && count < i - 2)  //���ҵ�i-1�����
	{
		p = p->next;
		count++;
	}
	if (p->next == first)  //���p�����ڻ�p�ĺ�̽�㲻����
		throw "λ��"; 
	else {
		q = p->next; x = q->data;         //�ݴ汻ɾ���
		p->next = q->next;              //ժ��
		delete q; 
		
		return x;
	}
}
}

template <class DataType>  
int LinkList<DataType> :: Locate(DataType x) 
{
	Node<DataType> *p = first;
	int count = 2;         //����ָ��p���ۼ���count��ʼ��
	if (p->data == x) return count;
	p = p->next;  
	while (p != first)    
	{
		if (p->data == x) return count;     //���ҳɹ��������������������
		p = p->next;                   
		count++;
	}
	return 0;                        //�˳�ѭ����������ʧ��
}

template <class DataType>
void LinkList<DataType> :: PrintList()
{
	Node<DataType> *p = first;                 //����ָ��p��ʼ��
	cout << p->data<<"  ";
	p = p->next; 
	while (p != first)
	{
		cout << p->data<<"  ";
		p = p->next;                 //����ָ��p���ƣ�ע�ⲻ��д��p++
	}
	cout<<endl;
}
template <class DataType>
int LinkList<DataType> :: Joseph(int m){
	Node<DataType> *p = first;                 //����ָ��p��ʼ��
	Node<DataType> *q ;    
	int count=1;
	while(p->next!=p){
		q=p;
		p=p->next;
		count++;
		if(count%m==0){
			q->next=p->next;
			delete p;
			p=q;
		}
/*		if(count>=n-1) //�Ǳ�Ҫ��������
			count=1;*/
	}
	return p->data;
}

#endif