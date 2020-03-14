#ifndef _FUNCTION_H_
#define _FUNCTION_H_
#include <iostream>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include "snake.h"
#include "food.h"
#include "gotoxy.h"
using namespace std;
#define A '0'
#define KEY_DOWN    80
#define KEY_UP      72
#define KEY_RIGHT   77
#define KEY_LEFT    75

void ShowInterface();
void ShowOperate();
void PaintSnake();
void ShowRule();
void cls();
void GenFood();
void Time();
void MoveSnake1();
void MoveSnake2();
void ShowEdge();
void PlayGame();
#endif
