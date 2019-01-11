#include "pch.h"
#include "ResourceManager.h"
#include <iostream>
#include <fstream>
#include <cstdlib>


std::map<std::string, sf::Texture> ResourceManager::_textures;
std::map<std::string, sf::Font> ResourceManager::_fonts;
void ResourceManager::Init()
{
	//load in stuff
	LoadTexture("player", "Resources/player.png");
	LoadTexture("resourceSheet", "Resources/sprites.png");


	//LoadFont("textFont", "Resources/PERI.ttf");
}

void ResourceManager::LoadTexture(std::string textureName, std::string fileName)
{
	sf::Texture tempTexture; //skapar en tom texture så man kan ladda in "filename" på den
	tempTexture.loadFromFile(fileName); //laddar in "filename" på den tomma texture
	_textures[textureName] = tempTexture; //vi ger _texture som har namnet "name" den texture som vi precis laddar in
}
sf::Texture &ResourceManager::GetTexture(std::string textureName)
{
	return _textures.at(textureName);
}
sf::Sprite &ResourceManager::MakeSprite(std::string textureName, int topleftPosX, int topleftPosY, int sizeWidth, int sizeHeight)
{
	sf::Sprite tempSprite;
	tempSprite = sf::Sprite(GetTexture(textureName));
	tempSprite.setTextureRect(sf::IntRect(topleftPosX, topleftPosY, sizeWidth, sizeHeight));
	return tempSprite;
}

void ResourceManager::LoadFont(std::string name, std::string fileName)
{
	sf::Font tempFont;
	tempFont.loadFromFile(fileName);
	_fonts[name] = tempFont;
}
sf::Font &ResourceManager::GetFont(std::string name)
{
	return _fonts.at(name);
}

ResourceManager::~ResourceManager()
{
}
