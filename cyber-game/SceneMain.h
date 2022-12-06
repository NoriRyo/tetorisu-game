#pragma once
#include "SceneBase.h"
#include "Vec2.h"
#include "Field.h"
#include "Tetromino.h"

class SceneMain : public SceneBase
{
public:
	SceneMain();

	virtual ~SceneMain(){}

	virtual void init() override;
	virtual void end()  override;

	virtual SceneBase* update() override;
	virtual void draw() override;


private:
	// 背景
	int m_hBg;

	// テキスト点滅用フレームカウント
	int m_textBlinkFrame;

	// 表示位置
	Vec2 m_pos;
	// 移動
	Vec2 m_vec;

	Field field;
	Tetromino tetromino;

};