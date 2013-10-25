#include<SFML/Graphics.hpp>

#ifndef ERROR_MESSAGE_HPP
#define ERROR_MESSAGE_HPP
class ErrorMessage {
private:
	sf::RenderWindow	window;
	sf::Text			text;
	sf::Font			font;
public:
						ErrorMessage(std::string ERROR);
};
#endif
