#include<iostream>
using namespace std;

class CMatrix
{
public:
 CMatrix(int,int);         
 bool initialize(int,int);  
 bool create();             
 void output();             
 CMatrix operator +(CMatrix &M2);  
 CMatrix operator -(CMatrix &M2);  
 CMatrix operator *(int &m);       
    CMatrix operator *(CMatrix &M2);
	friend ostream & operator<<(ostream &out,CMatrix &c);
private:
 int m_row;       
 int m_col;      
 double *m_pData;  
};
CMatrix::CMatrix(int r,int c)
{
  initialize(r,c); 
}
bool CMatrix::initialize(int r,int c)
{
   m_row=r;
   m_col=c;
   m_pData=new double[r*c];
   for(int i=0;i<m_row*m_col;i++)
   {
      m_pData[i]=1;
   }
   return true;
}
bool CMatrix::create()
{
  m_pData=new double[m_row*m_col];
  for(int i=0;i<m_row*m_col;i++)
  {
     cin>>m_pData[i];
  }
 return true;
}
void CMatrix::output()
{
   int j=0;
   for(int i=0;i<m_row*m_col;i++)
   {
      cout<<m_pData[i]<<" ";
   j++;
   if(j==m_col) {j=0;cout<<"\n";}
   }
}
CMatrix CMatrix::operator +(CMatrix &M2)
{  
   CMatrix M=*this;
   for(int i=0;i<m_row*m_col;i++)
     M.m_pData[i]=m_pData[i]+M2.m_pData[i];
   return M;
}
CMatrix CMatrix::operator -(CMatrix &M2)
{  
   CMatrix M=*this;
   for(int i=0;i<m_row*m_col;i++)
     M.m_pData[i]=m_pData[i]-M2.m_pData[i];
   return M;
}
CMatrix CMatrix::operator *(int m)
{
   CMatrix M=*this;
   for(int i=0;i<m_row*m_col;i++)
     M.m_pData[i]=m_pData[i]*m;
   return M;
}
CMatrix CMatrix::operator *(CMatrix &M2)
{
   CMatrix M=*this;
   int s=m_col;
   int a=0;
   for(int j=0;j<m_row;j++){
	    for(int i=0;i<m_col;i++){
      a+=m_pData[i]*M2.m_pData[i+s];
	  cout<<"a="<<a<<endl;}
	   m_pData[j]=a;
   a=0;
   }
   return M2;
 
}
ostream & operator<<(ostream &out,CMatrix &c){int j=0;
   for(int i=0;i<c.m_row*c.m_col;i++)
   {
      cout<<c.m_pData[i]<<" ";
   j++;
   if(j==c.m_col) {j=0;cout<<"\n";}
   }
   return out;
}

int main(){
	CMatrix A(3,3);
	A.initialize(3,3);
	A.output();
	CMatrix B(A);
	CMatrix C(1,1);
	C=A*B;
	cout<<C;
	getchar();
	getchar();
}