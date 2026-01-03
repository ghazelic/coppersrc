#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>

int main()
{
	sf::Window window(sf::VideoMode({800, 600}), "Window", sf::Style::Close, sf::State::Windowed);
	window.setVerticalSyncEnabled(true);

    
    	window.setActive(true);

    
    	bool running = true;
    	while (running)
    	{
        // handle events
        	while (const std::optional event = window.pollEvent())
        	{
            		if (event->is<sf::Event::Closed>())
            		{
                // end the program
                		running = false;
            		}
            		else if (const auto* resized = event->getIf<sf::Event::Resized>())
            		{
                // adjust the viewport when the window is resized
                		glViewport(0, 0, resized->size.x, resized->size.y);
            		}
        	}

        
        	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        	window.display();
	}

}

	
