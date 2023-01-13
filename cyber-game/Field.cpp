#include "Field.h"
#include "DxLib.h"

namespace
{
	constexpr int Wall = 5;
}

Field::Field()
{
	x = 0;
	y = 0;
	m_color = GetColor(255, 255, 255);
	m_isFill = true;
}

Field::~Field()
{
}

void Field::init()
{
	m_size.x = 20;
	m_size.y = 20;
	
}

void Field::update(Vec2 pos)
{
	// ”Õ–Ê•\Ž¦
	for ( y = 0; y < kFieldY; y++)
	{
		for (x = 0; x < kFieldX; x++)
		{
			if (x == 0 || x == 11 || y == 0 || y == 21)
			{
				board[y][x] = Wall;
			}
			else
			{
				board[y][x] = 1;
			}
		}
	}
}

void Field::drow()
{
	m_pos.y = 6;
	for ( y = 0; y < kFieldY; y++)
	{
		m_pos.x = 180;
		m_pos.y += m_size.y;
		for ( x = 0; x < kFieldX; x++)
		{
			m_pos.x += m_size.x;
			if (board[y][x] == Wall)
			{
				DrawBox(m_pos.x, m_pos.y, m_pos.x + m_size.x, m_pos.y + m_size.y,
					GetColor(255, 255, 255), true);
			}
			else
			{
				DrawBox(m_pos.x, m_pos.y, m_pos.x + m_size.x, m_pos.y + m_size.y,
					GetColor(100, 100, 100), false);
			}
		}
	}
}
