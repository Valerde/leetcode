#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <Windows.h> 
char board[15][15];               // 棋盘
int kx = 7 , ky = 7;              // 初始棋子坐标
char player = 'A';                // 定义玩家 
void set_interface();             // 设置界面 
void reminder();                  // 玩前提示 
void new_one();                   // 开始新一局游戏时将所有数据清零 
void show_board();                // 打印棋盘 
void get_key();                   //获得键盘信息 
bool check_board();               //检查是否连成五子 
void modeset(int w,int h);        //设置窗口大小 
bool make_sure_qiuhe();           //询问是否确定和棋 
bool make_sure_huiqi(); 
bool isnextgame();                //询问是否开启新一轮游戏 
int count_eqkey(int ox,int oy);   //计算相连的棋子个数 
struct chess{                     //记录走棋历史，x为横坐标，y为纵坐标 
	int x;
	int y;
};
struct chess a[150];              //利用结构定义一个栈，存储走棋历史，并       
int top=0;                        //用来悔棋时搜索前一步和前两步 
int main()                        
{	
    set_interface();
	reminder();
	while(1){
		new_one();
	     for(;;)
	     {
	        show_board();                                   //打印棋盘 

	     	get_key();                                      //获得键盘信息 
	     	
                                               
	     	
			 if(check_board())                              //每下完一步检查落子 
		    {          
			   show_board();                                  //再次打印    //如果连成五子， 
			   printf("恭喜玩家%c胜利,游戏结束!\n",player); //表示祝贺 
			   break;                                       //跳出此次游戏 
		    }
         player = 'A'==player?'B':'A';                    //交换玩家 
	     }
         if(!isnextgame())                                  //询问是否重来 
		    break;
    }
    return 0; 
}
 
void reminder(void)                                         //玩前说明
{
	printf("****************************\n");
	printf("* 1.请将键盘切换为英文模式 *\n");
	printf("* 2.使用wsad键控制落子位置 *\n");
	printf("* 3.wsad分别代表上下左右   *\n"); 
	printf("* 4.按下k键落子            *\n");
	printf("* 5.按下h键悔棋            *\n");
	printf("* 6.按下j键求和            *\n"); 
	printf("****************************\n");
	printf("----Do you understand?------\n");
	printf("-------输入y表示了解--------\n");
	while(1){
	switch(getch()){
		case 'y':system("cls");return;                      //如果表示了解规则，清空屏幕 
		 }
	}
} 

void show_board(void)                                       // 显示棋盘
{
	system("cls");
	int i , j ; 
	for(i=0; i<15; i++)                                     //行 
	{
		for( j=0; j<15; j++)                                //列 
		{
			if(board[i][j])                                 //此if语句表示如果该处存在落子，则进行选择 
			{  printf("-");
			  if(board[i][j]=='o') {                        //如果为B玩家落子，则打印蓝色棋子 
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xf9);//设置白底蓝字 
				printf("O");                                                  //以英文字母O为棋子 
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xf0);//设置为初始模式白底黑字 
			    }
			 else if(board[i][j]=='1'){                                                            //否则为A玩家落子 
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xFC);//设置白底红字 
				printf("O");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xF0);//设置为初始模式白底黑字 
			    }
			    else {
			    	printf("┼");  
			    }
			}
			else
			{
				printf("-┼");                               //如果此处无落子，则打印棋盘 ，以减号和特殊字符表示实线 
			}
		}
		printf("\n");
	}
}

bool make_sure_huiqi(void){                        //询问是否确定悔棋 
	printf("%c[%d;%dH",27,17,0);                   //将光标移到最下面 
	printf("你确定要悔棋吗？\n");                  //
	while(1){                                      //
	 printf("按下“y”表示确定，“n”表示取消\n"); //提示 y表示确定，n表示取消悔棋 
	 switch(getch()){
		case 'y':printf("%c[%d;%dH",27,a[top-1].x+1,(a[top-1].y+1)*2);return true;//如果确定则把光标移回上一步 
		case 'n':printf("%c[%d;%dH",27,kx+1,(ky+1)*2);show_board();return false;        //如果取消，则把光标移回到请求悔棋时的地方 
	    }
	}
}

bool make_sure_qiuhe(void)
{
	printf("%c[%d;%dH",27,17,0);                   //将光标移到最下面 
	printf("你们确定和棋吗？\n");                  //
	while(1){                                      //
	 printf("按下“y”表示确定，“n”表示取消\n"); //提示 y表示确定，n表示取消悔棋 
	 switch(getch()){                               
		case 'y':/*printf("%c[%d;%dH",27,a[top-1].x+1,(a[top-1].y+1)*2);*/return true;//如果确定则把光标移回上一步 
		case 'n':printf("%c[%d;%dH",27,kx+1,(ky+1)*2);show_board();return false;  //如果取消，则把光标移回到请求和棋时的地方 
	    }
	}
}

void get_key(void)                                      // 落子
{
	
	printf(" -----------请%c落子-----------\n",player); //提示落子方 
	for(;;)
	{
		printf("%c[%d;%dH",27,kx+1,(ky+1)*2);           //设置光标位置 void locateCursor(const int row, const int col){                     
		switch(getch())                      //        printf("%c[%d;%dH",27,row,col);            
		{                                    //                        
			case 'w': kx>0 && kx--; break;   //向上移动，当kx>0时kx--， 表示当坐标不超过上界线时坐标移到上面一行 
			case 's': kx<14 && kx++; break;  //向下移动，当kx<14时kx++，表示当坐标不超过下界线时坐标移到下面一行 
			case 'd': ky<14 && ky++; break;  //向右移动，当ky<14时ky++，表示当坐标不超过右界线时坐标移到右面一列 
			case 'a': ky>0 && ky--; break;   //向左移动，当ky>0时ky--， 表示当坐标不超过左界线时坐标移到左面一列 
			case 'h':{if(make_sure_huiqi())                     //悔棋，调用函数make_sure_huiqi, 
			          {board[a[top-1].x][a[--top].y]='\0';     //将上一步位置设为空 
			          kx=a[top-1].x; ky=a[top-1].y;            //将光标落为上上一步，防止check_board函数误判 
					  return;                                  //上一步处连成五个空 
					  }printf(" -----------请%c落子-----------\n",player);break;}
			case 'k': {if(!board[kx][ky]||board[7][7]=='3')     //如果该处无落子即可落子，空字符与无意义的字符3表示无落子 
			{
				a[top].x=kx;                                   //记录最近一次落子位置， 
				a[top++].y=ky;                                 //以备悔棋时用 
				if(player=='A')                                 //此if语句存储棋盘上玩家信息
				board[kx][ky] = '1';
				else if(player=='B')
				board[kx][ky]='o';
				return;
			}break;}
			 case 'j':{if(make_sure_qiuhe()){
			 new_one();
			 A:player = 'A'==player?'B':'A';
			 board[7][7]='3';
			 return;}printf(" -----------请%c落子-----------\n",player);break;}                                              //和棋操作，将初始位置玩家信息定义为 
		}                                                                 //无意义的字符3，防止误判五个空字符相连 
	}

}



int count_eqkey(int ox,int oy)                                  
{                                                               //计数 
	int count = 0, x ,y;                                        //
	for( x=kx+ox,y=ky+oy; x>=0 && x<15 && y>=0 && y<15 &&       //检查在规定方向不超过便捷的条件下是否连成五子 
		board[x][y]==board[kx][ky]; x+=ox,y+=oy)                //
	{                                                           //
		count++;                                                // 如果是，count++ 
	}                                                           //
	return count;                                               //返回连子数 
}                                                               //
                                                                //
bool check_board(void)                                          //检查五子 
{                                                               //
	if(count_eqkey(0,-1)+count_eqkey(0,1) >= 4)                 //判断竖向 
		return true;                                            //
	if(count_eqkey(-1,0)+count_eqkey(1,0) >= 4)                 //判断横向 
		return true;                                            //
	if(count_eqkey(-1,-1)+count_eqkey(1,1) >= 4)                //判断“\"向 
		return true;                                            //
	if(count_eqkey(-1,1)+count_eqkey(1,-1) >= 4)                //判断”/“向 
		return true;                                            //
                                                                //
	return false;                                               //如果是，返回真，否则返回假 
}

bool isnextgame(void)                                           //询问是否进行下一局 
{
	char ch;
	int i;
	printf("是否有兴趣再来一盘？\n");
    while(1){
     printf("输入“y”重来，输入“n”结束\n"); 
     switch(getch()){
    	case 'y':return true;break;
        case 'n':return false;break;
    	default:printf("输入错误！\n");
        }
	}
}

void new_one(void)                      //重新开始新一轮游戏时，
{                                       //将上一轮游戏清空。 
	int i,*p;
	kx=7;ky=7;                          //使初始位置位于正中央 
	for(p=board;p<board+14*14+1;p++)
	*p='\0';                            //利用指针将棋盘位置信息清空 
	top=0;                              //将落子历史记录清空 
	player='A'; 
}
 
void modeset(int w,int h) {                        //设置窗口大小， 
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);//引用自https://blog.csdn.net/yuanwow/article/details/89439077
	COORD size = {w, h};
	SetConsoleScreenBufferSize(hOut,size);
	SMALL_RECT rc = {1,1, w, h};
	SetConsoleWindowInfo(hOut ,true ,&rc);
	system("cls");
	return;
}
 
void set_interface(void)                           //修改窗口界面大小及背景、字体颜色
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xf0);
	//引用自网址https://baike.baidu.com/item/SetConsoleTextAttribute/570121?fr=aladdin 
	modeset(40,20);
}

