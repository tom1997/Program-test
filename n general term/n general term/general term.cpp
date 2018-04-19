 //********************************  
//*** ���κ�һ��ʵ�������***  
//********************************  
#include <math.h>  
#include <malloc.h>  
#include <iostream>   
#include <iomanip>  
using namespace std;   
#define  N  10                //���巽���������Ϊ10  
//��������������  
float MatDet(float *p, int n);                    //����������ʽ  
float Creat_M(float *p, int m, int n, int k);    //�����Ԫ��A(m, n)�Ĵ�����֮ʽ  
void print(float *p, int n);                    //�������n*n  
bool Gauss(float A[][N], float B[][N], int n);    //���ò�����Ԫ�ĸ�˹��ȥ������A�������B  
int main()  
{  
    float *buffer, *p;            //���������׵�ַָ�����  
    int row, num;                //�������������;���Ԫ�ظ���  
    int i, j;  
    float determ;                //������������ʽ  
    float a[N][N], b[N][N];  
    int n;  
    cout << "���������Ķ��巨�����������!\n";  
    cout << "��������������: ";  
    cin >> row;  
    num = 2 * row * row;  
    buffer = (float *)calloc(num, sizeof(float));        //�����ڴ浥Ԫ  
    p = buffer;  
    if (NULL != p)  
    {  
        for (i = 0; i < row; i++)  
        {  
            cout << "Please input the number of " << i+1 << " row: ";  
            for (j = 0; j < row; j++)  
            {  
                cin >> *p++;  
            }  
        }  
    }  
    else  
    {  
        cout << "Can't distribute memory\n";  
    }  
    cout << "The original matrix : \n";  
    print(buffer, row);                //��ӡ�þ���  
      
    determ = MatDet(buffer, row);    //���������������ʽ  
    p = buffer + row * row;  
    if (determ != 0)  
    {  
        cout << "The determinant of the matrix is " << determ << endl;  
        for (i = 0; i < row; i++)    //�������  
        {  
            for (j = 0; j < row; j++)  
            {  
                *(p+j*row+i) = Creat_M(buffer, i, j, row)/determ;  
            }  
        }  
        cout << "The inverse matrix is: " << endl;  
        print(p, row);                //��ӡ�þ���  
    }   
    else  
    {  
        cout << "The determinant is 0, and there is no inverse matrix!\n";  
    }  
    free(buffer);        //�ͷ��ڴ�ռ�  
    cout << "���ò�����Ԫ�ĸ�˹��ȥ������������!\n";  
    cout << "�����뷽��Ľ���: ";  
    cin >> n;  
    cout << "������" << n << "�׷���: \n";  
    //����һ��n�׷���  
    for (i = 0; i < n; i++)  
    {  
        for (j = 0; j < n; j++)  
        {  
            cin >> a[i][j];  
        }  
    }  
    //���ø�˹��ȥ����þ������������  
    if (Gauss(a, b, n))  
    {  
        cout << "�÷���������Ϊ: \n";  
        for (i = 0; i < n; i++)  
        {  
            cout << setw(4);  
            for (j = 0; j < n; j++)  
            {  
                cout << b[i][j] << setw(10);  
            }  
            cout << endl;  
        }  
    }      
    getchar();  
    return 0;  
}  
//-----------------------------------------------  
//����: �����(n*n)������ʽ  
//��ڲ���: ������׵�ַ�����������  
//����ֵ: ���������ʽֵ  
//----------------------------------------------  
float MatDet(float *p, int n)  
{  
    int r, c, m;  
    int lop = 0;  
    float result = 0;  
    float mid = 1;  
    if (n != 1)  
    {  
        lop = (n == 2) ? 1 : n;            //�������ѭ������,��Ϊ2�ף���ѭ��1�Σ�����Ϊn��  
        for (m = 0; m < lop; m++)  
        {  
            mid = 1;            //˳�����, ���Խ���Ԫ�����֮��  
            for (r = 0, c = m; r < n; r++, c++)  
            {  
                mid = mid * (*(p+r*n+c%n));  
            }  
            result += mid;  
        }  
        for (m = 0; m < lop; m++)  
        {  
            mid = 1;            //�������, ��ȥ�ζԽ���Ԫ�س˻�  
            for (r = 0, c = n-1-m+n; r < n; r++, c--)  
            {  
                mid = mid * (*(p+r*n+c%n));  
            }  
            result -= mid;  
        }  
    }  
    else   
        result = *p;  
    return result;  
}  
//----------------------------------------------------------------------------  
//����: ��k*k������Ԫ��A(m, n)�Ĵ�����֮ʽ  
//��ڲ���: k*k������׵�ַ������Ԫ��A���±�m,n,��������k  
//����ֵ: k*k������Ԫ��A(m, n)�Ĵ�����֮ʽ  
//----------------------------------------------------------------------------  
float Creat_M(float *p, int m, int n, int k)  
{  
    int len;  
    int i, j;  
    float mid_result = 0;  
    int sign = 1;  
    float *p_creat, *p_mid;  
    len = (k-1)*(k-1);            //k�׾���Ĵ�����֮ʽΪk-1�׾���  
    p_creat = (float*)calloc(len, sizeof(float)); //�����ڴ浥Ԫ  
    p_mid = p_creat;  
    for (i = 0; i < k; i++)  
    {  
        for (j = 0; j < k; j++)  
        {  
            if (i != m && j != n) //������i�к͵�j���������Ԫ�ش洢����p_midΪ�׵�ַ���ڴ浥Ԫ  
            {  
                *p_mid++ = *(p+i*k+j);  
            }  
        }  
    }  
    sign = (m+n)%2 == 0 ? 1 : -1;    //������֮ʽǰ�����������  
    mid_result = (float)sign*MatDet(p_creat, k-1);  
    free(p_creat);  
    return mid_result;  
}  
//-----------------------------------------------------  
//����: ��ӡn*n����  
//��ڲ���: n*n������׵�ַ,���������n  
//����ֵ: �޷���ֵ  
//-----------------------------------------------------  
void print(float *p, int n)  
{  
    int i, j;  
    for (i = 0; i < n; i++)  
    {  
        cout << setw(4);  
        for (j = 0; j < n; j++)  
        {  
            cout << setiosflags(ios::right) << *p++ << setw(10);  
        }  
        cout << endl;  
    }  
}  
//------------------------------------------------------------------  
//����: ���ò�����Ԫ�ĸ�˹��ȥ������A�������B  
//��ڲ���: ���뷽��������󣬷������  
//����ֵ: true or false  
//-------------------------------------------------------------------  
bool Gauss(float A[][N], float B[][N], int n)  
{  
    int i, j, k;  
    float max, temp;  
    float t[N][N];                //��ʱ����  
    //��A����������ʱ����t[n][n]��  
    for (i = 0; i < n; i++)          
    {  
        for (j = 0; j < n; j++)  
        {  
            t[i][j] = A[i][j];  
        }  
    }  
    //��ʼ��B����Ϊ��λ��  
    for (i = 0; i < n; i++)          
    {  
        for (j = 0; j < n; j++)  
        {  
            B[i][j] = (i == j) ? (float)1 : 0;  
        }  
    }  
    for (i = 0; i < n; i++)  
    {  
        //Ѱ����Ԫ  
        max = t[i][i];  
        k = i;  
        for (j = i+1; j < n; j++)  
        {  
            if (fabs(t[j][i]) > fabs(max))  
            {  
                max = t[j][i];  
                k = j;  
            }  
        }  
        //�����Ԫ�����в��ǵ�i�У������н���  
        if (k != i)  
        {  
            for (j = 0; j < n; j++)  
            {  
                temp = t[i][j];  
                t[i][j] = t[k][j];  
                t[k][j] = temp;  
                //B���潻��  
                temp = B[i][j];  
                B[i][j] = B[k][j];  
                B[k][j] = temp;   
            }  
        }  
        //�ж���Ԫ�Ƿ�Ϊ0, ����, �����A�������Ⱦ���,�����������  
        if (t[i][i] == 0)  
        {  
            cout << "There is no inverse matrix!";  
            return false;  
        }  
        //��ȥA�ĵ�i�г�ȥi������ĸ���Ԫ��  
        temp = t[i][i];  
        for (j = 0; j < n; j++)  
        {  
            t[i][j] = t[i][j] / temp;        //���Խ����ϵ�Ԫ�ر�Ϊ1  
            B[i][j] = B[i][j] / temp;        //�������  
        }  
        for (j = 0; j < n; j++)        //��0��->��n��  
        {  
            if (j != i)                //���ǵ�i��  
            {  
                temp = t[j][i];  
                for (k = 0; k < n; k++)        //��j��Ԫ�� - i��Ԫ��*j��i��Ԫ��  
                {  
                    t[j][k] = t[j][k] - t[i][k]*temp;  
                    B[j][k] = B[j][k] - B[i][k]*temp;  
                }  
            }  
        }  
    }  
    getchar();  
    return true;  
}  