#include "head.h"

extern int _Init();
extern void _play();
extern void DrawGame();


// 用一个二维数组来记录游戏区的边界，以及在游戏中确认该位置是否已被其他方块占领
// game_board[][] is used for identify the board of our game in screen,
// and let computer know if this place is occupied by other rocks or not
int game_board[2*X_ROCK_NUM+3][Y_ROCK_NUM+1];


/* 方块rockArray[]：
1000100011000000   35008
1110100000000000   59392
1100010001000000   50240
0010111000000000   11776

0100010011000000   17600
1000111000000000   36352
1100100010000000   51328
1110001000000000   57856
*/
_Rock_t rockArray[g_rockTypeNum]={
    {35008,1},{59392,2},{50240,3},{11776,0},
    {17600,5},{36352,6},{51328,7},{57856,4}
};




int main(){


    DrawGame();

    _Init();

    _play();

    return 0;

}

