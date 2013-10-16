#include"../include/Tile.hpp"

using namespace sf;

void Tile::draw(RenderTarget& target, RenderStates states) const
{
	target.draw(this->sprite);
}

void Tile::setPosition(Vector2f position)
{
	this->sprite.setPosition(position);
}
	
void Tile::setTexture(Texture& texture)
{
	this->sprite.setTexture(texture);
}
	
void Tile::move(Vector2f delta)
{
	this->sprite.move(delta);
}
