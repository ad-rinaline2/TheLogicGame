#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

int main(int argc, char const* argv[])
{
	//sf:: is like std:: in general C++
	sf::RenderWindow window(sf::VideoMode(600, 500), "Logic Game And Render"); //Setting the window name and size
	window.setFramerateLimit(60); //For set frame rate games

	window.setKeyRepeatEnabled(false);

#if BREAK
	//Default SFML code to show window screen
	sf::CircleShape shape(100.f);

	shape.setFillColor(sf::Color::Blue);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}
#endif

	//The states for button or event
	bool playGame = true;

	bool setPressed = false, setReleased = false;

	bool space = false, returnReleased = false;

	bool leftClick = false, rightClick = false;

	bool leftPressed = false, rightPressed = false;

	//Variable
	int numClicks = 0;
	int mouseX = 0, mouseY = 0;
	int rectangleXPosition = 0, circleXPosition = 0;

	//Event object for holding the all event
	sf::Event event;

	//Rendering rectangle shapes 
	sf::RectangleShape rectangle;
	rectangle.setSize(sf::Vector2f(200, 150));
	rectangle.setPosition(350, 100);
	rectangle.setFillColor(sf::Color::Magenta);

	//Circle shapes
	sf::CircleShape circle;
	circle.setRadius(100);
	circle.setPosition(200, 280);
	circle.setFillColor(sf::Color::Yellow);

	//The game loop
	while (playGame == true)
	{
		//Event
		while (window.pollEvent(event))
		{
			//This key should enter B to get pressed
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::B) {
				setPressed = true;
			}

			//Enter B to released
			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::B) {
				setReleased = true;
			}

			//Key space pressed
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
				space = true;
			}

			//Key space released
			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space) {
				space = false;
			}

			//Enter or return released
			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Return) {
				returnReleased = true;
			}

			//Left click mouse
			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
				leftClick = true;
			}

			//Right click mouse
			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Right) {
				rightClick = true;
			}

			//Mouse move position
			if (event.type == sf::Event::MouseMoved) {
				mouseX = event.mouseMove.x;
				mouseY = event.mouseMove.y;
			}

			//Left pressed 
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left) {
				leftPressed = true;
			}

			//Right pressed
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right) {
				rightPressed = true;
			}

			//Left released
			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Left) {
				leftPressed = false;
			}

			//Right released
			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Right) {
				rightPressed = false;
			}

			//Close the game loop
			if (event.type == sf::Event::Closed) {
				playGame = false;
			}
		}

		//The logic
		//Set B to pressed and releases
		if (setPressed == true) {
			std::cout << "The B key has been pressed \n";

			setPressed = false;
		}

		if (setReleased == true) {
			std::cout << "The B key has been released \n";

			setReleased = false;
		}

		//Enter or return released
		if (returnReleased == true) {
			std::cout << "Enter or return has been released \n";

			returnReleased = false;
		}

		//Mouse click left
		if (leftClick == true) {
			numClicks++; //Increase the numbers of left clicks by 1

			std::cout << "Number of left clicks " << numClicks << "\n";

			//It's gonna close the window when mouse click less than 200 from x coordinate or position
			if (mouseX < 200) {

				playGame = false;
			}

			leftClick = false; //Not print the next frame
		}

		//Mouse right
		if (rightClick == true) {
			numClicks--; //Decrease the number of right clicks by 1

			std::cout << "Number of right clicks is " << numClicks << "\n";

			rightClick = false;
		}

		if (leftPressed == true && rightPressed == true) {
			std::cout << "The left and right key has been pressed \n";
		}

		//Space
		if (space == true) {
			std::cout << "Space \n";

			space = false;
		}

		if (space == true) {
			std::cout << "Not space \n";
			
			space = false;
		}

		std::cout << "Mouse x: " << mouseX << " Mouse y: " << mouseY << "\n";

		//Increase the rectangle X position
		rectangleXPosition++;
		rectangle.setPosition(rectangleXPosition, rectangleXPosition);
		
		circleXPosition++;
		circle.setPosition(circleXPosition, 0);

		//Rendering
		window.clear();

		//Set the render shapes
		window.draw(rectangle);
		window.draw(circle);

		window.display();
	}

	//Clean up the game
	window.clear();

	return 0;
}