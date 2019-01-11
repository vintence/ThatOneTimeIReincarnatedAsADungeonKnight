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

private:
	sf::Sprite weapon;
	sf::Sprite consumer;
	sf::Sprite house;
	sf::Sprite road;
	sf::Sprite entertain;
	sf::Sprite empty;

	sf::Vector2f tileScale;

	std::vector<Tile> myTiles;
};

#endif