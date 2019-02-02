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
	sf::FloatRect GetRect();
	sf::FloatRect GetRectWithPosition();
	BoundingBox &GetBoungingBox();


private:
	sf::Sprite mySprite;
	sf::Vector2f myPosition;
	TileType myType;
	sf::FloatRect myRect;
	BoundingBox tileBoundingBox;
};

#endif