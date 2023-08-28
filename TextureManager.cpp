#include "TextureManager.h"

unordered_map<string, sf::Texture> TextureManager::textures;

void TextureManager::LoadTexture(string filename) {
	string path = "images/";
	path += filename + ".png";

	textures[filename].loadFromFile(path);
}

sf::Texture& TextureManager::GetTexture(string textureName) {
	if (textures.find(textureName) == textures.end()) {
		LoadTexture(textureName);
	}
	
	return textures[textureName];
}

void TextureManager::Clear() {
	textures.clear();
}


sf::Texture& TextureManager::GetDigit0() {
	if (textures.find("digits0") == textures.end()) {
		textures["digits0"].loadFromFile("images/digits.png", sf::IntRect(0, 0, 21, 32));
	}

	return textures["digits0"];

}
sf::Texture& TextureManager::GetDigit1() {
	if (textures.find("digits") == textures.end()) {
		textures["digits1"].loadFromFile("images/digits.png", sf::IntRect(21, 0, 21, 32));
	}

	return textures["digits1"];
}
sf::Texture& TextureManager::GetDigit2() {
	if (textures.find("digits2") == textures.end()) {
		textures["digits2"].loadFromFile("images/digits.png", sf::IntRect(42, 0, 21, 32));
	}

	return textures["digits2"];
}
sf::Texture& TextureManager::GetDigit3() {
	if (textures.find("digits3") == textures.end()) {
		textures["digits3"].loadFromFile("images/digits.png", sf::IntRect(63, 0, 21, 32));
	}

	return textures["digits3"];
}
sf::Texture& TextureManager::GetDigit4() {
	if (textures.find("digits4") == textures.end()) {
		textures["digits4"].loadFromFile("images/digits.png", sf::IntRect(84, 0, 21, 32));
	}

	return textures["digits4"];
}
sf::Texture& TextureManager::GetDigit5() {
	if (textures.find("digits5") == textures.end()) {
		textures["digits5"].loadFromFile("images/digits.png", sf::IntRect(105, 0, 21, 32));
	}

	return textures["digits5"];
}
sf::Texture& TextureManager::GetDigit6() {
	if (textures.find("digits6") == textures.end()) {
		textures["digits6"].loadFromFile("images/digits.png", sf::IntRect(126, 0, 21, 32));
	}

	return textures["digits6"];
}
sf::Texture& TextureManager::GetDigit7() {
	if (textures.find("digits7") == textures.end()) {
		textures["digits7"].loadFromFile("images/digits.png", sf::IntRect(147, 0, 21, 32));
	}

	return textures["digits7"];
}
sf::Texture& TextureManager::GetDigit8() {
	if (textures.find("digits8") == textures.end()) {
		textures["digits8"].loadFromFile("images/digits.png", sf::IntRect(168, 0, 21, 32));
	}

	return textures["digits8"];
}
sf::Texture& TextureManager::GetDigit9() {
	if (textures.find("digits9") == textures.end()) {
		textures["digits9"].loadFromFile("images/digits.png", sf::IntRect(189, 0, 21, 32));
	}

	return textures["digits9"];
}

sf::Texture& TextureManager::GetDigitNeg() {
	if (textures.find("digitsneg") == textures.end()) {
		textures["digitsneg"].loadFromFile("images/digits.png", sf::IntRect(210, 0, 21, 32));
	}

	return textures["digitsneg"];
}