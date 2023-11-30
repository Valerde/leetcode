#include <stdio.h>
#include <string.h>
char filename[20];
//创建文本文件的函数
void creattext(){
    FILE * fp;
    char ch;
    printf("请输入文件名：");
    gets(filename);
    //尝试打开文件，若无此文件，该函数会自动创建一个新的文件
    if((fp = fopen(filename,"w")) == NULL){
        printf("cannot open file\n");
        return;
    }
    //向文件中输入内容
    printf("请输入文件内容，以‘#’作为结束标志：\n");
    ch = getchar();
    while(ch!='#'){
        fputc(ch,fp);
        ch = getchar();
    }
    //创建文件完成后，关闭文件
    fclose(fp);
}
//统计文本文件中给定单词的数量
int count(char * word){
    FILE * fp;
    char ch,w[20];
    int j = 0,num = 0;
    //打开文件
    if((fp = fopen(filename,"r")) == NULL){
        printf("cannot open file\n");
        return 0;
    }
    //只要文件不结束，就一直判断
    while(!feof(fp)){
        //取文件中的每个单词
        ch = fgetc(fp);
        j = 0;
        //只要不是空格或转行，其所遇到的字母都隶属于一个单词
        while(ch != ' ' && ch != '\n' && !feof(fp)){
            w[j++] = ch;
            ch = fgetc(fp);
        }
        //给单词的最后添加结束符，防止各个单词的长度不同，导致从数组读取单词时多读的现象发生
        w[j] = '\0';
        //判断每个单词是否与给定单词相同，若相同，则计数变量num +1
        if(strcmp(w,word) == 0){
            num++;
        }
    }
    //最终返回计数变量 num 的值
    return num;
}
//检索并输出给定单词所在行号、在该行中出现的次数以及各自的具体位置
void search(char * word){
    FILE * fp;
    char ch,w[20];
    int j = 0,num = 0,row = 1,col[20],i = 0,k;
    //尝试打开文本文件
    if((fp = fopen(filename,"r")) == NULL){
        printf("cannot open file\n");
        return;
    }
    //遍历文本文件中的每个单词
    while(!feof(fp)){
        ch = fgetc(fp);
        j = 0, i++;
        while(ch != ' ' && ch != '\n' && !feof(fp)){
            w[j++] = ch;
            ch = fgetc(fp);
            i++;
        }
        w[j]='\0';
        //判断每个单词与给定单词是否相等
        if(strcmp(w,word) == 0){
            //如果相同，记录该单词在该行中的位置，同时计数变量 num+1
            col[num] = i-j,
            num++;
        }
        //如果遇到转行或者文件结束，则输出该行中单词的数量以及相应位置
        if(ch == '\n' || feof(fp)){
            if(num){
                printf("the number of %d row is %d\n",row,num);
                printf("the col is :");
                for(k = 0 ; k < num; k++){
                    printf("%5d",col[k]);
                }
                printf("\n");
            }
            //转行，row +1，同时 i 和 num 都清零
            row ++;
            i = 0;
            num = 0;
        }
    }
}
int main(){
    creattext();
    //输入要检索的单词
    printf("word is : ");
    char word[20];
    scanf("%s",word);
    //统计 word 的个数
    printf("count of %s is :%d\n",word,count(word));
    //检索 word 在文本中的相对位置
    search(word);
    return 0;
}
