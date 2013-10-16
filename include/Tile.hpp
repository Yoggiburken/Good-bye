#include"Actor.hpp"

#ifndef TILE_HPP
#define TILE_HPP
class Tile {
private:
	sf::Sprite				sprite;
	virtual void 		draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
						Tile(sf::Sprite& sprite, sf::Vector2f position);
	void				setPosition(sf::Vector2f position);
	void				setTexture(sf::Texture& texture);
	void				move(sf::Vector2f delta);
};
#endif
