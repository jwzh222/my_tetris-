#ifndef _HEAD_H_
#define _HEAD_H_


#include <iostream>
#include <stdio.h>
#include <stdlib.h>//using srand()��rand()
#include <time.h>//using time();
#include <windows.h>
#include <conio.h> // using kbhit() getch()

using  std::cout;


//x y ����С�������
#define X_ROCK_NUM 16
#define Y_ROCK_NUM 20

//����������
#define g_rockTypeNum 8

#define up      72
#define down    80
#define left    75
#define right   77

//int game_board[2*X_ROCK_NUM+3][Y_ROCK_NUM+1];


typedef struct _Rock {

unsigned int bit_value;
/* ��¼�����������1000100011000000�Ϳ��Ա�ʾL�ͷ���
1000
1000
1100
0000
*/

int next;   //����ͬһ����ת����λ

} _Rock_t;


//�ƶ��ķ���
#define DIRECT_UP    3
#define DIRECT_DOWN  2
#define DIRECT_LEFT  -1
#define DIRECT_RIGHT 1

//��Ļ�����н���x-y����ϵ,��ʾλ��
typedef struct _Location{
    int x;
    int y;
} _Location_t;



#endif // _HEAD_H_

