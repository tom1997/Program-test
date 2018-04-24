#ifndef SEQSTACK_waste_H
#define SEQSTACK_waste_H
const int QueueSize=100;
template<class T>
class CirQueue{
public:
	CirQueue(){front=rear=QueueSize-1;}
	~CirQueue(){};
	void EnQueue(T x);
	T DeQueue();
	T GetQueue();
	int Empty(){if(front==rear)return 1;
		else return 0;}
	template<class T>
	friend void Decimaltor(int num,int x);
private:
	T data[QueueSize];
	int front,rear;
};
template<class T>
void CirQueue<T>::EnQueue(T x){
	if((rear+1)%QueueSize==front) throw"иорГ";
	rear=(rear+1)%QueueSize;
	data[rear]=x;
};
template<class T>
T CirQueue<T>::DeQueue(){
	try{if(rear==front) throw"обрГ";}
	catch(char *str){
		cout<<str<<endl;
		return 0;
	}
	
	front=(front+1)%QueueSize;
	return data[front];
};
template<class T>
T CirQueue<T>::GetQueue(){
	try{if(rear==front) throw"обрГ";}
	catch(char *str){
		cout<<str<<endl;
		return -1;
	}
	int i=(front+1)%QueueSize;
	return data[i];
};
template<class T>
void Decimaltor(int num,int x){
		int top=-1;
		CirQueue<int>S;
		int k;
		while(num!=0){
			k=num%x;
			S.data[++top]=k;
			num=num/x;
		}
		while(top!=-1)
			cout<<S.data[top--];

	}


#endif