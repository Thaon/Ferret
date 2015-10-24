#pragma once
// Image Texture loading library
#include <string>
#include "IL\il.h"
#include "IL\ilu.h"
#include "IL\ilut.h"
#include "glm\glm.hpp"
#include "cTexture.h"
#include <cstdlib>

class SpriteComponent
{
private:
	SpriteComponent(const SpriteComponent&) = delete;
	SpriteComponent & operator = (SpriteComponent&) = delete;

	RECT boundingRect;
	int zOrder;

	glm::vec2 spriteCenter;

	//texturing
	glm::vec2 spriteVertexData[4];
	glm::vec2 spriteTexCoordData[4];

	// Texture width & Height
	int textureWidth;
	int textureHeight;
	GLuint GLTextureID;

public:
	SpriteComponent();

	//getters
	glm::vec2 GetCenter();
	GLuint GetTexture();  // Return the sprites current image
	RECT* GetRekt();
	glm::vec2* GetTexCoordData();
	int GetWidth() { return textureWidth; }
	int GetHeight() { return textureHeight; }

	//setters
	void setTexture(GLuint GLtexID);  // set the image of the sprite
	void setSpriteTexCoordData();
	void setTextureDimensions(int texWidth, int textHeight);
	void SetSprite(std::string path);
};