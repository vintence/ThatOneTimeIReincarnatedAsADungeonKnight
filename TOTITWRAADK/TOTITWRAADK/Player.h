#ifndef PLAYER_HEADER
#define PLAYER_HEADER
#include <SFML/Graphics.hpp>


class Player
{
public:
	Player();
	//Player(Player &aPlayer);
	~Player();

	void Draw(sf::RenderWindow &window);
	void Update(sf::RenderWindow &window);
	void LookAtMouse(sf::RenderWindow &window);
	sf::Vector2f GetPosition();
	void SetPosition(sf::Vector2f aPosition);
	sf::IntRect GetRect();
	bool moveUp = true, moveLeft = true, moveDown = true, moveRight = true;

	sf::Clock clock;

private:
	sf::Sprite player;
	sf::Vector2f playerScale;
	sf::Sprite attack;

	float movementSpeed;
	float baseSpeed = 1.2f;
	float intelligent = 1;
	float strenght = 10;
	float agility = 30;

	sf::IntRect playerFrame;
	int frame = 0;
};

#endif