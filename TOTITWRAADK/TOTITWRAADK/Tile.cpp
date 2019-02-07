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

	switch (type)
	{
	case Grass:
	{
		break;
	}
	case Water:
	{
		break;
	}
	case Dirt:
	{
		break;
	}
	case Lava:
	{
		break;
	}
	}

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
