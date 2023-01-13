#include "Mino.h"
#include "Vec2.h"
#include "DxLib.h"
#include "game.h"
#include "Field.h"
#include "Pad.h"

//　定数を定義
namespace
{
	constexpr int Empty = 0;		// 空いている
	constexpr int Stopped = 1;		// 止まっている
	constexpr int Moving = 2;		// 動いている
	constexpr int Wall = 5;			// 壁
	constexpr int WallUnder = 6;	// 壁下

	constexpr int kDropFrame = 30;	// 1ブロック落ちるのにかかるフレーム
}

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
	m_vec.x = 20.0f;
	m_vec.y = 20.0f;
	m_size.x = 20;
	m_size.y = 20;

	


	int mino[4][4] =
	{
		// Z
		{0,0,0,0},
		{1,1,0,0},
		{0,1,1,0},
		{0,0,0,0}
	};







	// 初期
	for (int y = 0; y < kFieldY; y++)
	{
		for (x = 0; x < kFieldX; x++)
		{
			if (x == 6  && y == 1)
			{
				field[y][x] = Moving;
			}
			else
			{
				field[y][x] = Empty;
			}
		}
	}
}

void Mino::update(Vec2 pos)
{

	int dropFrameCount = 0;

	// パッド(もしくはキーボード)からの入力を取得する
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	for (y = 0; y < kFieldY; y++)
	{
		for (x = 0; x < kFieldX; x++)
		{
			if (x == 0 || x == 11 || y == 0)
			{
				field[y][x] = Wall;
			}
			if (y == 21)
			{
				field[y][x] = WallUnder;
			}

			if (field[y][x] == Moving)
			{
				field[y][x] = Empty;

				//　入力でミノを左に移動
				if (padState & PAD_INPUT_LEFT)
				{
					if (field[y][x - 1] == Wall || field[y][x - 1] == Stopped)
					{
						x++;
					}
					x--;
				}
				//　入力でミノを右に移動
				else if (padState & PAD_INPUT_RIGHT)
				{
					if (field[y][x + 1] == Wall || field[y][x + 1] == Stopped)
					{
						x--;
					}
					x++;
				}

				//////////////////////////////////////////////////////////
				//dropFrameCount ++;
				//if (dropFrameCount >= kDropFrame)
				//{
				//	//　ミノを下に移動
				//	dropFrameCount = 0;
				//}
				/////////////////////////////////////////////////////////
					
				y++;


				WaitTimer(150);
				// ミノがぶつかったら止まって次のミノを出す
				if (field[y + 1][x] == WallUnder || (field[y + 1][x] == Stopped))
				{
					field[y][x] = Stopped;
					
					field[1][6] = Moving;
					continue;
				}
				field[y][x] = Moving;
			}
		}
	}
}

void Mino::draw()
{
	clsDx();
	printfDx("\n");
	m_pos.y = 6;
	for (y = 0; y < kFieldY; y++)
	{
		count = 0;
		m_pos.x = 180;
		m_pos.y += m_size.y;
		for (x = 0; x < kFieldX; x++)
		{
			m_pos.x += m_size.x;
			
			// 列ごとのミノをカウントする
			if (field[y][x] == Stopped)
			{
				count += field[y][x];
			}
			// 列のミノが１０になったら消す
			if (count == 10)
			{
				for (x = 0; x < kFieldX; x++)
				{
					if (field[y][x] == Stopped)
					{
						field[y][x] = Empty;
					}
				}
			}
			//　動いているミノを表示
			if (field[y][x] == Moving)
			{
				DrawBox(m_pos.x, m_pos.y, m_pos.x + m_size.x, m_pos.y + m_size.y,
					GetColor(0, 255, 255), true);
			}
			//　止まっているミノを表示
			else if (field[y][x] == Stopped)
			{
				DrawBox(m_pos.x, m_pos.y, m_pos.x + m_size.x, m_pos.y + m_size.y,
					GetColor(0, 255, 255), true);	
			}


			//　盤面の数値を表示（デバッグ用）
			//printfDx("%d", field[y][x]);
		}
		//　列ごとのミノの数を表示
	//	printfDx("  %d", count);
		printfDx("\n");
	}
}