#include <SFML/Graphics.hpp>
#include "../include/Button.hpp"

using namespace sf;

extern RenderWindow 		app;
extern Event 				event;

Button::Button(sf::Sprite& button_sprite, sf::Vector2f button_position)
{
	this->addSprite(button_sprite);
	this->actor_sprites[0].setPosition(button_position);
}
Button::Button(sf::Texture& button_texture, sf::Vector2f button_position)
{
	this->addSprite(button_texture);
	this->actor_sprites[0].setPosition(button_position);
}

bool Button::isHovering() const
{
	Vector2f mouse_pos = Vector2f(Mouse::getPosition(app).x, Mouse::getPosition(app).y);

	if (mouse_pos.x >= actor_sprites[0].getPosition().x-actor_sprites[0].getGlobalBounds().width/2 &&
		mouse_pos.x <= actor_sprites[0].getPosition().x+actor_sprites[0].getGlobalBounds().width/2 &&
		mouse_pos.y >= actor_sprites[0].getPosition().y-actor_sprites[0].getGlobalBounds().height/2 &&
		mouse_pos.y <= actor_sprites[0].getPosition().y+actor_sprites[0].getGlobalBounds().height/2) {
		
		return true;
	}

	return false;
}

bool Button::isClicked()
{
	if(event.type == Event::MouseButtonPressed &&
		event.mouseButton.button == Mouse::Left &&
		this->isHovering()) {
		
		this->clicked = true;
		return true;
		}

	return false;
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	if(this->clicked) {
		target.draw(actor_sprites[2]);
	} else if(this->isHovering()) {
		target.draw(actor_sprites[1]);	
	} else {
		target.draw(actor_sprites[0]);
	}
}
