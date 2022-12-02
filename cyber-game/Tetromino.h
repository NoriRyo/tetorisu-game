#pragma once
#include "Vec2.h"
class Tetromino
{
public:
	Tetromino();
	virtual~Tetromino();

	void init();

	void update();

	void draw();
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
};

