#include "pch.h"
#include "World.h"
#include "ResourceManager.h"
#include "InputManager.h"
#include <iostream> 

World::World()
{
	int map[] =
	{
		5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
		5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
		5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
		5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
		5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
		5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
		5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
		5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
		5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
		5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
		5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
		5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
		5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
		5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
		5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
		5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
		5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
		5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
		5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
		5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
		5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
		5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
		5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
		5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
		5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
		5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5
	};

	weapon = ResourceManager::MakeSprite("resourceSheet", 0, 0, 128, 128); //define sprite i classen gör att den inte åker tillbaka till origin efter triggered
	consumer = ResourceManager::MakeSprite("resourceSheet", 384, 0, 128, 128); //define sprite i classen gör att den inte åker tillbaka till origin efter triggered
	house = ResourceManager::MakeSprite("resourceSheet", 128, 0, 128, 128); //define sprite i classen gör att den inte åker tillbaka till origin efter triggered
	road = ResourceManager::MakeSprite("resourceSheet", 512, 0, 128, 128); //define sprite i classen gör att den inte åker tillbaka till origin efter triggered
	entertain = ResourceManager::MakeSprite("resourceSheet", 256, 0, 128, 128);
	empty = ResourceManager::MakeSprite("resourceSheet", 640, 0, 128, 128);

	int tileCountWidth = 46;
	int tileCountHeight = 25; //ska vara 1 från totalen pga börjar från 0
	int y = 0;
	for (int x = 0; x < tileCountWidth || y < tileCountHeight; x++)
	{
		if (x >= tileCountWidth)
		{
			x = 0;
			y++;
		}
		int mapTileCount = x + y * tileCountWidth; //det antal nummer på den tile där
		switch (map[mapTileCount])
		{
		case 0:
		{
			myTiles.push_back(Tile(weapon, sf::Vector2f(weapon.getPosition().x + 128 + (x * weapon.getGlobalBounds().width), weapon.getPosition().y + (y * weapon.getGlobalBounds().height)), Weapon));
			break;
		}
		case 3:
		{
			myTiles.push_back(Tile(consumer, sf::Vector2f(consumer.getPosition().x + 128 + (x * consumer.getGlobalBounds().width), consumer.getPosition().y + (y * consumer.getGlobalBounds().height)), Consumer));

			break;
		}
		case 1:
		{
			myTiles.push_back(Tile(house, sf::Vector2f(house.getPosition().x + 128 + (x * house.getGlobalBounds().width), house.getPosition().y + (y * house.getGlobalBounds().height)), House));

			break;
		}
		case 4:
		{
			myTiles.push_back(Tile(road, sf::Vector2f(road.getPosition().x + 128 + (x * road.getGlobalBounds().width), road.getPosition().y + (y * road.getGlobalBounds().height)), Road));

			break;
		}
		case 2:
		{
			myTiles.push_back(Tile(entertain, sf::Vector2f(entertain.getPosition().x + 128 + (x * entertain.getGlobalBounds().width), entertain.getPosition().y + (y * entertain.getGlobalBounds().height)), Entertain));

			break;
		}
		case 5:
		{
			myTiles.push_back(Tile(empty, sf::Vector2f(empty.getPosition().x + 128 + (x * empty.getGlobalBounds().width), empty.getPosition().y + (y * empty.getGlobalBounds().height)), Empty));

			break;
		}
		}
	}
}


World::~World()
{
}

void World::Draw(sf::RenderWindow & window)
{
	for (int i = 0; i < myTiles.size(); i++)
	{
		window.draw(myTiles[i].GetSprite());
	}
}

void World::Update(sf::RenderWindow & window)
{
	Draw(window);
}

