#include <stdio.h>
#include <string.h>
char filename[20];
//�����ı��ļ��ĺ���
void creattext(){
    FILE * fp;
    char ch;
    printf("�������ļ�����");
    gets(filename);
    //���Դ��ļ������޴��ļ����ú������Զ�����һ���µ��ļ�
    if((fp = fopen(filename,"w")) == NULL){
        printf("cannot open file\n");
        return;
    }
    //���ļ�����������
    printf("�������ļ����ݣ��ԡ�#����Ϊ������־��\n");
    ch = getchar();
    while(ch!='#'){
        fputc(ch,fp);
        ch = getchar();
    }
    //�����ļ���ɺ󣬹ر��ļ�
    fclose(fp);
}
//ͳ���ı��ļ��и������ʵ�����
int count(char * word){
    FILE * fp;
    char ch,w[20];
    int j = 0,num = 0;
    //���ļ�
    if((fp = fopen(filename,"r")) == NULL){
        printf("cannot open file\n");
        return 0;
    }
    //ֻҪ�ļ�����������һֱ�ж�
    while(!feof(fp)){
        //ȡ�ļ��е�ÿ������
        ch = fgetc(fp);
        j = 0;
        //ֻҪ���ǿո��ת�У�������������ĸ��������һ������
        while(ch != ' ' && ch != '\n' && !feof(fp)){
            w[j++] = ch;
            ch = fgetc(fp);
        }
        //�����ʵ������ӽ���������ֹ�������ʵĳ��Ȳ�ͬ�����´������ȡ����ʱ�����������
        w[j] = '\0';
        //�ж�ÿ�������Ƿ������������ͬ������ͬ�����������num +1
        if(strcmp(w,word) == 0){
            num++;
        }
    }
    //���շ��ؼ������� num ��ֵ
    return num;
}
//����������������������кš��ڸ����г��ֵĴ����Լ����Եľ���λ��
void search(char * word){
    FILE * fp;
    char ch,w[20];
    int j = 0,num = 0,row = 1,col[20],i = 0,k;
    //���Դ��ı��ļ�
    if((fp = fopen(filename,"r")) == NULL){
        printf("cannot open file\n");
        return;
    }
    //�����ı��ļ��е�ÿ������
    while(!feof(fp)){
        ch = fgetc(fp);
        j = 0, i++;
        while(ch != ' ' && ch != '\n' && !feof(fp)){
            w[j++] = ch;
            ch = fgetc(fp);
            i++;
        }
        w[j]='\0';
        //�ж�ÿ����������������Ƿ����
        if(strcmp(w,word) == 0){
            //�����ͬ����¼�õ����ڸ����е�λ�ã�ͬʱ�������� num+1
            col[num] = i-j,
            num++;
        }
        //�������ת�л����ļ�����������������е��ʵ������Լ���Ӧλ��
        if(ch == '\n' || feof(fp)){
            if(num){
                printf("the number of %d row is %d\n",row,num);
                printf("the col is :");
                for(k = 0 ; k < num; k++){
                    printf("%5d",col[k]);
                }
                printf("\n");
            }
            //ת�У�row +1��ͬʱ i �� num ������
            row ++;
            i = 0;
            num = 0;
        }
    }
}
int main(){
    creattext();
    //����Ҫ�����ĵ���
    printf("word is : ");
    char word[20];
    scanf("%s",word);
    //ͳ�� word �ĸ���
    printf("count of %s is :%d\n",word,count(word));
    //���� word ���ı��е����λ��
    search(word);
    return 0;
}
