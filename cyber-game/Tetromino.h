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
};

