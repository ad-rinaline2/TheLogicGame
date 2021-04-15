#include <SFML/Graphics.hpp>
#include <iostream>

int main(int argc, char const* argv[])
{
	//sf:: is like std::
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Game");
	window.setFramerateLimit(60); //For set frame rate games

	window.setKeyRepeatEnabled(false);

	/*/Default SFML to show window screen
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
	}*/

	//The states for button or event
	bool playGame = true;

	bool setPressed = false, setReleased = false;

	bool space = false, enter = false;

	bool leftClick = false, rightClick = true;

	//Variable
	int numClicks = 0;
	int mouseX, mouseY;

	//Event object for holding the all event
	sf::Event event;

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

			//Space
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
				space = true;
			}

			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space) {
				space = false;
			}

			//Enter released
			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Enter) {
				enter = true;
			}

			//Left click mouse
			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
				leftClick = true;
			}

			//Right click mouse
			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Right) {
				rightClick = true;
			}

			//Mouse move
			if (event.type == sf::Event::MouseMoved) {
				mouseX = event.mouseMove.x;
				mouseY = event.mouseMove.y;
			}

			//Close the loop
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

		//Enter released
		if (enter == true) {
			std::cout << "Entered has been released \n";
		}

		//Mouse click
		if (leftClick == true) {
			numClicks++; //Increase the numbers of left clicks by 1

			std::cout << "Number of left clicks " << numClicks << "\n";

			leftClick = false;
		}

		if (rightClick == true) {
			numClicks--; //Decrease the number of right clicks by 1
			std::cout << "Number of right clicks is " << numClicks << "\n";

			rightClick = false;
		}

		//std::cout << "Mouse x: " << mouseX << " Mouse y: " << mouseY << "\n";

		/*/Space
		if (space == true) {
			std::cout << "Space \n";
		}

		if (space == false) {
			std::cout << "Not space \n";
		}*/

		//Rendering
		window.clear();
		window.display();
	}

	//Clean up the game
	window.clear();

	return 0;
}