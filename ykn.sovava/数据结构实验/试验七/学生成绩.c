#include <stdio.h>
#include <stdlib.h>
#define MaxLength 255
 
//数据元素
typedef struct {
	int id;//学号
	char name[20];//姓名
	int score[3];//数电、模电、数据结构的成绩
	int total;//总成绩
}studentElement;
 
//顺序表结构
typedef struct {
	studentElement gra[MaxLength];
	int length;
}seqList; 
//初始化（输入学生人数建立线性表长度，录入每个学生的各科成绩信息，计算出每个人总成绩）。
int InitList(seqList*seqList){
	int length=0;
	int i=0;
	int total=0;
	int j=0;
	printf("输入学生人数：");
	scanf("%d",&length);
	if(length<0||length>MaxLength){
		printf("输入的学生人数不符合");
	}else{
		seqList->length=length;
	}
	if(seqList->length<0||seqList->length>MaxLength){
		printf("初始化学生人数失败！\n");
		return 0;
	}else{
		for(i=0;i<length;i++){//输入每个学生的信息
			seqList->gra[i].total=0;//每个学生的确立之前总成绩归零
			printf("输入第%d个人的信息:\n",i+1);
			//输入学号和姓名
			printf("学号：\n");
			scanf("%d",&seqList->gra[i].id);
			printf("姓名：\n");
			scanf("%s",&seqList->gra[i].name);
			//输入 数电、模电、数据结构的成绩
			printf("数电：\n");
			scanf("%d",&seqList->gra[i].score[0]);
			printf("模电：\n");
			scanf("%d",&seqList->gra[i].score[1]);
			printf("数据结构：\n");
			scanf("%d",&seqList->gra[i].score[2]);
			printf("\n第%d个同学插入操作完毕！\n\n",i+1);
			for(j=0;j<3;j++){//计算每个学生的总成绩
				seqList->gra[i].total+=seqList->gra[i].score[j];
			}
		}
	}
	return 0;
};
 
 
//排序（首先输入要对所有人成绩排序的科目后按照升序排列，最后打印显示排序后的所有人成绩表。）
int Sort(seqList *seqList){
	int option=0;
	int i=0,j=0;
	studentElement temp;
	printf("开始排序......\n\n数电输入0，模电输入1,数据结构则输入2，总成绩输入3 \n");
	printf("输入基于排序分数的科目:");
	scanf("%d",&option);
	if(option<4||option>=0){
		//安装某科成绩升序排列
		if(option>=0&&option<3){
			for(i=0;i<seqList->length-1;i++){
				for(j=i+1;j<seqList->length;j++){
					if(seqList->gra[i].score[option]>seqList->gra[j].score[option]){
						temp=seqList->gra[i];
						seqList->gra[i]=seqList->gra[j];
						seqList->gra[j]=temp;
					}
				}
			}
			printf("\n\n按某科成绩排序操作完毕\n");
		}
		//安装某科成绩升序排列
		if(option==3){
			for(i=0;i<seqList->length-1;i++){
				for(j=i+1;j<seqList->length;j++){
					if(seqList->gra[i].total>seqList->gra[j].total){
						temp=seqList->gra[i];
						seqList->gra[i]=seqList->gra[j];
						seqList->gra[j]=temp;
					}
				}
			}
			printf("\n按总成绩排序操作完毕");
		}
	}else{
		printf("输入不正确！！！");
	}
	return 0;
};
 
 
//查询（输入学号，将线性表中的每个学生的学号与给定的字符串相比较
//若有匹配则打印显示该学生多所有信息，否则出错误提示）。
int Puery(seqList *seqList){
	int id=0;
	int i=0;
	printf("输入学号即可查询该生的所有信息：");
	scanf("%d",&id);
	if(id<0){
		printf("\n学号不存在查询失败！\n\n");
	}else{
		for(i=0;i<sizeof(seqList->length);i++){//打印输出各学生的全部信息
			if(id==seqList->gra[i].id){
				printf("学号：%d\n姓名：%s\n数电：%d\n模电：%d\n数据结构：%d\n总分：%d\n\n恭喜！查询成功！\n\n",\
					seqList->gra[i].id,\
					seqList->gra[i].name,\
					seqList->gra[i].score[0],\
					seqList->gra[i].score[1],\
					seqList->gra[i].score[2],\
					seqList->gra[i].total);
			}
		}
	}
 
	return 0;
};
 
 
//输出所有信息
int Print(seqList *seqList){
	int i=0;
	for(i=seqList->length-1;i>=0;i--){
		printf("学号：%d\t姓名：%s\t数电：%d\t模电：%d\t数据结构：%d\t总分：%d\t\n",\
			seqList->gra[i].id,\
			seqList->gra[i].name,\
			seqList->gra[i].score[0],\
			seqList->gra[i].score[1],\
			seqList->gra[i].score[2],\
			seqList->gra[i].total);
	}
	printf("\n打印完毕！\n");
	return 0;
}
 
int main(){
	seqList SL;
	InitList(&SL);
	int key; 
	printf("排序前：\n");
	Print(&SL);
	printf("输入1表示排序，输入2表示查找:"); 
    scanf("%d",&key);
	while(key){
		switch(key){
			case 1:	Sort(&SL);
			printf("排序后：\n");
	        Print(&SL);
		    printf("\n");
            break;
            case 2:	Puery(&SL);break;
		}
    printf("输入1表示排序，输入2表示查找:");
    scanf("%d",&key);
	}
}
