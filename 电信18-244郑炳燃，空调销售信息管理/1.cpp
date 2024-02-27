#include<stdio.h>
#include<stdlib.h>     /*��׼�⺯���Ķ���*/
#include<string.h>     /*�����ַ��������ļ�*/
struct ac_conditioner     //����ṹ��ac_conditioner 
#define N 4
{
	int num;                                 
	char pinpai[10];      /*�յ�Ʒ��*/             
	char xinghao[10];     /*�յ��ͺ�*/
	char leibie[10];      /*�յ����*/
	char xsy[10];         /*����Ա*/
	float power;          /*����*/
	float danjia;          /*����*/                     
	float xssl;          /*��������*/
};
void in_record();                             //�������Զ��庯��
void out_record();
void search1();
void search2();
void revise_xinghao();
void revise_delete();
void xssl_sort();
int count=N;


 int menu()             /*�˵�����*/
{
	int a;                                                          //����int�ͺ���a���жԲ˵��Ĳ���
	printf("-----------�յ�������Ϣ����-----------\n");             //����printf�����ɻ�������
	printf("|        1.¼��������Ϣ              |\n");
	printf("|        2.��ʾ������Ϣ              |\n");
	printf("|        3.��ѯ�յ���Ϣ              |\n");
    printf("|        4.�޸�ɾ����Ϣ              |\n");
    printf("|        5.������������������        |\n");
	printf("|        7.�˳�����                  |\n");
	printf("--------------------------------------\n");
	printf("��ѡ�� 1--7:");
	scanf("%d",&a);
	return a;
 }
 struct ac_conditioner ac[10];
 //����¼��յ���Ϣ�Ӻ���

 void in_record()        //¼����Ϣ
 {
	 int i;                                              //����int�ͱ���i����forѭ����ѭ
	      for(i=0;i<count;i++)                               //������������ѭ���з���if����ж�
		  {                                              //ʱ����printf�����ʾ��scanf���
			  printf("������յ����:",i+1);             //�Խṹ�����ݽ����ֶ����롣
			  scanf("%d",&ac[i].num);
			  printf("������յ�Ʒ��:",i+1);
			  scanf("%s",ac[i].pinpai);
			  printf("������յ��ͺ�:",i+1);
			  scanf("%s",ac[i].xinghao);
			  printf("������յ����:",i+1);
			  scanf("%s",ac[i].leibie);
			  printf("������յ�����Ա:",i+1);
			  scanf("%s",ac[i].xsy);
			  printf("������յ�����(P):",i+1);
			  scanf("%f",&ac[i].power);
			  printf("������յ�����:",i+1);
			  scanf("%f",&ac[i].danjia);
			  printf("������յ���������:",i+1);
			  scanf("%f",&ac[i].xssl);
		  }
 }

//����յ�����Ӻ���
 void out_record()                  //�Զ������������ֱ�Ӷ�ȡ�ļ����ݣ����ȫ���ṹ������
 {	
	 int i;
	 printf("���\tƷ��\t�ͺ�\t���\t����Ա\t����(P)\t����\t����\n");
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
//��ѯ�˵�����
 int menu2()               
{
    int b;
	printf("|   1.���ͺŲ�ѯ�յ����ۻ�����Ϣ   |\n");
	printf("|   2.���ͺŲ�ѯ�յ������ܽ��     |\n");
	printf("���������蹦�ܵ����֣�");
	scanf("%d",&b);
	return b;
};
 int inquiry()          /*��ѯģ��*/
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


 //���ͺŲ�ѯ�յ����ۻ�����Ϣ
 void search1()
{
	int i;
	char xh[10];
	printf("������Ҫ���ҵ��ͺţ�");
	scanf("%s",xh);
	printf("���\tƷ��\t�ͺ�\t���\t����Ա\t����(P)\t����\t����\n");
		for(i=0;i<count;i++)
		{
			if (strcmp(xh,ac[i].xinghao)==0)     //�ַ��͵�ѡ�����                
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

 //���ͺŲ�ѯ�յ������ܽ��
 float main1(float x,float y)                                    //��main1����������  //�����ĵ��ã�ʵ�ΰ����ݴ��ݸ��β�
 {
   float z;                                                      //�ó˷��������ܽ��
	 z=x*y;
   return z;                                                     //����z��ֵ��main1������������main1����ʱ���൱�����z
 }
  void search2()
 {
   int i;
	char xh[10];
	printf("������Ҫ���ҵ��ͺţ�");
	scanf("%s",xh);
	printf("���\t�ͺ�\t�����ܽ��\n");
		for(i=0;i<count;i++)
		{
			if (strcmp(xh,ac[i].xinghao)==0)
			{
			  printf("%d\t",ac[i].num);
			  printf("%s\t",ac[i].xinghao);
              printf("%.0f\t",main1(ac[i].danjia,ac[i].xssl));      //��main1�����ĵ��ã�ʹ�÷���ֵz
			  printf("\n");
			}
		}
 }

int revise()//�޸�Ŀ¼
{ 
	int f;
    printf("|   1.�����ͺ��޸���Ϣ   |\n");
    printf("|   2.�����ͺ�ɾ����Ϣ   |\n");
    printf("���������蹦�ܵ����֣�");
    scanf("%d",&f);
    while(1)
	{  
	  switch(f)                 //�޸Ĳ˵�Ŀ¼ʹ��switch�����ת���޸ĺ�ɾ�����Զ��庯��
	  {  
		   case 1:revise_xinghao();break;            
           case 2:revise_delete();break;              
           case 7:exit(0);
	  }
      return f;
	} 
}

void revise_xinghao()//���ͺ��޸�
{  int i;                                                             //�Զ����޸ĺ�ɾ���������ֶ��������۵��ۣ�
   char xinghao[10];                                                  //��forѭ��������if����������strcmp�ַ��ͱȽϣ�
   printf("������Ҫ�޸ĵĿյ��ͺţ�");                                //�������ַ��ͱ�����ͬʱ�����Ӧ�յ���Ϣ��
   scanf("%s",xinghao);                                               //���Ը���Ϣ�����޸���Ӧ���ݻ���ɾ���������ݣ�
   for(i=0;i<count;i++)
   {  
	 if(strcmp(xinghao,ac[i].xinghao)==0)
	 {  printf("�޸�ǰ�յ�������Ϣ��\n");
          printf("��ţ�%d\nƷ�ƣ�%s\n�ͺţ�%s\n����:%.0f\n",
	             ac[i].num,ac[i].pinpai,ac[i].xinghao,ac[i].danjia);
          printf("������Ҫ�޸ĵ����۵��ۣ�\n");
          scanf("%f",&ac[i].danjia);
          printf("�޸ĺ�Ŀյ�������Ϣ��\n");
          printf("��ţ�%d\nƷ�ƣ�%s\n�ͺţ�%s\n����:%.0f\n",
	             ac[i].num,ac[i].pinpai,ac[i].xinghao,ac[i].danjia);
	 }
   } 
   
}

void revise_delete()//���ͺ�ɾ��
{
  int i,k;
  char xinghao[10];
  printf("������Ҫɾ���Ŀյ��ͺţ�");
  scanf("%s",xinghao);
  for(i=0;i<count;i++)
  {
      if(strcmp(xinghao,ac[i].xinghao)==0)
	  {
		  k=i;                         //��¼����Ҫɾ���ļ�¼��λ��
        for(k=i;k<count;k++)
	     	ac[k]=ac[k+1];           //��������	 �ṹ��λ���ƶ�               
		}
  }
         count--;
         printf("ɾ���ɹ�\n");
}


void xssl_sort()  //������������������
{
 struct ac_conditioner zz;   //����ṹ��
 int i,j;
 float sum=0;                               //����forѭ������if���������滻����ʵ����С��������
 for(i=0;i<count-1;i++)                   //���ѭ���������ȼ�-1�Σ���������ѭ����ѭ�����ٴ�
   for(j=0;j<count-1;j++)                 //���ѭ�������Ƚϣ�ð������Сֵ�ϸ�����ֵ�³�
   if(ac[j].xssl>ac[j+1].xssl)            //ǰ�߱Ⱥ��ߣ���ǰ�ߴ󣬽���λ�ã���֮������      
   {
    zz=ac[j];
    ac[j]=ac[j+1];                       //��¼����
    ac[j+1]=zz;
  
 }
   printf("���\tƷ��\t�ͺ�\t���\t����Ա\t����(P)\t����\t����\n");
   for(i=0;i<count;i++)
   {
     sum=sum+ac[i].xssl;//ͳ����������                              //��ѭ���н��������������ۼ�
     printf("%d\t%s\t%s\t%s\t%s\t%.0f\t%.0f\t%.0f\t\n",
	        ac[i].num,ac[i].pinpai,ac[i].xinghao,ac[i].leibie,ac[i].xsy,ac[i].power,ac[i].danjia,ac[i].xssl);
   }
  printf("ȫ�յ�����������Ϊ��%.0f\n",sum);
}



 //������
 void main()                          //�ύaֵ��switch����н��ж��Զ��庯������ת��
 {                                    //ʵ�ֹ��ܵ����ӡ�
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