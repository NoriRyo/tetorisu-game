#pragma once
#include "Vec2.h"

//#define kFieldX 12	//��
//#define kFieldY 22	//�c

// �Ֆʕ\��
class Field
{
public:
	static constexpr int kFieldX = 12;
	static constexpr int kFieldY = 22;

public:
	Field();
	virtual ~Field();

	void init();
	void update(Vec2 pos);
	void drow();

	// ���̎擾
	Vec2 getPos() const { return m_pos; }

	int board[kFieldY][kFieldX];
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

