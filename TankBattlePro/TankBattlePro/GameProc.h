#pragma once
#ifndef _GAME_PROC_
#define _GAME_PROC_
#include "framework.h"
#include "Entity.h"

enum LEVEL { OPEN, LEVEL1, LEVEL2_OPEN, LEVEL2, SUCCEED, FAIL };
void EnterKey(int key);
void NewEntity();
void ChangeWndSize(int w, int h);
void ChangeLevel(LEVEL newL);
void ResetPlayer(Entity* player);
void Draw(HDC hdc, HWND hWnd);
void DrawScene(HDC hdc, LEVEL curL);
void DrawGameScene(HDC hdc);//游戏内容绘制
void Update(int ts);
void EnemyBirth();
void Destory();//动态分配的内容释放
void NextFrame(int ts);













#endif