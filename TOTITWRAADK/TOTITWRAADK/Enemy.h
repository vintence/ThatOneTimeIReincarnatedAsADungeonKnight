#ifndef ENEMY_HEADER
#define ENEMY_HEADER
#include <SFML/Graphics.hpp>

class Enemy
{
public:
	Enemy();
	~Enemy();

	void Draw(sf::RenderWindow &window);
	void Update(sf::RenderWindow &window);

private:

};

#endif