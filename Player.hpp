#pragma once

#include "Game.hpp"
#include "TextureManager.hpp"

class Player
{
public:
	Player();
	~Player();

	void update();
	void render();
	
private:
	SDL_Texture* playerTexture;
	SDL_Point originPlayerTexture;
	SDL_FPoint position;

	SDL_FPoint velocity;
	float maxVelocity;

	float thrust;
	SDL_FPoint accelaration;
	float maxAccelaration;

	float angle;
	float radAngle; // angle in radian
	float angularVelocity;
	float maxAngularVelocity;
	float angularThrust;

	SDL_Rect hitBox;
	SDL_Rect src, dest;
};
