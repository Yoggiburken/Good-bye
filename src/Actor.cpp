#include"../include/Actor.hpp"
#include"../include/MediaClass.hpp"

using namespace sf;

extern MediaClass MediaBucket;

void 	Actor::draw(RenderTarget& target, RenderStates states) const
{
	for(int i=0; i<actor_sprites.size(); i++) {
		target.draw(actor_sprites[i]);
	}
}

void Actor::setPosition(sf::Vector2f position, int sprite_ID =- 1)
{
	if(sprite_ID == -1) {
		for(int i=0; i<actor_sprites.size(); i++) {
			actor_sprites[i].setPosition(position);
		}
	} else if(sprite_ID >= 0) {
		actor_sprites[sprite_ID].setPosition(position);	
	}
}

void	Actor::addSprite(Texture& texture)
{
	Sprite 	sprite;
			sprite.setTexture(texture);
			sprite.setOrigin(sprite.getLocalBounds().width/2, sprite.getLocalBounds().height/2);
	this->actor_sprites.push_back(sprite);
}

void	Actor::addSprite(Sprite& sprite)
{
	sprite.setOrigin(sprite.getLocalBounds().width/2, sprite.getLocalBounds().height/2);
	this->actor_sprites.push_back(sprite);
}

void 	Actor::addSprite(std::string& texture_name)
{
	Sprite 	sprite;
			sprite.setTexture(MediaBucket.getTexture(texture_name.c_str()));
			sprite.setOrigin(sprite.getLocalBounds().width/2, sprite.getLocalBounds().height/2);
	this->actor_sprites.push_back(sprite);
}
