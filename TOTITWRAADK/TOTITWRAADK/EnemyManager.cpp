#include "pch.h"
#include "EnemyManager.h"
#include "Enemy.h"
#include "Player.h"

EnemyManager::EnemyManager()
{
	
}

//Player player;

EnemyManager::EnemyManager(const sf::Sprite &sprite, const sf::Vector2f &position, const EnemyTypes &type, const int &speed)
{

	mySprite = sprite;
	mySprite.setPosition(position);
	myPosition = position;
	myType = type;
	mySpeed = speed;

	switch (type)
	{
	case Grunt:
	{
		break;
	}
	case Archer:
	{
		break;
	}

	}

}

EnemyManager::~EnemyManager()
{

}

const sf::Sprite & EnemyManager::GetSprite()
{
	return mySprite;
}

const sf::Vector2f & EnemyManager::GetPosition()
{
	return myPosition;
}

const EnemyTypes & EnemyManager::GetType()
{
	return myType;
}
const int & EnemyManager::GetSpeed()
{
	return mySpeed;
}



void EnemyManager::MoveGruntRight(const float &someDeltaTime)
{
	mySprite.move(mySpeed * someDeltaTime, 0);
}

void EnemyManager::MoveGruntLeft(const float &someDeltaTime)
{
	mySprite.move(- mySpeed * someDeltaTime, 0);
}
//void EnemyManager::MoveGruntUp(const float &someDeltaTime)
//{
//	mySprite.move(0,- mySpeed * someDeltaTime);
//}
//void EnemyManager::MoveGruntDown(const float &someDeltaTime)
//{
//
//	mySprite.move(0, mySpeed * someDeltaTime);
//}




void EnemyManager::UpdateArcher(const float &someDeltaTime)
{

	mySprite.move(0, mySpeed * someDeltaTime);
}
