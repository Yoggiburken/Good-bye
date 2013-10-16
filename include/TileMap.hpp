#include<vector>
#include<SFML/Graphics.hpp>
#include"Tile.hpp"

#ifndef TILE_MAP_HPP
#define TILE_MAP_HPP
class TileMap : public sf::Drawable {
private:
	std::vector<Tile>	tiles;
	virtual void 		draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
						TileMap(std::string filename);
};
#endif
