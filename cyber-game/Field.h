#pragma once
#include "Vec2.h"

#define HEIGHT 22	//�c
#define WIDTH 12	//��

// �Ֆʕ\��
class Field
{
public:
	Field();
	virtual ~Field();

	void init();
	void update(Vec2 pos);
	void drow();

	// ���̎擾
	Vec2 getPos() const { return m_pos; }

	int board[HEIGHT][WIDTH];
private:
	// �Ֆ�

	int x;
	int y;

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

