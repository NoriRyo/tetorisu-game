#include "SceneMain.h"
#include "DxLib.h"
#include "game.h"
#include <cassert>
#include "SceneTitle.h"
#include "Tetromino.h"
#include "Field.h"
#include "Vec2.h"

Field field;
Tetromino tetromino;

SceneMain::SceneMain()
{

}

void SceneMain::init()
{
	field.init();
	tetromino.init();
	
	m_hBg = LoadGraph("Data/titleBg1.jpg");
}

SceneBase* SceneMain::update()
{
	tetromino.update(m_pos);
	field.update(m_pos);

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

	DrawFormatString(0, 0, GetColor(255, 255, 255),
		"ƒeƒgƒŠƒX");

	tetromino.draw();

	field.drow();
}