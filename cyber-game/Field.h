#pragma once
#include "Vec2.h"

#define HEIGHT 22	//�c
#define WIDTH 12	//��

class Field
{
public:
	Field();
	virtual ~Field();

	void init();
	void update();
	void drow();
private:
	// �Ֆ�
	int board[HEIGHT][WIDTH];

	int h;
	int w;

	// �\���ʒu
	Vec2 m_pos;
	// �ړ�
	Vec2 m_vec;

	// �T�C�Y
	Vec2 m_size;
};

