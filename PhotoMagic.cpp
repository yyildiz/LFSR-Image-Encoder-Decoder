// using SFML to load a file, manipulate its pixels, write it to disk
// g++ -o pixels pixels.cpp -lsfml-graphics -lsfml-window

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "LFSR.hpp"
#include <string>
#include <stdlib.h>
#include <iostream>

int main(int argc, char* argv[])
{
    std::string inputPhoto, outputPhoto, bitString;
    int tap;
    if(argc == 5){
        inputPhoto = argv[1];
        outputPhoto = argv[2];
        bitString = argv[3];
        tap = atoi(argv[4]);
    }
    else{
        std::cout << "Invalid Argument";
    }
    sf::Image image;
    sf::Image original;
    LFSR rand(bitString, tap);
    if(!original.loadFromFile(inputPhoto))
        return -1;

    if (!image.loadFromFile(inputPhoto))
        return -1;

    sf::Color p; // Each pixel is represented as 'P'
    sf::Vector2u size = image.getSize();

    for (unsigned x=0; x < size.x; x++) {
        for (unsigned y= 0; y < size.y; y++) {
            p = image.getPixel(x, y);
            p.r = p.r ^ rand.generate(8);
            p.g = p.g ^ rand.generate(8);
            p.b = p.b ^ rand.generate(8);
            image.setPixel(x, y, p);
        }
    }

    sf::RenderWindow window(sf::VideoMode(size.x*2, size.y), "PhotoMagic Version 1.0");

    sf::Texture texture, originalTexture;
    texture.loadFromImage(image);
    originalTexture.loadFromImage(original);

    sf::Sprite sprite, originalSprite;
    sprite.setTexture(texture);
    originalSprite.setTexture(originalTexture);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);
        window.draw(originalSprite);
        sprite.setPosition(sf::Vector2f(size.x, 0));
        window.draw(sprite);
        window.display();
    }

    if (!image.saveToFile(outputPhoto))
        return -1;

    return 0;
}
