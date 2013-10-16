#include<map>
#include<vector>
#include<SFML/Graphics.hpp>
#include"UI.hpp"


#ifndef WORLD_HPP
#define WORLD_HPP
class World {
private:
	friend class UI;
	sf::RenderWindow					app;
	sf::Event							event;
	UI									tilewindow;
	int									tilenumber;
	sf::Texture							sprite_sheet;	
	std::vector<sf::Sprite>				tile_types;
	std::vector<sf::Sprite>				tilemap;
	void								addTile();
	void								drawMouseTile();
public:
										World();
	void								main();
};
#endif
