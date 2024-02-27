#include<stdio.h>
#include<stdlib.h>     /*标准库函数的定义*/
#include<string.h>     /*调用字符串处理文件*/
struct ac_conditioner     //定义结构体ac_conditioner 
#define N 4
{
	int num;                                 
	char pinpai[10];      /*空调品牌*/             
	char xinghao[10];     /*空调型号*/
	char leibie[10];      /*空调类别*/
	char xsy[10];         /*销售员*/
	float power;          /*功率*/
	float danjia;          /*单价*/                     
	float xssl;          /*销售数量*/
};
void in_record();                             //声明各自定义函数
void out_record();
void search1();
void search2();
void revise_xinghao();
void revise_delete();
void xssl_sort();
int count=N;


 int menu()             /*菜单界面*/
{
	int a;                                                          //定义int型函数a进行对菜单的操作
	printf("-----------空调销售信息管理-----------\n");             //多条printf语句组成互交界面
	printf("|        1.录入销售信息              |\n");
	printf("|        2.显示销售信息              |\n");
	printf("|        3.查询空调信息              |\n");
    printf("|        4.修改删除信息              |\n");
    printf("|        5.按销售数量升序排序        |\n");
	printf("|        7.退出程序                  |\n");
	printf("--------------------------------------\n");
	printf("请选择 1--7:");
	scanf("%d",&a);
	return a;
 }
 struct ac_conditioner ac[10];
 //定义录入空调信息子函数

 void in_record()        //录入信息
 {
	 int i;                                              //定义int型变量i用于for循环中循
	      for(i=0;i<count;i++)                               //环条件，后在循环中符合if语句判断
		  {                                              //时进行printf语句提示和scanf语句
			  printf("请输入空调序号:",i+1);             //对结构体数据进行手动输入。
			  scanf("%d",&ac[i].num);
			  printf("请输入空调品牌:",i+1);
			  scanf("%s",ac[i].pinpai);
			  printf("请输入空调型号:",i+1);
			  scanf("%s",ac[i].xinghao);
			  printf("请输入空调类别:",i+1);
			  scanf("%s",ac[i].leibie);
			  printf("请输入空调销售员:",i+1);
			  scanf("%s",ac[i].xsy);
			  printf("请输入空调功率(P):",i+1);
			  scanf("%f",&ac[i].power);
			  printf("请输入空调单价:",i+1);
			  scanf("%f",&ac[i].danjia);
			  printf("请输入空调销售数量:",i+1);
			  scanf("%f",&ac[i].xssl);
		  }
 }

//定义空调输出子函数
 void out_record()                  //自定义输出函数，直接读取文件数据，输出全部结构体数据
 {	
	 int i;
	 printf("序号\t品牌\t型号\t类别\t销售员\t功率(P)\t单价\t数量\n");
		 for(i=0;i<count;i++)
		 
			 {
			  printf("%d\t",ac[i].num);
			  printf("%s\t",ac[i].pinpai);
			  printf("%s\t",ac[i].xinghao);
			  printf("%s\t",ac[i].leibie);
			  printf("%s\t",ac[i].xsy);
			  printf("%.0f\t",ac[i].power);
			  printf("%.0f\t",ac[i].danjia);
			  printf("%.0f\t",ac[i].xssl);
			  printf("\n");
			 }
 }
//查询菜单界面
 int menu2()               
{
    int b;
	printf("|   1.按型号查询空调销售基本信息   |\n");
	printf("|   2.按型号查询空调销售总金额     |\n");
	printf("请输入所需功能的数字：");
	scanf("%d",&b);
	return b;
};
 int inquiry()          /*查询模块*/
{	
 int inq;
 while(1)
 {
  inq=menu2();
   switch(inq)
   {
      case 1:search1();break;           
      case 2:search2();break; 
      case 3:;break;
      case 4:;break;
      case 5:;break;
      case 6:;break;
      case 7:exit(0);
   };
     return inq;
 };
};


 //按型号查询空调销售基本信息
 void search1()
{
	int i;
	char xh[10];
	printf("请输入要查找的型号：");
	scanf("%s",xh);
	printf("序号\t品牌\t型号\t类别\t销售员\t功率(P)\t单价\t数量\n");
		for(i=0;i<count;i++)
		{
			if (strcmp(xh,ac[i].xinghao)==0)     //字符型的选择语句                
			{
			  printf("%d\t",ac[i].num);                       
			  printf("%s\t",ac[i].pinpai);
			  printf("%s\t",ac[i].xinghao);
			  printf("%s\t",ac[i].leibie);
			  printf("%s\t",ac[i].xsy);
			  printf("%.0f\t",ac[i].power);
			  printf("%.0f\t",ac[i].danjia);
			  printf("%.0f\t",ac[i].xssl);
			  printf("\n");
			}
		}

}

 //按型号查询空调销售总金额
 float main1(float x,float y)                                    //对main1函数的申明  //函数的调用，实参把数据传递给形参
 {
   float z;                                                      //用乘法求销售总金额
	 z=x*y;
   return z;                                                     //返回z的值到main1函数，当调用main1函数时，相当与调用z
 }
  void search2()
 {
   int i;
	char xh[10];
	printf("请输入要查找的型号：");
	scanf("%s",xh);
	printf("序号\t型号\t销售总金额\n");
		for(i=0;i<count;i++)
		{
			if (strcmp(xh,ac[i].xinghao)==0)
			{
			  printf("%d\t",ac[i].num);
			  printf("%s\t",ac[i].xinghao);
              printf("%.0f\t",main1(ac[i].danjia,ac[i].xssl));      //对main1函数的调用，使用返回值z
			  printf("\n");
			}
		}
 }

int revise()//修改目录
{ 
	int f;
    printf("|   1.输入型号修改信息   |\n");
    printf("|   2.输入型号删除信息   |\n");
    printf("请输入所需功能的数字：");
    scanf("%d",&f);
    while(1)
	{  
	  switch(f)                 //修改菜单目录使用switch语句跳转到修改和删除的自定义函数
	  {  
		   case 1:revise_xinghao();break;            
           case 2:revise_delete();break;              
           case 7:exit(0);
	  }
      return f;
	} 
}

void revise_xinghao()//按型号修改
{  int i;                                                             //自定义修改和删除函数中手动输入销售单价，
   char xinghao[10];                                                  //用for循环语句进行if条件语句进行strcmp字符型比较，
   printf("请输入要修改的空调型号：");                                //当两个字符型变量相同时输出相应空调信息，
   scanf("%s",xinghao);                                               //并对该信息进行修改相应数据或者删除整条数据，
   for(i=0;i<count;i++)
   {  
	 if(strcmp(xinghao,ac[i].xinghao)==0)
	 {  printf("修改前空调销售信息：\n");
          printf("序号：%d\n品牌：%s\n型号：%s\n单价:%.0f\n",
	             ac[i].num,ac[i].pinpai,ac[i].xinghao,ac[i].danjia);
          printf("请输入要修改的销售单价：\n");
          scanf("%f",&ac[i].danjia);
          printf("修改后的空调销售信息：\n");
          printf("序号：%d\n品牌：%s\n型号：%s\n单价:%.0f\n",
	             ac[i].num,ac[i].pinpai,ac[i].xinghao,ac[i].danjia);
	 }
   } 
   
}

void revise_delete()//按型号删除
{
  int i,k;
  char xinghao[10];
  printf("请输入要删除的空调型号：");
  scanf("%s",xinghao);
  for(i=0;i<count;i++)
  {
      if(strcmp(xinghao,ac[i].xinghao)==0)
	  {
		  k=i;                         //记录下来要删除的记录的位置
        for(k=i;k<count;k++)
	     	ac[k]=ac[k+1];           //互换变量	 结构体位置移动               
		}
  }
         count--;
         printf("删除成功\n");
}


void xssl_sort()  //按销售数量升序排序
{
 struct ac_conditioner zz;   //定义结构体
 int i,j;
 float sum=0;                               //利用for循环进行if条件进行替换数据实现由小到大排序
 for(i=0;i<count-1;i++)                   //外层循环几个数比几-1次，就是整个循环，循环多少次
   for(j=0;j<count-1;j++)                 //里层循环两两比较，冒泡排序，小值上浮，大值下沉
   if(ac[j].xssl>ac[j+1].xssl)            //前者比后者，若前者大，交换位置，反之，不变      
   {
    zz=ac[j];
    ac[j]=ac[j+1];                       //记录互换
    ac[j+1]=zz;
  
 }
   printf("序号\t品牌\t型号\t类别\t销售员\t功率(P)\t单价\t数量\n");
   for(i=0;i<count;i++)
   {
     sum=sum+ac[i].xssl;//统计销售数量                              //在循环中进行销售数量的累加
     printf("%d\t%s\t%s\t%s\t%s\t%.0f\t%.0f\t%.0f\t\n",
	        ac[i].num,ac[i].pinpai,ac[i].xinghao,ac[i].leibie,ac[i].xsy,ac[i].power,ac[i].danjia,ac[i].xssl);
   }
  printf("全空调总销售数量为：%.0f\n",sum);
}



 //主函数
 void main()                          //提交a值到switch语句中进行对自定义函数的跳转，
 {                                    //实现功能的连接。
	 int choice;
	 while(1)
	 {
		 choice=menu();
		 switch(choice)
		 {
		 case 1:in_record();break;
		 case 2:out_record();break;
		 case 3:inquiry();break;
		 case 4:revise();break;
		 case 5:xssl_sort();break;
		 case 7:exit(0);
		 }
	 }
 }