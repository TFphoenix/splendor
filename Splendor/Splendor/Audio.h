#pragma once
//#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <string>
#include <unordered_map>
#include <memory>

class Audio
{

public:
	enum class SoundType
	{
	
		ButtonSFX,
		TokenSFX,
		BuyCardSFX,
		HoldCardSFX,
		WinNobleSFX

	};

	enum class MusicType
	{
		MenuMusic,
		GameMusic
	};

public:
	
	Audio();
	~Audio() = default;

	//void Play(SoundType);
	void AddMusic(const std::string& key, std::unique_ptr<sf::Music> value);
	sf::Music &GetMusic(std::string key);
	void LoadAudio();
	


private:

	sf::Music m_music;
	sf::Sound sound;
	sf::SoundBuffer bsound;
	std::unordered_map <std::string, std::unique_ptr<sf::Music>> m_musics;

};

