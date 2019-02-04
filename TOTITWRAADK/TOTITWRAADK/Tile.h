#ifndef TILE_HEADER
#define TILE_HEADER
#include <SFML/Graphics.hpp>
#include "BoundingBox.h"


enum TileType
{
	Grass,
	Water,
	Dirt,
	Lava,
	Empty
};

class Tile
{
public:
	Tile();
	Tile(const sf::Sprite &sprite, const sf::Vector2f &position, const TileType &type);
	~Tile();

	const sf::Sprite &GetSprite();
	const sf::Vector2f &GetPosition();
	const TileType &GetType();
	const std::string GetTypeString();
	sf::FloatRect GetRect();
	sf::FloatRect GetRectWithPosition();


private:
	sf::Sprite mySprite;
	sf::Vector2f myPosition;
	TileType myType;
	std::string typeString;
	sf::FloatRect myRect;
};

#endif