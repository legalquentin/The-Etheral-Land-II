//
//  Scene.hpp
//  The Etheral Land II
//
//  Created by Quentin Le Gal on 02/02/2017.
//  Copyright © 2017 Quentin Le Gal. All rights reserved.
//

#ifndef Scene_hpp
#define Scene_hpp

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <string>

#include "Animator.hpp"
#include "Player.hpp"
#include "ResourcePath.hpp"

struct S_Scene {
    int Number;
    int PlayerScale;
    std::string Name;
    sf::Sprite Background;
    sf::Texture BackgroundTexture;
    sf::Vector2i BackgroundSize;
    sf::Vector2i PlayerPosition;
};

class Scene {
private:
    std::vector<S_Scene> m_Scene;
    int m_index;
public:
    Scene();
    void AddScene(Animator &animator,sf::Sprite &backgroundSprite ,std::string background,int num, int frames, sf::Vector2i backgroundSize,int playerSize, sf::Vector2i PlayerPosition, int LeftBoundaries, int RightBoundaries, sf::Sprite &player, int rows);
    void Play(Player &Hero, sf::Sprite &sprite, sf::Sprite &PlayerSprite);
    void Update(sf::Sprite &PlayerSprite, Animator &animator, sf::Sprite &sprite, Animator &PlayerAnimator);
    void SwitchScene(sf::Sprite &PlayerSprite, Animator &animator, int sceneNumber, sf::Sprite &sprite);
    void AddEffect(sf::Sprite &PlayerSprite, sf::Sprite &EffectSprite, Animator &animator, std::string effectName, int size);
};
#endif /* Scene_hpp */
