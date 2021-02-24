#include "FibLFSR.h"

int main(int argc, char* argv[]) {

    if(argc != 4) {
    	cerr << "There must be three command line arguments." << endl;
    	return -1;
    }

    string firstInput = argv[1];
    string secondInput = argv[2];
    string thirdInput = argv[3];
    FibLFSR seed(thirdInput);

    sf::Image image;
    if (!image.loadFromFile(firstInput))
	return -1;

    sf::Vector2u size = image.getSize();

    sf::RenderWindow window1(sf::VideoMode(size.x, size.y), "Input Encryption");
    sf::RenderWindow window2(sf::VideoMode(size.x, size.y), "Output Decryption");
	
    sf::Image image2 = image;
    
    transform(image2, &seed);
	
    sf::Texture texture1;
    texture1.loadFromImage(image);

    sf::Sprite sprite1;
    sprite1.setTexture(texture1);
    
    sf::Texture texture2;
    texture2.loadFromImage(image2);

    sf::Sprite sprite2;
    sprite2.setTexture(texture2);
	
    while (window1.isOpen() && window2.isOpen())
    {
	sf::Event event;
	while (window1.pollEvent(event))
	{
	    if (event.type == sf::Event::Closed)
		window1.close();
	}
	while (window2.pollEvent(event))
	{
	    if (event.type == sf::Event::Closed)
		window2.close();
	}

		window1.clear(sf::Color::White);
		window1.draw(sprite1);
		window1.display();
		window2.clear(sf::Color::White);
		window2.draw(sprite2);
		window2.display();
    }
    
    if (!image2.saveToFile(secondInput))
	return -1;

    return 0;
}

void transform(sf::Image& image, FibLFSR* lfsr) {

    sf::Color p;
    sf::Vector2u size = image.getSize();

    for (unsigned int x = 0; x < size.x; x++) {
        for (unsigned int y = 0; y < size.y; y++) {
	    p = image.getPixel(x, y);
	    p.r ^= lfsr->generate(8);
	    p.g ^= lfsr->generate(8);
	    p.b ^= lfsr->generate(8);
	    image.setPixel(x, y, p);
	}
    }
}
