#ifndef ENEMY_HEADER
#define ENEMY_HEADER
#include <SFML/Graphics.hpp>
#include "EnemyManager.h"

class Enemy
{
public:
	Enemy();
	~Enemy();
	//void UpdateGrunt();
	void Update(sf::RenderWindow &window, const float &someDeltaTime);

	std::vector<EnemyManager> myEnemies;

	sf::Sprite grunt;
	sf::Sprite archer;
	sf::Vector2f gruntScale;
	sf::Vector2f archerScale;

	int archerSpeed;
	int gruntSpeed;
	int frameTimer;
	int enemyFrames;

	void spawnEnemies();
	void initGrunt();
	void initArcher();
private:
	

};

#endif
