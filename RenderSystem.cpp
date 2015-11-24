#include "RenderSystem.h"

RenderSystem* pInstance = NULL;

RenderSystem::RenderSystem()
{
}


RenderSystem::~RenderSystem()
{
}


// WE NOW START WITH RENDERING INDIVIDUAL SPRITES!

void RenderSystem::RenderSprite(Entity* entity)
{
	glLoadIdentity();
	glPushMatrix();

	//glMatrixMode(GL_TEXTURE);
	glTranslatef(entity->GetSpriteComponent()->GetCenter(entity->GetTransform()->GetPosition()).x, entity->GetSpriteComponent()->GetCenter(entity->GetTransform()->GetPosition()).y, 0.0f);
	glRotatef(entity->GetTransform()->GetRotation(), 0.0f, 0.0f, 1.0f);
	glScalef(entity->GetTransform()->GetScale().x, entity->GetTransform()->GetScale().y, 1.0f);
	glTranslatef(-entity->GetSpriteComponent()->GetCenter(entity->GetTransform()->GetPosition()).x, -entity->GetSpriteComponent()->GetCenter(entity->GetTransform()->GetPosition()).y, 0.0f);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, entity->GetSpriteComponent()->GetTexture()); // Binding of GLtexture name 
											   //glMatrixMode(GL_MODELVIEW);


	glBegin(GL_QUADS);
	glColor3f(255.0f, 255.0f, 255.0f);
	glTexCoord2f(entity->GetSpriteComponent()->GetTexCoordData()[0].x, entity->GetSpriteComponent()->GetTexCoordData()[0].y);
	glVertex2f(entity->GetTransform()->GetPosition().x, entity->GetTransform()->GetPosition().y);
	glTexCoord2f(entity->GetSpriteComponent()->GetTexCoordData()[1].x, entity->GetSpriteComponent()->GetTexCoordData()[1].y);
	glVertex2f(entity->GetTransform()->GetPosition().x + entity->GetSpriteComponent()->GetWidth(), entity->GetTransform()->GetPosition().y);
	glTexCoord2f(entity->GetSpriteComponent()->GetTexCoordData()[2].x, entity->GetSpriteComponent()->GetTexCoordData()[2].y);
	glVertex2f(entity->GetTransform()->GetPosition().x + entity->GetSpriteComponent()->GetWidth(), entity->GetTransform()->GetPosition().y + entity->GetSpriteComponent()->GetHeight());
	glTexCoord2f(entity->GetSpriteComponent()->GetTexCoordData()[3].x, entity->GetSpriteComponent()->GetTexCoordData()[3].y);
	glVertex2f(entity->GetTransform()->GetPosition().x, entity->GetTransform()->GetPosition().y + entity->GetSpriteComponent()->GetHeight());

	glEnd();

	glDisable(GL_TEXTURE_2D);

	glPopMatrix();
}

void RenderSystem::Render(Scenegraph* sceneGraph)
{
	for each (Entity* entity in sceneGraph->GetEntities())
	{
		if (entity->GetSpriteComponent())
		{
			RenderSprite(entity);
		}
	}
}

void RenderSystem::SetColor(float r, float g, float b)
{
	glColor3f(r, g, b);
}
