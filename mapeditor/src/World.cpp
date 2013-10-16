#include<cmath>
#include<iostream>
#include"../include/World.hpp"

using namespace sf;


World::World() : app(VideoMode(800,600), "MapEditor")
{
	this->sprite_sheet.loadFromFile("../resources/terrain_tileset.png");
	this->tilenumber = 1;
	Sprite 	sprite;
	for(int i=0; i<36; i++) {
		sprite.setTexture(this->sprite_sheet);
		for(int j=0; j<9; j++) {
			sprite.setTextureRect(IntRect(32*j, 32*i, 32, 32));
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
			if(this->event.type == Event::KeyPressed) {
				if(this->event.key.code == Keyboard::Escape) {
					this->app.close();
				} else if(this->event.key.code == Keyboard::Up) {
					this->tilenumber++;
					if(this->tilenumber > 36) {
						this->tilenumber = 0;
					}
				} else if(this->event.key.code == Keyboard::Down) {
					this->tilenumber--;
					if(this->tilenumber < 0) {
						this->tilenumber = 35;
					}
				}	
			} else if(this->event.type == Event::MouseWheelMoved) {
				if(this->event.mouseWheel.delta > 0) {
					this->tilenumber++;
					if(this->tilenumber > 36) {
						this->tilenumber = 0;
					}
				} else {
					this->tilenumber--;
					if(this->tilenumber < 0) {
						this->tilenumber = 35;
					}
				}
			}
		}
	
		if(Mouse::isButtonPressed(Mouse::Left)) {
			this->addTile();
		}
		
		this->app.clear();
		for(int i=0; i<this->tilemap.size(); i++) {
			this->app.draw(this->tilemap[i]);
		}
		this->drawMouseTile();
		this->app.display();
	}
}

void World::addTile()
{
		Vector2f 	position = Vector2f(app.mapPixelToCoords(Mouse::getPosition(app)));
		position.x = floor(position.x/32)*32;
		position.y = floor(position.y/32)*32;
		for(int i=0; i<this->tilemap.size(); i++) {
			if(this->tilemap[i].getPosition() == position) {
				this->tilemap[i] = this->tile_types[this->tilenumber];
				return;
			}
		}
		this->tile_types[this->tilenumber].setPosition(position);
		this->tilemap.push_back(tile_types[this->tilenumber]);
}
void World::drawMouseTile()
{
	if(Mouse::getPosition(app).x  > 0 && Mouse::getPosition(this->app).y > 0 && Mouse::getPosition(this->app).x < 800 && Mouse::getPosition(this->app).y < 600) {
		Vector2f 	position = Vector2f(this->app.mapPixelToCoords(Mouse::getPosition(app)));
		position.x = floor(position.x/32)*32;
		position.y = floor(position.y/32)*32;
		this->tile_types[this->tilenumber].setPosition(position);
	}
		this->app.draw(tile_types[tilenumber]);
}
