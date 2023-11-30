#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <Windows.h> 
char board[15][15];               // ����
int kx = 7 , ky = 7;              // ��ʼ��������
char player = 'A';                // ������� 
void set_interface();             // ���ý��� 
void reminder();                  // ��ǰ��ʾ 
void new_one();                   // ��ʼ��һ����Ϸʱ�������������� 
void show_board();                // ��ӡ���� 
void get_key();                   //��ü�����Ϣ 
bool check_board();               //����Ƿ��������� 
void modeset(int w,int h);        //���ô��ڴ�С 
bool make_sure_qiuhe();           //ѯ���Ƿ�ȷ������ 
bool make_sure_huiqi(); 
bool isnextgame();                //ѯ���Ƿ�����һ����Ϸ 
int count_eqkey(int ox,int oy);   //�������������Ӹ��� 
struct chess{                     //��¼������ʷ��xΪ�����꣬yΪ������ 
	int x;
	int y;
};
struct chess a[150];              //���ýṹ����һ��ջ���洢������ʷ����       
int top=0;                        //��������ʱ����ǰһ����ǰ���� 
int main()                        
{	
    set_interface();
	reminder();
	while(1){
		new_one();
	     for(;;)
	     {
	        show_board();                                   //��ӡ���� 

	     	get_key();                                      //��ü�����Ϣ 
	     	
                                               
	     	
			 if(check_board())                              //ÿ����һ��������� 
		    {          
			   show_board();                                  //�ٴδ�ӡ    //����������ӣ� 
			   printf("��ϲ���%cʤ��,��Ϸ����!\n",player); //��ʾף�� 
			   break;                                       //�����˴���Ϸ 
		    }
         player = 'A'==player?'B':'A';                    //������� 
	     }
         if(!isnextgame())                                  //ѯ���Ƿ����� 
		    break;
    }
    return 0; 
}
 
void reminder(void)                                         //��ǰ˵��
{
	printf("****************************\n");
	printf("* 1.�뽫�����л�ΪӢ��ģʽ *\n");
	printf("* 2.ʹ��wsad����������λ�� *\n");
	printf("* 3.wsad�ֱ������������   *\n"); 
	printf("* 4.����k������            *\n");
	printf("* 5.����h������            *\n");
	printf("* 6.����j�����            *\n"); 
	printf("****************************\n");
	printf("----Do you understand?------\n");
	printf("-------����y��ʾ�˽�--------\n");
	while(1){
	switch(getch()){
		case 'y':system("cls");return;                      //�����ʾ�˽���������Ļ 
		 }
	}
} 

void show_board(void)                                       // ��ʾ����
{
	system("cls");
	int i , j ; 
	for(i=0; i<15; i++)                                     //�� 
	{
		for( j=0; j<15; j++)                                //�� 
		{
			if(board[i][j])                                 //��if����ʾ����ô��������ӣ������ѡ�� 
			{  printf("-");
			  if(board[i][j]=='o') {                        //���ΪB������ӣ����ӡ��ɫ���� 
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xf9);//���ð׵����� 
				printf("O");                                                  //��Ӣ����ĸOΪ���� 
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xf0);//����Ϊ��ʼģʽ�׵׺��� 
			    }
			 else if(board[i][j]=='1'){                                                            //����ΪA������� 
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xFC);//���ð׵׺��� 
				printf("O");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xF0);//����Ϊ��ʼģʽ�׵׺��� 
			    }
			    else {
			    	printf("��");  
			    }
			}
			else
			{
				printf("-��");                               //����˴������ӣ����ӡ���� ���Լ��ź������ַ���ʾʵ�� 
			}
		}
		printf("\n");
	}
}

bool make_sure_huiqi(void){                        //ѯ���Ƿ�ȷ������ 
	printf("%c[%d;%dH",27,17,0);                   //������Ƶ������� 
	printf("��ȷ��Ҫ������\n");                  //
	while(1){                                      //
	 printf("���¡�y����ʾȷ������n����ʾȡ��\n"); //��ʾ y��ʾȷ����n��ʾȡ������ 
	 switch(getch()){
		case 'y':printf("%c[%d;%dH",27,a[top-1].x+1,(a[top-1].y+1)*2);return true;//���ȷ����ѹ���ƻ���һ�� 
		case 'n':printf("%c[%d;%dH",27,kx+1,(ky+1)*2);show_board();return false;        //���ȡ������ѹ���ƻص��������ʱ�ĵط� 
	    }
	}
}

bool make_sure_qiuhe(void)
{
	printf("%c[%d;%dH",27,17,0);                   //������Ƶ������� 
	printf("����ȷ��������\n");                  //
	while(1){                                      //
	 printf("���¡�y����ʾȷ������n����ʾȡ��\n"); //��ʾ y��ʾȷ����n��ʾȡ������ 
	 switch(getch()){                               
		case 'y':/*printf("%c[%d;%dH",27,a[top-1].x+1,(a[top-1].y+1)*2);*/return true;//���ȷ����ѹ���ƻ���һ�� 
		case 'n':printf("%c[%d;%dH",27,kx+1,(ky+1)*2);show_board();return false;  //���ȡ������ѹ���ƻص��������ʱ�ĵط� 
	    }
	}
}

void get_key(void)                                      // ����
{
	
	printf(" -----------��%c����-----------\n",player); //��ʾ���ӷ� 
	for(;;)
	{
		printf("%c[%d;%dH",27,kx+1,(ky+1)*2);           //���ù��λ�� void locateCursor(const int row, const int col){                     
		switch(getch())                      //        printf("%c[%d;%dH",27,row,col);            
		{                                    //                        
			case 'w': kx>0 && kx--; break;   //�����ƶ�����kx>0ʱkx--�� ��ʾ�����겻�����Ͻ���ʱ�����Ƶ�����һ�� 
			case 's': kx<14 && kx++; break;  //�����ƶ�����kx<14ʱkx++����ʾ�����겻�����½���ʱ�����Ƶ�����һ�� 
			case 'd': ky<14 && ky++; break;  //�����ƶ�����ky<14ʱky++����ʾ�����겻�����ҽ���ʱ�����Ƶ�����һ�� 
			case 'a': ky>0 && ky--; break;   //�����ƶ�����ky>0ʱky--�� ��ʾ�����겻���������ʱ�����Ƶ�����һ�� 
			case 'h':{if(make_sure_huiqi())                     //���壬���ú���make_sure_huiqi, 
			          {board[a[top-1].x][a[--top].y]='\0';     //����һ��λ����Ϊ�� 
			          kx=a[top-1].x; ky=a[top-1].y;            //�������Ϊ����һ������ֹcheck_board�������� 
					  return;                                  //��һ������������� 
					  }printf(" -----------��%c����-----------\n",player);break;}
			case 'k': {if(!board[kx][ky]||board[7][7]=='3')     //����ô������Ӽ������ӣ����ַ�����������ַ�3��ʾ������ 
			{
				a[top].x=kx;                                   //��¼���һ������λ�ã� 
				a[top++].y=ky;                                 //�Ա�����ʱ�� 
				if(player=='A')                                 //��if���洢�����������Ϣ
				board[kx][ky] = '1';
				else if(player=='B')
				board[kx][ky]='o';
				return;
			}break;}
			 case 'j':{if(make_sure_qiuhe()){
			 new_one();
			 A:player = 'A'==player?'B':'A';
			 board[7][7]='3';
			 return;}printf(" -----------��%c����-----------\n",player);break;}                                              //�������������ʼλ�������Ϣ����Ϊ 
		}                                                                 //��������ַ�3����ֹ����������ַ����� 
	}

}



int count_eqkey(int ox,int oy)                                  
{                                                               //���� 
	int count = 0, x ,y;                                        //
	for( x=kx+ox,y=ky+oy; x>=0 && x<15 && y>=0 && y<15 &&       //����ڹ涨���򲻳�����ݵ��������Ƿ��������� 
		board[x][y]==board[kx][ky]; x+=ox,y+=oy)                //
	{                                                           //
		count++;                                                // ����ǣ�count++ 
	}                                                           //
	return count;                                               //���������� 
}                                                               //
                                                                //
bool check_board(void)                                          //������� 
{                                                               //
	if(count_eqkey(0,-1)+count_eqkey(0,1) >= 4)                 //�ж����� 
		return true;                                            //
	if(count_eqkey(-1,0)+count_eqkey(1,0) >= 4)                 //�жϺ��� 
		return true;                                            //
	if(count_eqkey(-1,-1)+count_eqkey(1,1) >= 4)                //�жϡ�\"�� 
		return true;                                            //
	if(count_eqkey(-1,1)+count_eqkey(1,-1) >= 4)                //�жϡ�/���� 
		return true;                                            //
                                                                //
	return false;                                               //����ǣ������棬���򷵻ؼ� 
}

bool isnextgame(void)                                           //ѯ���Ƿ������һ�� 
{
	char ch;
	int i;
	printf("�Ƿ�����Ȥ����һ�̣�\n");
    while(1){
     printf("���롰y�����������롰n������\n"); 
     switch(getch()){
    	case 'y':return true;break;
        case 'n':return false;break;
    	default:printf("�������\n");
        }
	}
}

void new_one(void)                      //���¿�ʼ��һ����Ϸʱ��
{                                       //����һ����Ϸ��ա� 
	int i,*p;
	kx=7;ky=7;                          //ʹ��ʼλ��λ�������� 
	for(p=board;p<board+14*14+1;p++)
	*p='\0';                            //����ָ�뽫����λ����Ϣ��� 
	top=0;                              //��������ʷ��¼��� 
	player='A'; 
}
 
void modeset(int w,int h) {                        //���ô��ڴ�С�� 
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);//������https://blog.csdn.net/yuanwow/article/details/89439077
	COORD size = {w, h};
	SetConsoleScreenBufferSize(hOut,size);
	SMALL_RECT rc = {1,1, w, h};
	SetConsoleWindowInfo(hOut ,true ,&rc);
	system("cls");
	return;
}
 
void set_interface(void)                           //�޸Ĵ��ڽ����С��������������ɫ
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xf0);
	//��������ַhttps://baike.baidu.com/item/SetConsoleTextAttribute/570121?fr=aladdin 
	modeset(40,20);
}

