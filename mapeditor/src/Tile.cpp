#include"../include/MediaClass.hpp"
#include"../include/Tile.hpp"

using namespace sf;

extern MediaClass 	MediaBucket;

Tile::Tile()
{
	this->text_rect.setFillColor(Color::White);

	this->type = "NONE";
	this->text.setString(this->type);
	this->text.setFont(MediaBucket.getFont("VT323-Regular"));
	this->text.setColor(Color::Black);
	this->text.setCharacterSize(10);
	this->show_typetext = false;
}

void Tile::draw(RenderTarget& target, RenderStates states) const
{
	target.draw(this->sprite);
	if(this->show_typetext) {
		target.draw(this->text_rect);
		target.draw(this->text);
	}
}

void Tile::setType(std::string type, Sprite& sprite)
{
	this->sprite 	= sprite;
	this->type 		= type;
	this->text.setString(this->type);
	this->text_rect.setSize(Vector2f(this->text.getLocalBounds().width, this->text.getLocalBounds().height) + Vector2f(2, 2));
	this->text_rect.setOrigin(Vector2f(this->text_rect.getSize().x/2, this->text_rect.getSize().y/2));
}

void Tile::setPosition(Vector2f position)
{
	this->sprite.setPosition(position);
	this->text.setPosition(position);
	FloatRect text_bounds = this->text.getGlobalBounds();
	this->text_rect.setPosition(Vector2f(text_bounds.left + text_bounds.width/2, text_bounds.top + text_bounds.height/2));
}

void Tile::setShowTypetext(bool value)
{
	this->show_typetext = value;
}

Vector2f Tile::getPosition() const
{
	return this->sprite.getPosition();
}

FloatRect Tile::getGlobalBounds() const
{
	return this->sprite.getGlobalBounds();
}

std::string Tile::getType() const
{
	return this->type;
}
