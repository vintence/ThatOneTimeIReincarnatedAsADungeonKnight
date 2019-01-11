#include "pch.h"
#include "Player.h"
#include "ResourceManager.h"
#include "InputManager.h"
#include <iostream>
#include <fstream>
#include <string>

Player::Player()
{
	player = ResourceManager::MakeSprite("player", 0, 0, 32, 32);
	playerScale = sf::Vector2f(4.0f, 4.0f);
	player.setOrigin(player.getTextureRect().width / 2, player.getTextureRect().height / 2);
	player.setScale(playerScale); //to flip put - infront scalenumber  player.setScale(-4.0f, 4.0f);
	player.setPosition(0, 0);

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
	window.draw(player);
}

void Player::Update(sf::RenderWindow & window)
{

	//movementspeed scaling
	movementSpeed = baseSpeed + (agility / 5);

	//draw
	Draw(window);

	//flip player on mouse position
	if (InputManager::getMousePosition(window).x < window.getSize().x / 2)
	{
		player.setScale(-playerScale.x, playerScale.y);
	}
	else
	{
		player.setScale(playerScale);
	}

	//
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		player.setPosition(GetPosition().x, GetPosition().y - movementSpeed); //can also use player.move('x', 'y');
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		player.setPosition(GetPosition().x, GetPosition().y + movementSpeed); //can also use player.move('x', 'y');
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		player.setPosition(GetPosition().x - movementSpeed, GetPosition().y); //can also use player.move('x', 'y');
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		player.setPosition(GetPosition().x + movementSpeed, GetPosition().y); //can also use player.move('x', 'y');
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

sf::Vector2f Player::GetPosition()
{
	return sf::Vector2f(player.getPosition());
}
