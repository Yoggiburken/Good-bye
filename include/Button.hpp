#include <SFML/Graphics.hpp>
#include "Clickable.hpp"
#include "Actor.hpp"

#ifndef BUTTON_HPP
#define BUTTON_HPP

class Button : public Clickable, public Actor {
private:
	Actor				button_actor;
	sf::Vector2f		button_position;

	virtual void		draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
						Button(sf::Sprite& button_sprite, sf::Vector2f button_position);
						Button(sf::Texture& button_texture, sf::Vector2f button_position);
	bool				isClicked();
};

#endif
