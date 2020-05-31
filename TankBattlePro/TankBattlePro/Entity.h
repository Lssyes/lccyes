#pragma once
#ifndef _ENTITY_H_
#define _ENTITY_H_
#include "framework.h"

enum Dir { UP, DOWN, LEFT, RIGHT, NONE };
typedef struct entity {
	int x, y;
	Dir dir;
	int v;
	int s;
	int p;
	HBITMAP a[4];
	int life;
	struct entity* next;			// 下一个节点的指针
	unsigned short f;				// 当前正在绘制的这一帧
	unsigned short frames;			// 表示一共有多少帧
	int animD;						// 控制当前动画帧的下一帧的方向
}Entity;
void DrawEntities(HDC hdc, const Entity* head);
void DrawEntity(HDC hdc, const Entity* ent);
void MoveEntities(Entity* head, int ts);
void Move(Entity* ent, int ts);
void Fire(const Entity* ent, Entity* pHeadB);
void Destory(Entity* pHead);
void Destory(Entity* pHead, Entity* ent);
int IsCollider(const Entity* ent1, const Entity* ent2);
int WallCollider(Entity* ent, int w, int h);
void NextFrameEntities(Entity* head, int ts);
void NextFrame(Entity* ent, int ts);




#endif