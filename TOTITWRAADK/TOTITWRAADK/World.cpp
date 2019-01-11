#include "pch.h"
#include "World.h"
#include "ResourceManager.h"
#include "InputManager.h"
#include <iostream> 

World::World()
{
	int map[] =
	{
		3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,
		3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,
		3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,
		3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,
		3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,
		2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,1,1,1,1,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,2,2,2,1,1,1,1,1,1,1,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,2,2,1,1,1,1,1,1,1,1,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,2,2,2,1,1,1,1,1,1,1,1,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,1,1,1,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,1,1,1,1,1,1,1,1,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,1,1,1,1,1,1,1,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,1,1,1,1,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1

	};

	//weapon = ResourceManager::MakeSprite("resourceSheet", 0, 0, 128, 128); //define sprite i classen g�r att den inte �ker tillbaka till origin efter triggered
	//consumer = ResourceManager::MakeSprite("resourceSheet", 384, 0, 128, 128); //define sprite i classen g�r att den inte �ker tillbaka till origin efter triggered
	//house = ResourceManager::MakeSprite("resourceSheet", 128, 0, 128, 128); //define sprite i classen g�r att den inte �ker tillbaka till origin efter triggered
	//road = ResourceManager::MakeSprite("resourceSheet", 512, 0, 128, 128); //define sprite i classen g�r att den inte �ker tillbaka till origin efter triggered
	//entertain = ResourceManager::MakeSprite("resourceSheet", 256, 0, 128, 128);
	grass = ResourceManager::MakeSprite("resourceSheet", 0, 0, 32, 32);
	grass.setScale(3.0f, 3.0f);
	water = ResourceManager::MakeSprite("resourceSheet", 32, 0, 32, 32);
	water.setScale(3.0f, 3.0f);
	dirt = ResourceManager::MakeSprite("resourceSheet", 0, 32, 32, 32);
	dirt.setScale(3.0f, 3.0f);
	lava = ResourceManager::MakeSprite("resourceSheet", 32, 32, 32, 32);
	lava.setScale(3.0f, 3.0f);
	empty = ResourceManager::MakeSprite("resourceSheet", 64, 0, 32, 32);
	empty.setScale(3.0f, 3.0f);

	int tileCountWidth = 60;
	int tileCountHeight = 33; //ska vara 1 fr�n totalen pga b�rjar fr�n 0
	int y = 0;
	for (int x = 0; x < tileCountWidth || y < tileCountHeight; x++)
	{
		if (x >= tileCountWidth)
		{
			x = 0;
			y++;
		}
		int mapTileCount = x + y * tileCountWidth; //det antal nummer p� den tile d�r
		switch (map[mapTileCount])
		{
		case 0:
		{
			myTiles.push_back(Tile(grass, sf::Vector2f(grass.getPosition().x + 128 + (x * grass.getGlobalBounds().width), grass.getPosition().y + (y * grass.getGlobalBounds().height)), Grass));
			break;
		}
		case 1:
		{
			myTiles.push_back(Tile(water, sf::Vector2f(water.getPosition().x + 128 + (x * water.getGlobalBounds().width), water.getPosition().y + (y * water.getGlobalBounds().height)), Water));

			break;
		}
		case 2:
		{
			myTiles.push_back(Tile(dirt, sf::Vector2f(dirt.getPosition().x + 128 + (x * dirt.getGlobalBounds().width), dirt.getPosition().y + (y * dirt.getGlobalBounds().height)), Dirt));

			break;
		}
		case 3:
		{
			myTiles.push_back(Tile(lava, sf::Vector2f(lava.getPosition().x + 128 + (x * lava.getGlobalBounds().width), lava.getPosition().y + (y * lava.getGlobalBounds().height)), Lava));

			break;
		}
		case 4:
		{
			myTiles.push_back(Tile(empty, sf::Vector2f(empty.getPosition().x + 128 + (x * empty.getGlobalBounds().width), empty.getPosition().y + (y * empty.getGlobalBounds().height)), Empty));

			break;
		}
		}
	}

	//for (int x = 0; x < tileCountWidth || y < tileCountHeight; x++)
	//{
	//	if (x >= tileCountWidth)
	//	{
	//		x = 0;
	//		y++;
	//	}
	//	int mapTileCount = x + y * tileCountWidth; //det antal nummer p� den tile d�r
	//	switch (map[mapTileCount])
	//	{
	//	case 0:
	//	{
	//		myTiles.push_back(Tile(weapon, sf::Vector2f(weapon.getPosition().x + 128 + (x * weapon.getGlobalBounds().width), weapon.getPosition().y + (y * weapon.getGlobalBounds().height)), Weapon));
	//		break;
	//	}
	//	case 3:
	//	{
	//		myTiles.push_back(Tile(consumer, sf::Vector2f(consumer.getPosition().x + 128 + (x * consumer.getGlobalBounds().width), consumer.getPosition().y + (y * consumer.getGlobalBounds().height)), Consumer));

	//		break;
	//	}
	//	case 1:
	//	{
	//		myTiles.push_back(Tile(house, sf::Vector2f(house.getPosition().x + 128 + (x * house.getGlobalBounds().width), house.getPosition().y + (y * house.getGlobalBounds().height)), House));

	//		break;
	//	}
	//	case 4:
	//	{
	//		myTiles.push_back(Tile(road, sf::Vector2f(road.getPosition().x + 128 + (x * road.getGlobalBounds().width), road.getPosition().y + (y * road.getGlobalBounds().height)), Road));

	//		break;
	//	}
	//	case 2:
	//	{
	//		myTiles.push_back(Tile(entertain, sf::Vector2f(entertain.getPosition().x + 128 + (x * entertain.getGlobalBounds().width), entertain.getPosition().y + (y * entertain.getGlobalBounds().height)), Entertain));

	//		break;
	//	}
	//	case 5:
	//	{
	//		myTiles.push_back(Tile(empty, sf::Vector2f(empty.getPosition().x + 128 + (x * empty.getGlobalBounds().width), empty.getPosition().y + (y * empty.getGlobalBounds().height)), Empty));

	//		break;
	//	}
	//	}
	//}
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

