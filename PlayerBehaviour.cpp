#include "PlayerBehaviour.h"



PlayerBehaviour::PlayerBehaviour()
{
}


PlayerBehaviour::~PlayerBehaviour()
{
}

void PlayerBehaviour::Start()
{
	GetTransform()->SetPosition(glm::vec2(10, 320));
	GetFontMgr()->addFont("space", "Fonts/space age.ttf", 24);
}

void PlayerBehaviour::Update(float deltaTime)
{
	if (GetInput()->isKeyDown(VK_UP) && GetTransform()->GetPosition().y - 60 > 0)
	{
		GetTransform()->SetPosition(0, -100 * deltaTime);

	}
	if (GetInput()->isKeyDown(VK_DOWN) && GetTransform()->GetPosition().y < 575)
	{
		GetTransform()->SetPosition(0, 100 * deltaTime);
	}

	//debug draw the center point
	GetFontMgr()->getFont("space")->printText(".", FTPoint(GetSpriteComponent()->GetCenter(GetTransform()->GetPosition()).x, GetSpriteComponent()->GetCenter(GetTransform()->GetPosition()).y, 0));
}

void PlayerBehaviour::OnCollisionEnter(Entity* other)
{

}