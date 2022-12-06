#include "Tetromino.h"
#include "Vec2.h"
#include "DxLib.h"
#include "game.h"
#include "Field.h"

#define EXIST 2		// ë∂ç›Ç∑ÇÈ
#define NOT_EXIST 1	// ë∂ç›ÇµÇ»Ç¢

Tetromino::Tetromino()
{
	m_color = GetColor(255,255,255);
	m_isFill = true;
}

Tetromino::~Tetromino()
{

}

void Tetromino::init()
{
	//m_pos.x = 320;
	//m_pos.y = 320;
	m_vec.x = 20.0f;
	m_vec.y = 20.0f;
	m_size.x = 20;
	m_size.y = 20;
}

void Tetromino::update(Vec2 pos)
{
	// î’ñ ï\é¶

	/*
	for (y = 0; y < HEIGHT; y++)
	{
		for (x = 0; x < WIDTH; x++)
		{
			if (board[y][x] == EXIST)
			{
				WaitTimer(1000);
				board[y][x] = NOT_EXIST;
			}
		}
	}
	*/
	// èâä˙
	for (y = 0; y < HEIGHT; y++)
	{
		for (x = 0; x < WIDTH; x++)
		{
			if( x == 5 && y == 1)
			{
				board[y][x] = EXIST;
			}
			else
			{
				board[y][x] = NOT_EXIST;
			}
		}
	}
	
}

void Tetromino::draw()
{
	clsDx();

	m_pos.y = 6;
	for (y = 0; y < HEIGHT; y++)
	{
		m_pos.x = 180;
		m_pos.y += m_size.y;
		for (x = 0; x < WIDTH; x++)
		{
			m_pos.x += m_size.x;
			if (board[y][x] == EXIST)
			{
				for (int i = 0; i < 30; i++)
				{
					DrawBox(m_pos.x, m_pos.y, m_pos.x + m_size.x, m_pos.y + m_size.y,
						GetColor(255, 0, 0), true);
				}
			}
			else
			{
				//DrawBox(m_pos.x, m_pos.y, m_pos.x + m_size.x, m_pos.y + m_size.y,
				//	GetColor(255, 255, 255), true);
			}
			printfDx("%d", board[y][x]);
		}
		printfDx("\n");
	}
}