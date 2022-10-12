/*
1、x86改64
2、peishi
*/

#include <fstream>
#include <memory>
#include<opencv2/opencv.hpp>
#include<iostream>
#include <cstddef>
#include <cstring>
#include <codecvt>
//#include <crpcndr>
//#include <rpcndr.h>
using namespace std;
using namespace cv;

//#include "QString.h"

//void read() {
//    Mat org = imread("out.png", 0);
//    int row = org.rows, col = org.cols;
//    for (int i = 0; i < row; i++) {
//        for (int j = 0; j < col; j++) {
//            org.at<uchar>(i, j) &= 1;
//            org.at<uchar>(i, j) *= 255;
//            //1->baise255
//            //0->heise
//        }
//    }
//    //imshow("s", org);
//    imwrite("read.png", org);
//    waitKey(0);
//}

//图片
void old() {
    //////imread()
    Mat org = imread("lena.bmp", 0);//读取,0，gray1,默认的bgr
    Mat logo = imread("name.png", 0);
    //获取图片高度

    int row = org.rows;
    int col = org.cols;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            int t = org.at<uchar>(i, j);//org.at可以查看像素值
            int x = logo.at<uchar>(i, j) > 126;
            //printf("%d", x);
            //修改像素值
            if ((t & 1) != x) {
                org.at<uchar>(i, j) ^= 1;
            }
        }
        //printf("\n");
    }

    imshow("lena", org);//显示（name,photo)
    imshow("name", logo);
    //隐藏的过程

    imwrite("lena_and_myname.png", org);//写出
    //waitKey(0);//等待，以毫秒为单位
    //read();

    org = imread("lena_and_myname.png", 0);
    row = org.rows;
    col = org.cols;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            org.at<uchar>(i, j) &= 1;
            org.at<uchar>(i, j) *= 255;
            //1->baise255
            //0->heise
        }
    }
    imshow("s", org);
    imwrite("myname_extract.png", org);
    waitKey(0);
}
//ascii字符
void newone() {
    string msg = "yangkainan 8208201004 xinan2002 |";
    int msg_len = msg.length();
    for (int i = 0; i < msg.length(); i++) {
        cout << (int) msg[i] << " ";
    }
    Mat org = imread("lena.bmp", 0);//读取,0，gray1,默认的bgr
    int row = org.rows;
    int col = org.cols;
    int cnt = 0, k = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (k < msg_len) {
                int t = org.at<uchar>(i, j);//org.at可以查看像素值
                int x = (int) msg[k] % 2;
                msg[k] /= 2;
                cnt++;
//                printf("%d ", x);
                //修改像素值
                if ((t & 1) != x) {
                    org.at<uchar>(i, j) ^= 1;
                }
                if (cnt == 8) {
                    cnt = 0;
                    k++;
                }

                t = org.at<uchar>(i, j);
                cout << (t & 1) << " ";
            }
        }
        //printf("\n");
    }

    imshow("lena", org);//显示（name,photo)
//    waitKey(0);
    imwrite("lena_and_myname.png", org);//写出


    org = imread("lena_and_myname.png", 0);
    imshow("lena_and_myname", org);//显示（name,photo)
    waitKey(0);
    row = org.rows;
    col = org.cols;
    int ch = 0;
    cnt = 0;
    k = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {

            int temp = org.at<uchar>(i, j) & 1;
            ch ^= (temp << cnt);


            cnt++;
            if (cnt == 8) {
                cnt = 0;
                cout << (char) ch;
                if (ch == '|') return;
                ch = 0;
                k++;
            }


        }
    }

//    imshow("lena", org);//显示（name,photo)


}

//utf8
void new2() {
    string msg = "杨凯楠 8208201004 信安2002  |";
    const char *s = msg.c_str();
    int i = 0;
    while (true) {
        if (s[i]) {
            cout << (int) s[i] << " ";
            i++;
        } else {
            break;
        }
    }

    cout << "\n" << s << "\n";
//return ;
    Mat org = imread("lena.bmp", 0);//读取,0，gray1,默认的bgr
    int row = org.rows;
    int col = org.cols;
    int cnt = 0, k = 0;
    int number = (int) s[0];
    cout << "number" << number;
    for (i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (s[k]) {
                int t = org.at<uchar>(i, j);//org.at可以查看像素值
                int x = (number & (1 << cnt)) > 0;
//                if(x==-1) x=1;
//                cout << "x:" << x << " ";
//                number /= 2;
                cnt++;
//                printf("%d ", x);
                //修改像素值
                if ((t & 1) != x) {
                    org.at<uchar>(i, j) ^= 1;
                }
                t = org.at<uchar>(i, j);
                cout << "隐藏后" << (t & 1) << " ";
                if (cnt == 8) {
                    cnt = 0;
                    k++;
                    number = (int) s[k];
                    cout << "\n" << "number" << ":" << number;
                }


            }
        }
        //printf("\n");
    }


//    imshow("lena", org);//显示（name,photo)
//    waitKey(0);
    imwrite("lena_and_myname_new2.png", org);//写出


    org = imread("lena_and_myname_new2.png", 0);
//    imshow("lena_and_myname_new2", org);//显示（name,photo)
//    waitKey(0);


    row = org.rows;
    col = org.cols;
    int ch = 0;
    cnt = 0;
    k = 0;
    char ans[45];
//    char *anss = (char *) malloc(15);
    bool flag = false;
    for (i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {

            int temp = org.at<uchar>(i, j) & 1;
//            cout<<"temp:"<<temp;
//            if (temp == -1) temp = 1;
            ch ^= (temp << cnt);


            cnt++;
            if (cnt == 8) {
                cnt = 0;

                if (((ch >> 7) & 1) == 1) ch -= 256;
                ans[k] = ch;
                cout << ans[k] << " ";
//                anss[k]=ch;
                if (ch == '|') {
                    flag = true;
                    break;
                }
                ch = 0;
                k++;
            }


        }

        if (flag) break;
    }

    cout << endl << endl;
//    for (int z = 0; z < 45; z++) {
    cout << ans << " ";
//    }


//    cout<<anss;
}

int main() {
//    old();
//    newone();

//    int i = -26;
//    while (i) {
//        cout << i % 2 << " ";
//        i /= 2;
//    }
//    cout << "-----------" << endl;
//cout<<"   "<<(26&-1)<<endl;
    new2();
//cout<<"杨凯楠";
    return 0;
}