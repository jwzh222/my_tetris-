#include "head.h"

extern _Rock_t rockArray[];


void DrawRock(int rockindex,_Location_t RockLocation, bool displayed){

    int x, y;
    int mask;
    x=RockLocation.x;
    y=RockLocation.y;
    mask=(unsigned int)1<<15;


    for (int i=1;i<=16;i++)
    {
        if(rockArray[rockindex].bit_value&mask)
        {
            COORD coord = { x, y };
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);


            switch(displayed){
            case 1:
                printf("■");break;
            case 0:
                printf(" ");break;

            default:
                printf("error");break;

            }

        }

        (i%4==0)?(x=RockLocation.x,y+=1):(x+=2);

        mask>>=1;

    }

}

void DrawGame(){

    int x,y;


        //»­±ß½ç
    for (int i=0;i<=Y_ROCK_NUM;i++){
    x=0;y=i;
    COORD coord = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
    printf("¡õ");

    }



    for (int i=0;i<=Y_ROCK_NUM;i++){
    x=X_ROCK_NUM*2+2;y=i;
    COORD coord = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
    printf("¡õ");

    }

    for (int i=2;i<=X_ROCK_NUM*2;i+=2){
    x=i;y=Y_ROCK_NUM;
    COORD coord = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
    printf("¡õ");

    }

    x=X_ROCK_NUM*2+8;
    y=Y_ROCK_NUM*0.618;
    COORD coord = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
    cout<<"don't worry, be happy!";
    x=X_ROCK_NUM*2+20;
    y=Y_ROCK_NUM*0.618+1;
     coord = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
    cout<<"----yang";

}

