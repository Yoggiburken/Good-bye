#include <SFML/Graphics.hpp>
#include "../include/Button.hpp"

extern RenderWindow 		app;
extern Event 				event;

Button::Button(sf::Sprite& button_sprite, sf::Vector2f button_position)
{
	if(this->addSprite(button_sprite)) {
		this->actor_sprites[actor_sprites.size()-1].setPosition(button_position);
	}
}

void Button::setOrigin(sf::Vector2f button_position)
{
	for (int i=0;i < actor_sprites.size();i++) {
		this->actor_sprites[i].setPosition(button_position);
	}
}

bool Button::isClicked()
{
	if (Event::MouseButtonPressed::x >= actor_sprites[0].getPosition().x-actor_sprites[0].getGlobalBounds().width/2 &&
		Event::MouseButtonPressed::x <= actor_sprites[0].getPosition().x+actor_sprites[0].getGlobalBounds().width/2 &&
		Event::MouseButtonPressed::y >= actor_sprites[0].getPosition().y-actor_sprites[0].getGlobalBounds().heigth/2 &&
		Event::MouseButtonPressed::y <= actor_sprites[0].getPosition().y+actor_sprites[0].getGlobalBounds().height/2) {

		return true;
	}
	return false;
}
