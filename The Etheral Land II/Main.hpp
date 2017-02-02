//
//  Main.hpp
//  The Etheral Land II
//
//  Created by Quentin Le Gal on 02/02/2017.
//  Copyright © 2017 Quentin Le Gal. All rights reserved.
//

#ifndef Main_hpp
#define Main_hpp

#include <stdio.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
#include "Menu.hpp"
#include "Animator.hpp"
#include "Player.hpp"
#include "Game.hpp"

int main(int, char const**);
std::vector<sf::Texture> LoadTextures();

#endif /* Main_hpp */
