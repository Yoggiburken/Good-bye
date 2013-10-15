#include<SFML/Graphics.hpp>
#include"Tile.hpp"

#ifndef COLLISION_TYPE
#define COLLISION_TYPE
enum CollisionType {UP,DOWN,LEFT,RIGHT};
#endif

#ifndef COLLISION


#ifndef TILE_MAP_HPP
#define TILE_MAP_HPP
class TileMap : public sf::Drawable {
private:
	virtual void 		draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
};
#endif
