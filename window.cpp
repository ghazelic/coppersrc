#include <SFML/Window.hpp>

int main()
{
	sf::Window window(sf::VideoMode({800, 600}), "Window", sf::Style::Close, sf::State::Windowed);
	
	while (window.isOpen())
	{
		
        	while (const std::optional event = window.pollEvent())
        	{
            		if (event->is<sf::Event::Closed>())
                	window.close();
        	}
	}
}
