#include "pch.h"
#include <vector>
#include "Grunt.h"
#include <SFML/Graphics.hpp>

Grunt::Grunt()
{
	sf::CircleShape shape(10);
	shape.setPosition(100, 100);
	speed = 2;
	health = 10;
	damage = 5;

	
}

Grunt::~Grunt()
{
}

void Grunt::move()
{
		

}