
#include "head.h"


//extern void DrawGame();
extern int game_board[][Y_ROCK_NUM+1];


//game_board[][]���� �߽��ʼ��
int _Init(){

    //DrawGame();

    int  i ;

    //��ʼ����Ϸ��(�������ά�����������1,����Χǽ,�����жϱ߽�)
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

