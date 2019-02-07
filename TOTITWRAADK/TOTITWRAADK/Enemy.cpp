#include "pch.h"
#include "Enemy.h"
#include "ResourceManager.h"
#include "InputManager.h"
#include <iostream>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <time.h>


Enemy::Enemy()
{
	srand(time(NULL));
	initGrunt();
	initArcher();

	for (int i = 0; i < 2; i++)
	{
		myEnemies.push_back(EnemyManager(grunt, sf::Vector2f(0,0), Grunt, gruntSpeed));
		myEnemies.push_back(EnemyManager(archer, sf::Vector2f(0,0), Archer, archerSpeed));
	}

}


Enemy::~Enemy()
{
}

//void Enemy::UpdateGrunt()
//{	
//	grunt.setPosition(100, 100);
//
//	frameTimer--;
//	if (frameTimer <= 0)
//	{
//		enemyFrames += 64;
//		frameTimer = 4;
//		enemyCount ++;
//		maxEnemy++;
//	}
//	if (enemyFrames > 192)
//	{
//		enemyFrames -= 192;
//	}
//
//}
void Enemy::initArcher()
{

	
	archerSpeed = rand() % 8 + 2;
	archerScale = sf::Vector2f(3.f, 3.f);
	archer = ResourceManager::MakeSprite("archer", enemyFrames, 0, 64, 64);
	archer.setScale(archerScale);
	archer.setOrigin(archer.getTextureRect().width / 2, archer.getTextureRect().height / 2);
	std::cout << " Archer ";
	std::cout << archerSpeed;
}
void Enemy::initGrunt()
{

	gruntSpeed = rand() % 7 + 3;
	gruntScale = sf::Vector2f(3.f, 3.f);
	grunt = ResourceManager::MakeSprite("grunt", 0, 0, 64, 64);
	grunt.setScale(gruntScale);
	grunt.setOrigin(grunt.getTextureRect().width / 2, grunt.getTextureRect().height / 2);
	std::cout << "Grunt ";
	std::cout << gruntSpeed;

}

void Enemy::Update(sf::RenderWindow & window)
{
	for (int i = 0; i < myEnemies.size(); i++)
	{
		window.draw(myEnemies[i].GetSprite());

		if (myEnemies[i].GetType() == Grunt)
		{
			myEnemies[i].UpdateGrunt();
		}

		if (myEnemies[i].GetType() == Archer)
		{
			myEnemies[i].UpdateArcher();
			
		}
	}
	
	
}
