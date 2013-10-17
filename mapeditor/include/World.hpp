#include<map>
#include<vector>
#include<SFML/Graphics.hpp>
#include"UI.hpp"

#ifndef WORLD_HPP
#define WORLD_HPP
class World {
private:
	friend class UI;

	
	//Windows and events
	sf::RenderWindow					app;
	sf::RenderWindow					tilewindow;
	UI									tile_manager;
	sf::Event							event;
	
	//tiles
	int									tilenumber; 		//Keeps track of selected tile
	sf::Texture							sprite_sheet;			
	std::vector<sf::Sprite>				tile_types;			//Tiles to choose from
	std::vector<sf::Sprite>				tilemap;
		
	void								events(); 			//Parse events
	void								input();  			//Reads input
	void								addTile(); 			//places tile at mouse pos
	void								drawMouseTile(); 	//Draws current tile at mouse pos
public:
										World();
	void								main();
};
#endif
