#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100//���ɴ������Ϣ����
#define A 5//ѧԺ����
#define B 7//��Ŀ����
FILE *fp;//�����ļ�ָ��
char college[A][30]={" "};//ѧԺ����Ŀ���Ƶ��ַ�������,֮�������ж��û��Ƿ����Ժ������Ŀ��
char event[B][30]={" "};
struct list//ÿ��������Ϣ�Ľṹ�壬�����������Ա�ѧԺ����Ŀ���ɼ���Ϣ
{	char name[20];
	char sex[4];
	char college[30];
	char event[30];
	char point[10];};
struct for_sort//��Ժ����+��Ӧ�ܻ���,���ڻ������������
{   char name[30];
	int sum;};
void out_college()
{	int i;
	for(i=0;i<A;i++)
		printf("%d.%s ",i+1,college[i]);
	printf("\n");}
void out_event()//�������ЩѧԺ����Ŀ���������Ժ������Ŀ������ʾ��Ϣ
{	int i;
	for(i=0;i<B;i++)
		printf("%d.%s ",i+1,event[i]);
	printf("\n");}
void data_output(struct list a[],int p)//������еĲ�����Ϣ
{	int i;
	if(p<=0)
	{printf("|=====================������=====================|\n\n");return 0;}
	printf("|==================��ѯ��������==================|\n");
	printf("|���----����----�Ա�----ѧԺ----��Ŀ----�ɼ�----|\n");
	for(i=0;i<p;i++)
		printf("|%-8d%-8s%-8s%-8s%-8s%-8s\n",i+1,a[i].name,a[i].sex,a[i].college,a[i].event,a[i].point);}
void data_delete(struct list a[],int *p)//ɾ����Ϣ����
{	int i,num;
	char ch;
	if(p<=0)
	{printf("|=====================������=====================|\n\n");return 0;}
shanchu:data_output(a,*p);//��55��goto���Ŀ�ĵ�
	printf("������Ҫɾ������Ϣ���:");
	scanf("%d",&num);
	num--;*p=*p-1;
	printf("      |=======================================\n");
	printf("ɾ����|%-8d%-8s%-8s%-8s%-8s%-8s\n",num+1,a[num].name,a[num].sex,a[num].college,a[num].event,a[num].point);
	printf("      |=======================================\n");//��ʾɾ����������Ϣ
	for(i=num;i<*p;i++)
		a[i]=a[i+1];//�ѱ�ɾ����Ϣ����֮�����Ϣȫ��ǰһλ��ֵ
	printf("(�����ַ�����)����X����ɾ��:");
	getchar();
	scanf("%c",&ch);
	if(toupper(ch)=='X')
		goto shanchu;}//���������42��ʵ�ֶ��ɾ��
void data_change(struct list a[],int *p)//�޸���Ϣ����
{	int i,num,option,flag1=1,flag2=1;
	char ch,temp[30];
xiugai1:data_output(a,*p);//��136��goto���Ŀ�ĵ�,ʵ�ֳ����޸���Ϣ
    printf("�������޸ĵ����:");
	scanf("%d",&num);
	num--;
	printf("            |=======================================\n");
	printf("�����޸ĵ���|%-8d%-8s%-8s%-8s%-8s%-8s\n",num+1,a[num].name,a[num].sex,a[num].college,a[num].event,a[num].point);
	printf("            |=======================================\n");
	do{
xiugai2:printf("���޸�������Ϣ:");//ĳ����Ϣĳ��Ԫ���޸���ɺ�goto���Ŀ�ĵ�,ʵ�ַ����޸�ĳ����Ϣ����
	    printf("|--1.����--2.�Ա�--3.ѧԺ--4.��Ŀ--5.�ɼ�--|\n��ѡ��:");
    	scanf("%d",&option);
    	switch(option)
		{case 1:
			{printf("\n��������Ϊ:");
			scanf("%s",&a[num].name);getchar();
			printf("\n(Y/N)�Ƿ�����޸ĸ�����Ϣ:");
			scanf("%c",&ch);
			if(toupper(ch)=='Y')
			    goto xiugai2;//������ת����67�У�ʵ�ַ����޸�ĳ����Ϣ
			else if(toupper(ch)=='N')
				break;}
    	case 2:
			{printf("\n�����Ա�Ϊ:");
			scanf("%s",&a[num].sex);getchar();
			printf("\n(Y/N)�Ƿ�����޸ĸ�����Ϣ:");
			scanf("%c",&ch);
			if(toupper(ch)=='Y')
			    goto xiugai2;//������ת����67�У�ʵ�ַ����޸�ĳ����Ϣ
			else if(toupper(ch)=='N')
				break;}
    	case 3:
			{gai_college:printf("\n����ѧԺΪ:");//��98��goto���Ŀ�ĵ�
				scanf("%s",&temp);
				for(i=0;i<A;i++)
				{   if(strcmp(temp,college[i])==0)//�ж��û��Ƿ������˲����������е����ƣ���ֹ�������
					{    strcpy(a[num].college,temp);flag2=0;}}
	           	if(flag2)
				{	printf("�޴�ѧԺ,������ѧԺ:");
			    	out_college();//��ʾ����������ЩѧԺ
			     	goto gai_college;}//���ִ�������ת����90���޸�����Ԫ��ǰ��������
			 	getchar();
				printf("\n(Y/N)�Ƿ�����޸ĸ�����Ϣ:");
				scanf("%c",&ch);
				if(toupper(ch)=='Y')
				    goto xiugai2;//������ת����67�У�ʵ�ַ����޸�ĳ����Ϣ
				else if(toupper(ch)=='N')
					break;}
    	case 4:
			{gai_event:printf("\n������ĿΪ:");//��115��goto���Ŀ�ĵ�
				scanf("%s",&temp);
				for(i=0;i<B;i++)
				{   if(strcmp(temp,event[i])==0)
					{	strcpy(a[num].event,temp);flag2=0;}}
	           	if(flag2)//���ִ�������ת����107���޸�����Ԫ��ǰ��������,ֱ��������ȷ
				{	printf("�޴���Ŀ,��������Ŀ:");
			    	out_event();//��ʾ����������Щ��Ŀ
			     	goto gai_event;}
				getchar();
				printf("\n(Y/N)�Ƿ�����޸ĸ�����Ϣ:");
				scanf("%c",&ch);
				if(toupper(ch)=='Y')
				    goto xiugai2;//��ת����67�У�ʵ�ַ����޸�ĳ����Ϣ
				else if(toupper(ch)=='N')
					break;}
    	case 5:
			{printf("\n���ĳɼ�Ϊ:");
			scanf("%s",&a[num].point);getchar();
			printf("\n(Y/N)�Ƿ�����޸ĸ�����Ϣ:");
			scanf("%c",&ch);
			if(toupper(ch)=='Y')
				goto xiugai2;//������ת����67�У�ʵ�ַ����޸�ĳ����Ϣ
			else if(toupper(ch)=='N')
				break;}
    	default:{printf("\n��Чѡ��");flag1=0;}}}while(flag1==0);
	printf("\n(�����ַ�����)����X�����޸���Ϣ:");getchar();
	scanf("%c",&ch);
	if(toupper(ch)=='X')
		goto xiugai1;//��ת����59�У�ʵ���޸Ķ�����Ϣ
}
void data_check(struct list a[],int *p)//��ѯ��Ϣ�ĺ���
{	int flag=1,num,option,i;    //flag���ڿ����û�����������Чʱ����ѡ���ѯ����
	struct list sort[N];        //option���û������ѡ�num�ǰ�����������ѯ������Ϣ���������ڴ��ݸ�������������ѯ������Ϣ
	char temp[30]={"\0"};       //�ṹ��sort���ڴ�Ű�������ѯ������Ϣ�����ݸ�����������������temp���û��Լ�����Ĳ�ѯ�������ݣ����ԶԱ�������Ϣȡ��������������Ϣ��
	printf("|========================================|\n");
    printf("|----------1.����--------2.�Ա�----------|\n");
	printf("|----------3.ѧԺ--------4.��Ŀ----------|\n");
	printf("|----------5.ȫ����Ϣ----6.����----------|\n");
	printf("|========================================|\n");
	do{ num=0;
     	printf("��������ѡ���ѯ����:");
    	scanf("%d",&option);
    	switch(option)
		{case 1:
			{printf("��������ѯ������:");
	    	scanf("%s",temp);
		   	for(i=0;i<*p;i++)
		        if(strcmp(a[i].name,temp)==0)
				{	sort[num]=a[i];num++;}
	    	data_output(sort,num);break;}//���������ѡ�������Ϣ�����ڵ�29�У�data_output();
    	case 2:
			{printf("��������ѯ���Ա�:");
			scanf("%s",temp);
			for(i=0;i<*p;i++)
		    	if(strcmp(a[i].sex,temp)==0)
				{	sort[num]=a[i];num++;}
	    	data_output(sort,num);break;}
    	case 3:
			{printf("��������ѯ��ѧԺ:");
	    	scanf("%s",temp);
	     	for(i=0;i<*p;i++)
		        if(strcmp(a[i].college,temp)==0)
				{	sort[num]=a[i];num++;}
	    	data_output(sort,num);break;}
     	case 4:
			{printf("��������ѯ����Ŀ:");
	    	scanf("%s",temp);
	    	for(i=0;i<*p;i++)
		        if(strcmp(a[i].event,temp)==0)
				{	sort[num]=a[i];num++;}
	    	data_output(sort,num);break;}
	case 5:{data_output(a,*p);break;}
	case 6:break;
	default:{printf("\n��Чѡ��\n");flag=0;}}}while(flag==0);
}
void data_add(struct list a[],int *p,int sign,int num)//¼����Ϣ������ͨ���������Ĵ���ֵ���Կ��Ʊ�ɲ��뺯��
{	int i,flag1=1,flag2=1;//flag1��������¼���ѭ����flag2����¼��ʱ���ѧԺ������Ŀ���������������ѭ��
	int ren=*p;          //ren������Ϣ������¼�����Ϣ�������һ����Ϣ�ĺ���
	char temp[30];       //temp���û������ѧԺ����Ŀ������ʱ�����temp�����ں������е�����ѧԺ����Ŀ���жԱȲ鿴�Ƿ��������
	if(sign==0)
		ren=num;         //������ݹ�����signֵΪ0����ren��Ϊ���ݹ�����numֵ��Ϊ���룬num�������Ϣ�����ڵڼ�����Ϣ���ֵ
	do{printf("|====================��ʼ¼��====================|\n");
    	printf("\n����:");
    	scanf("%s",a[ren].name);
    	printf("�Ա�:");
     	scanf("%s",a[ren].sex);
add_college:printf("ѧԺ:");//��203��goto���Ŀ�ĵ�
    	scanf("%s",temp);
		for(i=0;i<A;i++)
		{	if(strcmp(college[i],temp)==0)
			{strcpy(a[ren].college,temp);//�ж��Ƿ�������ȷ��ѧԺ����Ŀ��ֱ��������ȷ
			flag2=0;}}
		if(flag2)
		{	printf("�޴�ѧԺ,������ѧԺ:");
			out_college();//��ʾ����������ЩѧԺ
			goto add_college;}//��ת����194����������
		flag2=1;
add_event:printf("��Ŀ:");
    	scanf("%s",temp);
		for(i=0;i<B;i++)
		{   if(strcmp(event[i],temp)==0)
			{strcpy(a[ren].event,temp);
			flag2=0;}}
		if(flag2)
		{	printf("�޴���Ŀ,��������Ŀ:");
			out_event();
			goto add_event;}
		flag2=1;
    	printf("�ɼ�:");
    	scanf("%s",a[ren].point);ren++;
		if(sign!=0)
        {	printf("(�������ַ���)����0����¼��:");//�����Ƿ����¼��
    		scanf("%d",&flag1);}
	}while(flag1==0);
	if(sign==0)//����sign�����ͬ����ʾ��Ϣ���������¼��
	{	*p=*p+1;
    	printf("|====================�������====================|\n");}
	else
	{	*p=ren;
    	printf("|====================¼�����====================|\n");}
}
void data_insert(struct list a[],int *p)//���뺯��
{
	int num,i,flag=1;
	data_output(a,*p);
	printf("���ڵڼ�����Ϣ�����:");
	scanf("%d",&num);
	num--;
	for(i=*p+1;i>=num;i--)
		a[i]=a[i-1];
	data_add(a,p,0,num);//����¼�뺯�����Ҫ������Ϣ��¼��
}
void data_save(struct list a[],int *p)//������Ϣ����
{	int i;
	fp=fopen("data.txt","r+");
	if(fp==NULL)
	{printf("�ļ���ʧ��\n");exit(0);}
    for(i=0;i<=*p;i++)
		fprintf(fp,"%s %s %s %s %s\n",a[i].name,a[i].sex,a[i].college,a[i].event,a[i].point);
	fclose(fp);
	printf("|===================����ɹ�===================|\n");}
void data_load(struct list a[],int *p)//��ȡ��Ϣ�����ļ�
{	int i=0,ren=0;
	fp=fopen("data.txt","r+");
	if(fp==NULL)
	{printf("�ļ���ʧ��\n");exit(0);}
	while(!feof(fp))
	{	fscanf(fp,"%s %s %s %s %s\n",&a[i].name,&a[i].sex,&a[i].college,&a[i].event,&a[i].point);
	    ren++;i++;}//��ȡ��ͬʱ���������㿪ʼ�Լ�
	fclose(fp);
	*p=ren;
	printf("|===================��ȡ�ɹ�===================|\n");
}
void data(struct list a[],int *p)//������Ϣ����������
{	int flag=1,option;//flag����ѡ������ʱ��������ѡ�option���û������ѡ��
	printf("|========================================|\n");
    printf("|------1.��ѯ��Ϣ--------2.¼����Ϣ------|\n");
	printf("|------3.������Ϣ--------4.�޸���Ϣ------|\n");
	printf("|------5.ɾ����Ϣ--------6.��ȡ��Ϣ------|\n");
	printf("|------7.������Ϣ--------8.����----------|\n");
	printf("|========================================|\n");
	do{	printf("��ѡ��:");
     	scanf("%d",&option);
     	switch(option)
		{case 1:{data_check(a,p);break;}//��ѯ��Ϣ����138��
       	case 2:{data_add(a,p,1,1);break;}//1,1����Ϊ�˴����øĳɲ��뺯���������������������Կ����Ƿ�ת��Ϊ���ڲ��룬���ĸ��������û�����Ҫ�����λ�ã���183��
    	case 3:{data_insert(a,p);break;}//������Ϣ����229��
    	case 4:{data_change(a,p);break;}//�޸���Ϣ����56��
    	case 5:{data_delete(a,p);break;}//ɾ����Ϣ����37��
    	case 6:{data_load(a,p);break;}//�ӱ����ļ�������Ϣ���ݣ���249��
    	case 7:{data_save(a,p);break;}//���浱ǰ��Ϣ���ݵ������ļ�����240��
    	case 8:break;
    	default:{printf("\n��Чѡ��\n");flag=0;}}}while(flag==0);
}
void set_check()//�鿴���õ�ѧԺ����Ŀ����
{	printf("\n|=============��ǰ��������=============|\n|ѧԺ��:");
	out_college();//������е�ѧԺ��
	printf("|��Ŀ��:");
	out_event();//������е���Ŀ��
}
void set_change()//�޸�����
{	int flag;//flag�����û�������Чѡ�ѭ������ѡ��
	char ch1,ch2;//ch1�����û����޸ĵ���ѧԺ������Ŀ��ch2��do-whileѭ�������������û��Ƿ�������޸ġ�
	set_check();//�����ǰ���ã���282��
	do{	printf("�޸�ѧԺ����X,�޸���Ŀ����Y:");
    	do{	flag=1;
	    	printf("\n������:");
	    	getchar();
        	scanf("%c",&ch1);
        	switch(toupper(ch1))
			{	case 'X':
				{	int j;
		        	printf("��������ѡ��Ҫ�޸ĵ�ѧԺ����:");
		        	scanf("%d",&j);getchar();
		        	while(j<0||j>A)
					{printf("������ȷ��Χѡ��:");scanf("%d",&j);}
		        	printf("������������:");
		        	scanf("%s",&college[j-1]);
		     		set_check();
			    	break;}
            	case 'Y':
				{   int j;
		        	printf("��������ѡ��Ҫ�޸ĵ���Ŀ����:");
		        	scanf("%d",&j);getchar();
		         	while(j<0||j>B)
					{printf("������ȷ��Χѡ��:");scanf("%d",&j);}
		        	printf("������������:");
		        	scanf("%s",&event[j-1]);
			    	set_check();
					break;}
            	default:{printf("\n��Чѡ��\n");flag=0;}}}while(flag==0);
    	printf("����X�����޸ģ����������޸�:");
    	getchar();
    	scanf("%c",&ch2);
	}while(toupper(ch2)=='X');
}
void set_load()//��������
{	int i;
	fp=fopen("setting.txt","r");
	if(fp==NULL)
	{printf("��ȡʧ��\n");exit(0);}
	for(i=0;i<A;i++)
		fscanf(fp,"%s\n",&college[i]);
	for(i=0;i<B;i++)
		fscanf(fp,"%s\n",&event[i]);
	fclose(fp);
	printf("|===================��ȡ�ɹ�===================|\n");
	set_check();//�����ǰ���ã���282��
}
void set_save()//��������
{	int i;
	fp=fopen("setting.txt","w");
	if(fp==NULL)
	{printf("��ȡʧ��\n");exit(0);}
	for(i=0;i<A;i++)
		fprintf(fp,"%s\n",college[i]);
	for(i=0;i<B;i++)
		fprintf(fp,"%s\n",event[i]);
	fclose(fp);
	printf("|===================����ɹ�===================|\n");
	set_check();//�����ǰ���ã���282��
}
void setting()//������Ϣ��������
{	int flag=1,option;//flag����ѡ������ʱ��������ѡ�option���û������ѡ��
	printf("\n|========================================|\n");
    printf("|----1.�鿴��ǰ����-----2.�޸�����-------|\n");
	printf("|----3.��ȡ����---------4.��������-------|\n");
	printf("|----5.����------------------------------|\n");
	printf("|========================================|\n");
	do{	printf("��������ѡ��:");
    	scanf("%d",&option);
    	switch(option)
		{   case 1:{set_check();break;}//�鿴���ã���282��
        	case 2:{set_change();break;}//�޸����ã���288��
         	case 3:{set_load();break;}//�������ã���324��
        	case 4:{set_save();break;}//�������ã���337��
        	case 5:break;
        	default:{printf("\n��Чѡ��\n");flag=0;}}}while(flag==0);
}
void sort(struct list a[],int p,int sum[],int e_sum[][A])//���ṹ��������а���Ŀ����󰴳ɼ����򣬲�ͳ�Ƹ�Ժ��û��ֵ��������м������
{
	int i,j,q;//i��j��qΪѭ����������
	int e_num[B][A][5]={{0,0,0}};//ÿ����Ŀ�и���ѧԺ��1����5��������
	struct event_data
	{	struct list data[N];};
	struct event_data haha[B]={"\0"};//ÿ����Ŀ���������ģ���/Ů��)��Ϣ��Ƕ�׽ṹ������
	struct list temp;//���������õ���ʱ�ṹ�����
	int num[B]={0};//ÿ����Ŀ�еģ���/Ů������
	int p_num[A][5]={{0,0}};//ÿ��ѧԺ��һ���������ĸ�������
	for(i=0;i<p;i++)//��ÿ������/Ů������Ϣ���ൽ������Ŀ�Ľṹ��������ȥ
		for(j=0;j<B;j++)
	    	if(strcmp(a[i].event,event[j])==0)
			{	haha[j].data[num[j]]=a[i];num[j]++;}
	for(i=0;i<B;i++)
		for(j=0;j<num[i]-1;j++)
	    	for(q=j+1;q<num[i];q++)//����Ŀ��Ա���ɼ���������
		    	if(strcmp(haha[i].data[j].point,haha[i].data[q].point)<0)
				{	temp=haha[i].data[j];
			    	haha[i].data[j]=haha[i].data[q];
			    	haha[i].data[q]=temp;}
	for(i=0;i<B;i++)
		for(j=0;j<num[i];j++)//ͳ��ÿ����Ŀ�����ѧԺ���1��7���ֵ���Ů������
			for(q=0;q<A;q++)
		    	if(strcmp(haha[i].data[j].college,college[q])==0)
				{	p_num[q][j]++;e_num[i][q][j]++;}
	if(strcmp(a[i].sex,"��")==0)//�������
    	for(i=0;i<B;i++)
	    	for(j=0;j<A;j++)
		    	e_sum[i][j]=e_num[i][j][0]*7+e_num[i][j][1]*5+e_num[i][j][2]*3+e_num[i][j][3]*2+e_num[i][j][4]*1;
	if(strcmp(a[i].sex,"Ů")==0)
    	for(i=0;i<B;i++)
	    	for(j=0;j<A;j++)
		    	e_sum[i][j]=e_num[i][j][0]*5+e_num[i][j][1]*3+e_num[i][j][2]*2;
	if(strcmp(a[i].sex,"��")==0)
    	for(i=0;i<A;i++)
	    	sum[i]=p_num[i][0]*7+p_num[i][1]*5+p_num[i][2]*3+p_num[i][3]*2+p_num[i][4]*1;
	if(strcmp(a[i].sex,"Ů")==0)
    	for(i=0;i<A;i++)
	    	sum[i]=p_num[i][0]*5+p_num[i][1]*3+p_num[i][2]*2;
}
void chuli(struct list a[],int *p,struct for_sort hehe[],int sum[][A])//��������Ϣ��Ϊ�С�Ů�����֣��õ�367�е��Զ��庯��������󷵻ص��˺���������֣�
{                                                                     //a������������Ϣ��*p����Ϣ������hehe���ú��淽��ÿ��Ժ��������Ľṹ��(��Ժ����������)
	int i,j=0,m=0,f=0;//i��j��ѭ��������m��f�ǰ���Ů����ʱͳ�Ƶ��С�Ů������    //sum[][]��ÿ����Ŀ�и�Ժ�Ļ���
	int nan[A]={0};//��Ժ����������
	int nv[A]={0};//��Ժ��Ů������
	int e_nan[B][A]={{0,0}};    //������Ŀ�и�Ժ����������
	int e_nv[B][A]={{0,0}};    //������Ŀ�и�Ժ��Ů������
	struct list male[N]={"\0"};    //ֻ�������Ĳ�����Ϣ
	struct list female[N]={"\0"};    //Ů��������Ϣ
	struct for_sort temp;    //�����õ���ʱ�ṹ��
	for(i=0;i<A;i++)
		strcpy(hehe[i].name,college[i]);//��Ժ�����Ƶ�������ֵĽṹ����
	for(i=0;i<*p;i++)//��������Ϣ����Ů�ֳ������ṹ�����飬�ֿ�����
	{	if(strcmp(a[i].sex,"��")==0)
		{	male[m]=a[i];m++;}
		if(strcmp(a[i].sex,"Ů")==0)
		{	female[f]=a[i];f++;}}
        sort(male,m,nan,e_nan);//����Ŀ�а��ɼ��������򣬼���ÿ��ѧԺ������Ů�����Ի�õĻ���,�˺����ڵ�367��
        sort(female,f,nv,e_nv);
	for(i=0;i<A;i++)//����Ů������Ӿ���ÿ��ѧԺ�ܻ��֡�
		hehe[i].sum=(nan[i])+(nv[i]);
	for(i=0;i<A-1;i++)
		for(j=i+1;j<A;j++)//�Լ�������ֵ�ѧԺ��������
			if(hehe[i].sum<hehe[j].sum)
			{temp=hehe[i];hehe[i]=hehe[j];hehe[j]=temp;}
	for(i=0;i<B;i++)//�Ѹ�����Ŀ�и�Ժ����Ů�����ֱַ���ӣ��õ�������Ŀ�и�Ժ��õĻ���
		for(j=0;j<A;j++)
			sum[i][j]=e_nan[i][j]+e_nv[i][j];
}
void p_event(struct list a[],int *p)//���������Ŀ�и�Ժ�ĵ÷����
{	int i,j;//i��j����ѭ��
	int sum[B][A]={{0,0}};//ÿ����Ŀ�и�Ժ�Ļ��������ά����
	struct for_sort hehe[A];//�ڴ˺�������ʵ�����壬Ϊ���chuli()������ȱʧ�ĺ�������
	chuli(a,p,hehe,sum);//������Ϣ���˺����ڵ�408��
	for(i=0;i<B;i++)
	{	printf("|%d.%s\n",i+1,event[i]);//�������Ŀ�и�Ժ�÷����
		for(j=0;j<A;j++)
			printf("|--%s---%d��\n",college[j],sum[i][j]);}
}
void p_college(struct list a[],int *p)//�����Ժ�Ļ�������
{	int i;
	struct for_sort hehe[A];//Ժ���Ͷ�Ӧ���ֵĽṹ�壬��������������
	int sum[B][A]={{0,0}};//�ڴ˺�������ʵ�����壬Ϊ���chuli()������ȱʧ�ĺ�������
	chuli(a,p,hehe,sum);
	printf("\n|============��Ժ������������============|\n");
	for(i=0;i<A;i++)
    	printf("|======%d.%s--%d��\n",i+1,hehe[i].name,hehe[i].sum);
}
void points(struct list a[],int *p)//���ֲ鿴������
{
	int flag=1,option;//flag����ѡ������ʱ��������ѡ�option���û������ѡ��
	printf("|========================================|\n");
   	printf("|------1.�鿴��Ժ��������----------------|\n");
   	printf("|------2.����Ŀ�и�Ժ�÷����------------|\n");
   	printf("|------3.����----------------------------|\n");
   	printf("|========================================|\n");
	do{ printf("��������ѡ��:");
    	scanf("%d",&option);
    	switch(option)
		{	case 1:{p_college(a,p);break;}//��448�У������Ժ�Ļ�������
	    	case 2:{p_event(a,p);break;}//��437�У����������Ŀ�и�Ժ�ĵ÷����
         	case 3:break;
        	default:{printf("\n��Чѡ��\n");flag=0;}}}while(flag==0);
}
int main()//���˵�����
{	int flag=1,sign=1,ren=0,option;
	int *p=&ren;//ren����Ϣ�������ṹ������all�����Ϣ
	struct list all[N];
	while(flag)
	{	printf("|========================================|\n");
    	printf("|-----------�˶����������ϵͳ-----------|\n");
    	printf("|------1.���ֲ鿴--------2.���ݹ���------|\n");
    	printf("|------3.��ʼ����--------4.�˳�ϵͳ------|\n");
    	printf("|========================================|\n");
		do{	printf("��������ѡ��:");
         	scanf("%d",&option);
        	switch(option)
			{	case 1:{points(all,p);break;}//���ֲ鿴����458��
            	case 2:{data(all,p);break;}//���ݹ�����261��
				case 3:{setting();break;}//���ù�����350��
            	case 4:{flag=0;break;}
				default:{printf("\n��Чѡ��\n");sign=0;}}}while(sign==0);}
	return 0;
}