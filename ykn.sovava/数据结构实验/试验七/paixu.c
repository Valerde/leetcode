//01����_Sort
#include <stdio.h>    
#include <string.h>
#include <ctype.h>      
#include <stdlib.h>   
#include <io.h>  
#include <math.h>  
#include <time.h>
 
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
 
#define MAX_LENGTH_INSERT_SORT 7 /* ���ڿ�������ʱ�ж��Ƿ�ѡ�ò���������ֵ */
 
typedef int Status; 
 
#define MAXSIZE 10000  /* ����Ҫ��������������ֵ���ɸ�����Ҫ�޸� */
typedef struct
{
	int r[MAXSIZE+1];	/* ���ڴ洢Ҫ�������飬r[0]�����ڱ�����ʱ���� */
	int length;			/* ���ڼ�¼˳���ĳ��� */
}SqList;
 
/* ����L������r���±�Ϊi��j��ֵ */
void swap(SqList *L,int i,int j) 
{ 
	int temp=L->r[i]; 
	L->r[i]=L->r[j]; 
	L->r[j]=temp; 
}
 
void print(SqList L)
{
	int i;
	for(i=1;i<L.length;i++)
		printf("%d,",L.r[i]);
	printf("%d",L.r[i]);
	printf("\n");
}
 

 
/* ��˳���L��ð������ */
void BubbleSort(SqList *L)
{ 
	int i,j,count=0;
	for(i=1;i<L->length;i++)
	{
		for(j=L->length-1;j>=i;j--)  /* ע��j�ǴӺ���ǰѭ�� */
		{
			if(L->r[j]>L->r[j+1]) /* ��ǰ�ߴ��ں��ߣ�ע����������һ�㷨�Ĳ��죩*/
			{
				 count+=3;
				 swap(L,j,j+1);/* ����L->r[j]��L->r[j+1]��ֵ */
			}
		}
	}
	printf("�ƶ�����Ϊ��%d\n",count);
}
 

 
/* ��˳���L����ѡ������ */
void SelectSort(SqList *L)
{
	int i,j,min,count=0;
	for(i=1;i<L->length;i++)
	{ 
		min = i;						/* ����ǰ�±궨��Ϊ��Сֵ�±� */
		for (j = i+1;j<=L->length;j++)/* ѭ��֮������� */
        {
			if (L->r[min]>L->r[j])	/* �����С�ڵ�ǰ��Сֵ�Ĺؼ��� */
                min = j;				/* ���˹ؼ��ֵ��±긳ֵ��min */
        }
		if(i!=min)						/* ��min������i��˵���ҵ���Сֵ������ */
			{swap(L,i,min);count+=3;	}			/* ����L->r[i]��L->r[min]��ֵ */
	}printf("�ƶ�����Ϊ��%d\n",count);
}
 
/* ��˳���L��ֱ�Ӳ������� */
void InsertSort(SqList *L)
{ 
	int i,j,count=0;
	for(i=2;i<=L->length;i++)
	{
		if (L->r[i]<L->r[i-1]) /* �轫L->r[i]���������ӱ� */
		{
			L->r[0]=L->r[i]; /* �����ڱ� */
			for(j=i-1;L->r[j]>L->r[0];j--)
				{L->r[j+1]=L->r[j];count++;} /* ��¼���� */
			L->r[j+1]=L->r[0]; /* ���뵽��ȷλ�� */
		}
	}printf("�ƶ�����Ϊ��%d\n",count);
}
 

 
 
/* ������********************************** */
 
/* ��֪L->r[s..m]�м�¼�Ĺؼ��ֳ�L->r[s]֮�������ѵĶ��壬 */
/* ����������L->r[s]�Ĺؼ���,ʹL->r[s..m]��Ϊһ���󶥶� */
void HeapAdjust(SqList *L,int s,int m)
{ 
	int temp,j;
	temp=L->r[s];
	for(j=2*s;j<=m;j*=2) /* �عؼ��ֽϴ�ĺ��ӽ������ɸѡ */
	{
		if(j<m && L->r[j]<L->r[j+1])
			++j; /* jΪ�ؼ����нϴ�ļ�¼���±� */
		if(temp>=L->r[j])
			break; /* rcӦ������λ��s�� */
		L->r[s]=L->r[j];
		s=j;
	}
	L->r[s]=temp; /* ���� */
}
 
/*  ��˳���L���ж����� */int c=0;
void HeapSort(SqList *L)
{
	int i;
	for(i=L->length/2;i>0;i--) /*  ��L�е�r������һ������� */
		 HeapAdjust(L,i,L->length);
 
	for(i=L->length;i>1;i--)
	{ 
		 swap(L,1,i);c+=3; /* ���Ѷ���¼�͵�ǰδ�����������е����һ����¼���� */
		 HeapAdjust(L,1,i-1); /*  ��L->r[1..i-1]���µ���Ϊ����� */
	}
}
 
/* **************************************** */
 
 
/* �鲢����********************************** */
 
/* �������SR[i..m]��SR[m+1..n]�鲢Ϊ�����TR[i..n] */
void Merge(int SR[],int TR[],int i,int m,int n,int *count)
{
	int j,k,l;
	for(j=m+1,k=i;i<=m && j<=n;k++)	/* ��SR�м�¼��С����ز���TR */
	{
		if (SR[i]<SR[j])
			TR[k]=SR[i++];
		else
			TR[k]=SR[j++];
		*count+=1;
	}
	if(i<=m)
	{
		for(l=0;l<=m-i;l++){
			TR[k+l]=SR[i+l];
				*count+=1;}	/* ��ʣ���SR[i..m]���Ƶ�TR */
	}
	if(j<=n)
	{
		for(l=0;l<=n-j;l++){
			TR[k+l]=SR[j+l];		/* ��ʣ���SR[j..n]���Ƶ�TR */
	         	*count+=1;} 
	}
}
 
 
/* �ݹ鷨 */
/* ��SR[s..t]�鲢����ΪTR1[s..t] */
void MSort(int SR[],int TR1[],int s, int t,int *count)
{
	int m;
	int TR2[MAXSIZE+1];
	if(s==t)
		TR1[s]=SR[s];
	else
	{
		m=(s+t)/2;				/* ��SR[s..t]ƽ��ΪSR[s..m]��SR[m+1..t] */
		MSort(SR,TR2,s,m,count);		/* �ݹ�ؽ�SR[s..m]�鲢Ϊ�����TR2[s..m] */
		MSort(SR,TR2,m+1,t,count);	/* �ݹ�ؽ�SR[m+1..t]�鲢Ϊ�����TR2[m+1..t] */
		Merge(TR2,TR1,s,m,t,count);	/* ��TR2[s..m]��TR2[m+1..t]�鲢��TR1[s..t] */
	}
}
 
/* ��˳���L���鲢���� */
void MergeSort(SqList *L)
{ 
    int count=0;
 	MSort(L->r,L->r,1,L->length,&count);
 	printf("�ƶ�����Ϊ��%d\n",count);
}
 

 
/* **************************************** */
 
/* ��������******************************** */
 
/* ����˳���L���ӱ�ļ�¼��ʹ�����¼��λ��������������λ�� */
/* ��ʱ����֮ǰ(��)�ļ�¼������(С)������ */
int Partition(SqList *L,int low,int high,int *count)
{ 
	int pivotkey;
 
	pivotkey=L->r[low]; /* ���ӱ�ĵ�һ����¼�������¼ */
	while(low<high) /*  �ӱ�����˽�������м�ɨ�� */
	{ 
		 while(low<high&&L->r[high]>=pivotkey)
			high--;
		 swap(L,low,high);(*count)+=3;/* ���������¼С�ļ�¼�������Ͷ� */
		 while(low<high&&L->r[low]<=pivotkey)
			low++;
		 swap(L,low,high);(*count)+=3;/* ���������¼��ļ�¼�������߶� */
	}
	return low; /* ������������λ�� */
}
 
/* ��˳���L�е�������L->r[low..high]���������� */
void QSort(SqList *L,int low,int high,int *count)
{ 
	int pivot;
	if(low<high)
	{
			pivot=Partition(L,low,high,count); /*  ��L->r[low..high]һ��Ϊ�����������ֵpivot */
			QSort(L,low,pivot-1,count);		/*  �Ե��ӱ�ݹ����� */
			QSort(L,pivot+1,high,count);		/*  �Ը��ӱ�ݹ����� */
	}
}
 
/* ��˳���L���������� */
void QuickSort(SqList *L)
{ 
int count=0;
	QSort(L,1,L->length,&count);printf("�ƶ�����Ϊ��%d\n",count);
}
 
/* **************************************** */
 

 

/* **************************************** */
int main()
{
	
	clock_t start, finish;
   double  duration;
   /* ����һ���¼�������ʱ��*/
   start = clock();
  
   finish = clock();
   duration = (double)(finish - start) / CLOCKS_PER_SEC;	
   int i;
   int Max=10000;
   srand(time(0));  
   int d[Max];
	for(i=0;i<Max;i++)
		d[i]=rand()%100000+1;
   SqList l0,l1,l2,l3,l4,l5,l6,l7,l8,l9,l10;
   
   for(i=0;i<Max;i++)
     l0.r[i+1]=d[i];
   l0.length=Max;
   l1=l2=l3=l4=l5=l6=l7=l8=l9=l10=l0;
   printf("����ǰ:\n");
   //print(l0);
   
 
   
    start = clock();
   printf("ð������:\n");
   BubbleSort(&l1);
  // print(l1);
   finish = clock();
   duration = (double)(finish - start) / CLOCKS_PER_SEC;
   printf( "%f seconds\n", duration );
   
   
   
    start = clock();
   printf("ѡ������:\n");
   SelectSort(&l3);
  // print(l3);
   finish = clock();
   duration = (double)(finish - start) / CLOCKS_PER_SEC;
   printf( "%f seconds\n", duration );
   
    start = clock();
   printf("ֱ�Ӳ�������:\n");
   InsertSort(&l4);
  // print(l4);
 finish = clock();
   duration = (double)(finish - start) / CLOCKS_PER_SEC;
   printf( "%f seconds\n", duration );
 
  
	 start = clock();
   printf("������:\n");
   HeapSort(&l6);
  // print(l6);
  printf("�ƶ�����Ϊ��%d\n",c);
   finish = clock();
   duration = (double)(finish - start) / CLOCKS_PER_SEC;
   printf( "%f seconds\n", duration );
   
  start = clock();
   printf("�鲢���򣨵ݹ飩:\n");
   MergeSort(&l7);
   //print(l7);
 finish = clock();
   duration = (double)(finish - start) / CLOCKS_PER_SEC;
   printf( "%f seconds\n", duration );
 
  start = clock();
   printf("��������:\n");
   QuickSort(&l9);
  //print(l9);
 finish = clock();
   duration = (double)(finish - start) / CLOCKS_PER_SEC;
   printf( "%f seconds\n", duration );
 
  
	return 0;
}
