# my_tetris-
简易版

20160505：目前gcc下编译通过，能控制方块移动变形， 

待完成：满行消行函数、判断游戏结束函数、计分、加速等功能


1.方块表示：
unsigned int bit_value;
/* 记录方块如二进制1000100011000000就可以标示L型方块
1000
1000
1100
0000
*/

2.位置：
将屏幕按行列建立x-y坐标系，利用以下函数移动光标到对应位置，进行画方块，移动方块等操作
            COORD coord = { x, y };
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);

3.游戏边界
// 用一个二维数组来记录游戏区的边界，以及在游戏中确认该位置是否已被其他方块占领
// game_board[][] is used for identify the board of our game in screen,
// and let computer know if this place is occupied by other rocks or not
int game_board[2*X_ROCK_NUM+3][Y_ROCK_NUM+1];

![image](https://github.com/jwzh222/my_tetris-/raw/master/Image.png)
