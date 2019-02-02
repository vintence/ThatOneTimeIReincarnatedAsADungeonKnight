#ifndef WORLD_HEADER
#define WORLD_HEADER

#include <SFML/Graphics.hpp>
#include "Tile.h"
#include <vector>

class Player;

class World
{
public:
	//World();
	World(Player &aPlayer);
	~World();
	void Update(sf::RenderWindow &window);
	void Draw(sf::RenderWindow &window);
	//sf::IntRect GetRect(sf::Sprite aSprite);
	//sf::IntRect GetRectWithPosition(sf::Sprite aSprite);

	//void SetPlayer(Player &aPlayer);

private:
	Player &player;
	//sf::Sprite weapon;
	//sf::Sprite consumer;
	//sf::Sprite house;
	//sf::Sprite road;
	//sf::Sprite entertain;
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