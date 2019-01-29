#include "pch.h"
#include "InputManager.h"



void InputManager::Init()
{

}
bool InputManager::isSpriteClicked(const sf::Sprite &sprite, sf::Mouse::Button mouseButton, sf::RenderWindow &window)
{
	sf::IntRect spriteRect(sprite.getPosition().x, sprite.getPosition().y, sprite.getTextureRect().width*sprite.getScale().x, sprite.getTextureRect().height*sprite.getScale().y); //hämta spritens storlek
	if (spriteRect.contains(getMousePosition(window)))//om musen clickar på spriten inom spritens rect return true
	{
		if (sf::Mouse::isButtonPressed(mouseButton))
		{
			return true;
		}
	}
}
bool InputManager::isSpriteCollided(const sf::Sprite &sprite, sf::RenderWindow &window)
{
	sf::IntRect spriteRect(sprite.getPosition().x, sprite.getPosition().y, sprite.getTextureRect().width*sprite.getScale().x, sprite.getTextureRect().height*sprite.getScale().y); //hämta spritens storlek

	if (spriteRect.contains((sf::Vector2i)getMousePosition(window))) //om musen är inom spritens storlek return true
	{
		return true;
	}
}
bool InputManager::isSpriteCollidedWithPosition(const sf::Sprite & sprite1, sf::Vector2f aPosition)
{
	sf::IntRect sprite1Rect(sprite1.getPosition().x, sprite1.getPosition().y, sprite1.getTextureRect().width*sprite1.getScale().x, sprite1.getTextureRect().height*sprite1.getScale().y);
	if (sprite1Rect.contains(sf::Vector2i(aPosition)))
	{
		return true;
	}
}
bool InputManager::isMouseInsideWindow(sf::RenderWindow &window)
{
	sf::IntRect windowRect(0, 0, window.getSize().x, window.getSize().y);
	if (windowRect.contains(getMousePosition(window)))
	{
		return true;
	}
	return false;
}
sf::Vector2i InputManager::getMousePosition(sf::RenderWindow &window)
{
	return sf::Mouse::getPosition(window);
}

InputManager::~InputManager()
{
}
