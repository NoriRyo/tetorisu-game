#include "Field.h"
#include "DxLib.h"

#define WALL 5

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
	//board[h][w] = 1;
	m_size.x = 20;
	m_size.y = 20;
	
}

void Field::update(Vec2 pos)
{
	// ”Õ–Ê•\Ž¦
	for ( y = 0; y < HEIGHT; y++)
	{
		for (x = 0; x < WIDTH; x++)
		{
			if (x == 0 || x == 11 || y == 0 || y == 21)
			{
				board[y][x] = WALL;
				//	DrawBox(m_pos.x, m_pos.y, m_pos.x + m_size.x, m_pos.y + m_size.y,
				//		GetColor(255, 255, 255), false);
			}
			else
			{
				board[y][x] = 1;
				//DrawBox(m_pos.x, m_pos.y, m_pos.x + m_size.x, m_pos.y + m_size.y, 
				//	GetColor(255, 255, 255), false);
			}
		}
	}
}

void Field::drow()
{
	//clsDx();

	m_pos.y = 6;
	for ( y = 0; y < HEIGHT; y++)
	{
		m_pos.x = 180;
		m_pos.y += m_size.y;
		for ( x = 0; x < WIDTH; x++)
		{
			m_pos.x += m_size.x;
			if (board[y][x] == WALL)
			{
				DrawBox(m_pos.x, m_pos.y, m_pos.x + m_size.x, m_pos.y + m_size.y,
					GetColor(255, 255, 255), false);
			}
			else
			{
				//DrawBox(m_pos.x, m_pos.y, m_pos.x + m_size.x, m_pos.y + m_size.y,
				//	GetColor(255, 255, 255), true);
			}
			//printfDx("%d", board[y][x]);
		}
		//printfDx("\n");
	}
}
