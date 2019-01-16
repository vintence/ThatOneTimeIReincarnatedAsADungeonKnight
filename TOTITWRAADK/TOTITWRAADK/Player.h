#ifndef PLAYER_HEADER
#define PLAYER_HEADER
#include <SFML/Graphics.hpp>


class Player
{
public:
	Player();
	~Player();

	void Draw(sf::RenderWindow &window);
	void Update(sf::RenderWindow &window);
	void LookAtMouse(sf::RenderWindow &window);
	sf::Vector2f GetPosition();

private:
	sf::Sprite player;
	sf::Vector2f playerScale;

	float movementSpeed;
	float baseSpeed = 1.2f;
	float intelligent = 1;
	float strenght = 10;
	float agility = 10;
};

#endif