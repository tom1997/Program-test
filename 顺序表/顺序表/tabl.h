#ifndef TABL_H
#define TABL_H

const int MaxSize=100;    //10只是示例性的数据，可以根据实际问题具体定义
class SeqList
{
public:
   SeqList( ){length=0;}       //无参构造函数，创建一个空表
   SeqList(int a[ ], int n);       //有参构造函数
   void Insert(int i, int x);   //在线性表中第i个位置插入值为x的元素
   int Delete(int i);        //删除线性表的第i个元素
   int Locate(int x);       //按值查找，求线性表中值为x的元素序号
   void PrintList( );      //遍历线性表，按序号依次输出各元素
   int Length( );      //求性线表的长度
   int Get(int i);       //按位查找，在线性表中查找第i个元素
   friend void add(SeqList &a,SeqList &b);
private:
   int data[MaxSize];      //存放数据元素的数组
   int length;            //线性表的长度
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
    }  
	 catch(char *str)  
    { 
		cout<<str<<endl;
		cout<<"It will be corrected for i=1"<<endl;
		system("pause");
		return Insert(1,x);
    }  
	for(int j=length;j>=i;j--){
	data[j]=data[j-1];
}
	data[i-1]=x;
	length++;
	
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
	for(int i=0;i<length;i++){
		cout<<data[i]<<"  ";
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
		 x = LB.Get(i);         	//在LB中取一元素
	      k = LA.Locate(x);         	//在LA中搜索它
	      if (k == 0)	                //若在LA中未找到插入它
	       { C.Insert(n1, x);  n1++; }		  //插入到第n个表项位置}
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
       x = C.Get(i);       //在C中取一元素
       k = LB.Locate(x);        //在LB中搜索它	
	   if (k == 0) 		      //若在LB中未找到
       { C.Delete(i);  n1--; }  //在C中删除它
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
    while (i < len_a&&i < len_b){  
        c.data[i] = (a.data[i] + b.data[i] + flag) % 10;  
        flag = (a.data[i] + b.data[i] + flag) / 10;  
        i++;  
    }
	    for (; i < len_a; i++){  
        c.data[i] = (a.data[i] + flag) % 10;  
        flag = (a.data[i] + flag) / 10;  
    }  
    for (; i < len_b; i++){  
        c.data[i] = (b.data[i] + flag) % 10;  
        flag = (b.data[i] + flag) / 10;  
    }  
    c.length = (len_b>len_a ? len_b : len_a) + flag;  
    if (flag == 1)  
        c.data[c.length] = 1;  
	c.PrintList();
}  

#endif TABLE_H