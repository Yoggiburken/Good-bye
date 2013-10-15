<<<<<<< HEAD
#include "../inc/a.hpp"
#include <iostream>

using namespace std;

int main()
{
	A a;
	a.b=5;
	cout << a.b <<endl;
=======
#include<SFML/Graphics.hpp>
#include"../include/MediaClass.hpp"

using namespace sf;

Vector2f		WINDOW_RESOLUTION(800, 600);

RenderWindow 	app(VideoMode(WINDOW_RESOLUTION.x, WINDOW_RESOLUTION.y), "Good-bye!");
Event 			event;
Time			elapsed_time;
MediaClass 		MediaBucket;

void intro();

int main()
{
	RectangleShape 	play_button;
					play_button.setSize(Vector2f(300,66));
					play_button.setOrigin(play_button.getSize().x/2, play_button.getSize().y/2);
					play_button.setPosition(WINDOW_RESOLUTION.x/2, WINDOW_RESOLUTION.y/2);
	
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
		}
		app.clear();
		app.draw(play_button);
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
		if(Keyboard::isKeyPressed(Keyboard::Escape)) {
			intro_time = seconds(0);
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
>>>>>>> 4b67d25b0e3b0247bf913eebdec83ee7f72c1b5f
}
