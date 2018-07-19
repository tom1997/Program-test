#include<iostream>
using namespace std;
 
#define MAXN 100		//����������ֵ
#define MAXM 200		//���������ֵ
 
struct ArcNode
{
	int to, dur, no;	//�ߵ���һ�����㡢����ʱ�䡢����
	ArcNode *next;
};
int n, m;				//�������������
ArcNode *List1[MAXN];	//ÿ������ı������ͷָ�루���߱�
ArcNode *List2[MAXM];	//ÿ������ı������ͷָ�루��߱�
int count1[MAXN];		//����������
int count2[MAXM];		//������ĳ���
int Ee[MAXN];			//���¼���������ܿ�ʼʱ��
int El[MAXN];			//���¼����������ʼʱ��
int e[MAXM];			//�����������ܿ�ʼʱ��
int L[MAXM];			//������������ʼʱ��
void CriticalPath()		//��ؼ�·��
{
	//����������Ee
	int i, j, k;
	int top1 = -1;
	ArcNode *temp1;
	memset(Ee, 0, sizeof(Ee));
	for(i = 0; i < n; i++)
		if(count1[i] == 0) { count1[i] = top1; top1 = i; }
	for(i = 0; i < n; i++)
	{
		if(top1 == -1) { printf("Network has a cycle!\n"); return; }
		else 
		{
			j = top1; top1 = count1[top1];
			temp1 = List1[j];
			while(temp1 != NULL)
			{
				k = temp1->to;
				if(--count1[k] == 0) { count1[k] = top1; top1 = k; }
				if(Ee[j]+temp1->dur > Ee[k]) Ee[k] = Ee[j] + temp1->dur;//�����<j, k>
				temp1 = temp1->next;
			}
		}
	}
	//������������El
	int top2 = -1;
	ArcNode *temp2;
	for(i = 0; i < n; i++)
	{
		El[i] = Ee[n-1];
		if(count2[i] == 0) { count2[i] = top2; top2 = i; }
	}
	for(i = 0; i < n; i++)
	{
		j = top2; top2 = count2[top2];
		temp2 = List2[j];
		while(temp2 != NULL)
		{
			k = temp2->to;
			if(--count2[k] == 0) { count2[k] = top2; top2 = k; }
			if(El[j]-temp2->dur < El[k]) El[k] = El[j] - temp2->dur;//�����<k, j>
			temp2 = temp2->next;
		}
	}
	//������e[k]��L[k]
	memset(e, 0, sizeof(e)); memset(L, 0, sizeof(L));
	printf("The Critical activities are:\n");
	for(i = 0; i < n; i++)
	{
		temp1 = List1[i];
		while(temp1 != NULL)
		{
			j = temp1->to; k = temp1->no;	//�����<i, j>
			e[k] = Ee[i]; L[k] = El[j] - temp1->dur;
			if(e[k] == L[k]) printf("a%d : %d->%d\n", k, i, j);
			temp1 = temp1->next;
		}
	}
}
int main()
{
	int i, u, v, w;	//ѭ���������ߵ������յ�
	cout<<"�����빤����Ŀ�����ͱ���"<<endl;
	scanf("%d%d", &n, &m);	//���붥������ͱ���
	memset(List1, 0, sizeof(List1)); memset(List2, 0, sizeof(List2));
	memset(count1, 0, sizeof(count1)); memset(count2, 0, sizeof(count2));
	ArcNode *temp1, *temp2;
	for(i = 0; i < m; i++)
	{
		scanf("%d%d%d", &u, &v, &w);	//����ߵ������յ�
		count1[v]++;
		temp1 = new ArcNode;			//�����ڽӱ�
		temp1->to = v; temp1->dur = w;
		temp1->no = i + 1; temp1->next = NULL;
		if(List1[u] == NULL) List1[u] = temp1;
		else { temp1->next = List1[u]; List1[u] = temp1; }
		count2[u]++;
		temp2 = new ArcNode;			//�������ڽӱ�
		temp2->to = u; temp2->dur = w;
		temp2->no = i + 1; temp2->next = NULL;
		if(List2[v] == NULL) List2[v] = temp2;
		else { temp2->next = List2[v]; List2[v] = temp2; }
	}
	CriticalPath();
	for(i = 0; i < n; i++)				//�ͷű������ϸ��߽����ռ�õĴ洢�ռ�
	{
		temp1 = List1[i]; temp2 = List2[i];
		while(temp1 != NULL) { List1[i] = temp1->next; delete temp1; temp1 = List1[i]; }
		while(temp2 != NULL) { List2[i] = temp2->next; delete temp2; temp2 = List2[i]; }
	}
	system("pause");
	return 0;
}
