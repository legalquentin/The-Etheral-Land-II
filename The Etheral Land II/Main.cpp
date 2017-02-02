//
//  Main.cpp
//  The Etheral Land II
//
//  Created by Quentin Le Gal on 02/02/2017.
//  Copyright © 2017 Quentin Le Gal. All rights reserved.
//

#include "Main.hpp"

int main(int, char const**) {
    
    sf::RenderWindow Window(sf::VideoMode(1920, 1080), "Might & Magic");
    sf::Image icon;
    sf::Font font;
    std::vector<sf::Texture> Textures;
    Player Hero;
    Game Instance;
    
    Textures = LoadTextures();
    font.loadFromFile(resourcePath() + "Plain_Black.ttf");
    icon.loadFromFile(resourcePath() + "icon.png");
    Window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    
    Menu menu;
    
    menu.Play(Window, Textures, font, Hero);
    Instance.Play(Window, Textures, font, Hero);
    
    return EXIT_SUCCESS;
}

std::vector<sf::Texture> LoadTextures() {
    sf::Texture Warrior,Mage,Rogue,Ranger,Buttons,HUD;
    
    Warrior.loadFromFile(resourcePath() + "ErrantCrusader.png");
    Mage.loadFromFile(resourcePath() + "ErrantMage.png");
    Rogue.loadFromFile(resourcePath() + "ErrantRogue.png");
    Ranger.loadFromFile(resourcePath() + "ErrantRanger.png");
    Buttons.loadFromFile(resourcePath() + "Button.png");
    HUD.loadFromFile(resourcePath() + "interface.png");
    
    return {Warrior,Mage,Rogue,Ranger,Buttons,HUD};
}
