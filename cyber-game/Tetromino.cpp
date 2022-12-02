#include "Tetromino.h"
#include "Vec2.h"
#include "DxLib.h"
#include "game.h"

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
	//m_vec.x = 0.0f;
	//m_vec.y = 0.0f;
}

void Tetromino::update()
{
	///m_pos.x = ;
	//m_pos.y = ;
}

void Tetromino::draw()
{
	DrawBox(240, 0, 256, 16, m_color, m_isFill);
}


