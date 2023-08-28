#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <unordered_map>
using std::unordered_map;
using std::string;


class TextureManager {
	static unordered_map<string, sf::Texture> textures;
	static void LoadTexture(string textureName);
public:
	static sf::Texture& GetTexture(string textureName);
	static void Clear();
	static sf::Texture& GetDigitNeg();
	static sf::Texture& GetDigit0();
	static sf::Texture& GetDigit1();
	static sf::Texture& GetDigit2();
	static sf::Texture& GetDigit3();
	static sf::Texture& GetDigit4();
	static sf::Texture& GetDigit5();
	static sf::Texture& GetDigit6();
	static sf::Texture& GetDigit7();
	static sf::Texture& GetDigit8();
	static sf::Texture& GetDigit9();

};
