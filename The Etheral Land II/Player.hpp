//
//  Player.hpp
//  The Etheral Land II
//
//  Created by Quentin Le Gal on 02/02/2017.
//  Copyright © 2017 Quentin Le Gal. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include <string>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
#include "Animator.hpp"

struct S_BaseStats {
    int str,dext,wis,intel,constit,speed;
};
struct S_Stats {
    int dmg,base_health,base_mana,base_stamina,current_health,current_mana,current_stamina;
    S_BaseStats BaseStats;
};
struct S_Class {
    std::string name;
    S_BaseStats BaseStats;
};
struct S_Items {
    int gold;
};

struct S_Player {
    int age,xp,lvl,status;
    std::string name,surname,title;
    sf::Texture playerTexture;
    sf::Sprite playerSprite;
    sf::Sprite Effect;
    std::vector<sf::Texture> EffectTexture;
    S_Items Items;
    S_Stats Stats;
    S_Class playerClass;
};

class Player {

private:

public:
private:
  S_Player m_Player;
  void Setup_class();
public:
  // Constructor
  Player();
  // Inspector
  S_Player GetPlayer() const;
  // Mutator
  void LevelUp();
  void Init(std::string Name, std::string Surname, int PlayerClass, std::vector<sf::Texture> &PlayerTextures);
  void Animate(std::string action, int speed);
  void Effects(Animator &Animator, sf::Sprite &EffectSprite);
  void Attack(std::string AttackType, Animator &PlayerAnimator, int &velocity);
  void Setup_Animations(Animator &Animator);
};

#endif /* Player_hpp */
