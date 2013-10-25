#include<vector>
#include<SFML/Graphics.hpp>
#include"Tile.hpp"


#ifndef MAP_HPP
#define MAP_HPP
class Map : public sf::Drawable {
private:
	std::vector<std::vector<Tile> > 	layers;
	virtual void 						draw(sf::RenderTarget& target, sf::RenderStates states) const;

	void								replaceTile();
public:
										Map() 	{layers.reserve(4);}
										~Map() 	{layers.clear();}
	void								addTileToLayer(Tile& tile, int layer_index);
	void								removeTileFromLayer(int layer_index, int tile_index);
	void								clearLayer(int index);
	void								clearAllLayers();

	std::vector<Tile>&					getLayer(int index);
	std::vector<std::vector<Tile> >& 	getAllLayers();
};
#endif
