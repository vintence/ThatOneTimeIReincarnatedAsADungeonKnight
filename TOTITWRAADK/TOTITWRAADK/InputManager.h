#ifndef INPUTMANAGER_HEADER
#define INPUTMANAGER_HEADER
#include <SFML/Graphics.hpp>


class InputManager
{
public:
	~InputManager();

	static void Init();
	static bool isSpriteClicked(const sf::Sprite &sprite, sf::Mouse::Button mouseButton, sf::RenderWindow &window);
	static bool isSpriteCollided(const sf::Sprite &sprite, sf::Mouse::Button mouseButton, sf::RenderWindow &window);
	static bool isMouseInsideWindow(sf::RenderWindow &window);
	static sf::Vector2i getMousePosition(sf::RenderWindow &window);

private:
	InputManager() {};

};

#endif