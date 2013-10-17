#include<SFML/Graphics.hpp>


#ifndef TILE_HPP
#define TILE_HPP
class Tile : public sf::Drawable {
private:
	sf::Sprite					sprite;
	int							type;

	virtual void				draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
	int							getType() const {return type;}
	sf::Vector2f				getPosition() const {return this->sprite.getPosition();}
};
#endif
