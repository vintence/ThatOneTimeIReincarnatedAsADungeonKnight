#ifndef WORLD_HEADER
#define WORLD_HEADER

#include <SFML/Graphics.hpp>
#include "Tile.h"
#include <vector>


class World
{
public:
	World();
	~World();
	void Update(sf::RenderWindow &window);
	void Draw(sf::RenderWindow &window);

	Tile GetTile(int tileId);

private:
	sf::Sprite dirt;
	sf::Sprite grass;
	sf::Sprite lava;
	sf::Sprite water;
	sf::Sprite empty;

	sf::Vector2f tileScale;

	std::vector<Tile> myTiles;
	std::vector<Tile> conCreteTiles;


};

#endif