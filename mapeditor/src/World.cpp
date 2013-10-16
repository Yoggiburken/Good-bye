#include<iostream>
#include"../include/World.hpp"

using namespace sf;


World::World() : app(VideoMode(800,600), "MapEditor")
{
	this->sprite_sheet.loadFromFile("../resources/terrain_tileset.png");
	int	tilenumber = 1;
	Sprite 	sprite;
	for(int i=0; i<36; i++) {
		sprite.setTexture(this->sprite_sheet);
		for(int j=0; j<9; j++) {
			sprite.setTextureRect(IntRect(32*j, 32*i, 32, 32));
			sprite.setOrigin(16,16);
			this->tile_types.push_back(sprite);
		}
	}
}

void World::main()
{
	while(this->app.isOpen())
	{
		while(this->app.pollEvent(this->event))
		{
			if(event.type == Event::KeyPressed) {
				if(event.key.code == Keyboard::Num1) {
					this->tilenumber = 1;
				} else if(event.key.code == Keyboard::Num2) {
					this->tilenumber = 2;
				}
			} else if(event.type == Event::MouseWheelMoved) {
				if(event.mouseWheel.delta > 0) {
					tilenumber++;
					if(tilenumber > 36) {
						tilenumber = 0;
					}
				} else {
					tilenumber--;
					if(tilenumber < 0) {
						tilenumber = 35;
					}
				}
			}
		}
	
		if(Mouse::isButtonPressed(Mouse::Left)) {
			Vector2f 	position = Vector2f(app.mapPixelToCoords(Mouse::getPosition(app)));
			tile_types[tilenumber].setPosition(position);
			tilemap.push_back(tile_types[tilenumber]);
		}
		
		this->app.clear();
		for(int i=0; i<tilemap.size(); i++) {
			app.draw(tilemap[i]);
		}
		this->app.display();
	}
}
