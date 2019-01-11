#pragma once
#include "enemy.h"
class Grunt : public Enemy
{
public:
	Grunt();
	~Grunt();

	void move();
};