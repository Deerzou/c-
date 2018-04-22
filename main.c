#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#define M 36
//1002672  1002700

struct city//������ؽṹ��
{
    char type_name[60];//Ʒ����
    char fcity_name[60];//����������
    char tcity_name[60];//���������
    int time;//ʱЧ
    char way_type[60];//��·����
    float h_price;//�ػ��۸�
    float h_discount;//�ػ��ۿ�
    float l_price;//����۸�
    float l_discount;//����ۿ�
};

struct city c[100];//����ṹ��;

int main()
{
    clock_t start, finish;
     double Total_time1,Total_time2,Total_time3;
     printf("��ӭ������������ϵͳ��\n");
     printf("_________________________________________________________________________________________\n");
     FILE *fp;
     char filename[40];
     printf("�������ļ���:\n");
     gets(filename);
     fp=fopen(filename,"r");//���ļ�
     fseek(fp,72L,SEEK_SET);//���ļ��ڶ��п�ʼ��ȡ

     int i;
     printf("���������ڳ���:\n");
     for(i=0;i<100;i++)
     {
            fscanf(fp,"%s%s%s%d%s%f%f%f%f",c[i].type_name,c[i].fcity_name,c[i].tcity_name,
                   &c[i].time,c[i].way_type,&c[i].h_price,&c[i].h_discount,&c[i].l_price,&c[i].l_discount);
     }
     fclose(fp);

     printf("**************************************����һ************************************************\n");
     start=clock();
     printf("��������е�������˾��:\n");
     char zfcity_name[60];//Ӧ��Ѱ����
     scanf("%s",zfcity_name);
     int d,b;
     char tt[1000][50];
     for(i=0,d=0;i<M;i++)
    {
        if(strcmp(zfcity_name,c[i].fcity_name)==0)//�Ƚϳ�������
        {
            d++;
            if(d==1)
            {
                printf("%s\n",tt[1]);
            }
            else
            {
              for(b=1;b<d;b++)
              {
                if((strcmp(c[i].type_name,tt[b]))==0)
                {
                   break;
                }
              }
              if(b>=d)
              {
                  strcpy(tt[b],c[i].type_name);
                  printf("%s\n",tt[b]);
              }
            }
        }
    }
     finish = clock();
     Total_time1= (double)(finish-start) / CLOCKS_PER_SEC;
     printf( "%f seconds/n", Total_time1);//�������һ��ʱ
     printf("\n");

     printf("****************************************���ܶ�**********************************************\n");
     start = clock();
     printf("����������������:\n");
     char ztcity_name[60];
     scanf("%s",ztcity_name);
     printf("-----------------------------------------------------------------------------------------\n");
     printf("Ʒ��      |��·����             |�ػ�����               |�������\n");
     printf("-----------------------------------------------------------------------------------------\n");
     for(i=0;i<M;i++)
     {
         if(strcmp(zfcity_name,c[i].fcity_name)==0)
         if(strcmp(ztcity_name,c[i].tcity_name)==0)
         {
             printf("%-10s| %-20s|%-10f\t|%-10f\n",
                    c[i].type_name,c[i].way_type,c[i].h_price*c[i].h_discount/10,c[i].l_price*c[i].l_discount/10);
             printf("-----------------------------------------------------------------------------------------\n");
         }
     }
     finish = clock();
     Total_time2= (double)(finish-start) / CLOCKS_PER_SEC;
     printf( "%f seconds/n", Total_time2);//������ܶ���ʱ
     printf("\n");

     printf("****************************************������**********************************************\n");
     start = clock();
     printf("�������������:\n");
     int weight;//�����������
     scanf("%d kg",&weight);
     printf("�������������:\n");
     char type[10];//�����������
     scanf("%s",type);
     printf("------------------------------------------------------------\n");
     printf("Ʒ��      |��·����             |�۸�\n");
     printf("------------------------------------------------------------\n");
     for(i=0;i<M;i++)//����֪���������뵽����е������£�������ͼ۸�
     {
         if(strcmp(zfcity_name,c[i].fcity_name)==0)
         if(strcmp(ztcity_name,c[i].tcity_name)==0)
         {
             if(strcmp(type,"�ػ�")==0)
             {
                  printf("%-10s| %-20s|%-10f\n",c[i].type_name,c[i].way_type,weight*c[i].h_price*c[i].h_discount/10);
                  printf("------------------------------------------------------------\n");
             }

             else if(strcmp(type,"���")==0)
                printf("%s  ����ѡ�� %s  ������,���ͼ۸�Ϊ:%f\n",c[i].type_name,c[i].way_type,weight*c[i].l_price*c[i].l_discount/10);
             else
                printf("û���������͵Ļ���Ŷ\n");
         }
     }
     finish = clock();
     Total_time3= (double)(finish-start) / CLOCKS_PER_SEC;
     printf( "%f seconds/n", Total_time3);//�����������ʱ
     printf("\n");

     printf("********************************ѡ������һ*****************************************************\n");
     start=clock();
     double Total_time4,Total_time5;
     printf("���Ƿ�Ҫ������������ʽ�Ƽ���\n");
     char w[4];
     scanf("%s",w);
     if(strcmp(w,"No")==0) return 0;
     else ;
     float price[50]={0};
     int count=0;
     for(i=0;i<M;i++)
     {
         if(strcmp(zfcity_name,c[i].fcity_name)==0)
         if(strcmp(ztcity_name,c[i].tcity_name)==0)
         {
             if(strcmp(type,"�ػ�")==0)
             {
                 price[i]=weight*c[i].h_price*c[i].h_discount/10;
                 count++;
             }
             if(strcmp(type,"���")==0)
             {
                 price[i]=weight*c[i].l_price*c[i].l_discount/10;
                 count++;
             }
         }
     }
     int k=0;
     for(i=0;i<M;i++)
     {
         if(strcmp(zfcity_name,c[i].fcity_name)==0)
         if(strcmp(ztcity_name,c[i].tcity_name)==0)
         {
             k=i;
             break;
         }
     }
     float min;
     for(i=k;i<count;i++)
        if(min>price[i])
            min=price[i];
     printf("��ϵͳ�����жϣ�������ѷ����ǣ�%sƷ��  %s��·����\n",c[i].type_name,c[i].way_type);
     finish = clock();
     Total_time4= (double)(finish-start) / CLOCKS_PER_SEC;
     printf( "%f seconds/n", Total_time4);//���ѡ������һ��ʱ
     printf("\n");

     printf("********************************ѡ�����ܶ�*****************************************************\n");
     start = clock();
     printf("���Ƿ�Ҫ����ʱЧ�Ż���\n");
     char m[4];
     scanf("%s",m);
     if(strcmp(m,"No")==0) return 0;
     else ;
     int t=10000;
     for(i=k;i<count;i++);
         if((t>c[i].time)&&(c[i].time!=0))
            t=c[i].time;
     printf("ʱЧ����ʱΪ%d����ʱ�������ѡ���ǣ�%sƷ��  %s��·����\n",c[i].time,c[i].type_name,c[i].way_type);
     finish = clock();
     Total_time5= (double)(finish-start) / CLOCKS_PER_SEC;
     printf( "%f seconds/n", Total_time5);//���ѡ�����ܶ���ʱ
     printf("\n");
     system("pause");
return 0;
}
