#ifndef LinkQueue_c_H
#define LinkQueue_c_H
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
private:
	T data[QueueSize];
	int front,rear;
	int flag;
};
template<class T>
void CirQueue<T>::EnQueue(T x){
	if(front==rear && flag==1) throw"иорГ";
	flag=1;
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
	flag=0;
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

#endif