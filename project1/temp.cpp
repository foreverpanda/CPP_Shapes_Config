#include<iostream>
#include <SFML/Graphics.hpp>
#include "imgui.h"
#include "imgui-SFML.h"


void drawShape(sf::CircleShape* circle) {

	circle->setRadius(60);
	circle->setPosition(sf::Vector2f(400, 80));
	circle->setFillColor(sf::Color::Cyan);


}



int _main() {

	sf::RenderWindow window(sf::VideoMode({ 1200,800 }), "My Window");
	window.setFramerateLimit(60);

	sf::CircleShape* circle = new sf::CircleShape;
	bool showCircle = true;


	ImGui::SFML::Init(window);
	sf::Clock deltaClock;

	while (window.isOpen()) {

		while (const std::optional event = window.pollEvent())
		{
			ImGui::SFML::ProcessEvent(window, *event);
			if (event->is<sf::Event::Closed>())
			{
				window.close();
			}
		}

		ImGui::SFML::Update(window, deltaClock.restart());
		ImGui::Begin("ImGui Config");
		ImGui::Checkbox("Display Circle ", &showCircle);

		ImGui::Text("Hello Bhai");

		ImGui::End();
		

		window.clear(sf::Color::Red);
		ImGui::SFML::Render(window);

		if (showCircle)
		{
			drawShape(circle);
			window.draw(*circle);
		}


		window.display();
		


	
	}





}