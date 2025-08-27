#include "headers.h"
#include "shapesFunc.h"
#include "fileReader.h"


//float xStep;
//float yStep;
//int R, G, B;
//std::string shape;
//std::string shapeName;
//float width;
//float height;
//sf::CircleShape circle;
//sf::RectangleShape rect;
//int windX; int windY;


int main()
{
	Config config;
	readFile("config.txt", config);
	sf::RenderWindow window(sf::VideoMode({ config.winx, config.winy }), "Shapes window");

	window.setFramerateLimit(60);

	initShapes(config);
	
	std::vector<const char*> items;

	for (auto& s : config.rectangleVector) {
		items.push_back(s.shapeName.c_str());
	}

	for (auto& s : config.circleVector) {
		items.push_back(s.shapeName.c_str());
	}

	int item_index = 0;

	ImGui::SFML::Init(window);
	sf::Clock deltaClock;

	while (window.isOpen()) {

		while (const std::optional event = window.pollEvent())
		{
			//
			ImGui::SFML::ProcessEvent(window, *event);

			
			if (event->is<sf::Event::Closed>())
			{
				window.close();
			}
		}
		//
		ImGui::SFML::Update(window, deltaClock.restart());
		ImGui::Begin("Manipulator");

		ImGui::Combo("Select Shape", &item_index, items.data(), items.size());


		int totalRects = config.rectangleVector.size();
		int idx = item_index;

		if (idx < totalRects)
		{
			auto& selectedShape = config.rectangleVector[idx];
			ImGui::SliderFloat("X Speed", &selectedShape.xStep, 5.0f, 10.0f);
			ImGui::SliderFloat("Y Speed", &selectedShape.yStep, 5.0f, 10.0f);		
			ImGui::Checkbox("Visible", &selectedShape.visible);
			float* a[3] = { &selectedShape.R,&selectedShape.G,&selectedShape.B };

			ImGui::ColorEdit3("Color", *a);
			//ImGui::ColorEdit3("Color", (float*)selectedShape.R);  // needs struct tweak
		}
		else
		{
			idx -= totalRects;
			auto& selectedShape = config.circleVector[idx];
			ImGui::SliderFloat("X Speed", &selectedShape.xStep, 5.0f, 50.0f);
			ImGui::SliderFloat("Y Speed", &selectedShape.yStep, 5.0f, 50.0f);
			ImGui::Checkbox("Visible", &selectedShape.visible);
			float *a[3] = {&selectedShape.R,&selectedShape.G,&selectedShape.B};

			ImGui::ColorEdit3("Color", *a);

		
		}





		ImGui::End();


		window.clear(sf::Color::Black);

;
		



		for (auto & i : config.circleVector) {
			

			if(i.visible) {
				i.move();
				i.display(window);
				std::cout << "visible :" << i.shapeName << " : " << i.visible << std::endl;
			}

		}
		for (auto& i : config.rectangleVector) {
			if (i.visible) {
				i.move();
				i.display(window);
			}
			}

		ImGui::SFML::Render(window);
		window.display();


	}
	ImGui::SFML::Shutdown();

	return 0;
}