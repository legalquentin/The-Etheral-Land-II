//
//  Game.hpp
//  The Etheral Land II
//
//  Created by Quentin Le Gal on 02/02/2017.
//  Copyright © 2017 Quentin Le Gal. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
#include "Animator.hpp"
#include "Player.hpp"
#include "Scene.hpp"
#include "Tools.hpp"

struct S_Textures {
    sf::Font font;
    sf::Texture GUI;
    sf::Texture Map;
    sf::Texture woodTexture;
    sf::Texture guiTextTexture;
};

class Game {
private:
    S_Textures m_Textures;
    void mouseEvent(sf::Text &opt, sf::RenderWindow &window, float posX, float posY, int police, sf::Event &event);
public:
    Game();
    void Play(sf::RenderWindow &window, std::vector<sf::Texture> &Textures, sf::Font &Font, Player &Hero);
    
};

#endif /* Game_hpp */
