#include "pch.h"
#include "Player.h"
#include "ResourceManager.h"
#include "InputManager.h"
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <fstream>
#include "World.h"

Player::Player(World &aWorld)
	:world(aWorld)
{
	player = ResourceManager::MakeSprite("player", frame, 0, 16, 32);
	playerScale = sf::Vector2f(2.0f, 2.0f);
	player.setOrigin(player.getTextureRect().width / 2, player.getTextureRect().height / 2); //set var mitten är för rotation
	player.setScale(playerScale); //to flip put - infront scalenumber  player.setScale(-4.0f, 4.0f);
	player.setPosition(2000, 2000);

	attack = ResourceManager::MakeSprite("attack", 0, 0, 24, 32);
	attack.setScale(3.0f, 3.0f);
	attack.setOrigin(0, attack.getTextureRect().height / 2);

	std::ifstream config("Resources/config.cfg");
	float number;
	std::string name;
	while (config >> name >> number)
	{
		if (name == "strenght:")
		{
			strenght = number;
		}
		if (name == "intelligent:")
		{
			intelligent = number;
		}
	}
}


Player::~Player()
{

}

void Player::Draw(sf::RenderWindow & window)
{
	//window.draw(collidebox);
	window.draw(player);
	window.draw(attack);
}

void Player::Update(sf::RenderWindow & window, const float &someDeltaTime)
{
	collidebox = sf::RectangleShape(sf::Vector2f(player.getTextureRect().width * player.getScale().x, player.getTextureRect().height * player.getScale().y));
	collidebox.setPosition(player.getPosition());
	collidebox.setOrigin(collidebox.getGlobalBounds().width / 2, collidebox.getGlobalBounds().height / 2);

	attack.setPosition(player.getPosition().x, player.getPosition().y + player.getGlobalBounds().height/4);

	//movementspeed scaling
	movementSpeed = (baseSpeed + (agility/2));

	LookAtMouse(window);

	//draw
	Draw(window);

	//collider checks
	//full body below
	//topTileId = (int)(((int)player.getGlobalBounds().left + ((int)player.getGlobalBounds().width / 2)) / 128) + (((int)player.getGlobalBounds().top / 128) * 100);
	//leftTileId = (int)((int)player.getGlobalBounds().left / 128) + ((((int)player.getGlobalBounds().top + ((int)player.getGlobalBounds().height / 2)) / 128) * 100);
	//botTileId = (int)(((int)player.getGlobalBounds().left + ((int)player.getGlobalBounds().width / 2)) / 128) + ((((int)player.getGlobalBounds().top + (int)player.getGlobalBounds().height) / 128) * 100);
	//rightTileId = (int)(((int)player.getGlobalBounds().left + (int)player.getGlobalBounds().width) / 128) + ((((int)player.getGlobalBounds().top + ((int)player.getGlobalBounds().height / 2)) / 128) * 100);
	//half body, bot part
	int tileSize = 160;
	int xRangeToDetect = 16;
	int yRangeToDetect = 16;
	topTileId = (int)(((int)player.getGlobalBounds().left + ((int)player.getGlobalBounds().width / 2)) / tileSize) + ((((int)player.getGlobalBounds().top - yRangeToDetect + ((int)player.getGlobalBounds().height / 2)) / tileSize)* 100);
	leftTileId = (int)(((int)player.getGlobalBounds().left - xRangeToDetect)/ tileSize) + ((((int)player.getGlobalBounds().top + (((int)player.getGlobalBounds().height / 2) + ((int)player.getGlobalBounds().height/4))) / tileSize) * 100);
	botTileId = (int)(((int)player.getGlobalBounds().left + ((int)player.getGlobalBounds().width / 2)) / tileSize) + ((((int)player.getGlobalBounds().top + yRangeToDetect + (int)player.getGlobalBounds().height) / tileSize) * 100);
	rightTileId = (int)(((int)player.getGlobalBounds().left  + xRangeToDetect + (int)player.getGlobalBounds().width) / tileSize) + ((((int)player.getGlobalBounds().top + (((int)player.getGlobalBounds().height / 2) + ((int)player.getGlobalBounds().height / 4))) / tileSize) * 100);

	//std::cout << "x: " << (int)player.getGlobalBounds().left << "\ny: " << (int)player.getGlobalBounds().top << "\nlefttileid: " << ((((int)player.getGlobalBounds().top + (int)player.getGlobalBounds().height) / 32) * 100) << "\ntileType: " << world.GetTile(leftTileId).GetTypeString();
	//std::cout << "\nx: "<<player.getGlobalBounds().left <<"\ny: " << player.getGlobalBounds().top;

	//basic WASD movement
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		if (world.GetTile(topTileId).GetType() != Lava && (player.getGlobalBounds().left > world.GetTile(topTileId).GetSprite().getGlobalBounds().width || player.getGlobalBounds().width < world.GetTile(topTileId).GetSprite().getGlobalBounds().left))//(world.GetTile(lastTopLeftId + 100).GetType() != Lava || world.GetTile(lastTopRightId + 100).GetType() != Lava) && (world.GetTile(topLeftId).GetType() == Lava || world.GetTile(topRightId).GetType() == Lava))
		{
			player.move(0, -movementSpeed * someDeltaTime);
		}
		else
		{
			player.move(0, 1 * someDeltaTime);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		if (world.GetTile(leftTileId).GetType() != Lava && (player.getGlobalBounds().top > world.GetTile(topTileId).GetSprite().getGlobalBounds().height || player.getGlobalBounds().height < world.GetTile(topTileId).GetSprite().getGlobalBounds().top))
		{
			player.move(-movementSpeed * someDeltaTime, 0);
		}
		else
		{
			player.move(1 * someDeltaTime, 0);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		if (world.GetTile(botTileId).GetType() != Lava && (player.getGlobalBounds().left > world.GetTile(topTileId).GetSprite().getGlobalBounds().width || player.getGlobalBounds().width < world.GetTile(topTileId).GetSprite().getGlobalBounds().left))
		{
			player.move(0, movementSpeed * someDeltaTime);
		}
		else
		{
			player.move(0, -1 * someDeltaTime);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		if (world.GetTile(rightTileId).GetType() != Lava && (player.getGlobalBounds().top > world.GetTile(topTileId).GetSprite().getGlobalBounds().height || player.getGlobalBounds().height < world.GetTile(topTileId).GetSprite().getGlobalBounds().top))
		{
			player.move(movementSpeed * someDeltaTime, 0);
		}
		else
		{
			player.move(-1 * someDeltaTime, 0);
		}
	}


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
	{
		agility -= 1000 * someDeltaTime;
		std::cout << "agility: " << agility << std::endl;
		std::cout << "speed: " << movementSpeed << std::endl;
		std::cout << strenght << std::endl;
		std::cout << intelligent << std::endl;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
	{
		agility += 1000 * someDeltaTime;
		std::cout << "agility: " << agility << std::endl;
		std::cout << "speed: " << movementSpeed << std::endl;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		window.close();
	}
}

sf::Vector2f Player::GetPosition() //mitten av player
{
	return player.getPosition();
}
void Player::SetPosition(sf::Vector2f aPosition)
{
	player.setPosition(aPosition);
}

sf::FloatRect Player::GetRect()
{ //läggas till saker efter getposition för att origin är i mitten av spriten.
	return player.getGlobalBounds(); //sf::FloatRect(player.getPosition().x - ((player.getTextureRect().width * playerScale.x)/2), player.getPosition().y - ((player.getTextureRect().height * playerScale.y) / 2), player.getTextureRect().width * playerScale.x, player.getTextureRect().height * playerScale.y);
}

sf::FloatRect Player::GetRectWithPosition()
{
	return sf::FloatRect(player.getPosition().x - ((player.getTextureRect().width * playerScale.x) / 2), player.getPosition().y - ((player.getTextureRect().height * playerScale.y) / 2), (player.getPosition().x - ((player.getTextureRect().width * playerScale.x) / 2)) + player.getTextureRect().width * playerScale.x, (player.getPosition().y - ((player.getTextureRect().height * playerScale.y) / 2)) + player.getTextureRect().height * playerScale.y);
}

void Player::LookAtMouse(sf::RenderWindow &window)
{
	//hämta width och height från config fil. vi behöver windows storlek för att göra rotate to mouse eftersom player är i mitten och vi behöver windows mitt för att vara en bas man roterar runt om
	std::ifstream config("Resources/config.cfg");
	float number;
	std::string name;
	int windowWidth;
	int windowHeight;
	while (config >> name >> number)
	{
		if (name == "windowWidth:")
		{
			windowWidth = number;
		}
		if (name == "windowHeight:")
		{
			windowHeight = number;
		}
	}

	sf::Vector2i mousepos = InputManager::getMousePosition(window); // now we have both the sprite position and the cursor position lets do the calculation so our sprite will
	// face the position of the mouse
	const float PI = 3.14159265;

	//make cursor pos start 0,0 in middle of screen
	mousepos.x = mousepos.x - windowWidth / 2;
	mousepos.y = mousepos.y - windowHeight / 2;


	//atan = arctan https://www.mathopenref.com/arctan.html <kollar matte
	float radian = atan2(mousepos.y, mousepos.x);
	float rotation = radian * (180 / PI);
	rotation = rotation;

	//std::cout << "mouseposX:" << mousepos.x << " mouseposY:" << mousepos.y << "playerposX:" << player.getPosition().x << "playerposY:" << player.getPosition().y << std::endl;
	//std::cout << "rotation:" << rotation << std::endl;

	//player.setRotation(rotation);
	//collidebox.setRotation(rotation);
	attack.setRotation(rotation);
}