#include "function.h"
extern char ch1, ch2;
DWORD WINAPI Fun(LPVOID lpParamter)
{
    char ch;
    while(1){
        if(kbhit())
        {    
            ch1 = ch2 = getch();
        }
    }
    return 0L;
}
int main(){
    system("color 9f");
	system("mode con cols=74 lines=25");
    ShowInterface();
    ShowOperate();
    PaintSnake();
    ShowRule();
    cls();
    GenFood();
    HANDLE hThread = CreateThread(NULL, 0, Fun, NULL, 0, NULL);
    PlayGame();
    getchar();
    //system("pause");
    return 0;
}
