void initShapes(Config& config) {

	for (auto& i : config.circleVector) {
		i.createShape();
	}
	for (auto& i : config.rectangleVector) {
		i.createShape();
	}

}

void render(Config& config, sf::RenderWindow & window) {



	for (auto& i : config.circleVector) {
		i.move();
		i.display(window);
	}
	for (auto& i : config.rectangleVector) {
		i.move();
		i.display(window);
	}

}

#pragma once
