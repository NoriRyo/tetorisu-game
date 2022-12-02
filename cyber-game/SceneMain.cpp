#include "SceneMain.h"
#include "DxLib.h"
#include "game.h"
#include <cassert>
#include "SceneTitle.h"
#include "Tetromino.h"
#include "Field.h"

Field field;

SceneMain::SceneMain()
{

}

void SceneMain::init()
{
	field.init();

	
	m_hBg = LoadGraph("Data/titleBg1.jpg");
}

SceneBase* SceneMain::update()
{
	field.update();

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

	field.drow();

	//tetromino.draw();
}