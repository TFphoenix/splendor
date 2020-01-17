#include "SoundSystem.h"
#include "SoundSystem.h"
#include "SoundSystem.h"
#include "SoundSystem.h"
#include "SoundSystem.h"
#include "SoundSystem.h"

void SoundSystem::AddMusic(MusicType musicType, std::unique_ptr<sf::Music> value)
{
	m_musics.insert(std::make_pair(musicType, std::move(value)));

}

void SoundSystem::AddSound(SoundType soundType, std::unique_ptr<sf::SoundBuffer> value)
{

	m_sounds.insert(std::make_pair(soundType, std::move(value)));

}

sf::Music& SoundSystem::GetMusic(MusicType musicType)
{
	return *m_musics.at(musicType);
}

sf::SoundBuffer& SoundSystem::GetSound(SoundType soundType)
{
	return *m_sounds.at(soundType);

}



void SoundSystem::StopMusic(MusicType musicType)
{
	GetMusic(musicType).pause();

}




void SoundSystem::PlayMusic(MusicType musicType)
{

	GetMusic(musicType).setVolume(std::clamp<uint16_t>(s_musicVolume, 0, 100));
	GetMusic(musicType).setLoop(true);
	GetMusic(musicType).play();


}

void SoundSystem::PlaySFX(SoundType soundType)
{

	m_buffer = new sf::SoundBuffer;

	m_activeSound = new sf::Sound;

	*m_buffer = GetSound(soundType);
	m_activeSound->setBuffer(*m_buffer);
	m_activeSound->setVolume(std::clamp<uint16_t>(s_sfxVolume, 0, 100));
	m_activeSound->play();

}

void SoundSystem::LoadFromFile()
{
	if (alreadyLoaded)
		return;

	for (uint16_t musicIt = 0; musicIt < s_musicTypeSize; ++musicIt)
	{
		auto music = std::unique_ptr<sf::Music>(new sf::Music());
		auto path = s_musicFile + "m_" + std::to_string(static_cast<int>(static_cast<MusicType>(musicIt))) + ".ogg";
		if (!music->openFromFile(path))
			throw "error";
		AddMusic(static_cast<MusicType>(musicIt), std::move(music));


	}



	for (uint16_t soundIt = 0; soundIt < s_soundTypeSize; ++soundIt)
	{
		auto sound = std::unique_ptr<sf::SoundBuffer>(new sf::SoundBuffer());
		auto path = s_musicFile + "s_" + std::to_string(static_cast<int>(static_cast<SoundType>(soundIt))) + ".wav";
		if (!sound->loadFromFile(path))
			throw "error";
		AddSound(static_cast<SoundType>(soundIt), std::move(sound));


	}

	alreadyLoaded = true;


}

uint16_t SoundSystem::GetSFXVolume()
{
	return s_sfxVolume;
}

uint16_t SoundSystem::GetMusicVolume()
{
	return s_musicVolume;
}

void SoundSystem::SetMusicVolume(uint16_t musicVolume)
{
	s_musicVolume = musicVolume;
}

void SoundSystem::SetSFXVolume(uint16_t sfxVolume)
{
	s_sfxVolume = sfxVolume;
}
