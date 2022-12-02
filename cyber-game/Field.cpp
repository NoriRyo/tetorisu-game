#include "Field.h"
#include "DxLib.h"

Field::Field()
{
}

Field::~Field()
{
}

void Field::init()
{
	m_size.x = 20;
	m_size.y = 20;
}

void Field::update()
{
}

void Field::drow()
{
	// ”Õ–Ê•\Ž¦
	m_pos.y = 6;
	for (h = 0; h < HEIGHT; h++)
	{
		m_pos.x = 180;
		m_pos.y += m_size.y;
		for (w = 0; w < WIDTH; w++)
		{
			m_pos.x += m_size.x;
			if (w == 0 || w == 11 || h == 0 || h == 21)
			{

				DrawBox(m_pos.x, m_pos.y, m_pos.x + m_size.x, m_pos.y + m_size.y,
					GetColor(255, 255, 255), false);
			}
			else
			{
				//DrawBox(m_pos.x, m_pos.y, m_pos.x + m_size.x, m_pos.y + m_size.y, 
				//	GetColor(255, 255, 255), false);
			}
		}
	}
}
