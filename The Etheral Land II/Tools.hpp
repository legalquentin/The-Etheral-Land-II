//
//  Tools.hpp
//  The Etheral Land II
//
//  Created by Quentin Le Gal on 02/02/2017.
//  Copyright © 2017 Quentin Le Gal. All rights reserved.
//

#ifndef Tools_hpp
#define Tools_hpp

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include "ResourcePath.hpp"

class Tools {
    public :
    Tools();
    std::vector<sf::Sprite> DisplayHud(sf::RenderWindow &window, sf::Texture &guiTexture, sf::Vector2i spriteSize, sf::Texture &mapTexture, sf::Texture &guiTextTexture, sf::Texture &leatherTexture);
    std::vector<sf::Sprite> DisplayCreator(sf::RenderWindow &window,sf::Texture &GUI, sf::Texture &Buttons);
    private :
};
#endif /* Tools_hpp */
