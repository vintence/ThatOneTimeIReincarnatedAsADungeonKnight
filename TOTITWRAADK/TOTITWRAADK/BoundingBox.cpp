#include "pch.h"
#include "BoundingBox.h"


BoundingBox::BoundingBox()
{
}


BoundingBox::~BoundingBox()
{
}

void BoundingBox::Init(const float & anX, const float & anY, const int & aWidth, const int & aHeigth)
{
	myLeft = anX;
	myRight = anX + aWidth;
	myTop = anY;
	myBottom = anY + aHeigth;
}

void BoundingBox::Copy(const BoundingBox & aBox)
{
	myLeft = aBox.myLeft;
	myRight = aBox.myRight;
	myTop = aBox.myTop;
	myBottom = aBox.myBottom;
}

void BoundingBox::Copy(const sf::FloatRect & aRect)
{
	myLeft = aRect.left;
	myRight = aRect.left + aRect.width;
	myTop = aRect.top;
	myBottom = aRect.top + aRect.height;
}

const float & BoundingBox::GetLeft()
{
	return myLeft;
}

const float & BoundingBox::GetRight()
{
	return myRight;
}

const float & BoundingBox::GetTop()
{
	return myTop;
}

const float & BoundingBox::GetBottom()
{
	return myBottom;
}
