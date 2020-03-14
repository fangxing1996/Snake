#include "function.h"
snake Snake1[400] = { 0 }, Snake2[400] = { 0 };
food Food;
int Snake1Len = 1, Snake2Len = 1;
int Snake1_EatCount = 0;
int Snake2_EatCount = 0;
int temp;
int Flag1 = 4; 
int Flag2 = 3;
int hour = 6, mi = 59, sec = 59;
char ch1, ch2;

void ShowInterface(){

    int i, j, k;
	for(i = 0; i < 74; i++){

		gotoxy(i, 0);
		cout << A;
		Sleep(5);
    }
    for(j = 1; j < 26; j++){
        if((j == 20) || (j == 25)){
            for(i = 0; i < 74; i++){
		        gotoxy(i, j);
		        cout << A;
		        Sleep(5);
            }
        }
        else if((j >= 21) && (j <= 24)){
            gotoxy(0, j);
            cout << A;
            gotoxy(25, j);
            cout << A;
            gotoxy(48, j);
            cout << A;
            gotoxy(73, j);
            cout << A;
        }
        else{
            gotoxy(0, j);
            cout << A;
            gotoxy(73, j);
            cout << A;
        }
    }
}

void ShowOperate(){
    gotoxy(4, 22); 
	printf("W S A D move Snake1");
	gotoxy(52, 22); 
	printf("1 2 3 4 move Snake2");
	gotoxy(29, 22); 
	printf("author: fangxing");
}

void PaintSnake()
{
	Snake1[0].x = 2; 
	Snake1[0].y = 10;
	Snake2[0].x = 71; 
	Snake2[0].y = 10;

	gotoxy(Snake1[0].x, Snake1[0].y); 
	cout << '1';
	gotoxy(Snake2[0].x, Snake2[0].y); 
	cout << '2';
}

void ShowRule()
{
	gotoxy(26, 6); 
	printf("THIS IS THE GAME RULE\n");
	gotoxy(26, 7); 
	system("pause"); 
}

void cls(){
	int i, j;
	for(i = 10; i <= 68; i++){
		
		for(j = 4; j <= 12; j++){
			
			gotoxy(i, j);
			cout << ' ';
		}
	}
}

int IsCoincide(food *f, snake *s, int l){

	int i;
	snake *t = s;
	for(i = 0; i < l; i++){
		if((f->x == (t + i)->x) && (f->y == (t + i)->y)){
			return 1;
		}
	}
	return 0;
}

void GenFood(){

    srand((unsigned)time(0));
	do{
		Food.x = rand() % 72 + 1;
		Food.y = rand() % 19 + 1;
	}
	while(IsCoincide(&Food, Snake1, Snake1Len) || IsCoincide(&Food, Snake2, Snake2Len));
	gotoxy(Food.x, Food.y);
	cout << 'S';
}


void Time(){
	sec--;
   	if((sec == 0) && (mi > 0))
	{
		sec = 60;
		mi--;
	}
    if((mi == 0) && (hour > 0))
	{
		mi = 60;
		hour--;
	}
    gotoxy(34, 23);
	printf("%d:%d:%d", hour, mi, sec);
} 

void MoveSnake1(){
	int var;
	if(Snake1Len == 1){
		gotoxy(Snake1[0].x, Snake1[0].y);
		cout << ' ';
		if(Flag1 == 1)
		{
			Snake1[0].y -= 1;
		}
		else if(Flag1 == 2)
		{
			Snake1[0].y += 1;
		}
		else if(Flag1 == 3)
		{
			Snake1[0].x -= 1;
		}
		else if(Flag1 == 4)
		{
			Snake1[0].x += 1;
		}
		gotoxy(Snake1[0].x, Snake1[0].y);
		cout << '1';
	}
	else{
		if(Flag1 == 1)
		{
			Snake1[0].y -= 1;
		}
		else if(Flag1 == 2)
		{
			Snake1[0].y += 1;
		}
		else if(Flag1 == 3)
		{
			Snake1[0].x -= 1;
		}
		else if(Flag1 == 4)
		{
			Snake1[0].x += 1;
		}
		gotoxy(Snake1[Snake1Len - 1].x, Snake1[Snake1Len - 1].y);
		printf(" ");
		for(var = Snake1Len - 1; var != 0; var--){
			Snake1[var].x = Snake1[var - 1].x;
			Snake1[var].y = Snake1[var - 1].y;
			gotoxy(Snake1[var].x, Snake1[var].y);
			cout << '1';
		}
	}
	
}

void MoveSnake2(){
	int var;
	if(Snake2Len == 1){
		gotoxy(Snake2[0].x, Snake2[0].y);
		cout << ' ';
		if(Flag2 == 1)
		{
			Snake2[0].y -= 1;
		}
		else if(Flag2 == 2)
		{
			Snake2[0].y += 1;
		}
		else if(Flag2 == 3)
		{
			Snake2[0].x -= 1;
		}
		else if(Flag2 == 4)
		{
			Snake2[0].x += 1;
		}
		gotoxy(Snake2[0].x, Snake2[0].y);
		cout << '2';
	}
	else{
		if(Flag2 == 1)
		{
			Snake2[0].y -= 1;
		}
		else if(Flag2 == 2)
		{
			Snake2[0].y += 1;
		}
		else if(Flag2 == 3)
		{
			Snake2[0].x -= 1;
		}
		else if(Flag2 == 4)
		{
			Snake2[0].x += 1;
		}	
		gotoxy(Snake2[Snake2Len - 1].x, Snake2[Snake2Len - 1].y);
		printf(" ");
		for(var = Snake2Len - 1; var != 0; var--)
		{
			Snake2[var].x = Snake2[var - 1].x;
			Snake2[var].y = Snake2[var - 1].y;
			gotoxy(Snake2[var].x, Snake2[var].y);
			cout << '2';
		}	
	}
	
}

void ShowEdge()
{
	int i, j;
	for(i = 0; i < 74; i++)
	{
		gotoxy(i, 0); 
		cout << '0';
	}
	for(j = 1; j < 20; j++)
	{
		gotoxy(0, j); 
		cout << '0';
	}
	for(i = 0; i < 74; i ++)
	{
		gotoxy(i, 20); 
		cout << '0';
	}
	for(j = 1; j < 20; j++)
	{
		gotoxy(73, j); 
		cout << '0';
	}
} 
void PlayGame(){
	int p = 100;		
	GenFood();
	while(1){

		gotoxy(10, 23);
			printf("%d", Snake1_EatCount);
		gotoxy(58, 23);
			printf("%d", Snake2_EatCount);
		Time();
		if(Snake1[0].x == 0 || Snake1[0].y == 0 || Snake1[0].x == 73 || Snake1[0].y == 20)
		{
			Snake1Len = 1;
			Snake1_EatCount = 0;
			gotoxy(10, 23);
			printf("%d", Snake1_EatCount);
			Flag1 = 4;
			Snake1[0].x = 2; 
			Snake1[0].y = 10;
			gotoxy(Snake1[0].x, Snake1[0].y); 
			cout << '1';
			// gotoxy(Snake1[0].x, Snake1[0].y); 
			// printf(" ");
			ShowEdge();
		}
		if(Snake2[0].x == 0 || Snake2[0].y == 0 || Snake2[0].x == 73 || Snake2[0].y == 20)
		{
			Snake2Len = 1;
			Snake2_EatCount = 0;
			gotoxy(58, 23);
			printf("%d", Snake2_EatCount);
			Flag2 = 3;
			Snake2[0].x = 71; 
			Snake2[0].y = 10;
			gotoxy(Snake2[0].x, Snake2[0].y); 
			printf("2");
			// gotoxy(Snake2[0].x, Snake2[0].y); 
			// printf(" ");
			ShowEdge();	
		}
		if(Food.x == Snake1[0].x && Food.y == Snake1[0].y)
		{
			Snake1Len++;
			GenFood();
			Snake1_EatCount++;
			gotoxy(10, 23);
			printf("%d", Snake1_EatCount);
		}
		if(Food.x == Snake2[0].x && Food.y == Snake2[0].y)
		{
			Snake2Len++;
			GenFood();
			Snake2_EatCount++;
			gotoxy(55, 23);
			printf("%d", Snake2_EatCount);
		}		
		MoveSnake1();
		MoveSnake2();
		if(p == 100)
		{
			ShowEdge();
			p = 2;
		}
		switch(ch1)
		{
			case 'w':
				if((Flag1 == 3) || (Flag1 == 4) || (Snake1Len == 1))
					Flag1 = 1;
				break;
			case 's':
				if((Flag1 == 3) || (Flag1 == 4) || (Snake1Len == 1))
					Flag1 = 2;
				break;
			case 'a':
				if((Flag1 == 1) || (Flag1 == 2) || (Snake1Len == 1))
					Flag1 = 3;
				break;
			case 'd':
				if((Flag1 == 1) || (Flag1 == 2) || (Snake1Len == 1))
					Flag1 = 4;
				break;
		}
		switch(ch2)
		{
			case KEY_UP:
				if((Flag2 == 3) || (Flag2 == 4) || (Snake2Len == 1))
					Flag2 = 1;
				break;
			case KEY_DOWN:
				if((Flag2 == 3) || (Flag2 == 4) || (Snake2Len == 1))
					Flag2 = 2;
				break;
			case KEY_LEFT:
				if((Flag2 == 1) || (Flag2 == 2) || (Snake2Len == 1))
					Flag2 = 3;
				break;
			case KEY_RIGHT:
				if((Flag2 == 1) || (Flag2 == 2) || (Snake2Len == 1))
					Flag2 = 4;
				break;
		}
		Sleep(300);
		if(hour == 0 && mi == 0 && sec <= 0)
   		{
   			gotoxy(34, 6);
			   printf("game over!");
   			gotoxy(28, 7);
			   printf("%d", Snake1_EatCount);
   			gotoxy(40, 7);
			   printf("%d", Snake2_EatCount);
   			if(Snake1_EatCount > Snake2_EatCount)
   			{
   				gotoxy(34, 9);
				printf("snake1 win!");
   			}else if(Snake1_EatCount = Snake2_EatCount)
   			{
   				gotoxy(34, 9);
				printf("no result");
   			}else
   			{
   				gotoxy(34, 9);
				printf("snake2 win");

   			}
   			gotoxy(34, 10);
   			printf("string");
   			Sleep(10000);
   			exit(-1);
   		}
	}	
}
