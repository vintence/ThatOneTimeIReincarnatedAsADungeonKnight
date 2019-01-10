#ifndef TILE_HEADER
#define TILE_HEADER
#include <SFML/Graphics.hpp>


enum TileType
{
	House,
	Consumer,
	Weapon,
	Road,
	Entertain,
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

	const float &GetGenerateMoney();
	const float &GetGenerateWeapon();
	const float &GetPopulationCost();
	const float &GetGeneratePopulation();
	const float &GetMoneyCost();
	const float &GetGenerateHappiness();

private:
	sf::Sprite mySprite;
	sf::Vector2f myPosition;
	TileType myType;

	float generateMoney;
	float generateWeapon;
	float populationCost;
	float generatePopulation;
	float moneyCost;
	float generateHappiness;
};

#endif