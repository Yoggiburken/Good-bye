#include<map>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>

#ifndef MEDIA_CLASS_HPP
#define MEDIA_CLASS_HPP
class MediaClass {
private:
    std::map<std::string, sf::Texture> 		textures;
	std::map<std::string, sf::SoundBuffer> 	soundbuffers;
	std::map<std::string, sf::Font>			fonts;
public:
    MediaClass();
    ~MediaClass();
	sf::Texture&    	getTexture(std::string textureID);
	sf::SoundBuffer&	getSoundBuffer(std::string soundbufferID);
	sf::Font&			getFont(std::string fontID);
};
#endif
