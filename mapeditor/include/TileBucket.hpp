#include<map>
#include"Tile.hpp"

#ifndef TILE_BUCKET_HPP
#define TILE_BUCKET_HPP
class TileBucket {
private:
	std::map<std::string, Tile> tiles;
public:
								TileBucket();
								~TileBucket();
	void						loadSpriteSheet(std::string file_name);

	Tile&						getTile(std::string tile_name);
};
#endif
