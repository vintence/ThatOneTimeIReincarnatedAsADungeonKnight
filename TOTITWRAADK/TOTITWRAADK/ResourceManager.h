#ifndef RESOURCEMANAGER_HEADER
#define	RESOURCEMANAGER_HEADER
#include <SFML/Graphics.hpp>


class ResourceManager
{
public:
	~ResourceManager();

	static void Init();
	static void LoadTexture(std::string textureName, std::string fileName);
	static sf::Texture &GetTexture(std::string textureName);
	static sf::Sprite &MakeSprite(std::string textureName, int topleftPosX, int topleftPosY, int sizeWidth, int sizeHeight); //gör en sprite utav en av texture som vi har laddat in. 

	static sf::Font &GetFont(std::string fontName);
	static void LoadFont(std::string fontName, std::string fileName);


private:
	ResourceManager() {};
	static std::map<std::string, sf::Texture>_textures; //en container/lista typ, en _textures ska innehålla ett string(namn på det vi laddar in) och ett texture
	static std::map<std::string, sf::Font>_fonts;
};

#endif 
