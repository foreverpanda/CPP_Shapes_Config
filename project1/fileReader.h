void readFile(const std::string fileName, Config& config) {

	std::ifstream fin(fileName);
	if (!fin.is_open()) {
		std::cout << "Error opening file for reading." << std::endl;
		std::cout << fileName << std::endl;
		exit(0);
	}
	std::string line;
	std::getline(fin, line);

	std::stringstream stream(line);
	stream >> config.windowsKeyword >> config.winx >> config.winy;
	std::getline(fin, line);
	stream >> config.fontKeyword >> config.fontStyle >> config.fontSize >> config.fontR >> config.fontG >> config.fontB;

	while (std::getline(fin, line)) {
		std::stringstream ss(line);
		std::string shape, shapeName;
		float x, y, sx, sy, width, height;
		float R, G, B;
		ss >> shape >> shapeName >> x >> y >> sx >> sy >> R >> G >> B >> width;

		if (shape == "Circle") {
			config.circleVector.push_back(Circle(shape, shapeName, x, y, sx, sy, R, G, B, width, 0.0f, config.winx, config.winy));
		}
		else if (shape == "Rectangle") {
			ss >> height;
			config.rectangleVector.push_back(Rectangle(shape, shapeName, x, y, sx, sy, R, G, B, width, height, config.winx, config.winy));
		}

	}
}
