#ifndef ENEMYMANAGER_HEADER
#define ENEMYMANAGER_HEADER
#include <SFML/Graphics.hpp>
//#include "Player.h"
//
//Player player;
enum EnemyTypes
{
	Grunt, Archer
};

class EnemyManager
{
public:
	EnemyManager();
	EnemyManager(const sf::Sprite &sprite, const sf::Vector2f &position, const EnemyTypes &type,const int &speed);
	~EnemyManager();



	const sf::Sprite &GetSprite();
	const sf::Vector2f &GetPosition();
	const EnemyTypes &GetType();
	const int &GetSpeed();

	void UpdateGrunt();
	void UpdateArcher();

private:

	sf::Sprite mySprite;
	sf::Vector2f myPosition;
	EnemyTypes myType;
	int mySpeed;
	
};
#endif
