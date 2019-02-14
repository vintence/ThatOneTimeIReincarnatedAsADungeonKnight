#include "pch.h"
#include "Enemy.h"
#include "ResourceManager.h"
#include "InputManager.h"
#include <iostream>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Player.h"

Enemy::Enemy()
{
	srand(time(NULL));
	initGrunt();
	initArcher();

	for (int i = 0; i < 2; i++)
	{
		myEnemies.push_back(EnemyManager(grunt, sf::Vector2f(2000,2000), Grunt, gruntSpeed));
		myEnemies.push_back(EnemyManager(archer, sf::Vector2f(2000,2000), Archer, archerSpeed));
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

	
	archerSpeed = rand() % 400 + 100;
	archerScale = sf::Vector2f(3.f, 3.f);
	archer = ResourceManager::MakeSprite("archer", enemyFrames, 0, 64, 64);
	archer.setScale(archerScale);
	archer.setOrigin(archer.getTextureRect().width / 2, archer.getTextureRect().height / 2);
	std::cout << " Archer ";
	std::cout << archerSpeed;
}
void Enemy::initGrunt()
{

	gruntSpeed = rand() % 150 + 50;
	gruntScale = sf::Vector2f(3.f, 3.f);
	grunt = ResourceManager::MakeSprite("grunt", 0, 0, 64, 64);
	grunt.setScale(gruntScale);
	grunt.setOrigin(grunt.getTextureRect().width / 2, grunt.getTextureRect().height / 2);
	std::cout << "Grunt ";
	std::cout << gruntSpeed;

}

void Enemy::Update(sf::RenderWindow & window, const float &someDeltaTime)
{
	for (int i = 0; i < myEnemies.size(); i++)
	{
		window.draw(myEnemies[i].GetSprite());

		if (myEnemies[i].GetType() == Grunt)
		{
	
			/*sf::View(window.)*/
					std::cout << "Grunt ";
					myEnemies[i].MoveGruntRight(someDeltaTime);
				

			/*
					std::cout << "Grunt1 ";
					myEnemies[i].MoveGruntLeft(someDeltaTime);
			*/
		/*		if (player.GetPosition().y > grunt.getPosition().y)
				{
				
					myEnemies[i].MoveGruntUp(someDeltaTime);
				}
				if (player.GetPosition().y < grunt.getPosition().y)
				{
					myEnemies[i].MoveGruntDown(someDeltaTime);
				}*/
	
		
				
		}

		if (myEnemies[i].GetType() == Archer)
		{
			myEnemies[i].UpdateArcher(someDeltaTime);
			
		}
	}
	
	
}
