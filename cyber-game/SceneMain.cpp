#include "SceneMain.h"
#include "DxLib.h"
#include "game.h"
#include <cassert>
#include "SceneTitle.h"
#include "Tetromino.h"
#include "Field.h"
#include "Vec2.h"

namespace
{
	// �\�����镶����
	const char* const kTitleText = "�e�g���X";

	// ������_��
	constexpr int kTextDispFrame = 50;
	constexpr int kTextHideFrame = 15;

	// �����F
	const int kFontColor = GetColor(255, 0, 0);
}


SceneMain::SceneMain()
{

}

void SceneMain::init()
{
	field.init();
	tetromino.init();
	m_textBlinkFrame = 0;
	
	m_hBg = LoadGraph("Data/titleBg1.jpg");
}

SceneBase* SceneMain::update()
{
	field.update(m_pos);
	tetromino.update(m_pos);

	// �e�L�X�g�̓_��
	m_textBlinkFrame++;
	if (m_textBlinkFrame >= kTextDispFrame + kTextHideFrame)
	{
		m_textBlinkFrame = 0;
	}

	m_pos.y = 0;
	if(m_pos.y == 100)
	return (new SceneTitle);
}

void SceneMain::end()
{

}

void SceneMain::draw()
{
	DrawGraph(0, 0, m_hBg, false);

	

	if (m_textBlinkFrame < kTextDispFrame)
	{
		int width = GetDrawStringWidth(kTitleText, static_cast<int>(strlen(kTitleText)));
		DrawString(Game::kScreenWidth / 2 - width / 2, 0, kTitleText, kFontColor);
	}

	

	field.drow();

	tetromino.draw();
}