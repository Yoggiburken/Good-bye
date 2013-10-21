#include<SFML/Graphics.hpp>


#ifndef TILE_HPP
#define TILE_HPP
class Tile : public sf::Drawable {
private:
	sf::Sprite					sprite;
	sf::RectangleShape			text_rect;
	sf::Text					text;
	std::string					type;
	bool						show_typetext;

	virtual void				draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
								Tile();
	void						setType(std::string type, sf::Sprite& sprite);
	void						setPosition(sf::Vector2f position);
	void						setShowTypetext(bool value);
	sf::Vector2f				getPosition() const;
	sf::FloatRect				getGlobalBounds() const;
};
#endif
