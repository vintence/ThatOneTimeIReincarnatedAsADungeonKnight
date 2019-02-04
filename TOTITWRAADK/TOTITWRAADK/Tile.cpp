#include "pch.h"
#include "Tile.h"


Tile::Tile()
{

}

Tile::Tile(const sf::Sprite &sprite, const sf::Vector2f &position, const TileType &type)
{
	mySprite = sprite;
	mySprite.setPosition(position);
	myPosition = position;
	myType = type;
	myRect = mySprite.getGlobalBounds();

	switch (type)
	{
	case Grass:
	{
		typeString = "Grass";
		break;
	}
	case Water:
	{
		typeString = "Water";
		break;
	}
	case Dirt:
	{
		typeString = "Dirt";
		break;
	}
	case Lava:
	{
		typeString = "Lava";
		break;
	}
	}

	//switch (type)
	//{
	//case Weapon:
	//{
	//	generateWeapon = 10;
	//	generateMoney = 0;
	//	populationCost = 10;
	//	generatePopulation = 0;
	//	moneyCost = 100;
	//	break;
	//}
	//case House:
	//{
	//	generateWeapon = 0;
	//	generateMoney = 0;
	//	populationCost = 0;
	//	generatePopulation = 5;
	//	moneyCost = 50;
	//	generateHappiness = 0;
	//	break;
	//}
	//case Consumer:
	//{
	//	generateWeapon = 0;
	//	generateMoney = 50;
	//	populationCost = 5;
	//	generatePopulation = 0;
	//	moneyCost = 150;
	//	generateHappiness = 0;
	//	break;
	//}
	//case Entertain:
	//{
	//	generateWeapon = 0;
	//	generateMoney = 25;
	//	populationCost = 5;
	//	generatePopulation = 0;
	//	moneyCost = 100;
	//	generateHappiness = 0.5;
	//	break;
	//}
	//case Road:
	//{
	//	generateWeapon = 0;
	//	generateMoney = 0;
	//	populationCost = 0;
	//	generatePopulation = 0;
	//	moneyCost = 10;
	//	generateHappiness = 0;
	//	break;
	//}
	//}
}
Tile::~Tile()
{

}

const sf::Sprite & Tile::GetSprite()
{
	return mySprite;
}

const sf::Vector2f & Tile::GetPosition()
{
	return myPosition;
}

const TileType & Tile::GetType()
{
	return myType;
}

const std::string Tile::GetTypeString()
{
	return typeString;
}

sf::FloatRect Tile::GetRect()
{
	return myRect; //sf::IntRect(myPosition.x, myPosition.y, mySprite.getTextureRect().width, mySprite.getTextureRect().height);
}
sf::FloatRect Tile::GetRectWithPosition()
{
	return sf::FloatRect(myPosition.x, myPosition.y, myPosition.x + (mySprite.getTextureRect().width * mySprite.getScale().x), myPosition.y + (mySprite.getTextureRect().height * mySprite.getScale().y));
}