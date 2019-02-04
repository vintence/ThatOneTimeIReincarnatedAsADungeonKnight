#ifndef PLAYER_HEADER
#define PLAYER_HEADER

#include "BoundingBox.h"

class World;

class Player
{
public:
	//Player();
	Player(World &aWorld);
	~Player();

	void Draw(sf::RenderWindow &window);
	void Update(sf::RenderWindow &window, const float &someDeltaTime);
	void LookAtMouse(sf::RenderWindow &window);
	sf::Vector2f GetPosition();
	void SetPosition(sf::Vector2f aPosition);
	sf::FloatRect GetRect();
	sf::FloatRect GetRectWithPosition();
	bool moveUp = true, moveLeft = true, moveDown = true, moveRight = true;


private:
	World &world;

	sf::Sprite player;
	sf::Vector2f playerScale;
	sf::Sprite attack;

	int topLeftTileId;
	int topRightTileId;
	int botLeftTileId;
	int botRightTileId;
	int topTileId;
	int leftTileId;
	int botTileId;
	int rightTileId;

	float movementSpeed;
	float baseSpeed = 400.f;
	float intelligent = 1;
	float strenght = 10;
	float agility = 30;

	sf::RectangleShape collidebox;

	sf::IntRect playerFrame;
	int frame = 0;
};

#endif