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

	// ���̎擾
	Vec2 getPos() const { return m_pos; }

	//int GetBoard() const { return board[x][y]; }

private:

	int x;
	int y;

private:
	// �\���ʒu
	Vec2 m_pos;
	// �ړ�
	Vec2 m_vec;
	// �T�C�Y
	Vec2 m_size;

	// �J���[
	unsigned int m_color;
	// �h��Ԃ�
	bool m_isFill;

	//Field field;
	int board[HEIGHT][WIDTH];
};

