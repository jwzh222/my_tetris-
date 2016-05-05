
#include "head.h"


//extern void DrawGame();
extern int game_board[][Y_ROCK_NUM+1];


//game_board[][]数组 边界初始化
int _Init(){

    //DrawGame();

    int  i ;

    //初始化游戏板(把这个二维数组的四周置1,当作围墙,用于判断边界)
    for (i = 0; i <= X_ROCK_NUM*2+2; i++)
    {
        game_board[i][Y_ROCK_NUM]=1;
    }
    for (i = 0; i <= Y_ROCK_NUM; i++)
    {
        game_board[0][i] = 1 ;
        game_board[X_ROCK_NUM*2+2][i]= 1 ;
    }

    return 0;
}

