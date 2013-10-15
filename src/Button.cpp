#include <SFML/Graphics.hpp>
#include "../include/Button.hpp"

using namespace sf;

extern RenderWindow 		app;
extern Event 				event;

Button::Button(sf::Sprite& button_sprite, sf::Vector2f button_position)
{
	this->addSprite(button_sprite);
	this->actor_sprites[0].setOrigin(this->actor_sprites[0].getLocalBounds().width/2, this->actor_sprites[0].getLocalBounds().height/2);
	this->actor_sprites[0].setPosition(button_position);
}
Button::Button(sf::Texture& button_texture, sf::Vector2f button_position)
{
	this->addSprite(button_texture);
	this->actor_sprites[0].setOrigin(this->actor_sprites[0].getLocalBounds().width/2, this->actor_sprites[0].getLocalBounds().height/2);
	this->actor_sprites[0].setPosition(button_position);
}

bool Button::isClicked()
{
	if (event.mouseButton.x >= actor_sprites[0].getPosition().x-actor_sprites[0].getGlobalBounds().width/2 &&
		event.mouseButton.x <= actor_sprites[0].getPosition().x+actor_sprites[0].getGlobalBounds().width/2 &&
		event.mouseButton.y >= actor_sprites[0].getPosition().y-actor_sprites[0].getGlobalBounds().height/2 &&
		event.mouseButton.y <= actor_sprites[0].getPosition().y+actor_sprites[0].getGlobalBounds().height/2) {

		return true;
	}
	return false;
}
