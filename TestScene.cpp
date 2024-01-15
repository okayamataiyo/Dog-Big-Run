#include "Engine/Input.h"
#include "Engine/SceneManager.h"
#include "Engine/Sprite.h"
#include "TestScene.h"
#include"Stage.h"


TestScene::TestScene(GameObject* parent)
	:GameObject(parent, "TestScene")
{
}

void TestScene::Initialize()
{
	Instantiate<Stage>(this);
	Sprite* spr;
	spr = new Sprite;
}

void TestScene::Update()
{
}

void TestScene::Draw()
{

}

void TestScene::Release()
{
}
