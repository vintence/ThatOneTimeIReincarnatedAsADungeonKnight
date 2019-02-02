#ifndef BOUNDING_BOX_HEADER
#define BOUNDING_BOX_HEADER

#include <SFML/Graphics.hpp>

class BoundingBox
{
public:
	BoundingBox();
	~BoundingBox();

	void Init(const float &anX, const float &anY, const int &aWidth, const int &aHeigth);
	void Copy(const BoundingBox &aBox);
	void Copy(const sf::FloatRect &aRect);

	const float &GetLeft();
	const float &GetRight();
	const float &GetTop();
	const float &GetBottom();
private:
	float myLeft, myRight, myTop, myBottom;
};

#endif