#include"../include/UI.hpp"
#include"../include/World.hpp"

using namespace sf;

extern World 	world;

UI::UI()
{
	this->window.create(VideoMode(200, 600), "tiles");
	this->window.setPosition(Vector2i(0,0));
}


void UI::main()
{
	if(this->window.isOpen()) {
		this->window.clear();
		this->window.display();
	}
}
