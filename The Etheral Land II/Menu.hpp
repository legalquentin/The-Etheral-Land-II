//
//  Menu.hpp
//  The Etheral Land II
//
//  Created by Quentin Le Gal on 02/02/2017.
//  Copyright © 2017 Quentin Le Gal. All rights reserved.
//

#ifndef Menu_hpp
#define Menu_hpp

#include <stdio.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
#include "Animator.hpp"
#include "Player.hpp"

struct S_Menu {
    sf::Sprite sprite;
    sf::Texture texture;
    Animator animator;
};

struct S_PlayerText {
    sf::Texture Mage;
    sf::Texture Crusader;
    sf::Texture Ranger;
    sf::Texture Rogue;
};

class Menu {
public:
    Menu();
    int Play(sf::RenderWindow &Window, std::vector<sf::Texture> &Textures, sf::Font &font, Player &Hero);
    void DisplayMenu();
private:
    bool m_start;
    int m_class;
    int m_Player_class;
    std::string m_name;
    S_PlayerText m_PlayerTextures;
    void GetPlayerTextures(std::vector<sf::Texture> textures);
    void DrawChar(sf::RenderWindow &Window);
    std::vector<S_Menu> MenuDisplay;
    void SetTextures(std::vector<sf::Texture> &Textures);
    void CreateButton(sf::Texture &Texture, Animator &ButtonAnimator);
    void MouseAction(sf::RenderWindow &Window, sf::Event &event, std::vector<Animator*> &Animations);
    void MouseEvent(sf::RenderWindow &window, sf::Event &event, sf::Sprite &Button, Animator &Animator);
};
#endif /* Menu_hpp */
