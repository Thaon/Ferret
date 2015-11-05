#include "SpriteComponent.h"

SpriteComponent::SpriteComponent()
{
	zOrder = 0;
}

//cTexture rocketTxt;
//rocketTxt.createTexture("Images\\rocketSprite.png");
//cSprite rocketSprite;
//rocketSprite.attachInputMgr(theInputMgr); // Attach the input manager to the sprite
//rocketSprite.setSpritePos(glm::vec2(512.0f, 380.0f));
//rocketSprite.setSpriteTranslation(glm::vec2(5.0f, 0.0f));
//rocketSprite.setTexture(rocketTxt.getTexture());
//rocketSprite.setTextureDimensions(rocketTxt.getTWidth(), rocketTxt.getTHeight());

GLuint SpriteComponent::GetTexture()  // Return the sprites current image
{
	return GLTextureID;
}

void SpriteComponent::setTexture(GLuint GLtexID)  // set the image of the sprite
{
	GLTextureID = GLtexID;
}

void SpriteComponent::setSpriteTexCoordData()
{
	spriteTexCoordData[0] = glm::vec2(0.0f, 0.0f);
	spriteTexCoordData[1] = glm::vec2(1.0f, 0.0f);
	spriteTexCoordData[2] = glm::vec2(1.0f, 1.0f);
	spriteTexCoordData[3] = glm::vec2(0.0f, 1.0f);
}

void SpriteComponent::setTextureDimensions(int texWidth, int textHeight)
{
	textureWidth = texWidth;
	textureHeight = textHeight;
}

glm::vec2 SpriteComponent::GetCenter(glm::vec2 position)
{
	spriteCenter = glm::vec2(position.x + textureWidth / 2, position.y + textureHeight / 2);
	return spriteCenter;
}

RECT* SpriteComponent::GetRekt()
{
	return &boundingRect;
}

glm::vec2* SpriteComponent::GetTexCoordData()
{
	return spriteTexCoordData;
}

void SpriteComponent::SetSprite(std::string path)
{
	texture.createTexture(path.c_str());
	setTexture(texture.getTexture());
	setTextureDimensions(texture.getTWidth(), texture.getTHeight());
	setSpriteTexCoordData();
}