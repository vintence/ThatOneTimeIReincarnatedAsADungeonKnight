#include "pch.h"
#include "Player.h"
#include "ResourceManager.h"
#include "InputManager.h"
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <fstream>

Player::Player()
{

	player = ResourceManager::MakeSprite("player", frame, 0, 32, 32);
	playerScale = sf::Vector2f(2.0f, 2.0f);
	player.setOrigin(player.getTextureRect().width / 2, player.getTextureRect().height / 2); //set var mitten är för rotation
	player.setScale(playerScale); //to flip put - infront scalenumber  player.setScale(-4.0f, 4.0f);
	player.setPosition(0, 0);

	attack = ResourceManager::MakeSprite("bullet", 0, 0, 10, 10);
	attack.setOrigin(attack.getTextureRect().width / 2, attack.getTextureRect().height / 2);

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

//Player::Player(Player & aPlayer)
//{
//	*this = aPlayer;
//}


Player::~Player()
{
}

void Player::Draw(sf::RenderWindow & window)
{
	window.draw(player);
	window.draw(attack);
}

void Player::Update(sf::RenderWindow & window)
{
	//std::cout << "\n" <<player.getPosition().x << " y:" << player.getPosition().y; //cout player position
	//movementspeed scaling
	movementSpeed = baseSpeed + (agility / 5);

	LookAtMouse(window);
	//draw
	Draw(window);

	//basic WASD movement
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		if (moveUp == true)
		{
			player.setPosition(GetPosition().x, GetPosition().y - movementSpeed); //can also use player.move('x', 'y');
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		if (moveLeft == true)
		{
			player.setPosition(GetPosition().x - movementSpeed, GetPosition().y); //can also use player.move('x', 'y');
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		if(moveDown == true)
		{
			player.setPosition(GetPosition().x, GetPosition().y + movementSpeed); //can also use player.move('x', 'y');
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		if (moveRight == true)
		{
			player.setPosition(GetPosition().x + movementSpeed, GetPosition().y); //can also use player.move('x', 'y');
		}
	}


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
	{
		agility--;
		std::cout << "agility: " << agility << std::endl;
		std::cout << "speed: " << movementSpeed << std::endl;
		std::cout << strenght << std::endl;
		std::cout << intelligent << std::endl;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
	{
		agility++;
		std::cout << "agility: " << agility << std::endl;
		std::cout << "speed: " << movementSpeed << std::endl;
	}
	if (agility < 0)
	{
		agility = 0;
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

sf::IntRect Player::GetRect()
{ //läggas till saker efter getposition för att origin är i mitten av spriten.
	return sf::IntRect(player.getPosition().x - ((player.getTextureRect().width * playerScale.x)/2), player.getPosition().y - ((player.getTextureRect().height * playerScale.y) / 2), player.getTextureRect().width * playerScale.x, player.getTextureRect().height * playerScale.y);
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
	mousepos.x = mousepos.x - windowWidth/2;
	mousepos.y = mousepos.y - windowHeight/2;


	//atan = arctan https://www.mathopenref.com/arctan.html <kollar matte
	float radian = atan2(mousepos.y, mousepos.x);
	float rotation = radian * (180 / PI);
	rotation = rotation + 90;

	//std::cout << "mouseposX:" << mousepos.x << " mouseposY:" << mousepos.y << "playerposX:" << player.getPosition().x << "playerposY:" << player.getPosition().y << std::endl;
	//std::cout << "rotation:" << rotation << std::endl;

	player.setRotation(rotation);
}