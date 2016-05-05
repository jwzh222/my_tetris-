#ifndef _HEAD_H_
#define _HEAD_H_


#include <iostream>
#include <stdio.h>
#include <stdlib.h>//using srand()、rand()
#include <time.h>//using time();
#include <windows.h>
#include <conio.h> // using kbhit() getch()

using  std::cout;


//x y 方向小方块个数
#define X_ROCK_NUM 16
#define Y_ROCK_NUM 20

//方块种类数
#define g_rockTypeNum 8

#define up      72
#define down    80
#define left    75
#define right   77

//int game_board[2*X_ROCK_NUM+3][Y_ROCK_NUM+1];


typedef struct _Rock {

unsigned int bit_value;
/* 记录方块如二进制1000100011000000就可以标示L型方块
1000
1000
1100
0000
*/

int next;   //用于同一方块转换方位

} _Rock_t;


//移动的方向
#define DIRECT_UP    3
#define DIRECT_DOWN  2
#define DIRECT_LEFT  -1
#define DIRECT_RIGHT 1

//屏幕按行列建立x-y坐标系,标示位置
typedef struct _Location{
    int x;
    int y;
} _Location_t;



#endif // _HEAD_H_

