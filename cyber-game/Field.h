#pragma once
#include "Vec2.h"

#define HEIGHT 22	//縦
#define WIDTH 12	//横

// 盤面表示
class Field
{
public:
	Field();
	virtual ~Field();

	void init();
	void update(Vec2 pos);
	void drow();

	// 情報の取得
	Vec2 getPos() const { return m_pos; }

	int board[HEIGHT][WIDTH];
private:
	// 盤面

	int x;
	int y;

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

