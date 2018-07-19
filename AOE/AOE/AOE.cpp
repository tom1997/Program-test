#include<iostream>
using namespace std;
 
#define MAXN 100		//顶点个数最大值
#define MAXM 200		//边数的最大值
 
struct ArcNode
{
	int to, dur, no;	//边的另一个顶点、持续时间、活动序号
	ArcNode *next;
};
int n, m;				//顶点个数、边数
ArcNode *List1[MAXN];	//每个顶点的边链表表头指针（出边表）
ArcNode *List2[MAXM];	//每个顶点的边链表表头指针（入边表）
int count1[MAXN];		//各顶点的入度
int count2[MAXM];		//各顶点的出度
int Ee[MAXN];			//各事件的最早可能开始时间
int El[MAXN];			//各事件的最迟允许开始时间
int e[MAXM];			//各活动的最早可能开始时间
int L[MAXM];			//各活动的最迟允许开始时间
void CriticalPath()		//求关键路径
{
	//拓扑排序求Ee
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
				if(Ee[j]+temp1->dur > Ee[k]) Ee[k] = Ee[j] + temp1->dur;//有向边<j, k>
				temp1 = temp1->next;
			}
		}
	}
	//逆拓扑排序求El
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
			if(El[j]-temp2->dur < El[k]) El[k] = El[j] - temp2->dur;//有向边<k, j>
			temp2 = temp2->next;
		}
	}
	//求各活动的e[k]和L[k]
	memset(e, 0, sizeof(e)); memset(L, 0, sizeof(L));
	printf("The Critical activities are:\n");
	for(i = 0; i < n; i++)
	{
		temp1 = List1[i];
		while(temp1 != NULL)
		{
			j = temp1->to; k = temp1->no;	//有向边<i, j>
			e[k] = Ee[i]; L[k] = El[j] - temp1->dur;
			if(e[k] == L[k]) printf("a%d : %d->%d\n", k, i, j);
			temp1 = temp1->next;
		}
	}
}
int main()
{
	int i, u, v, w;	//循环变量、边的起点和终点
	cout<<"请输入工作项目数量和边数"<<endl;
	scanf("%d%d", &n, &m);	//读入顶点个数和边数
	memset(List1, 0, sizeof(List1)); memset(List2, 0, sizeof(List2));
	memset(count1, 0, sizeof(count1)); memset(count2, 0, sizeof(count2));
	ArcNode *temp1, *temp2;
	for(i = 0; i < m; i++)
	{
		scanf("%d%d%d", &u, &v, &w);	//读入边的起点和终点
		count1[v]++;
		temp1 = new ArcNode;			//构造邻接表
		temp1->to = v; temp1->dur = w;
		temp1->no = i + 1; temp1->next = NULL;
		if(List1[u] == NULL) List1[u] = temp1;
		else { temp1->next = List1[u]; List1[u] = temp1; }
		count2[u]++;
		temp2 = new ArcNode;			//构造逆邻接表
		temp2->to = u; temp2->dur = w;
		temp2->no = i + 1; temp2->next = NULL;
		if(List2[v] == NULL) List2[v] = temp2;
		else { temp2->next = List2[v]; List2[v] = temp2; }
	}
	CriticalPath();
	for(i = 0; i < n; i++)				//释放边链表上各边结点所占用的存储空间
	{
		temp1 = List1[i]; temp2 = List2[i];
		while(temp1 != NULL) { List1[i] = temp1->next; delete temp1; temp1 = List1[i]; }
		while(temp2 != NULL) { List2[i] = temp2->next; delete temp2; temp2 = List2[i]; }
	}
	system("pause");
	return 0;
}
