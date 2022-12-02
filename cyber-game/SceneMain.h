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
	// �w�i
	int m_hBg;

	

	// �\���ʒu
	Vec2 m_pos;
	// �ړ�
	Vec2 m_vec;

	

	Tetromino tetromino;
	
};