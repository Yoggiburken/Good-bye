#include<vector>
#include<SFML/Graphics.hpp>

#ifndef ACTOR_HPP
#define ACTOR_HPP
class Actor : public sf::Drawable {
private:
	virtual void 			draw(sf::RenderTarget& target, sf::RenderStates states) const;
protected:
	std::vector<sf::Sprite> 		actor_sprites;
	void					addSprite(sf::Texture& 	texture);
	void					addSprite(sf::Sprite&  	sprite);
	void					addSprite(std::string&	texture_name);
};
#endif
