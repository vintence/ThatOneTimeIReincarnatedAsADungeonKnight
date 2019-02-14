#ifndef ENEMYMANAGER_HEADER
#define ENEMYMANAGER_HEADER
#include <SFML/Graphics.hpp>


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

	void MoveGruntRight(const float &someDeltaTime);
	void MoveGruntLeft(const float &someDeltaTime);
	void MoveGruntUp(const float &someDeltaTime);
	void MoveGruntDown(const float &someDeltaTime);

	void MoveToPlayer();
	void UpdateArcher(const float &someDeltaTime);

private:

	sf::Sprite mySprite;
	sf::Vector2f myPosition;
	EnemyTypes myType;
	int mySpeed;
	
};
#endif
