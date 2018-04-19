#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#define Max 1

typedef struct book//�����Ϣ
{
	char book_num[10];//���
	char book_name[20];//����
	char book_writer[10];//����
	int book_xc;//����ִ�
	int book_kc;//��Ŀ��
	struct book *next;
}BK;



typedef struct borrow//���������Ϣ
{
	char borrow_book_num[10];//�������
	char limit_date[8];//����黹����
}BO;

typedef struct reader//������Ϣ
{
	char reader_num[10];//���ߺ�
	char reader_name[10];//��������
	int right;//�ѽ�����
	BO borrow[Max];//�ѽ�����Ϣ
	struct reader *next;
}RD;

BK *h_book;//BK��ָ��
RD *h_reader;

int Menu();
void Init();
void Init_book();
void Menu_select();
void Insert_New_Book();
void Find_Book();
void add_reader();
void Print_reader();
void Print_book();
void Borrow_Book();
void Return_Book();
void Save();
void Save_Book();
void Save_Reader();
void Load();
void Load_Reader();
void Load_Book();

int Menu()/*���˵�*/
{
	int dm;
	printf("\n\t\tͼ�����ϵͳ���˵�\n");
	printf("=================================================\n");
	printf("\t 0----�˳�ϵͳ \n");
	printf("\t 1----�ɱ���� \n");
	printf("\t 2----�ǼǶ��� \n");
	printf("\t 3----���ĵǼ� \n");
	printf("\t 4----������� \n");
	printf("\t 5----��ѯͼ����Ϣ \n");
	printf("\t 6----��ѯ������Ϣ \n");
	printf("=================================================\n");
	printf("��ѡ����Ӧ�Ĵ���:");
	for(;;)
	{
		scanf("%d",&dm);
		if(dm<0||dm>6)
			printf("\n����!����������:");
		else break;
	}
	return dm;
}

void Menu_select()/*���˵�ѡ����*/
{
	for(;;)//��������ѭ�����
	{
		switch(Menu())/*����ѡ��*/
		{
		case 0:
			system("cls");
			Save();
			printf("\n\n\t�ļ�����ɹ�!\n");
			printf("\n\n\t��ӭ�´�ʹ�ñ�ϵͳ!\n");
			getch();
			exit(0);
		case 1:Insert_New_Book();break;
		case 2:add_reader();break;
		case 3:Borrow_Book();break;
		case 4:Return_Book();break;
		case 5:Print_book();break;
		case 6:Print_reader();break;
		default:printf("\n�������!");
			exit(0);
		}
	}
}

void Init()/*��ʼ��*/
{
	Init_book();
//	Init_reader();
}

void Init_book()/*��ʼ��ͼ����Ϣ*/
{
	BK *p0;//BK�ṹ��ָ��
	printf("\nͼ���ʼ����ʼ,������ͼ����Ϣ..\n�������.����.����..\n");
	p0=(BK*)malloc(sizeof(BK));//�����ڴ�
	h_book=p0;
	printf("\n������ͼ����Ϣ:\n");
	printf("ͼ����:");/*����ͼ����(Ψһ)*/
	scanf("%s",p0->book_num);
	printf("ͼ������:");/*����ͼ������*/
	scanf("%s",p0->book_name);
	printf("ͼ������:");/*����ͼ������*/
	scanf("%s",p0->book_writer);
	printf("ͼ������:");/*����ͼ������*/
	scanf("%d",&p0->book_kc);
	p0->book_xc=p0->book_kc;/*��ʼʱͼ���������Ϳ�������*/
	p0->next=NULL;
	printf("\nͼ����Ϣ��ʼ�����!�������������һ������..\n");
	getch();//�����ڵȴ�״̬�����������ִ������Ĵ���
	system("cls");
}

void Insert_New_Book()/*�������*/
{
	BK *p,*p0,*p1;
	p=p1=h_book;
	printf("\n�������ģ��...\n");
	printf("\n������������Ϣ..\n�������.����.����..\n");
	p0=(BK *)malloc(sizeof(BK));
	printf("ͼ����:");
	scanf("%s",p0->book_num);
	while(strcmp(p0->book_num,p1->book_num)!=0&&p1->next!=NULL)//�Ƚ������ַ���
		p1=p1->next;
	if(strcmp(p0->book_num,p1->book_num)==0)/*�˴����������,��ͼ���Ŵ���,��ֱ�ӽ���,ֻ�������������*/
	{
		printf("\n�˱��ͼ���Ѵ���!!ֱ�����!\n");
		printf("ͼ������:");
		scanf("%d",&p0->book_kc);
		p1->book_kc =p0->book_kc;
		p1->book_xc =p0->book_kc;
	}
	else/*��������,����Ҫ������������Ϣ ,Ȼ���ڽ��в������*/
	{
		printf("ͼ������:");
		scanf("%s",p0->book_name);
		printf("ͼ������:");
		scanf("%s",p0->book_writer);
		printf("ͼ������:");
		scanf("%d",p0->book_kc);
		while(p->next)
		{
			p=p->next;
		}
		if(h_book==NULL)
			h_book=p0;/*�˴����������,������û������,headֱ��ָ��p0��*/
		else
			p->next=p0;/*�˴����������,������������,���������Ԫ�ص�nextָ��p0��*/
		    p0->next=NULL;
		    p0->book_xc=p0->book_kc;
	}
	printf("\n����������!�������������һ������..\n");
	getch();
	system("cls");
}

void add_reader()/*��Ӷ���*/
{ RD *p0;
  int i;
  printf("\n���߳�ʼ����ʼ,�����������Ϣ..\n������֤��.����..\n");
  p0=(RD*)malloc(sizeof(RD));/*�����½��洢�ռ�*/
  h_reader=p0;
  printf("\n��������ߵ���Ϣ:\n");
  printf("������֤��:");
  scanf("%s",&p0->reader_num);
  printf("��������:");
  scanf("%s",&p0->reader_name);
  p0->right=0;
  for(i=0;i<3;i++)
  {
	  strcpy(p0->borrow[i].borrow_book_num,"0");//����ͼ��ֱ����Ϊ0(��û�н���)
	  strcpy(p0->borrow[i].limit_date,"0");
  }
  p0->next=NULL;
  printf("\n������Ϣ��ʼ�����!�������������һ������..\n");
  getch();
  system("cls");
}

void Borrow_Book()/*����ģ��*/
{
BK *p0; RD *p1;
char bo_num[10],rea_num[10],lim_date[8];
int i;
p0=h_book; p1=h_reader;
printf("\n����ģ��...\n");
printf("\n���������Ķ�����֤��:");
scanf("%s",rea_num);
while(p1->next!=NULL&&strcmp(rea_num,p1->reader_num)!=0)//���Ҷ��ߺ�
{
	p1=p1->next;
}
if(p1->next==NULL&&strcmp(rea_num,p1->reader_num)!=0)
{
	printf("\n�˶��߱�Ų�����!�����������..\n");
	goto END;
}
printf("\n��������Ҫ�����ı��:");
scanf("%s",bo_num);
while(strcmp(bo_num,p0->book_num)!=0&&p0->next!=NULL)//�������
{
	p0=p0->next;
}
if(p0->next==NULL&&strcmp(bo_num,p0->book_num)!=0)
{
	printf("\n��ͼ���Ų�����!�����������..\n");
}
else if(p0->book_xc<=0)
{
printf("\n��Ǹ,�����ѽ���!��ȴ�����ĵ���!!\n�����������....");
}
else if(p1->right>=Max)
{
printf("\n������˼,������Ŀ����!���ܽ���!\n�����������....");
}
else if(strcmp(p1->borrow[0].borrow_book_num,"0")!=0)
{
for(i=0;i<Max;i  )
{
if(strcmp(p1->borrow[i].borrow_book_num,bo_num)==0)
{
printf("\n��Ǹ!ͬһ�����߲���ͬ��������ͬ����!\n");
}
else if(strcmp(p1->borrow[i].borrow_book_num,"0")==0)
{
	printf("\n��������Ҫ�黹ͼ�������:");
	scanf("%s",lim_date);
	strcpy(p1->borrow[p1->right  ].borrow_book_num,bo_num);
	strcpy(p1->borrow[p1->right-1].limit_date,lim_date);
	p0->book_xc--;
	printf("\n���߱��%s�������!������������²�����..",p1->reader_num);
}
}
}
else
{
printf("\n��������Ҫ�黹ͼ�������:");
scanf("%s",lim_date);
strcpy(p1->borrow[p1->right  ].borrow_book_num,bo_num);
strcpy(p1->borrow[p1->right-1].limit_date ,lim_date );
p0->book_xc--;
printf("\n���߱��%s�������!������������²�����..",p1->reader_num);
}
END:getch(); system("cls");
}

void Return_Book()/*����ģ��*/
{
BK *p; RD *q;
int i,j,find=0;
char return_book_num[10],return_reader_num[10];
p=h_book; q=h_reader;
printf("\n����ģ��...\n");
printf("\n������Ҫ����Ķ��߱��:");
scanf("%s",return_reader_num);
while(q->next!=NULL&&strcmp(return_reader_num,q->reader_num)!=0)
q=q->next;
if(q->next==NULL&&strcmp(return_reader_num,q->reader_num)!=0)
{
find=2;
printf("\n�˶��߱�Ų�����!�����������..\n");
goto end;
}
printf("\n��������߻���ı��:");
scanf("%s",return_book_num);
while(p->next!=NULL&&strcmp(return_book_num,p->book_num)!=0)
p=p->next;
if(p->next==NULL&&strcmp(return_book_num,p->book_num)!=0)
{
find=2;
printf("\n����!��ͼ���Ų�����!�����������..\n");
goto end;
}
for(i=0;i<3;i++)
if(strcmp(return_book_num,q->borrow[i].borrow_book_num)==0)/*����˶��߽��˴���*/
{
find=1;
for(j=i;j<i-1;j  )
{
strcpy(q->borrow[j].borrow_book_num,q->borrow[j,1].borrow_book_num);
strcpy(q->borrow[j].limit_date,q->borrow[j,1].limit_date);
}
strcpy(q->borrow[i-1].borrow_book_num,"0");
strcpy(q->borrow[i-1].limit_date,"0");
p->book_xc++;
q->right--;
printf("\n���%s�Ķ��߻������!������������²�����..",return_reader_num);
}
if(find==0)
printf("\n����!�˶���δ�����!�����������..\n");
end: getch(); system("cls");
}

void Print_book()/*��ѯͼ����Ϣ*/
{
BK *p;
p=h_book;
printf("\nͼ����Ϣ����:\n\n");
printf("ͼ����\tͼ������\tͼ������\t����\t\t���\n");
while(p!=NULL)
{
printf("%s\t\t%s\t\t%s\t\t%d\t\t%d\n",p->book_num,p->book_name,p->book_writer,p->book_xc,p->book_kc);
p=p->next;
}
printf("\nͼ����Ϣ��ӡ���!�������������һ������..");
getch();
system("cls");
}

void Print_reader()/*��ѯ������Ϣ*/
{
	RD *p;
	int i;
	p=h_reader;
	printf("\n������Ϣ����:\n\n");
	printf("������֤��\t\t��������\n");
	printf("\n");
	while(p!=NULL)
	{
		printf("\t%s\t\t%s",p->reader_num,p->reader_name);
		for(i=0;i<3;i++)
		{
			printf("\n");
			printf("ͼ����",i,1);
			printf("\t��������",i,1);
			printf("\n");
			printf("\t%s",p->borrow[i].borrow_book_num);
			printf("\t\t%s",p->borrow[i].limit_date);
		}
		printf("\n");
		p=p->next;
	}
	printf("\n������Ϣ��ӡ���!�������������һ������..");
	getch();
	system("cls");
}

//�ļ�ģ��
void Save()/*������Ϣ*/
{
Save_Reader();
Save_Book();
}
void Save_Reader()/*���������Ϣ*/
{
FILE *fp_reader;
RD *p,*p0;
p=h_reader;
if((fp_reader=fopen("Reader.txt","wb"))==NULL)/*�����ļ�,���б���*/
{
printf("\n�ļ�����ʧ��!\n������������ϵͳ...\n");
exit(0);
}
while(p!=NULL)
{
if(fwrite(p,sizeof(RD),1,fp_reader)!=1)/*�������е���Ϣд���ļ���*/
printf("\nд���ļ�ʧ��!\n������������ϵͳ!\n");
p0=p;
p=p->next;
free(p0);/*�ͷ����н��*/
}
h_reader=NULL;
fclose(fp_reader);/*�ر��ļ�*/
}

void Save_Book()/*����ͼ����Ϣ*/
{
FILE *fp_book;/*�����ļ���ָ��*/
BK *p,*p0;
p=h_book;
if((fp_book=fopen("Book.txt","wb"))==NULL)/*�����ļ�,���б���*/
{
printf("\n�ļ�����ʧ��!\n������������ϵͳ...\n");
exit(0);
}
while(p!=NULL)
{
if(fwrite(p,sizeof(BK),1,fp_book)!=1)/*�������е���Ϣд���ļ���*/
printf("\nд���ļ�ʧ��!\n������������ϵͳ!\n");
p0=p;
p=p->next;
free(p0);
}
h_book=NULL;
fclose(fp_book);/*�ر��ļ�*/
}

void Load()/*������Ϣ*/
{
Load_Reader();
Load_Book();
}
void Load_Reader()/*���ض�����Ϣ*/
{
RD *p1,*p2,*p3;
FILE *fp;/*�����ļ���ָ��*/
fp=fopen("book.txt","rb");/*���ļ�*/
p1=(RD *)malloc(sizeof(RD));
fread(p1,sizeof(RD),1,fp);
h_reader=p3=p2=p1;
while(! feof(fp))/*������Ϣ,������������*/
{ p1=(RD *)malloc(sizeof(RD));
fread(p1,sizeof(RD),1,fp);
p2->next=p1;
p3=p2;
p2=p1;
}
p3->next=NULL;
free(p1);
fclose(fp);/*�ر��ļ�*/
}

void Load_Book()/*����ͼ����Ϣ*/
{
BK *p1,*p2,*p3;
FILE *fp;/*�����ļ���ָ��*/
fp=fopen("Book.txt","rb");/*���ļ�*/
p1=(BK *)malloc(sizeof(BK));
fread(p1,sizeof(BK),1,fp);
h_book=p3=p2=p1;
while(! feof(fp))/*������Ϣ,������������*/
{ p1=(BK *)malloc(sizeof(BK));
fread(p1,sizeof(BK),1,fp);
p2->next=p1;
p3=p2;
p2=p1;
}
p3->next=NULL;
free(p1);
fclose(fp);/*�ر��ļ�*/
}

void main()
{
FILE *fp_book,*fp_reader;/*�����ļ���ָ��*/
//Login();
if((fp_book=fopen("Book.txt","rb"))==NULL||(fp_reader=fopen("Reader.txt","rb"))==NULL)
{ Init(); }
else Load();
Menu_select();/*�������˵�*/
}