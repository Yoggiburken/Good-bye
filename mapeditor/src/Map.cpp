#include"../include/Map.hpp"

using namespace sf;


void Map::replaceTile(int layer_index, int tile_index, Tile& tile)
{
	this->layers[layer_index].erase(this->layers[layer_index].begin() + tile_index);
	this->layers[layer_index].push_back(tile);

	return;
}

void Map::addTileToLayer(int layer_index, Tile& tile)
{
	Vector2f position = tile.getPosition();
	for(int i=0; i<this->layers[layer_index].size(); i++) {
		if(position == this->layers[layer_index][i].getPosition()) {
			this->replaceTile(layer_index, i, tile);
			return;
		}
	}
	this->layers[layer_index].push_back(tile);
}

bool Map::removeTileFromLayer(int layer_index, Vector2f position)
{
	for(int i=0; i<this->layers[layer_index].size(); i++) {
		if(position == this->layers[layer_index][i].getPosition()) {
			this->layers[layer_index].erase(this->layers[layer_index].begin() + i);
			return true;
		}
	}
	return false;
}

void Map::clearLayer(int layer_index)
{
	this->layers[layer_index].clear();
}

void Map::clearAllLayers()
{
	this->layers.clear();
	this->layers.reserve(4);
}

std::vector<Tile>& Map::getLayer(int layer_index)
{
	return this->layers[layer_index];
}

std::vector<std::vector<Tile> >& Map::getAllLayers()
{
	return this->layers;
}	
