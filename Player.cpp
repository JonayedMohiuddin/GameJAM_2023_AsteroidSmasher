#include "Player.hpp"

#define PLAYER_IMAGE_WIDTH 87
#define PLAYER_IMAGE_HEIGHT 72

Player::Player()
{
	playerTexture = TextureManager::LoadTexture("assets/player.png");

	position = { 0,0 };
	velocity = { 0,0 };
	accelaration = { 0,0 };
	maxVelocity = 5;
	maxAccelaration = 0.05;
	thrust = 0.01;

	angle = 0;
	radAngle = (angle * 3.1416) / 180;
	angularVelocity = 0;
	maxAngularVelocity = 3;
	angularThrust = 1;

	hitBox.x = 0;
	hitBox.y = 0;
	hitBox.w = 64;
	hitBox.h = 64;

	src.x = src.y = 0;
	src.w = PLAYER_IMAGE_WIDTH;
	src.h = PLAYER_IMAGE_HEIGHT;
	originPlayerTexture = { src.w / 2, src.h / 2 };
	dest.x = dest.y = 0;
	dest.w = PLAYER_IMAGE_WIDTH;
	dest.h = PLAYER_IMAGE_HEIGHT;
}

Player::~Player(){}

void Player::update()
{
	if (Game::event.type == SDL_KEYDOWN)
	{
		switch (Game::event.key.keysym.sym)
		{
		case SDLK_UP:
			accelaration.x += thrust * SDL_cos(radAngle);
			accelaration.y += thrust * SDL_sin(radAngle);
			break;
		case SDLK_DOWN:
			accelaration.x -= thrust * SDL_cos(radAngle);
			accelaration.y -= thrust * SDL_sin(radAngle);
			break;
		case SDLK_LEFT:
			angularVelocity -= angularThrust;
			break;
		case SDLK_RIGHT:
			angularVelocity += angularThrust;
			break;
		}
	}
	accelaration.x = SDL_clamp(accelaration.x, -maxAccelaration, maxAccelaration);
	accelaration.y = SDL_clamp(accelaration.y, -maxAccelaration, maxAccelaration);

	if (Game::event.type == SDL_KEYUP)
	{
		switch (Game::event.key.keysym.sym)
		{
		case SDLK_UP:
		case SDLK_DOWN:
			accelaration.x = 0;
			accelaration.y = 0;
			break;
		case SDLK_RIGHT:
		case SDLK_LEFT:
			angularVelocity = 0;
			break;
		}
	}

	angularVelocity = SDL_clamp(angularVelocity, -maxAngularVelocity, maxAngularVelocity);

	velocity.x += accelaration.x;
	velocity.y += accelaration.y;

	angle += angularVelocity;

	if (angle < 0)
		angle += 360;
	else if (angle > 360)
		angle -= 360;

	radAngle = (angle * M_PI) / 180;

	std::cout << angle << std::endl;

	position.x += velocity.x;
	position.y += velocity.y;

	dest.x = position.x;
	dest.y = position.y;
}

void Player::render()
{
	TextureManager::DrawRotated(playerTexture, angle, originPlayerTexture, src, dest);
}



