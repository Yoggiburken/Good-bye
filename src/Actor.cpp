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

void	Actor::addSprite(Texture& texture)
{
	Sprite 	sprite;
			sprite.setTexture(texture);
	this->actor_sprites.push_back(sprite);
}

void	Actor::addSprite(Sprite& sprite)
{
	this->actor_sprites.push_back(sprite);
}

void 	Actor::addSprite(std::string& texture_name)
{
	Sprite 	sprite;
			sprite.setTexture(MediaBucket.getTexture(texture_name.c_str()));
	this->actor_sprites.push_back(sprite);
}
