#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100//最多可储存的信息条数
#define A 5//学院个数
#define B 7//项目个数
FILE *fp;//定义文件指针
char college[A][30]={" "};//学院和项目名称的字符串数组,之后用于判断用户是否输错院名和项目名
char event[B][30]={" "};
struct list//每条参赛信息的结构体，包含姓名，性别，学院，项目，成绩信息
{	char name[20];
	char sex[4];
	char college[30];
	char event[30];
	char point[10];};
struct for_sort//各院名称+对应总积分,用于积分排名的输出
{   char name[30];
	int sum;};
void out_college()
{	int i;
	for(i=0;i<A;i++)
		printf("%d.%s ",i+1,college[i]);
	printf("\n");}
void out_event()//输出有哪些学院、项目，用于输错院名、项目名的提示信息
{	int i;
	for(i=0;i<B;i++)
		printf("%d.%s ",i+1,event[i]);
	printf("\n");}
void data_output(struct list a[],int p)//输出含有的参赛信息
{	int i;
	if(p<=0)
	{printf("|=====================无数据=====================|\n\n");return 0;}
	printf("|==================查询数据如下==================|\n");
	printf("|序号----姓名----性别----学院----项目----成绩----|\n");
	for(i=0;i<p;i++)
		printf("|%-8d%-8s%-8s%-8s%-8s%-8s\n",i+1,a[i].name,a[i].sex,a[i].college,a[i].event,a[i].point);}
void data_delete(struct list a[],int *p)//删除信息函数
{	int i,num;
	char ch;
	if(p<=0)
	{printf("|=====================无数据=====================|\n\n");return 0;}
shanchu:data_output(a,*p);//第55行goto语句目的地
	printf("请输入要删除的信息序号:");
	scanf("%d",&num);
	num--;*p=*p-1;
	printf("      |=======================================\n");
	printf("删除了|%-8d%-8s%-8s%-8s%-8s%-8s\n",num+1,a[num].name,a[num].sex,a[num].college,a[num].event,a[num].point);
	printf("      |=======================================\n");//提示删除了哪条信息
	for(i=num;i<*p;i++)
		a[i]=a[i+1];//把被删除信息那栏之后的信息全往前一位赋值
	printf("(其它字符返回)输入X继续删除:");
	getchar();
	scanf("%c",&ch);
	if(toupper(ch)=='X')
		goto shanchu;}//语句跳到第42行实现多次删除
void data_change(struct list a[],int *p)//修改信息函数
{	int i,num,option,flag1=1,flag2=1;
	char ch,temp[30];
xiugai1:data_output(a,*p);//第136行goto语句目的地,实现持续修改信息
    printf("输入想修改的序号:");
	scanf("%d",&num);
	num--;
	printf("            |=======================================\n");
	printf("正在修改的是|%-8d%-8s%-8s%-8s%-8s%-8s\n",num+1,a[num].name,a[num].sex,a[num].college,a[num].event,a[num].point);
	printf("            |=======================================\n");
	do{
xiugai2:printf("想修改哪项信息:");//某条信息某个元素修改完成后goto语句目的地,实现反复修改某条信息内容
	    printf("|--1.姓名--2.性别--3.学院--4.项目--5.成绩--|\n请选择:");
    	scanf("%d",&option);
    	switch(option)
		{case 1:
			{printf("\n更改姓名为:");
			scanf("%s",&a[num].name);getchar();
			printf("\n(Y/N)是否继续修改该条信息:");
			scanf("%c",&ch);
			if(toupper(ch)=='Y')
			    goto xiugai2;//可以跳转到第67行，实现反复修改某条信息
			else if(toupper(ch)=='N')
				break;}
    	case 2:
			{printf("\n更改性别为:");
			scanf("%s",&a[num].sex);getchar();
			printf("\n(Y/N)是否继续修改该条信息:");
			scanf("%c",&ch);
			if(toupper(ch)=='Y')
			    goto xiugai2;//可以跳转到第67行，实现反复修改某条信息
			else if(toupper(ch)=='N')
				break;}
    	case 3:
			{gai_college:printf("\n更改学院为:");//第98行goto语句目的地
				scanf("%s",&temp);
				for(i=0;i<A;i++)
				{   if(strcmp(temp,college[i])==0)//判断用户是否输入了不存在设置中的名称，防止输入错误
					{    strcpy(a[num].college,temp);flag2=0;}}
	           	if(flag2)
				{	printf("无此学院,请输入学院:");
			    	out_college();//提示设置中有哪些学院
			     	goto gai_college;}//发现错误则跳转到第90行修改这项元素前重新输入
			 	getchar();
				printf("\n(Y/N)是否继续修改该条信息:");
				scanf("%c",&ch);
				if(toupper(ch)=='Y')
				    goto xiugai2;//可以跳转到第67行，实现反复修改某条信息
				else if(toupper(ch)=='N')
					break;}
    	case 4:
			{gai_event:printf("\n更改项目为:");//第115行goto语句目的地
				scanf("%s",&temp);
				for(i=0;i<B;i++)
				{   if(strcmp(temp,event[i])==0)
					{	strcpy(a[num].event,temp);flag2=0;}}
	           	if(flag2)//发现错误则跳转到第107行修改这项元素前重新输入,直到输入正确
				{	printf("无此项目,请输入项目:");
			    	out_event();//提示设置中有哪些项目
			     	goto gai_event;}
				getchar();
				printf("\n(Y/N)是否继续修改该条信息:");
				scanf("%c",&ch);
				if(toupper(ch)=='Y')
				    goto xiugai2;//跳转到第67行，实现反复修改某条信息
				else if(toupper(ch)=='N')
					break;}
    	case 5:
			{printf("\n更改成绩为:");
			scanf("%s",&a[num].point);getchar();
			printf("\n(Y/N)是否继续修改该条信息:");
			scanf("%c",&ch);
			if(toupper(ch)=='Y')
				goto xiugai2;//可以跳转到第67行，实现反复修改某条信息
			else if(toupper(ch)=='N')
				break;}
    	default:{printf("\n无效选项");flag1=0;}}}while(flag1==0);
	printf("\n(其它字符返回)输入X继续修改信息:");getchar();
	scanf("%c",&ch);
	if(toupper(ch)=='X')
		goto xiugai1;//跳转到第59行，实现修改多条信息
}
void data_check(struct list a[],int *p)//查询信息的函数
{	int flag=1,num,option,i;    //flag用于控制用户输入数字无效时重新选择查询条件
	struct list sort[N];        //option是用户输入的选项，num是按各种条件查询到的信息个数，用于传递给输出函数输出查询到的信息
	char temp[30]={"\0"};       //结构体sort用于存放按条件查询到的信息，传递给输出函数用于输出，temp是用户自己输入的查询具体内容，用以对比所有信息取出符合条件的信息。
	printf("|========================================|\n");
    printf("|----------1.姓名--------2.性别----------|\n");
	printf("|----------3.学院--------4.项目----------|\n");
	printf("|----------5.全部信息----6.返回----------|\n");
	printf("|========================================|\n");
	do{ num=0;
     	printf("输入数字选择查询条件:");
    	scanf("%d",&option);
    	switch(option)
		{case 1:
			{printf("输入所查询的姓名:");
	    	scanf("%s",temp);
		   	for(i=0;i<*p;i++)
		        if(strcmp(a[i].name,temp)==0)
				{	sort[num]=a[i];num++;}
	    	data_output(sort,num);break;}//输出按条件选择完的信息函数在第29行，data_output();
    	case 2:
			{printf("输入所查询的性别:");
			scanf("%s",temp);
			for(i=0;i<*p;i++)
		    	if(strcmp(a[i].sex,temp)==0)
				{	sort[num]=a[i];num++;}
	    	data_output(sort,num);break;}
    	case 3:
			{printf("输入所查询的学院:");
	    	scanf("%s",temp);
	     	for(i=0;i<*p;i++)
		        if(strcmp(a[i].college,temp)==0)
				{	sort[num]=a[i];num++;}
	    	data_output(sort,num);break;}
     	case 4:
			{printf("输入所查询的项目:");
	    	scanf("%s",temp);
	    	for(i=0;i<*p;i++)
		        if(strcmp(a[i].event,temp)==0)
				{	sort[num]=a[i];num++;}
	    	data_output(sort,num);break;}
	case 5:{data_output(a,*p);break;}
	case 6:break;
	default:{printf("\n无效选项\n");flag=0;}}}while(flag==0);
}
void data_add(struct list a[],int *p,int sign,int num)//录入信息函数，通过后两个的传递值可以控制变成插入函数
{	int i,flag1=1,flag2=1;//flag1控制整体录入的循环，flag2控制录入时输错学院名或项目名进行重新输入的循环
	int ren=*p;          //ren所有信息条数，录入的信息加在最后一条信息的后面
	char temp[30];       //temp是用户输入的学院和项目名，临时存放在temp中用于和设置中的所有学院、项目进行对比查看是否输错名称
	if(sign==0)
		ren=num;         //如果传递过来的sign值为0，则ren改为传递过来的num值改为插入，num是想把信息插入在第几条信息后的值
	do{printf("|====================开始录入====================|\n");
    	printf("\n姓名:");
    	scanf("%s",a[ren].name);
    	printf("性别:");
     	scanf("%s",a[ren].sex);
add_college:printf("学院:");//第203行goto语句目的地
    	scanf("%s",temp);
		for(i=0;i<A;i++)
		{	if(strcmp(college[i],temp)==0)
			{strcpy(a[ren].college,temp);//判断是否输入正确的学院、项目，直到输入正确
			flag2=0;}}
		if(flag2)
		{	printf("无此学院,请输入学院:");
			out_college();//提示设置中有哪些学院
			goto add_college;}//跳转到第194行重新输入
		flag2=1;
add_event:printf("项目:");
    	scanf("%s",temp);
		for(i=0;i<B;i++)
		{   if(strcmp(event[i],temp)==0)
			{strcpy(a[ren].event,temp);
			flag2=0;}}
		if(flag2)
		{	printf("无此项目,请输入项目:");
			out_event();
			goto add_event;}
		flag2=1;
    	printf("成绩:");
    	scanf("%s",a[ren].point);ren++;
		if(sign!=0)
        {	printf("(其它数字返回)输入0继续录入:");//控制是否继续录入
    		scanf("%d",&flag1);}
	}while(flag1==0);
	if(sign==0)//根据sign输出不同的提示信息，插入或是录入
	{	*p=*p+1;
    	printf("|====================插入完成====================|\n");}
	else
	{	*p=ren;
    	printf("|====================录入完成====================|\n");}
}
void data_insert(struct list a[],int *p)//插入函数
{
	int num,i,flag=1;
	data_output(a,*p);
	printf("想在第几条信息后插入:");
	scanf("%d",&num);
	num--;
	for(i=*p+1;i>=num;i--)
		a[i]=a[i-1];
	data_add(a,p,0,num);//调用录入函数完成要插入信息的录入
}
void data_save(struct list a[],int *p)//保存信息数据
{	int i;
	fp=fopen("data.txt","r+");
	if(fp==NULL)
	{printf("文件打开失败\n");exit(0);}
    for(i=0;i<=*p;i++)
		fprintf(fp,"%s %s %s %s %s\n",a[i].name,a[i].sex,a[i].college,a[i].event,a[i].point);
	fclose(fp);
	printf("|===================保存成功===================|\n");}
void data_load(struct list a[],int *p)//读取信息数据文件
{	int i=0,ren=0;
	fp=fopen("data.txt","r+");
	if(fp==NULL)
	{printf("文件打开失败\n");exit(0);}
	while(!feof(fp))
	{	fscanf(fp,"%s %s %s %s %s\n",&a[i].name,&a[i].sex,&a[i].college,&a[i].event,&a[i].point);
	    ren++;i++;}//读取的同时把人数从零开始自加
	fclose(fp);
	*p=ren;
	printf("|===================读取成功===================|\n");
}
void data(struct list a[],int *p)//参赛信息管理主界面
{	int flag=1,option;//flag控制选项有误时反复输入选项，option是用户输入的选项
	printf("|========================================|\n");
    printf("|------1.查询信息--------2.录入信息------|\n");
	printf("|------3.插入信息--------4.修改信息------|\n");
	printf("|------5.删除信息--------6.读取信息------|\n");
	printf("|------7.保存信息--------8.返回----------|\n");
	printf("|========================================|\n");
	do{	printf("请选择:");
     	scanf("%d",&option);
     	switch(option)
		{case 1:{data_check(a,p);break;}//查询信息，第138行
       	case 2:{data_add(a,p,1,1);break;}//1,1是因为此处不用改成插入函数，第三个函数参数可以控制是否转化为用于插入，第四个参数是用户键入要插入的位置，第183行
    	case 3:{data_insert(a,p);break;}//插入信息，第229行
    	case 4:{data_change(a,p);break;}//修改信息，第56行
    	case 5:{data_delete(a,p);break;}//删除信息，第37行
    	case 6:{data_load(a,p);break;}//从本地文件加载信息数据，第249行
    	case 7:{data_save(a,p);break;}//保存当前信息数据到本地文件，第240行
    	case 8:break;
    	default:{printf("\n无效选项\n");flag=0;}}}while(flag==0);
}
void set_check()//查看设置的学院、项目名称
{	printf("\n|=============当前设置如下=============|\n|学院有:");
	out_college();//输出现有的学院名
	printf("|项目有:");
	out_event();//输出现有的项目名
}
void set_change()//修改设置
{	int flag;//flag控制用户输入无效选项，循环输入选项
	char ch1,ch2;//ch1控制用户想修改的是学院还是项目；ch2做do-while循环条件，控制用户是否想继续修改。
	set_check();//输出当前设置，第282行
	do{	printf("修改学院输入X,修改项目输入Y:");
    	do{	flag=1;
	    	printf("\n请输入:");
	    	getchar();
        	scanf("%c",&ch1);
        	switch(toupper(ch1))
			{	case 'X':
				{	int j;
		        	printf("输入数字选择要修改的学院名称:");
		        	scanf("%d",&j);getchar();
		        	while(j<0||j>A)
					{printf("请在正确范围选择:");scanf("%d",&j);}
		        	printf("请输入新名称:");
		        	scanf("%s",&college[j-1]);
		     		set_check();
			    	break;}
            	case 'Y':
				{   int j;
		        	printf("输入数字选择要修改的项目名称:");
		        	scanf("%d",&j);getchar();
		         	while(j<0||j>B)
					{printf("请在正确范围选择:");scanf("%d",&j);}
		        	printf("请输入新名称:");
		        	scanf("%s",&event[j-1]);
			    	set_check();
					break;}
            	default:{printf("\n无效选项\n");flag=0;}}}while(flag==0);
    	printf("输入X继续修改，其他结束修改:");
    	getchar();
    	scanf("%c",&ch2);
	}while(toupper(ch2)=='X');
}
void set_load()//加载设置
{	int i;
	fp=fopen("setting.txt","r");
	if(fp==NULL)
	{printf("读取失败\n");exit(0);}
	for(i=0;i<A;i++)
		fscanf(fp,"%s\n",&college[i]);
	for(i=0;i<B;i++)
		fscanf(fp,"%s\n",&event[i]);
	fclose(fp);
	printf("|===================读取成功===================|\n");
	set_check();//输出当前设置，第282行
}
void set_save()//保存设置
{	int i;
	fp=fopen("setting.txt","w");
	if(fp==NULL)
	{printf("读取失败\n");exit(0);}
	for(i=0;i<A;i++)
		fprintf(fp,"%s\n",college[i]);
	for(i=0;i<B;i++)
		fprintf(fp,"%s\n",event[i]);
	fclose(fp);
	printf("|===================保存成功===================|\n");
	set_check();//输出当前设置，第282行
}
void setting()//设置信息的主界面
{	int flag=1,option;//flag控制选项有误时反复输入选项，option是用户输入的选项
	printf("\n|========================================|\n");
    printf("|----1.查看当前设置-----2.修改设置-------|\n");
	printf("|----3.读取设置---------4.保存设置-------|\n");
	printf("|----5.返回------------------------------|\n");
	printf("|========================================|\n");
	do{	printf("输入数字选择:");
    	scanf("%d",&option);
    	switch(option)
		{   case 1:{set_check();break;}//查看设置，第282行
        	case 2:{set_change();break;}//修改设置，第288行
         	case 3:{set_load();break;}//加载设置，第324行
        	case 4:{set_save();break;}//保存设置，第337行
        	case 5:break;
        	default:{printf("\n无效选项\n");flag=0;}}}while(flag==0);
}
void sort(struct list a[],int p,int sum[],int e_sum[][A])//将结构体数组进行按项目分类后按成绩排序，并统计各院获得积分的人数进行计算积分
{
	int i,j,q;//i，j，q为循环控制条件
	int e_num[B][A][5]={{0,0,0}};//每个项目中各个学院第1至第5名的人数
	struct event_data
	{	struct list data[N];};
	struct event_data haha[B]={"\0"};//每个项目中所包含的（男/女生)信息，嵌套结构体数组
	struct list temp;//进行排序用的临时结构体变量
	int num[B]={0};//每个项目中的（男/女）人数
	int p_num[A][5]={{0,0}};//每个学院第一至第五名的各个人数
	for(i=0;i<p;i++)//将每条（男/女生）信息分类到各个项目的结构体数组中去
		for(j=0;j<B;j++)
	    	if(strcmp(a[i].event,event[j])==0)
			{	haha[j].data[num[j]]=a[i];num[j]++;}
	for(i=0;i<B;i++)
		for(j=0;j<num[i]-1;j++)
	    	for(q=j+1;q<num[i];q++)//各项目人员按成绩进行排序
		    	if(strcmp(haha[i].data[j].point,haha[i].data[q].point)<0)
				{	temp=haha[i].data[j];
			    	haha[i].data[j]=haha[i].data[q];
			    	haha[i].data[q]=temp;}
	for(i=0;i<B;i++)
		for(j=0;j<num[i];j++)//统计每个项目里各个学院获得1至7积分的男女生人数
			for(q=0;q<A;q++)
		    	if(strcmp(haha[i].data[j].college,college[q])==0)
				{	p_num[q][j]++;e_num[i][q][j]++;}
	if(strcmp(a[i].sex,"男")==0)//计算积分
    	for(i=0;i<B;i++)
	    	for(j=0;j<A;j++)
		    	e_sum[i][j]=e_num[i][j][0]*7+e_num[i][j][1]*5+e_num[i][j][2]*3+e_num[i][j][3]*2+e_num[i][j][4]*1;
	if(strcmp(a[i].sex,"女")==0)
    	for(i=0;i<B;i++)
	    	for(j=0;j<A;j++)
		    	e_sum[i][j]=e_num[i][j][0]*5+e_num[i][j][1]*3+e_num[i][j][2]*2;
	if(strcmp(a[i].sex,"男")==0)
    	for(i=0;i<A;i++)
	    	sum[i]=p_num[i][0]*7+p_num[i][1]*5+p_num[i][2]*3+p_num[i][3]*2+p_num[i][4]*1;
	if(strcmp(a[i].sex,"女")==0)
    	for(i=0;i<A;i++)
	    	sum[i]=p_num[i][0]*5+p_num[i][1]*3+p_num[i][2]*2;
}
void chuli(struct list a[],int *p,struct for_sort hehe[],int sum[][A])//把所有信息分为男、女两部分，用第367行的自定义函数处理完后返回到此函数计算积分，
{                                                                     //a数组是所有信息，*p是信息条数，hehe是用后面方便每个院积分排序的结构体(各院积分在其中)
	int i,j=0,m=0,f=0;//i，j作循环条件，m和f是按男女分类时统计的男、女生人数    //sum[][]是每个项目中各院的积分
	int nan[A]={0};//各院的男生积分
	int nv[A]={0};//各院的女生积分
	int e_nan[B][A]={{0,0}};    //各个项目中各院的男生积分
	int e_nv[B][A]={{0,0}};    //各个项目中各院的女生积分
	struct list male[N]={"\0"};    //只含男生的参赛信息
	struct list female[N]={"\0"};    //女生参赛信息
	struct for_sort temp;    //排序用的临时结构体
	for(i=0;i<A;i++)
		strcpy(hehe[i].name,college[i]);//把院名复制到输出积分的结构体中
	for(i=0;i<*p;i++)//将所有信息按男女分成两个结构体数组，分开处理
	{	if(strcmp(a[i].sex,"男")==0)
		{	male[m]=a[i];m++;}
		if(strcmp(a[i].sex,"女")==0)
		{	female[f]=a[i];f++;}}
        sort(male,m,nan,e_nan);//在项目中按成绩进行排序，计算每个学院男生和女生各自获得的积分,此函数在第367行
        sort(female,f,nv,e_nv);
	for(i=0;i<A;i++)//把男女积分相加就是每个学院总积分。
		hehe[i].sum=(nan[i])+(nv[i]);
	for(i=0;i<A-1;i++)
		for(j=i+1;j<A;j++)//对计算完积分的学院进行排序
			if(hehe[i].sum<hehe[j].sum)
			{temp=hehe[i];hehe[i]=hehe[j];hehe[j]=temp;}
	for(i=0;i<B;i++)//把各个项目中各院的男女生积分分别相加，得到各个项目中各院获得的积分
		for(j=0;j<A;j++)
			sum[i][j]=e_nan[i][j]+e_nv[i][j];
}
void p_event(struct list a[],int *p)//输出各个项目中各院的得分情况
{	int i,j;//i，j控制循环
	int sum[B][A]={{0,0}};//每个项目中各院的积分情况二维数组
	struct for_sort hehe[A];//在此函数中无实际意义，为了填补chuli()函数中缺失的函数参数
	chuli(a,p,hehe,sum);//处理信息，此函数在第408行
	for(i=0;i<B;i++)
	{	printf("|%d.%s\n",i+1,event[i]);//输出各项目中各院得分情况
		for(j=0;j<A;j++)
			printf("|--%s---%d分\n",college[j],sum[i][j]);}
}
void p_college(struct list a[],int *p)//输出各院的积分排名
{	int i;
	struct for_sort hehe[A];//院名和对应积分的结构体，方便后续排序输出
	int sum[B][A]={{0,0}};//在此函数中无实际意义，为了填补chuli()函数中缺失的函数参数
	chuli(a,p,hehe,sum);
	printf("\n|============各院积分排名如下============|\n");
	for(i=0;i<A;i++)
    	printf("|======%d.%s--%d分\n",i+1,hehe[i].name,hehe[i].sum);
}
void points(struct list a[],int *p)//积分查看主界面
{
	int flag=1,option;//flag控制选项有误时反复输入选项，option是用户输入的选项
	printf("|========================================|\n");
   	printf("|------1.查看各院积分排名----------------|\n");
   	printf("|------2.各项目中各院得分情况------------|\n");
   	printf("|------3.返回----------------------------|\n");
   	printf("|========================================|\n");
	do{ printf("输入数字选择:");
    	scanf("%d",&option);
    	switch(option)
		{	case 1:{p_college(a,p);break;}//第448行，输出各院的积分排名
	    	case 2:{p_event(a,p);break;}//第437行，输出各个项目中各院的得分情况
         	case 3:break;
        	default:{printf("\n无效选项\n");flag=0;}}}while(flag==0);
}
int main()//主菜单界面
{	int flag=1,sign=1,ren=0,option;
	int *p=&ren;//ren是信息条数，结构体数组all存放信息
	struct list all[N];
	while(flag)
	{	printf("|========================================|\n");
    	printf("|-----------运动会比赛积分系统-----------|\n");
    	printf("|------1.积分查看--------2.数据管理------|\n");
    	printf("|------3.初始设置--------4.退出系统------|\n");
    	printf("|========================================|\n");
		do{	printf("输入数字选择:");
         	scanf("%d",&option);
        	switch(option)
			{	case 1:{points(all,p);break;}//积分查看，第458行
            	case 2:{data(all,p);break;}//数据管理，第261行
				case 3:{setting();break;}//设置管理，第350行
            	case 4:{flag=0;break;}
				default:{printf("\n无效选项\n");sign=0;}}}while(sign==0);}
	return 0;
}