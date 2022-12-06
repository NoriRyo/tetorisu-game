#pragma once
#include "Vec2.h"
#include "Field.h"
class Tetromino
{
public:
	Tetromino();
	virtual~Tetromino();

	void init();

	void update(Vec2 pos);

	void draw();

	// 情報の取得
	Vec2 getPos() const { return m_pos; }

	//int GetBoard() const { return board[x][y]; }

private:

	int x;
	int y;

private:
	// 表示位置
	Vec2 m_pos;
	// 移動
	Vec2 m_vec;
	// サイズ
	Vec2 m_size;

	// カラー
	unsigned int m_color;
	// 塗りつぶし
	bool m_isFill;

	//Field field;
	int board[HEIGHT][WIDTH];
};

