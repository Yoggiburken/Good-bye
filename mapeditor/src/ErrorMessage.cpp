#include"../include/ErrorMessage.hpp"


ErrorMessage::ErrorMessage(std::string ERROR)
{
	font.loadFromFile("../resources/VT323-Regular.ttf");
	text.setFont(font);
	text.setCharacterSize(22);
	text.setString(ERROR);
	text.setOrigin(sf::Vector2f(text.getLocalBounds().width/2, text.getLocalBounds().height/2));
	sf::Event event;
	this->window.create(sf::VideoMode(20 + text.getLocalBounds().width, 10 + text.getLocalBounds().height), "ERROR");
	text.setPosition(sf::Vector2f(this->window.getSize().x/2, this->window.getSize().y/2));
	while(this->window.isOpen())
	{
		while(this->window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed) {
				this->window.close();
			} else if(event.type == sf::Event::KeyPressed) {
				if(event.key.code == sf::Keyboard::Escape) {
					this->window.close();
				}
			}
		}

		this->window.clear();
		this->window.draw(text);
		this->window.display();
	}
}
