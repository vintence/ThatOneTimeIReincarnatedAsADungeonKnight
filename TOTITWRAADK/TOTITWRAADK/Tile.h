#ifndef TILE_HEADER
#define TILE_HEADER
#include <SFML/Graphics.hpp>


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

private:
	sf::Sprite mySprite;
	sf::Vector2f myPosition;
	TileType myType;
};

#endif