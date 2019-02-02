#ifndef PLAYER_HEADER
#define PLAYER_HEADER

#include "BoundingBox.h"

class Player
{
public:
	Player();
	//Player(Player &aPlayer);
	~Player();

	void Draw(sf::RenderWindow &window);
	void Update(sf::RenderWindow &window, const float &someDeltaTime);
	void LookAtMouse(sf::RenderWindow &window);
	sf::Vector2f GetPosition();
	void SetPosition(sf::Vector2f aPosition);
	sf::FloatRect GetRect();
	sf::FloatRect GetRectWithPosition();
	bool moveUp = true, moveLeft = true, moveDown = true, moveRight = true;

	const bool &GetLeftCollision(sf::FloatRect aRectWithPosition);
	const bool &GetRightCollision(sf::FloatRect aRectWithPosition);
	const bool &GetUpCollision(sf::FloatRect aRectWithPosition);
	const bool &GetDownCollision(sf::FloatRect aRectWithPosition);

	const bool &GetLeftCollision(BoundingBox &aColisionBox);
	const bool &GetRightCollision(BoundingBox &aColisionBox);
	const bool &GetUpCollision(BoundingBox &aColisionBox);
	const bool &GetDownCollision(BoundingBox &aColisionBox);

	const sf::FloatRect &GetLastTileCollidedLeft();
	const sf::FloatRect &GetLastTileCollidedRight();
	const sf::FloatRect &GetLastTileCollidedUp();
	const sf::FloatRect &GetLastTileCollidedDown();

	const void SetTileCollidedLeft(const sf::FloatRect &aCollider);
	const void SetTileCollidedRight(const sf::FloatRect &aCollider);
	const void SetTileCollidedUp(const sf::FloatRect &aCollider);
	const void SetTileCollidedDown(const sf::FloatRect &aCollider);

private:
	sf::Sprite player;
	sf::Vector2f playerScale;
	sf::Sprite attack;

	sf::FloatRect playerOldRect;
	sf::FloatRect playerCurrentRect;

	BoundingBox myCurrentBox;
	BoundingBox myOldBox;

	sf::FloatRect myLastTileColliderLeft;
	sf::FloatRect myLastTileColliderRight;
	sf::FloatRect myLastTileColliderUp;
	sf::FloatRect myLastTileColliderDown;

	bool collideTileLeft;

	float movementSpeed;
	float baseSpeed = 200.f;
	float intelligent = 1;
	float strenght = 10;
	float agility = 30;

	sf::RectangleShape collidebox;

	sf::IntRect playerFrame;
	int frame = 0;
};

#endif