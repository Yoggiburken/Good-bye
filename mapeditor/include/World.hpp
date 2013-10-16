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
	sf::RenderWindow					tilewindow;
	UI									tile_manager;
	sf::Event							event;
	int									tilenumber;
	sf::Texture							sprite_sheet;	
	std::vector<sf::Sprite>				tile_types;
	std::vector<sf::Sprite>				tilemap;
	void								events();
	void								addTile();
	void								drawMouseTile();
public:
										World();
	void								main();
};
#endif
