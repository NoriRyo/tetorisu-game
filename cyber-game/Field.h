#pragma once
#include "Vec2.h"

#define HEIGHT 22	//縦
#define WIDTH 12	//横

class Field
{
public:
	Field();
	virtual ~Field();

	void init();
	void update();
	void drow();
private:
	// 盤面
	int board[HEIGHT][WIDTH];

	int h;
	int w;

	// 表示位置
	Vec2 m_pos;
	// 移動
	Vec2 m_vec;

	// サイズ
	Vec2 m_size;
};

