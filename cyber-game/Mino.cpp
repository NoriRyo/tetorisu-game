#include "Mino.h"
#include "Vec2.h"
#include "DxLib.h"
#include "game.h"
#include "Field.h"
#include "Pad.h"

//�@�萔���`
namespace
{
	constexpr int Empty = 0;		// �󂢂Ă���
	constexpr int Stopped = 1;		// �~�܂��Ă���
	constexpr int Moving = 2;		// �����Ă���
	constexpr int Wall = 5;			// ��
	constexpr int WallUnder = 6;	// �ǉ�

	constexpr int kDropFrame = 30;	// 1�u���b�N������̂ɂ�����t���[��
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







	// ����
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

	// �p�b�h(�������̓L�[�{�[�h)����̓��͂��擾����
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

				//�@���͂Ń~�m�����Ɉړ�
				if (padState & PAD_INPUT_LEFT)
				{
					if (field[y][x - 1] == Wall || field[y][x - 1] == Stopped)
					{
						x++;
					}
					x--;
				}
				//�@���͂Ń~�m���E�Ɉړ�
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
				//	//�@�~�m�����Ɉړ�
				//	dropFrameCount = 0;
				//}
				/////////////////////////////////////////////////////////
					
				y++;


				WaitTimer(150);
				// �~�m���Ԃ�������~�܂��Ď��̃~�m���o��
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
			
			// �񂲂Ƃ̃~�m���J�E���g����
			if (field[y][x] == Stopped)
			{
				count += field[y][x];
			}
			// ��̃~�m���P�O�ɂȂ��������
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
			//�@�����Ă���~�m��\��
			if (field[y][x] == Moving)
			{
				DrawBox(m_pos.x, m_pos.y, m_pos.x + m_size.x, m_pos.y + m_size.y,
					GetColor(0, 255, 255), true);
			}
			//�@�~�܂��Ă���~�m��\��
			else if (field[y][x] == Stopped)
			{
				DrawBox(m_pos.x, m_pos.y, m_pos.x + m_size.x, m_pos.y + m_size.y,
					GetColor(0, 255, 255), true);	
			}


			//�@�Ֆʂ̐��l��\���i�f�o�b�O�p�j
			//printfDx("%d", field[y][x]);
		}
		//�@�񂲂Ƃ̃~�m�̐���\��
	//	printfDx("  %d", count);
		printfDx("\n");
	}
}