#ifndef TABLE_f_H
#define TABLE_f_H

const int MaxSize=10000;    //10ֻ��ʾ���Ե����ݣ����Ը���ʵ��������嶨��
class SeqList
{
public:
   SeqList( ){length=0;}       //�޲ι��캯��������һ���ձ�
   SeqList(int a[ ], int n);       //�вι��캯��
   void Insert(int i, int x);   //�����Ա��е�i��λ�ò���ֵΪx��Ԫ��
   int Delete(int i);        //ɾ�����Ա�ĵ�i��Ԫ��
   int Locate(int x);       //��ֵ���ң������Ա���ֵΪx��Ԫ�����
   void PrintList( );      //�������Ա���������������Ԫ��
   int Length( );      //�����߱�ĳ���
   int Get(int i);       //��λ���ң������Ա��в��ҵ�i��Ԫ��
   friend void add(SeqList &a, SeqList &b);
   friend void minus(SeqList &a, SeqList &b);
   friend void multiple (SeqList &a, SeqList &b);
private:
   int data[MaxSize];      //�������Ԫ�ص�����
   int length;            //���Ա�ĳ���
};
SeqList::SeqList(int a[ ], int n){
	try{
		if(n>MaxSize) throw "overflow";
	}
	catch(char *str){
	cout<<*str<<endl;
	}
	for(int i=0;i<n;i++){
		data[i]=a[i];
	}
	length=n;
};
void SeqList::Insert(int i, int x){
	length++;
	try  
    {   
    if(length>=MaxSize) throw length;
	if(i<1||i>length) throw"position error";
    }  
    catch(int)  
    {  
        cout<<"overflow"<<endl;
		system("pause");
		return Insert(MaxSize,x);
		length--;
    }  
	 catch(char *str)  
    { 
		cout<<str<<endl;
		cout<<"It will be corrected for i=1"<<endl;
		system("pause");
		return Insert(1,x);
		length--;
    }  
	for(int j=length;j>=i;j--){
	data[j]=data[j-1];
}
	data[i-1]=x;
	
	
}
int SeqList::Locate(int x){
	for(int i=0;i<length;i++){
		if(data[i]==x)
			return i+1;
	}
	return 0;
};
int SeqList::Get(int i){
	
	try  
    {   
    if(i<1||i>length) throw"fail to search the position";
    }  
    catch(char *str)  
    {  
        cout<<str<<endl;
		system("pause");
		return 0;
    }  

	return data[i-1];
}
void SeqList::PrintList( ){
	for(int i=length-1;i>=0;i--){
		cout<<data[i];
	}
}
int SeqList::Delete(int i){
	try  
    {   
    if(length==0) throw "underflow";
	if(i<1||i>length) throw "position warning";
    }  
    catch(char *str)  
    {  
        cout<<str<<endl;
		cout<<"It will be corrected for i=1"<<endl;
		system("pause");
		return 0;
    }  

	int x=data[i-1];
	for(int j=i;j<length;j++){
		data[j-1]=data[j];
		}
		length--;
		return x;
	

};
int SeqList::Length( ){
	return length;
};

void Union ( SeqList & LA,  SeqList &LB ) {
     int n1 = LA.Length(), n2 = LB.Length();
     int i, k, x;
	 SeqList C(LA);
     for ( i = 1; i < n2+1; i++ ) {
		 x = LB.Get(i);         	//��LB��ȡһԪ��
	      k = LA.Locate(x);         	//��LA��������
	      if (k == 0)	                //����LA��δ�ҵ�������
	       { C.Insert(n1, x);  n1++; }		  //���뵽��n������λ��}
 }
	 cout<<"Their union set are ";	 
	 if(C.Length()==0)
		 cout<<"null"<<endl;
	 else C.PrintList();
	 cout<<endl;
}
void Intersection (SeqList & LA,    SeqList & LB ) {
	 SeqList C(LA);
     int n1 = C.Length();
     int x, k=0;
	 int i=1;
     while ( i < n1 +1) {
       x = C.Get(i);       //��C��ȡһԪ��
       k = LB.Locate(x);        //��LB��������	
	   if (k == 0) 		      //����LB��δ�ҵ�
       { C.Delete(i);  n1--; }  //��C��ɾ����
	   else i++;
     }
	 cout<<"Their intersection set are ";
	 if(C.Length()==0)
		 cout<<"null"<<endl;
	 else C.PrintList();
	 cout<<endl;
 }
void add(SeqList &a, SeqList &b){  
	SeqList c;
    int flag = 0;  
    int len_a = a.Length();  
    int len_b = b.Length();  
    int i = 0;  

	cout<<endl;


    while (i<len_a&&i<len_b)  
    {  
        c.data[i] = (a.data[i] + b.data[i] + flag) % 10;  
        flag = (a.data[i] + b.data[i] + flag) / 10;  
        i++;  
    }  
    for (; i < len_a; i++)  
    {  
        c.data[i] = (a.data[i] + flag) % 10;  
        flag = (a.data[i] + flag) / 10;  
    }  
    for (; i < len_b; i++)  
    {  
        c.data[i] = (b.data[i] + flag) % 10;  
        flag = (b.data[i] + flag) / 10;  
    }  
    c.length = max(len_a, len_b) + flag;  
    if (flag == 1)  
        c.data[c.length - 1] = 1;  
    c.PrintList();  
}  
void minus(SeqList &a, SeqList &b){  
	SeqList c;
    int flag = 0;  
    int len_a = a.Length();  
    int len_b = b.Length();  
    int i = 0;  
	cout<<endl;

    while (i<len_a&&i<len_b)  
    {  
		if(len_a>len_b){
        c.data[i] = (a.data[i] - b.data[i] - flag);  
		if(c.data[i]<0){
			c.data[i]=(10+c.data[i]);
			flag=1;
		}
		else
			flag=0;
        i++; 
		}
		else if (len_a<len_b){
			c.data[i] = (b.data[i] - a.data[i] - flag);  
		if(c.data[i]<0){
			c.data[i]=(10+c.data[i]);
			flag=1;
		}
		else
			flag=0;
        i++; 

    }  
		else if(len_a=len_b){
			if(a.data[len_a-1]>b.data[len_b-1])
			{
				c.data[i] = (a.data[i] - b.data[i] - flag);  
				if(c.data[i]<0){
					c.data[i]=(10+c.data[i]);
					flag=1;
		}
		else 
			flag=0;
        i++; 

			}
			else{
			c.data[i] = (b.data[i] - a.data[i] - flag);  
				if(c.data[i]<0){
					c.data[i]=(10+c.data[i]);
					flag=1;
		}
		else 
			flag=0;
        i++; }

		}

	}
   for (; i < len_a; i++)  
    {  
        c.data[i] = (a.data[i] - flag) % 10;  
        flag = (a.data[i] - flag) / 10;  
    }  
    for (; i < len_b; i++)  
    {  
        c.data[i] = (b.data[i] - flag) % 10;  
        flag = (b.data[i] - flag) / 10;  
    }  
    c.length = max(len_a, len_b);  
    if (flag == 1)  
        c.data[c.length - 1] = 1;  
    c.PrintList();  
}  
void multiple(SeqList &a, SeqList &b){
	SeqList c;
	int len_a = a.Length();  
    int len_b = b.Length();  
	int *d=new int [len_a+len_b-1];
	int flag=0;
	c.length = len_a+len_b;
	c.data[len_a+len_b-1]=0;
	for(int i=0;i<len_a+len_b-1;i++){
		c.data[i]=0;
	}
	for(int i=0;i<len_a;i++){
			for(int j=0;j<len_b;j++){
				c.data[i+j]=((a.data[i]*b.data[j])+flag)%10;
				
				d[len_a+len_b-i-j-1]=((a.data[i]*b.data[j])+flag)%10;
				flag=(a.data[i]*b.data[j])/10;
				cout<<d[len_a+len_b-i-j-1]<<" ";
			   //c.PrintList();
			}

			cout<<endl;

	}
	cout<<endl;
	c.PrintList();
}
  
#endif