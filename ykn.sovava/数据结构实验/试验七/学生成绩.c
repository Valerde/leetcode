#include <stdio.h>
#include <stdlib.h>
#define MaxLength 255
 
//����Ԫ��
typedef struct {
	int id;//ѧ��
	char name[20];//����
	int score[3];//���硢ģ�硢���ݽṹ�ĳɼ�
	int total;//�ܳɼ�
}studentElement;
 
//˳���ṹ
typedef struct {
	studentElement gra[MaxLength];
	int length;
}seqList; 
//��ʼ��������ѧ�������������Ա��ȣ�¼��ÿ��ѧ���ĸ��Ƴɼ���Ϣ�������ÿ�����ܳɼ�����
int InitList(seqList*seqList){
	int length=0;
	int i=0;
	int total=0;
	int j=0;
	printf("����ѧ��������");
	scanf("%d",&length);
	if(length<0||length>MaxLength){
		printf("�����ѧ������������");
	}else{
		seqList->length=length;
	}
	if(seqList->length<0||seqList->length>MaxLength){
		printf("��ʼ��ѧ������ʧ�ܣ�\n");
		return 0;
	}else{
		for(i=0;i<length;i++){//����ÿ��ѧ������Ϣ
			seqList->gra[i].total=0;//ÿ��ѧ����ȷ��֮ǰ�ܳɼ�����
			printf("�����%d���˵���Ϣ:\n",i+1);
			//����ѧ�ź�����
			printf("ѧ�ţ�\n");
			scanf("%d",&seqList->gra[i].id);
			printf("������\n");
			scanf("%s",&seqList->gra[i].name);
			//���� ���硢ģ�硢���ݽṹ�ĳɼ�
			printf("���磺\n");
			scanf("%d",&seqList->gra[i].score[0]);
			printf("ģ�磺\n");
			scanf("%d",&seqList->gra[i].score[1]);
			printf("���ݽṹ��\n");
			scanf("%d",&seqList->gra[i].score[2]);
			printf("\n��%d��ͬѧ���������ϣ�\n\n",i+1);
			for(j=0;j<3;j++){//����ÿ��ѧ�����ܳɼ�
				seqList->gra[i].total+=seqList->gra[i].score[j];
			}
		}
	}
	return 0;
};
 
 
//������������Ҫ�������˳ɼ�����Ŀ�Ŀ�����������У�����ӡ��ʾ�����������˳ɼ�����
int Sort(seqList *seqList){
	int option=0;
	int i=0,j=0;
	studentElement temp;
	printf("��ʼ����......\n\n��������0��ģ������1,���ݽṹ������2���ܳɼ�����3 \n");
	printf("���������������Ŀ�Ŀ:");
	scanf("%d",&option);
	if(option<4||option>=0){
		//��װĳ�Ƴɼ���������
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
			printf("\n\n��ĳ�Ƴɼ�����������\n");
		}
		//��װĳ�Ƴɼ���������
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
			printf("\n���ܳɼ�����������");
		}
	}else{
		printf("���벻��ȷ������");
	}
	return 0;
};
 
 
//��ѯ������ѧ�ţ������Ա��е�ÿ��ѧ����ѧ����������ַ�����Ƚ�
//����ƥ�����ӡ��ʾ��ѧ����������Ϣ�������������ʾ����
int Puery(seqList *seqList){
	int id=0;
	int i=0;
	printf("����ѧ�ż��ɲ�ѯ������������Ϣ��");
	scanf("%d",&id);
	if(id<0){
		printf("\nѧ�Ų����ڲ�ѯʧ�ܣ�\n\n");
	}else{
		for(i=0;i<sizeof(seqList->length);i++){//��ӡ�����ѧ����ȫ����Ϣ
			if(id==seqList->gra[i].id){
				printf("ѧ�ţ�%d\n������%s\n���磺%d\nģ�磺%d\n���ݽṹ��%d\n�ܷ֣�%d\n\n��ϲ����ѯ�ɹ���\n\n",\
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
 
 
//���������Ϣ
int Print(seqList *seqList){
	int i=0;
	for(i=seqList->length-1;i>=0;i--){
		printf("ѧ�ţ�%d\t������%s\t���磺%d\tģ�磺%d\t���ݽṹ��%d\t�ܷ֣�%d\t\n",\
			seqList->gra[i].id,\
			seqList->gra[i].name,\
			seqList->gra[i].score[0],\
			seqList->gra[i].score[1],\
			seqList->gra[i].score[2],\
			seqList->gra[i].total);
	}
	printf("\n��ӡ��ϣ�\n");
	return 0;
}
 
int main(){
	seqList SL;
	InitList(&SL);
	int key; 
	printf("����ǰ��\n");
	Print(&SL);
	printf("����1��ʾ��������2��ʾ����:"); 
    scanf("%d",&key);
	while(key){
		switch(key){
			case 1:	Sort(&SL);
			printf("�����\n");
	        Print(&SL);
		    printf("\n");
            break;
            case 2:	Puery(&SL);break;
		}
    printf("����1��ʾ��������2��ʾ����:");
    scanf("%d",&key);
	}
}
