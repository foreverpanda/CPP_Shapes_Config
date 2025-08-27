
class Collisions {
public:
	float initPosX;
	float initPosY;
	float xStep;
	float yStep;
	float R, G, B;
	std::string shape;
	std::string shapeName;
	float width;
	float height;
	sf::CircleShape circle;
	sf::RectangleShape rect;
	int windX; int windY;
	bool visible = true;
	Collisions(std::string shape, std::string shapeName,
		float initPosX,
		float initPosY,
		float xStep,
		float yStep,
		float R, float G, float B, float width, float height, int windX, int windY) {

		this->shape = shape;
		this->shapeName = shapeName;

		this->initPosX = initPosX;
		this->initPosY = initPosY;
		this->xStep = xStep;
		this->yStep = yStep;
		this->R = R/255;
		this->G = G/255;
		this->B = B/255;
		this->windX = windX;
		this->windY = windY;
		if (shape == "Rectangle" || shape == "Square")
		{
			this->width = width;
			this->height = height;
		}
		else {
			this->width = width;
			this->height = 0.0f;
		}

	}

};

class Rectangle : public Collisions {
public:
	Rectangle(std::string shape, std::string shapeName,
		float initPosX,
		float initPosY,
		float xStep,
		float yStep,
		float R, float G, float B, float width, float height, int windX, int windY) :Collisions(shape, shapeName,
			initPosX,
			initPosY,
			xStep,
			yStep,
			R, G, B, width, height, windX, windY) {
	}


	const void createShape() {
		rect.setSize(sf::Vector2f(width, height));
		rect.setPosition(sf::Vector2f(initPosX, initPosY));
		rect.setFillColor(sf::Color(int(R * 255), int(G * 255), int(B * 255)));
	}
	void move() {
		if (rect.getPosition().x > windX - width) {
			xStep = -xStep;
		}
		if (rect.getPosition().x < 0) {
			xStep = -xStep;
		}
		if (rect.getPosition().y > windY - height) {
			yStep = -yStep;
		}
		if (rect.getPosition().y < 0) {
			yStep = -yStep;
		}
		rect.move(sf::Vector2f(xStep, yStep));

	}
	void display(sf::RenderWindow& window) {
		rect.setFillColor(sf::Color(int(R * 255), int(G * 255), int(B * 255)));

		window.draw(rect);
	}
};

class Circle : public Collisions {
public:

	Circle(std::string shape, std::string shapeName,
		float initPosX,
		float initPosY,
		float xStep,
		float yStep,
		float R, float G, float B, float width, float height, int windX, int windY) :Collisions(shape, shapeName,
			initPosX,
			initPosY,
			xStep,
			yStep,
			R, G, B, width, height, windX, windY) {
	}

	const void createShape() {
		circle.setRadius(width);
		circle.setPosition(sf::Vector2f(initPosX, initPosY));
		circle.setFillColor(sf::Color(int(R * 255), int(G * 255), int(B * 255)));
	}
	void move() {
		if (circle.getPosition().x > windX - (2 * width)) {
			xStep = -xStep;
		}
		if (circle.getPosition().x < 0) {
			xStep = -xStep;
		}
		if (circle.getPosition().y > windY - (2 * width)) {
			yStep = -yStep;
		}
		if (circle.getPosition().y < 0) {
			yStep = -yStep;
		}
		circle.move(sf::Vector2f(xStep, yStep));
	}

	void display(sf::RenderWindow& window) {
		circle.setFillColor(sf::Color(int(R * 255), int(G * 255), int(B * 255)));
		window.draw(circle);
	}
};

struct Config {
	std::string windowsKeyword = "";
	std::string fontKeyword = "";
	unsigned int winx, winy;
	std::string fontStyle = "";
	int fontSize = 12, fontR = 255, fontG = 255, fontB = 255;
	std::vector<Rectangle> rectangleVector;
	std::vector<Circle> circleVector;
};
#pragma once
