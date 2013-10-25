#include<vector>
#include<SFML/Graphics.hpp>
#include"Tile.hpp"


#ifndef MAP_HPP
#define MAP_HPP
class Map : public sf::Drawable {
private:
	std::vector<std::vector<Tile> > 	layers;
	virtual void 						draw(sf::RenderTarget& target, sf::RenderStates states) const;

	void								replaceTile(int layer_index, int tile_index, Tile& tile);
public:
										Map() 	{layers.reserve(4);}
										~Map() 	{layers.clear();}
	void								addTileToLayer(int layer_index, Tile& tile);
	bool								removeTileFromLayer(int layer_index, sf::Vector2f position);
	void								clearLayer(int index);
	void								clearAllLayers();

	std::vector<Tile>&					getLayer(int index);
	std::vector<std::vector<Tile> >& 	getAllLayers();
};
#endif
