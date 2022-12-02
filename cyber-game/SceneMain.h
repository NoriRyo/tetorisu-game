#pragma once
#include "SceneBase.h"
#include "Vec2.h"
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
	// ”wŒi
	int m_hBg;

	

	// •\Ž¦ˆÊ’u
	Vec2 m_pos;
	// ˆÚ“®
	Vec2 m_vec;

	

	Tetromino tetromino;
	
};