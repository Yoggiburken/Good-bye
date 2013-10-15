#include <SFML/Graphics.hpp>
#include "Clickable.hpp"
#include "Actor.hpp"

#ifndef
#define

class Button : public Clickable, public Actor {
private:
	Actor				button_actor;
	sf::Vector2f		button_position;
public:
						Button(sf::Sprite& button_sprite, sf::Vector2f button_position);
	bool				isClicked();
};

#endif
