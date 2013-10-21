#include"../include/UI.hpp"
#include"../include/World.hpp"

using namespace sf;

extern World	world;

UI::~UI()
{
	this->tile_types.clear();
}

void UI::setContent(std::vector<Tile>& tile_types)
{
	this->tile_types = tile_types;
	for(int i=0; i<this->tile_types.size()/4; i++) {
		for(int j=0; j<4; j++) {
			this->tile_types[j+4*i].setPosition(Vector2f(32*j,32*i));
		}
	}
}

void UI::draw(RenderTarget& target, RenderStates states) const
{
	for(int i=0; i<this->tile_types.size(); i++) {
		target.draw(this->tile_types[i]);
	}
}

void UI::mouseHover(RenderWindow& window)
{
	Vector2f 	mousepos 	= window.mapPixelToCoords(Mouse::getPosition(window));
	for(int i=0; i<this->tile_types.size(); i++) {
		FloatRect tile = this->tile_types[i].getGlobalBounds();
		if(mousepos.x > tile.left && mousepos.x < tile.left + tile.width &&
		   mousepos.y > tile.top  && mousepos.y < tile.top  + tile.height) {
			tile_types[i].setShowTypetext(true);
		} else {
			tile_types[i].setShowTypetext(false);
		}
	}

}

void UI::setMouseTileOnClick(sf::Event& event)
{
	for(int i=0; i<this->tile_types.size(); i++) {
		FloatRect 	tile = this->tile_types[i].getGlobalBounds();
		if(event.mouseButton.x > tile.left && event.mouseButton.x < tile.left + tile.width &&
		   event.mouseButton.y > tile.top  && event.mouseButton.y < tile.top  + tile.height) {
			
			world.tilenumber = i;
		}
	}
}
