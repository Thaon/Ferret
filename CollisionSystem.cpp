#include "CollisionSystem.h"


CollisionSystem::CollisionSystem()
{
}

CollisionSystem::~CollisionSystem()
{
}

void CollisionSystem::Update(Scenegraph* scene)
{
	for each (Entity* collider in scene->GetEntities())
	{
		if (collider->GetCollision2DComponent() != NULL)
		{
			//update the position of the colliders
			collider->GetCollision2DComponent()->SetBoundingBox(collider->GetTransform()->GetPosition(), collider->GetSpriteComponent()->GetWidth(), collider->GetSpriteComponent()->GetHeight());
			//check for collisions against other colliders
			for each (Entity* collider2 in scene->GetEntities())
			{
				//need to check if the last collider was tested and break or each collider will be tested N times, massive slow down ahead!!!
				if (collider2 != collider)//we cannot collide with ourselves
				{
					if ((collider->GetCollision2DComponent()->GetBoundingBox()->left < collider2->GetCollision2DComponent()->GetBoundingBox()->right
						&& collider->GetCollision2DComponent()->GetBoundingBox()->right > collider2->GetCollision2DComponent()->GetBoundingBox()->left
						&& collider->GetCollision2DComponent()->GetBoundingBox()->top < collider2->GetCollision2DComponent()->GetBoundingBox()->bottom
						&& collider->GetCollision2DComponent()->GetBoundingBox()->bottom > collider2->GetCollision2DComponent()->GetBoundingBox()->top))
					{
						if (collider->GetBehaviour() != NULL)//notify collider 1
						{
							collider->GetBehaviour()->OnCollisionEnter(collider2);
						}

						if (collider2->GetBehaviour() != NULL)//notify collider 2
						{
							collider2->GetBehaviour()->OnCollisionEnter(collider);
						}
					}
				}
			}
		}
	}
}