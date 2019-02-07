#include "pch.h"
#include "EnemyManager.h"
#include "Enemy.h"



EnemyManager::EnemyManager()
{
	
}


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



void EnemyManager::UpdateGrunt()
{
	//if (mySprite.getPosition().x < player.GetPosition().x)
	//{
		mySprite.move(0, mySpeed);
	/*}*/

}

void EnemyManager::UpdateArcher()
{

	mySprite.move(0, mySpeed);
}
