//01排序_Sort
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
 
#define MAX_LENGTH_INSERT_SORT 7 /* 用于快速排序时判断是否选用插入排序阙值 */
 
typedef int Status; 
 
#define MAXSIZE 10000  /* 用于要排序数组个数最大值，可根据需要修改 */
typedef struct
{
	int r[MAXSIZE+1];	/* 用于存储要排序数组，r[0]用作哨兵或临时变量 */
	int length;			/* 用于记录顺序表的长度 */
}SqList;
 
/* 交换L中数组r的下标为i和j的值 */
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
 

 
/* 对顺序表L作冒泡排序 */
void BubbleSort(SqList *L)
{ 
	int i,j,count=0;
	for(i=1;i<L->length;i++)
	{
		for(j=L->length-1;j>=i;j--)  /* 注意j是从后往前循环 */
		{
			if(L->r[j]>L->r[j+1]) /* 若前者大于后者（注意这里与上一算法的差异）*/
			{
				 count+=3;
				 swap(L,j,j+1);/* 交换L->r[j]与L->r[j+1]的值 */
			}
		}
	}
	printf("移动次数为：%d\n",count);
}
 

 
/* 对顺序表L作简单选择排序 */
void SelectSort(SqList *L)
{
	int i,j,min,count=0;
	for(i=1;i<L->length;i++)
	{ 
		min = i;						/* 将当前下标定义为最小值下标 */
		for (j = i+1;j<=L->length;j++)/* 循环之后的数据 */
        {
			if (L->r[min]>L->r[j])	/* 如果有小于当前最小值的关键字 */
                min = j;				/* 将此关键字的下标赋值给min */
        }
		if(i!=min)						/* 若min不等于i，说明找到最小值，交换 */
			{swap(L,i,min);count+=3;	}			/* 交换L->r[i]与L->r[min]的值 */
	}printf("移动次数为：%d\n",count);
}
 
/* 对顺序表L作直接插入排序 */
void InsertSort(SqList *L)
{ 
	int i,j,count=0;
	for(i=2;i<=L->length;i++)
	{
		if (L->r[i]<L->r[i-1]) /* 需将L->r[i]插入有序子表 */
		{
			L->r[0]=L->r[i]; /* 设置哨兵 */
			for(j=i-1;L->r[j]>L->r[0];j--)
				{L->r[j+1]=L->r[j];count++;} /* 记录后移 */
			L->r[j+1]=L->r[0]; /* 插入到正确位置 */
		}
	}printf("移动次数为：%d\n",count);
}
 

 
 
/* 堆排序********************************** */
 
/* 已知L->r[s..m]中记录的关键字除L->r[s]之外均满足堆的定义， */
/* 本函数调整L->r[s]的关键字,使L->r[s..m]成为一个大顶堆 */
void HeapAdjust(SqList *L,int s,int m)
{ 
	int temp,j;
	temp=L->r[s];
	for(j=2*s;j<=m;j*=2) /* 沿关键字较大的孩子结点向下筛选 */
	{
		if(j<m && L->r[j]<L->r[j+1])
			++j; /* j为关键字中较大的记录的下标 */
		if(temp>=L->r[j])
			break; /* rc应插入在位置s上 */
		L->r[s]=L->r[j];
		s=j;
	}
	L->r[s]=temp; /* 插入 */
}
 
/*  对顺序表L进行堆排序 */int c=0;
void HeapSort(SqList *L)
{
	int i;
	for(i=L->length/2;i>0;i--) /*  把L中的r构建成一个大根堆 */
		 HeapAdjust(L,i,L->length);
 
	for(i=L->length;i>1;i--)
	{ 
		 swap(L,1,i);c+=3; /* 将堆顶记录和当前未经排序子序列的最后一个记录交换 */
		 HeapAdjust(L,1,i-1); /*  将L->r[1..i-1]重新调整为大根堆 */
	}
}
 
/* **************************************** */
 
 
/* 归并排序********************************** */
 
/* 将有序的SR[i..m]和SR[m+1..n]归并为有序的TR[i..n] */
void Merge(int SR[],int TR[],int i,int m,int n,int *count)
{
	int j,k,l;
	for(j=m+1,k=i;i<=m && j<=n;k++)	/* 将SR中记录由小到大地并入TR */
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
				*count+=1;}	/* 将剩余的SR[i..m]复制到TR */
	}
	if(j<=n)
	{
		for(l=0;l<=n-j;l++){
			TR[k+l]=SR[j+l];		/* 将剩余的SR[j..n]复制到TR */
	         	*count+=1;} 
	}
}
 
 
/* 递归法 */
/* 将SR[s..t]归并排序为TR1[s..t] */
void MSort(int SR[],int TR1[],int s, int t,int *count)
{
	int m;
	int TR2[MAXSIZE+1];
	if(s==t)
		TR1[s]=SR[s];
	else
	{
		m=(s+t)/2;				/* 将SR[s..t]平分为SR[s..m]和SR[m+1..t] */
		MSort(SR,TR2,s,m,count);		/* 递归地将SR[s..m]归并为有序的TR2[s..m] */
		MSort(SR,TR2,m+1,t,count);	/* 递归地将SR[m+1..t]归并为有序的TR2[m+1..t] */
		Merge(TR2,TR1,s,m,t,count);	/* 将TR2[s..m]和TR2[m+1..t]归并到TR1[s..t] */
	}
}
 
/* 对顺序表L作归并排序 */
void MergeSort(SqList *L)
{ 
    int count=0;
 	MSort(L->r,L->r,1,L->length,&count);
 	printf("移动次数为：%d\n",count);
}
 

 
/* **************************************** */
 
/* 快速排序******************************** */
 
/* 交换顺序表L中子表的记录，使枢轴记录到位，并返回其所在位置 */
/* 此时在它之前(后)的记录均不大(小)于它。 */
int Partition(SqList *L,int low,int high,int *count)
{ 
	int pivotkey;
 
	pivotkey=L->r[low]; /* 用子表的第一个记录作枢轴记录 */
	while(low<high) /*  从表的两端交替地向中间扫描 */
	{ 
		 while(low<high&&L->r[high]>=pivotkey)
			high--;
		 swap(L,low,high);(*count)+=3;/* 将比枢轴记录小的记录交换到低端 */
		 while(low<high&&L->r[low]<=pivotkey)
			low++;
		 swap(L,low,high);(*count)+=3;/* 将比枢轴记录大的记录交换到高端 */
	}
	return low; /* 返回枢轴所在位置 */
}
 
/* 对顺序表L中的子序列L->r[low..high]作快速排序 */
void QSort(SqList *L,int low,int high,int *count)
{ 
	int pivot;
	if(low<high)
	{
			pivot=Partition(L,low,high,count); /*  将L->r[low..high]一分为二，算出枢轴值pivot */
			QSort(L,low,pivot-1,count);		/*  对低子表递归排序 */
			QSort(L,pivot+1,high,count);		/*  对高子表递归排序 */
	}
}
 
/* 对顺序表L作快速排序 */
void QuickSort(SqList *L)
{ 
int count=0;
	QSort(L,1,L->length,&count);printf("移动次数为：%d\n",count);
}
 
/* **************************************** */
 

 

/* **************************************** */
int main()
{
	
	clock_t start, finish;
   double  duration;
   /* 测量一个事件持续的时间*/
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
   printf("排序前:\n");
   //print(l0);
   
 
   
    start = clock();
   printf("冒泡排序:\n");
   BubbleSort(&l1);
  // print(l1);
   finish = clock();
   duration = (double)(finish - start) / CLOCKS_PER_SEC;
   printf( "%f seconds\n", duration );
   
   
   
    start = clock();
   printf("选择排序:\n");
   SelectSort(&l3);
  // print(l3);
   finish = clock();
   duration = (double)(finish - start) / CLOCKS_PER_SEC;
   printf( "%f seconds\n", duration );
   
    start = clock();
   printf("直接插入排序:\n");
   InsertSort(&l4);
  // print(l4);
 finish = clock();
   duration = (double)(finish - start) / CLOCKS_PER_SEC;
   printf( "%f seconds\n", duration );
 
  
	 start = clock();
   printf("堆排序:\n");
   HeapSort(&l6);
  // print(l6);
  printf("移动次数为：%d\n",c);
   finish = clock();
   duration = (double)(finish - start) / CLOCKS_PER_SEC;
   printf( "%f seconds\n", duration );
   
  start = clock();
   printf("归并排序（递归）:\n");
   MergeSort(&l7);
   //print(l7);
 finish = clock();
   duration = (double)(finish - start) / CLOCKS_PER_SEC;
   printf( "%f seconds\n", duration );
 
  start = clock();
   printf("快速排序:\n");
   QuickSort(&l9);
  //print(l9);
 finish = clock();
   duration = (double)(finish - start) / CLOCKS_PER_SEC;
   printf( "%f seconds\n", duration );
 
  
	return 0;
}
