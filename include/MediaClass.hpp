#include<map>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>

#ifndef MEDIA_CLASS_HPP
#define MEDIA_CLASS_HPP
class MediaClass {
private:
    std::map<std::string, sf::Texture> 		textures;
public:
    MediaClass();
    sf::Texture&    getTexture(std::string textureID);

};
#endif
