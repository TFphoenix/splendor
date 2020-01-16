#include "Audio.h"
#include <iostream>

Audio::Audio()
{
	/*if (!bsound.loadFromFile("../external/Music/Anderson.wav")) {
		std::cout << "ERROR: sounds/fire.wav didn't load" << std::endl;
	}
	else {
		sound.setBuffer(bsound);
	}*/
	LoadAudio();
}

void Audio::AddMusic(const std::string& key, std::unique_ptr<sf::Music> value)
{
	m_musics.insert(std::make_pair(key, std::move(value)));

}

sf::Music &Audio::GetMusic(std::string key)
{
	return *m_musics.at(key);
}

void Audio::LoadAudio()
{

	auto menuMusic = std::unique_ptr<sf::Music>(new sf::Music());
	if (!menuMusic->openFromFile("../external/Music/test1.ogg"))
		throw "error";
	AddMusic(std::string("menuMusic"), std::move(menuMusic));

}
