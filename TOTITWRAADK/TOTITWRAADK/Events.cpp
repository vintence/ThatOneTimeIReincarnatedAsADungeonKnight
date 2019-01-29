#include "pch.h"
#include "Events.h"
#include <iostream>
#include <string>
#include "ResourceManager.h"
#include "InputManager.h"

Events::Events()
{
	show = true;
	eventText = rand() % 20;

}
Events::~Events()
{
}
void Events::GetCard()
{
	show = true;
	eventText = rand() % 20;
}
void Events::Popup(sf::RenderWindow &window)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		GetCard();
	}
	//loads a random event card              

	if (eventText < 5) //TERROR
	{
		eventTitle = 0;
	}
	if (eventText > 4 && (eventText < 10)) //FOLK
	{
		eventTitle = 1;
	}
	if (eventText > 9 && (eventText < 16)) //POL
	{
		eventTitle = 2;
	}
	if (eventText < 21 && (eventText > 15)) //WEATHER
	{
		eventTitle = 3;
	}
	eventBackground = ResourceManager::MakeSprite("eventCard", 0, 0, 750, 550);
	button1 = ResourceManager::MakeSprite("button", button1Frame, 0, 30, 30);
	button2 = ResourceManager::MakeSprite("button", button2Frame, 0, 30, 30);
	titleText.setFont(ResourceManager::GetFont("titleFont"));
	text.setFont(ResourceManager::GetFont("textFont"));
	optionText1.setFont(ResourceManager::GetFont("textFont"));
	optionText2.setFont(ResourceManager::GetFont("textFont"));

	//ALl the text stuff
	sf::String eventTitleList[4]
	{
		"TERRORANSLCHAG!", "Das Folk rapport", "Note from Hotlir", "Das Wetter"
	};

	sf::String eventFlavor[21]
	{
		//TERROR
		" Two houses got burned to the ground at the same time, \n we suspect that it was an terror attack by the opposition \n because the houses belong to two  political figures \n Let's teach thoose who oppose us a lession they'll not soon forget",
		" A Bomb has gone of in one of your Factories, luckily\n none got hurt for it blew up during the night. \n We have no lead on who did it, but it is probobly the commies. \n How to we respond to an attack like this?",
		" A group of communists burned down a house killing the \n inhabitants inside! \n You lose 1 House and 5 happines \n How do you act?",
		" You have cought a western spy when he destroyed one of your \n military factories. \n -50 money \n How do we deal with such foreign hostility?",
		" Some western capitalists are undercutting our grain prices! \n - 50 money \n How do we deal whit the capitalits?",
		" Spain has plunged into Civil war and it is in Hotlir interest \n that the right side wins, it could prove vital in the great war. \n Do we aid them with men or guns?",



		//FOLKENREPORT
		" Your workers feel unhappy and put up a strike and many \n of them will not work! \n What do you do?",
		" A local fundraiser for the nazi party raised money for you! \n +100 money",
		" Exllent planning and morale makes one construction \n to be finish ahead of time \n 1 Instabuild",
		"Poor planning and bad excuses leads to 1 constuction \n to be delayed. \n 1 delayed turn on construction",

		//POLITICS
		" Hotlir has sent you some extra money. He thinks the investment \n will pay off /n + 150 money",
		" Hotlier needs to relocate people form your \n town to another. \n - 5 population",
		" Hotlir has sent a request that we need to finish our given \n deadline earlier! \n Deadline - 1 turn",
		" Hotlir sees that our town could use some extra money. \n He has what we need!",
		" Hotlir needs money from our town for a secret project, we must aid him!",

		//WEATHER	
		" A snowstorm has ruined a part of the city railroad. \n It will be up and running in 2 turns if we do nothing",
		" A long dry period makes it too risky having big pyiers, \n A factory cannot procede working \n - 1 F income 1 turn",
		" Terrible weather makes it hard for your workers to get to \n their respetive factories! \n What do we tell the workers?",
		" A heatwave and a warm summer dries out the local lake! \n How do we cope with this?",
		" Stormy weather risks a construction to be delayed. \n Shall they continue?",
		" A lightning storm has ravaged a miliratry factory \n Damned be the gods!"

	};

	sf::String option1[21]
	{
		//TERROR
		" Find those bastards! 50/50% \n 1. +1 Happiness + 100 money \n 2. -1 happiness",
		"Arm the guards to try to \n prevent future attacks \n- 10 Weapons",
		" It's an futile cause to try \n  to catch them, rebuild the houses \n -40 money",
		" Send him back to where he came form \n and let his embacy pay for his crimes \n  +100 money - 2 happiness",
		"Charge them for their \n crimes and thats that. \n  - 1 happiness + 100 money",
		"Send the guns, we need our men! \n A lend lease will suffice \n - 10 weapons",

		//FOLK
		"Let them strike! \n -3 F(2turns) - 1 Happiness",
		" \n A Surprise to be sure,\n but a welcome one",
		" \n Well done people of the third reich!",
		" \n Can't say i am a fan of this.",

		//Politics
		"We'll put it to good use mein Fürher, \n  heil Hotlir!",
		"If thats what he thinks, \n we are in no position to disobey.",
		"A storm is comming, \n  faster than expected... \n  We'll double are efforts!",
		"We will not deny this gift, Heil Hotlir!",
		"He is a generous man, \n its our time to help him!",

		//Weather
		"We must remove the snow at once! - 50 money",
		"Their work must conitue, work the fires! \n  50/50 1) - 2 happiness, 2)Nothing",
		"They must continue working \n -1 happiness",
		" Buy truck loads of water \n to aid your city \n -50 momey + 1 happiness",
		"We cannot allow our constructions \n to be aprehended, keep working! \n  -1 happiness",
		"What can be done!"
	};

	sf::String option2[21]
	{
		//Terror
		"Launch a crowdfund and \n quickly rebuild the house \n -25 money + 1House",
		"Tell everyone that rebuilding \n will commence \n -1 happiness",
		"Raid the house. 60% to catch them \n +10 money +2 happy \n -1 house",
		"Catch thoose commie \n bastards! + 2 happiness",
		"Let's incorparte them into \n our market they could help \n +10 income",
		"Send them some men! they need every man they can get \n -1H (2turns)",

		//FOLK
		"This will blow over, they have nothing to complain about \n -2 happiness",
		"(Close)",
		"(Close)",
		"\n No workdays, no paydays. \n -1Happines + 20 money",

		//Politics
		"\n (Close)",
		"\n (Close)",
		"\n (Close)",
		"\n (Close)",
		"\n (Close)",

		//Weather
		"Let the snow melt away",
		"It would be wise to shutdown \n the factory for a limited time",
		"If they can't get to work,\n whats there to be done? \n - 50 money",
		"Tell your city to take quicker \n showers \n Happiness - 2",
		"The safty of the workers \n is paramount, we will deal with a \n slight delay \n 1 Construction delayed",
		"Pray to Thor that it wont happen again"

	};

	//TITLE TEXT TITLE TEXT THANOS TEXT
	titleText.setString(eventTitleList[eventTitle]);
	titleText.setCharacterSize(90);
	titleText.setFillColor(sf::Color::Black);

	//OTHER TEXT LIKE DESCRIPTIONS
	text.setString(eventFlavor[eventText]);
	text.setCharacterSize(25);
	text.setFillColor(sf::Color::Black);

	//OPTION TEXTS
	optionText1.setString(option1[eventText]);
	optionText1.setCharacterSize(20);
	optionText1.setFillColor(sf::Color::Black);

	optionText2.setString(option2[eventText]);
	optionText2.setCharacterSize(20);
	optionText2.setFillColor(sf::Color::Black);

	//sets the positions
	eventBackground.setPosition(500, 100);
	button1.setPosition(sf::Vector2f(eventBackground.getPosition().x + 80, 420.f));
	button2.setPosition(sf::Vector2f(eventBackground.getPosition().x + 80, 510.f));
	titleText.setPosition(eventBackground.getPosition().x + 85, 110);
	text.setPosition(eventBackground.getPosition().x + 55, 250);
	optionText1.setPosition(eventBackground.getPosition().x + 115, 410);
	optionText2.setPosition(eventBackground.getPosition().x + 115, 500);

	//draws the card 
	if (show)
	{
		window.draw(eventBackground);
		window.draw(button1);
		window.draw(button2);
		window.draw(titleText);
		window.draw(text);
		window.draw(optionText1);
		window.draw(optionText2);
	}



	//click event
	if (InputManager::isSpriteClicked(button1, sf::Mouse::Button::Left, window))
	{

		//ALL OF THE eventXOptionY, Y = 1
		if (eventText == 1)
		{
			event1Option1();
		}
		if (eventText == 2)
		{
			event2Option1();
		}
		if (eventText == 3)
		{
			event3Option1();
		}
		if (eventText == 4)
		{
			event4Option1();
		}
		//eventText = rand() % 20;
		//std::cout << eventText << std::endl;
		////show = false;
	}
	if (InputManager::isSpriteClicked(button2, sf::Mouse::Button::Left, window))
	{

		//ALL OF THE eventXOptionY, Y = 2
		if (eventText == 1)
		{
			event1Option2();
		}

		if (eventText == 2)
		{
			event1Option2();
		}

		if (eventText == 3)
		{
			event1Option2();
		}

		if (eventText == 4)
		{
			event1Option2();
		}
	}

	//small graphic for hovering over a button
	if (InputManager::isSpriteCollided(button1, window))
	{
		button1Frame = 30;
		//std::cout << InputManager::getMousePosition(window).x << ", " << InputManager::getMousePosition(window).y <<std::endl ;
	}
	else button1Frame = 0;
	if (InputManager::isSpriteCollided(button2, window))
	{
		button2Frame = 30;
		//std::cout << InputManager::getMousePosition(window).x << ", " << InputManager::getMousePosition(window).y << std::endl;
	}
	else button2Frame = 0;

	//let the player make a choice via click
	//text manager
	//sound
	//random event	//event closes

}
void Events::event1Option1()
{
	std::cout << "Event number 1 option 1 \n";
	show = false;
}
void Events::event1Option2()
{
	std::cout << "hello bo2i This is number";
	show = false;
}

void Events::event2Option1()
{
	std::cout << "Event number 2 option 1 \n";
	show = false;
}
void Events::event2Option2()
{
	std::cout << "hello boi This is number \n";
	show = false;
}

void Events::event3Option1()
{
	std::cout << "Event number 3 option 1 \n";
	show = false;
}
void Events::event3Option2()
{
	std::cout << "hello boi This is number";
	show = false;
}

void Events::event4Option1()
{
	std::cout << "Event number 4 option 1";
	show = false;
}
void Events::event4Option2()
{
	std::cout << "hello boi This is number";
	show = false;
}

void Events::event5Option1()
{
	std::cout << "Event number 4 option 1";
	show = false;
}
void Events::event5Option2()
{
	std::cout << "hello boi This is number";
	show = false;
}

void Events::event6Option1()
{
	std::cout << "Event number 4 option 1";
	show = false;
}
void Events::event6Option2()
{
	std::cout << "hello boi This is number";
	show = false;
}

void Events::event7Option1()
{
	std::cout << "Event number 4 option 1";
	show = false;
}
void Events::event7Option2()
{
	std::cout << "hello boi This is number";
	show = false;
}

void Events::event8Option1()
{
	std::cout << "Event number 4 option 1";
	show = false;
}
void Events::event8Option2()
{
	std::cout << "hello boi This is number";
	show = false;
}

void Events::event9Option1()
{
	std::cout << "Event number 4 option 1";
	show = false;
}
void Events::event9Option2()
{
	std::cout << "hello boi This is number";
	show = false;
}

void Events::event10Option1()
{
	std::cout << "Event number 4 option 1";
	show = false;
}
void Events::event10Option2()
{
	std::cout << "hello boi This is number";
	show = false;
}

void Events::event11Option1()
{
	std::cout << "Event number 1 option 1 \n";
	show = false;
}
void Events::event11Option2()
{
	std::cout << "hello bo2i This is number";
	show = false;
}

void Events::event12Option1()
{
	std::cout << "Event number 2 option 1 \n";
	show = false;
}
void Events::event12Option2()
{
	std::cout << "hello boi This is number \n";
	show = false;
}

void Events::event13Option1()
{
	std::cout << "Event number 3 option 1 \n";
	show = false;
}
void Events::event13Option2()
{
	std::cout << "hello boi This is number";
	show = false;
}

void Events::event14Option1()
{
	std::cout << "Event number 4 option 1";
	show = false;
}
void Events::event14Option2()
{
	std::cout << "hello boi This is number";
	show = false;
}

void Events::event15Option1()
{
	std::cout << "Event number 4 option 1";
	show = false;
}
void Events::event15Option2()
{
	std::cout << "hello boi This is number";
	show = false;
}

void Events::event16Option1()
{
	std::cout << "Event number 4 option 1";
	show = false;
}
void Events::event16Option2()
{
	std::cout << "hello boi This is number";
	show = false;
}

void Events::event17Option1()
{
	std::cout << "Event number 4 option 1";
	show = false;
}
void Events::event17Option2()
{
	std::cout << "hello boi This is number";
	show = false;
}

void Events::event18Option1()
{
	std::cout << "Event number 4 option 1";
	show = false;
}
void Events::event18Option2()
{
	std::cout << "hello boi This is number";
	show = false;
}

void Events::event19Option1()
{
	std::cout << "Event number 4 option 1";
	show = false;
}
void Events::event19Option2()
{
	std::cout << "hello boi This is number";
	show = false;
}

void Events::event20Option1()
{
	std::cout << "Event number 4 option 1";
	show = false;
}
void Events::event20Option2()
{
	std::cout << "hello boi This is number";
	show = false;
}

void Events::event21Option1()
{
	std::cout << "Event number 4 option 1";
	show = false;
}
void Events::event21Option2()
{
	std::cout << "hello boi This is number";
	show = false;
}