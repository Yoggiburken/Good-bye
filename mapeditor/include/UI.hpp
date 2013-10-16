#include<SFML/Graphics.hpp>
#include<vector>

#ifndef UI_HPP
#define UI_HPP
class UI : public sf::Drawable {
private:
	std::vector<sf::Sprite>		tile_types;

	void						draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
	void						setContent(std::vector<sf::Sprite>& tile_types);
	void						setMouseTileOnClick(sf::Event& event);
};
#endif
