#include "pch.h"
#include <SFML/Graphics.hpp>

#include "InputManager.h"
#include "ResourceManager.h"
#include "Player.h"
#include "World.h"
#include <iostream>
#include <fstream>



//void NormalizeWindowResize(const sf::RenderWindow &window, sf::View &view)
//{
//	float windowAspectRatio = float(window.getSize().x) / float(window.getSize().y);
//	view.setSize(windowWidth * windowAspectRatio, windowHeight * windowAspectRatio);
//}
int main()
{
	float windowWidth = 500;  //change to 1920x1080 at game final
	float windowHeight = 500;

	//load from file, config.cfg
	std::ifstream config("Resources/config.cfg");
	float number;
	std::string name;
	while (config >> name >> number)
	{
		if (name == "windowWidth:")
		{
			windowWidth = number;
		}
		if (name == "windowHeight:")
		{
			windowHeight = number;
		}
	}

	InputManager::Init();
	ResourceManager::Init();

	World world;
	Player player(world);

	sf::Clock deltaClock;

	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "The Realm", sf::Style::None); //olika sf::style kan hittas här https://www.sfml-dev.org/tutorials/2.5/window-window.php
	window.setFramerateLimit(60);
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(windowWidth, windowHeight));

	//world.SetPlayer(player);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
			{
				window.close();
				break;
			}
			//case sf::Event::Resized: //windows och allt element i window ska normalize om man resize window med musen
			//{
			//	NormalizeWindowResize(window, view);
			//}
			}
		}

		float tempDelta = deltaClock.restart().asSeconds();

		window.clear(sf::Color::White);
		//code under
		window.setView(view);
		world.Update(window);
		player.Update(window, tempDelta);
		view.setCenter(sf::Vector2f(player.GetPosition()));


		//code above
		window.display();
	}

	return 0;
}