#include<cmath>
#include<iostream>
#include<sstream>
#include"../include/World.hpp"
#include"../include/Tile.hpp"
using namespace sf;

std::string itoa(int num)
{
	std::stringstream ss;
	ss<<num;
	std::string str = ss.str();
	return str;
}

World::World() : app(VideoMode(800,600), "MapEditor"), tilewindow(VideoMode(128, 600), "Tile Manager")
{
	this->tilewindow.setPosition(Vector2i(app.getPosition().x - 138, app.getPosition().y));
	
	this->sprite_sheet.loadFromFile("../resources/terrain_tileset.png");
	this->tilenumber = 1;
	Sprite 	sprite;
	for(int i=0; i<4; i++) {
		sprite.setTexture(this->sprite_sheet);
		for(int j=0; j<9; j++) {
			sprite.setTextureRect(IntRect(32*j, 32*i, 32, 32));
			Tile 	tile;
					tile.setType("LELEL");
					tile.setPosition(Vector2f(32*j, 32*i));
			this->tile_types.push_back(tile);
		}
	}
}

World::~World()
{
	this->tile_types.clear();
	this->tilemap.clear();
}

void World::main()
{
	this->tile_manager.setContent(this->tile_types);
	while(this->app.isOpen())
	{
		this->events();
		this->input();	
			this->app.clear();
		for(int i=0; i<this->tilemap.size(); i++) {
			this->app.draw(this->tilemap[i]);
		}
		this->drawMouseTile();
		this->app.display();
		this->tilewindow.clear(Color::White);
		this->tilewindow.draw(tile_manager);
		this->tilewindow.display();
	}
}

void World::events() 
{
	while(this->app.pollEvent(this->event))
	{
		if(this->event.type == Event::Resized) {
			View 	view = app.getView();
					view.setSize(Vector2f(event.size.width, event.size.height));
			app.setView(view);
		} else if(this->event.type == Event::KeyPressed) {
			if(this->event.key.code == Keyboard::Escape) {
				this->app.close();
				this->tilewindow.close();
				std::string LEL = "l";
				this->filemanager.writeToFile(LEL, this->tilemap);
				return;
			} else if(this->event.key.code == Keyboard::L) {
				std::cout << "ELO" <<std::endl;
				this->filemanager.readFromFile("MAPNAME.map", this->tilemap);
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
		}
	}
	
	while(this->tilewindow.pollEvent(this->event))
	{
		if(this->event.type == Event::Resized) {
			View 	view = this->tilewindow.getView();
					view.setSize(Vector2f(event.size.width, event.size.height));
					view.setCenter(Vector2f(event.size.width/2, event.size.height/2));
			this->tilewindow.setView(view);
		} else if(this->event.type == Event::MouseButtonPressed) {
			if(this->event.mouseButton.button == Mouse::Left) {
				this->tile_manager.setMouseTileOnClick(this->event);
			}
		}

	}
}

void World::input()
{
	if(!app.isOpen()) {
		return;
	}
	if(this->tilewindow.isOpen()) {
		this->tile_manager.mouseHover(this->tilewindow);
	}
	if(Mouse::isButtonPressed(Mouse::Left)) {
		this->addTile();
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
