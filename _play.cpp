
#include "head.h"


bool MoveAble(int Rockindex,const _Location_t * RockLocationPtr, int direction );
void ProccessUserHit(char userhit,int * currentRockIndex,  _Location_t * RockLocationPtr);
void SetOccupyFlag(int rockindex,const _Location_t * location);

extern void DrawRock(int rockindex,_Location_t RockLocation, bool displayed);
extern int game_board[][Y_ROCK_NUM+1];
extern _Rock_t rockArray[];


////unfinished function, waiting for develop
void deletefull();
bool gameover();


void _play(){

    _Location_t currentLocation,initLocation;
    initLocation={10,0};
    currentLocation.x=initLocation.x;
    currentLocation.y=initLocation.y;

    int currentRockIndex,nextRockIndex;
    char userhit;
    bool moveAbled=false;
    DWORD oldtime=0;

    srand(time(NULL)) ;
    currentRockIndex = rand()%g_rockTypeNum ;
    nextRockIndex = rand()%g_rockTypeNum ;
    currentLocation.x = initLocation.x ;
    currentLocation.y = initLocation.y ;


    while(1){

        DrawRock(currentRockIndex,currentLocation,true);

        moveAbled = MoveAble(currentRockIndex, &currentLocation, DIRECT_DOWN) ;
        if(!moveAbled){
            //game_board[][]站位
            SetOccupyFlag(currentRockIndex, &currentLocation) ;

            //生成新的方块
            currentRockIndex = nextRockIndex ;
            nextRockIndex = rand()%g_rockTypeNum ;
            currentLocation.x = initLocation.x ;
            currentLocation.y = initLocation.y ;
        }

        //稳步下落一格
        DWORD newtime=GetTickCount();
        if(newtime-oldtime>=(unsigned int)1000 && moveAbled)
        {
            oldtime=newtime;
            DrawRock(currentRockIndex,currentLocation,false);
            currentLocation.y+=1;
        }

        //处理键盘控制
        if (kbhit())
        {
            userhit = getch() ;
            ProccessUserHit(userhit, &currentRockIndex, &currentLocation) ;
        }


        // stand by , unfinished
        deletefull();

        if (gameover()){}




        Sleep(20) ; //降低CPU使用率

    }

}

// judge if can move or not
bool MoveAble(int Rockindex,const _Location_t * RockLocationPtr, int direction ){

    int x=RockLocationPtr->x;
    int y=RockLocationPtr->y;
    int mask;

    mask=(unsigned int)1<<15;

    for (int i=1;i<=16;i++){

    if(rockArray[Rockindex].bit_value&mask){

    if(direction==DIRECT_DOWN)
    {
        if (game_board[x][y+1]==1)
            return false;
    }

    else if (direction==DIRECT_UP)
    {
        if (game_board[x][y] == 1)
            return false ;
    }

    else if (game_board[x+2*direction][y]==1)
        return false;


    }
     i%4 == 0 ? (y += 1, x = RockLocationPtr->x)
                 :  x += 2 ;

    mask >>= 1 ;

    }

    return true;
}



void ProccessUserHit(char userhit,int * currentRockIndex,  _Location_t * RockLocationPtr){

    switch(userhit){

case 'W': case 'w':case up:
    {
        if (MoveAble(rockArray[*currentRockIndex].next, RockLocationPtr, DIRECT_UP))
        {

            DrawRock(*currentRockIndex, *RockLocationPtr, false) ;
            //currentRockIndex=& rockArray[*currentRockIndex].next;  not ok!!!!
            *currentRockIndex= rockArray[*currentRockIndex].next;

        }
        break;
    }

case 'S':case 's':case down:
    if (MoveAble(*currentRockIndex, RockLocationPtr, DIRECT_DOWN))
    {
        DrawRock(*currentRockIndex, *RockLocationPtr, false) ;
        RockLocationPtr->y+=1;
    }
    break;

case 'A':case 'a':case left:
    if (MoveAble(*currentRockIndex, RockLocationPtr, DIRECT_LEFT))
    {
        DrawRock(*currentRockIndex, *RockLocationPtr, false) ;
        RockLocationPtr->x-=2;        // my test shows on x direction it's better we add or minus 2 to move rocks once.
    }
    break;

case 'D':case 'd':case right:
    if (MoveAble(*currentRockIndex, RockLocationPtr, DIRECT_RIGHT))
    {
        DrawRock(*currentRockIndex, *RockLocationPtr, false) ;
        RockLocationPtr->x+=2;
    }
    break;

case 13:
    while(1){
            userhit=getch();
            if(userhit==13)break;
        }

    break;

default:
    break;

    }


}





// once the rocks cannot move,it means this rock will end it here, we should make other rocks know this place is occupied.
void SetOccupyFlag(int rockindex,const _Location_t * location){

    int mask;
    mask=(unsigned int)1<<15;

    int x=location->x;
    int y=location->y;

    for (int i=1;i<=16;i++){

        if(rockArray[rockindex].bit_value&mask){

            game_board[x][y]=1;
        }

        (i%4==0)?(x=location->x,y+=1):(x+=2);
        mask>>=1;
    }

}


/////////waiting for develop

//清满行
void deletefull(){
}
//判断游戏是否结束
bool gameover(){
}

