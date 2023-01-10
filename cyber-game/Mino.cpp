#include "Mino.h"
#include "Vec2.h"
#include "DxLib.h"
#include "game.h"
#include "Field.h"
#include "Pad.h"

#define MOVING 2		// 存在する
#define NOT_MOVING 1	// 存在しない
#define WALL 5
#define WALL_UNDER 6	// 壁下
#define STOPPED 4		// 止まっている

Mino::Mino()
{
	m_color = GetColor(255, 255, 255);
	m_isFill = true;
	count = 0;
}

Mino::~Mino()
{

}

void Mino::init()
{
	//m_pos.x = 320;
	//m_pos.y = 320;
	m_vec.x = 20.0f;
	m_vec.y = 20.0f;
	m_size.x = 20;
	m_size.y = 20;

	// 初期
	for (y = 0; y < HEIGHT; y++)
	{
		for (x = 0; x < WIDTH; x++)
		{
			if (x == 5 && y == 1)
			{
				board[y][x] = MOVING;
			}
			else
			{
				board[y][x] = NOT_MOVING;
			}
		}
	}
}

void Mino::update(Vec2 pos)
{
	// パッド(もしくはキーボード)からの入力を取得する
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	for (y = 0; y < HEIGHT; y++)
	{
		for (x = 0; x < WIDTH; x++)
		{
			if (x == 0 || x == 11 || y == 0)
			{
				board[y][x] = WALL;
			}
			if (y == 21)
			{
				board[y][x] = WALL_UNDER;
			}

			if (board[y][x] == MOVING)
			{
				board[y][x] = NOT_MOVING;
				WaitTimer(100);

				//　入力でミノを左に移動
				if (padState & PAD_INPUT_LEFT)
				{
					if (board[y][x - 1] == WALL)
					{
						x++;
					}
					x--;
				}
				//　入力でミノを右に移動
				else if (padState & PAD_INPUT_RIGHT)
				{
					if (board[y][x + 1] == WALL)
					{
						x--;
					}
					x++;
				}

				//　ミノを下に移動
				y++;

				// ミノがぶつかったら止まって次のミノを出す
				if (board[y + 1][x] == WALL_UNDER || (board[y + 1][x] == 4))
				{
					board[y][x] = STOPPED;
					
					board[1][5] = MOVING;
					continue;
				}
				board[y][x] = MOVING;
			}

			if (board[y][x] == STOPPED)
			{
				count++;
			}
		}
	}
}

void Mino::draw()
{
	clsDx();
	printfDx("                                                 %d", count);
	printfDx("\n");
	m_pos.y = 6;
	for (y = 0; y < HEIGHT; y++)
	{
		m_pos.x = 180;
		m_pos.y += m_size.y;
		for (x = 0; x < WIDTH; x++)
		{
			m_pos.x += m_size.x;

			//　動いているミノを表示
			if (board[y][x] == MOVING)
			{
				DrawBox(m_pos.x, m_pos.y, m_pos.x + m_size.x, m_pos.y + m_size.y,
					GetColor(255, 0, 0), true);
			}
			//　止まっているミノを表示
			else if (board[y][x] == STOPPED)
			{
				DrawBox(m_pos.x, m_pos.y, m_pos.x + m_size.x, m_pos.y + m_size.y,
					GetColor(255, 255, 255), true);
			}

			//　盤面の数値を表示（デバッグ用）
			printfDx("%d", board[y][x]);
		}
		printfDx("\n");
	}
}