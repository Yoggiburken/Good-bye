#include<SFML/Graphics.hpp>
#include"../include/MediaClass.hpp"
#include"../include/Button.hpp"
using namespace sf;

Vector2f		WINDOW_RESOLUTION(800, 600);

RenderWindow 	app(VideoMode(WINDOW_RESOLUTION.x, WINDOW_RESOLUTION.y), "Good-bye!");
Event 			event;
Time			elapsed_time;
MediaClass 		MediaBucket;

void intro();

int main()
{
	Button			play_button(MediaBucket.getTexture("button_icon"), sf::Vector2f(WINDOW_RESOLUTION.x/2, WINDOW_RESOLUTION.y/2));
	
	Sprite			firecan_icon;
					firecan_icon.setTexture(MediaBucket.getTexture("firecan_icon"));
					FloatRect firecan_icon_size = firecan_icon.getLocalBounds();
					firecan_icon.setOrigin(firecan_icon_size.width/2, firecan_icon_size.height/2);
					firecan_icon.setPosition(Vector2f(firecan_icon_size.width/2, WINDOW_RESOLUTION.y-firecan_icon_size.height/2));
	intro();
	
	while(app.isOpen())
	{
		while(app.pollEvent(event))
		{
			if(event.type == Event::KeyPressed) {
				if(event.key.code == Keyboard::Escape) {
					app.close();
				}
			}
			if(event.type == Event::Closed) {
				app.close();
			}
			if(event.type == Event::MouseButtonPressed && play_button.isClicked()) {
			
			}
		}
		app.clear(Color::White);
		app.draw(play_button);
		app.draw(firecan_icon);
		app.display();
	}
}

void intro()
{
	Sprite firecan;
	firecan.setTexture(MediaBucket.getTexture("firecan"));
	firecan.setOrigin(firecan.getLocalBounds().width/2, firecan.getLocalBounds().height/2);
	firecan.setPosition(400, 300);
	Time	intro_time = seconds(4);
	Clock 	clock;

	double opacity = 255;

	RectangleShape filter;
	filter.setFillColor(Color(255,255,255,opacity));
	filter.setSize(Vector2f(800,600));
	filter.setOrigin(400,300);
	filter.setPosition(400,300);

	while(intro_time > seconds(0)) 
	{
		while(app.pollEvent(event))
		{
			if(event.type == Event::KeyPressed) {
				if(event.key.code == Keyboard::Escape) {
					intro_time = seconds(0);
				}
			}
		}
		elapsed_time = clock.restart();
		intro_time -= elapsed_time;
		if(opacity >= 0) {
			opacity -= 255/2*elapsed_time.asSeconds();
			if(opacity < 0) {
				opacity = 0;
			}
		}
		filter.setFillColor(Color(255,255,255,opacity));
		app.clear(Color::White);
		app.draw(firecan);
		app.draw(filter);
		app.display();
	}
}
