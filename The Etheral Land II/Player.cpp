//
//  Player.cpp
//  The Etheral Land II
//
//  Created by Quentin Le Gal on 02/02/2017.
//  Copyright © 2017 Quentin Le Gal. All rights reserved.
//

#include "Player.hpp"

Player::Player() {
}

S_Player Player::GetPlayer() const {
    return m_Player;
}

void Player::Init(std::string PlayerName,std::string PlayerSurname,int PlayerClass, std::vector<sf::Texture> &PlayerTextures) {
    int rc,cl;
    m_Player.xp = 0;
    m_Player.lvl = 0;
    m_Player.status = 0;
    m_Player.name = PlayerSurname;
    m_Player.surname = PlayerName;
    m_Player.title = "";
    printf("Player Class = %d\n",PlayerClass);
    std::vector<std::string> classes = {"Crusader","Mage","Rogue","Ranger"};
    m_Player.playerClass.name = classes[PlayerClass-1];
    m_Player.playerTexture = PlayerTextures[PlayerClass-1];
    sf::Texture tmp;
    tmp.loadFromFile(resourcePath() + "FireAura.png");
    m_Player.EffectTexture.push_back(tmp);
    tmp.loadFromFile(resourcePath() + "DemonFireAura.png");
    m_Player.EffectTexture.push_back(tmp);
    Setup_class();
    LevelUp();
}

void Player::Setup_class() {
    std::vector<int> stats;
    if (m_Player.playerClass.name == "Crusader")
        stats = {5,5,1,1,5,220};
    if (m_Player.playerClass.name == "Ranger")
        stats = {2,5,4,3,3,500};
    if (m_Player.playerClass.name == "Rogue")
        stats = {2,5,4,3,3,400};
    if (m_Player.playerClass.name == "Mage")
        stats = {1,2,6,6,2,350};
    m_Player.playerClass.BaseStats.str = stats[0];
    m_Player.playerClass.BaseStats.dext = stats[1];
    m_Player.playerClass.BaseStats.wis = stats[2];
    m_Player.playerClass.BaseStats.intel = stats[3];
    m_Player.playerClass.BaseStats.constit = stats[4];
}

void Player::LevelUp() {
    
    // Uncomment if races become avaibles
    m_Player.Stats.BaseStats.str += m_Player.playerClass.BaseStats.str;// + m_Player.Race.stats.str;
    m_Player.Stats.BaseStats.dext += m_Player.playerClass.BaseStats.dext;// + m_Player.Race.stats.dext;
    m_Player.Stats.BaseStats.wis += m_Player.playerClass.BaseStats.wis;// + m_Player.Race.stats.wis;
    m_Player.Stats.BaseStats.intel += m_Player.playerClass.BaseStats.intel;// + m_Player.Race.stats.intel;
    m_Player.Stats.BaseStats.constit += m_Player.playerClass.BaseStats.constit;
    // + m_Player.Race.stats.constit;
    m_Player.Stats.BaseStats.speed += 1;
    
    m_Player.Stats.base_health += m_Player.Stats.BaseStats.constit;
    m_Player.Stats.base_mana += m_Player.Stats.BaseStats.intel;
    m_Player.Stats.base_stamina += m_Player.Stats.BaseStats.dext;
    
    // Restore full life, mana, stamina
    m_Player.Stats.current_health = m_Player.Stats.base_health;
    m_Player.Stats.current_mana = m_Player.Stats.base_mana;
    m_Player.Stats.current_stamina = m_Player.Stats.base_stamina;
    
    if (m_Player.playerClass.name == "Crusader") m_Player.Stats.dmg += m_Player.Stats.BaseStats.str;
    if (m_Player.playerClass.name == "Ranger") m_Player.Stats.dmg += m_Player.Stats.BaseStats.dext;
    if (m_Player.playerClass.name == "Rogue") m_Player.Stats.dmg += m_Player.Stats.BaseStats.dext;
    if (m_Player.playerClass.name == "Mage") m_Player.Stats.dmg += m_Player.Stats.BaseStats.intel;
    m_Player.lvl+=1;
}

void Player::Attack(std::string AttackType, Animator &PlayerAnimator, int &velocity) {
    
    if (PlayerAnimator.GetCurrentAnimationName() == "MoveLeft" ||
        PlayerAnimator.GetCurrentAnimationName() == "IdleLeft")
        PlayerAnimator.SwitchAnimation(AttackType+"AttackLeft");
    
    if (PlayerAnimator.GetCurrentAnimationName() == "MoveRight" ||
        PlayerAnimator.GetCurrentAnimationName() == "IdleRight")
        PlayerAnimator.SwitchAnimation(AttackType+"AttackRight");
    
    if (PlayerAnimator.GetCurrentAnimationName() == "IdleBack")
        PlayerAnimator.SwitchAnimation(AttackType+"AttackBack");
    
    if (PlayerAnimator.GetCurrentAnimationName() == "IdleFront")
        PlayerAnimator.SwitchAnimation(AttackType+"AttackFront");
    
    velocity = 0;
}

void Player::Effects(Animator &Animator, sf::Sprite &EffectSprite) {
    auto& AnimationMagicFireAura = Animator.CreateAnimation("MagicFireAura", m_Player.EffectTexture[0], sf::seconds(2),false);
    AnimationMagicFireAura.AddFrames(sf::Vector2i(0,0), sf::Vector2i(150,150), 7);
    AnimationMagicFireAura.AddFrames(sf::Vector2i(0,150), sf::Vector2i(150,150), 7);
    AnimationMagicFireAura.AddFrames(sf::Vector2i(0,300), sf::Vector2i(150,150), 5);
    AnimationMagicFireAura.AddFrames(sf::Vector2i(0,0), sf::Vector2i(150,150), 1);
    
    auto& AnimationMagicDemonAura = Animator.CreateAnimation("MagicDemonAura", m_Player.EffectTexture[1], sf::seconds(2),false);
    AnimationMagicDemonAura.AddFrames(sf::Vector2i(0,0), sf::Vector2i(150,150), 7);
    AnimationMagicDemonAura.AddFrames(sf::Vector2i(0,150), sf::Vector2i(150,150), 7);
    AnimationMagicDemonAura.AddFrames(sf::Vector2i(0,300), sf::Vector2i(150,150), 5);
    AnimationMagicDemonAura.AddFrames(sf::Vector2i(0,0), sf::Vector2i(150,150), 1);
}

void Player::Setup_Animations(Animator &Animator) {
    //    sprite.setTextureRect(sf::IntRect(0, 0, 53, 95));
    //    sprite.setScale(2.5, 2.5);
    //    sprite.setPosition(900, 460);
    //
    auto& AnimationGetUp = Animator.CreateAnimation("GetUp", m_Player.playerTexture, sf::seconds(1.6), false);
    AnimationGetUp.AddFrames(sf::Vector2i(920,307), sf::Vector2i(120,91), 1);
    AnimationGetUp.AddFrames(sf::Vector2i(800,307), sf::Vector2i(120,91), 1);
    AnimationGetUp.AddFrames(sf::Vector2i(680,307), sf::Vector2i(120,91), 1);
    AnimationGetUp.AddFrames(sf::Vector2i(560,307), sf::Vector2i(120,91), 1);
    AnimationGetUp.AddFrames(sf::Vector2i(440,307), sf::Vector2i(120,91), 1);
    AnimationGetUp.AddFrames(sf::Vector2i(320,307), sf::Vector2i(120,91), 1);
    AnimationGetUp.AddFrames(sf::Vector2i(920,307), sf::Vector2i(120,91), 1);
    AnimationGetUp.AddFrames(sf::Vector2i(0,0), sf::Vector2i(120,100), 1);
    
    
    auto& AnimationRight = Animator.CreateAnimation("MoveRight", m_Player.playerTexture,sf::seconds(1),false);
    AnimationRight.AddFrames(sf::Vector2i(0,100), sf::Vector2i(120,100), 1);
    AnimationRight.AddFrames(sf::Vector2i(125,100), sf::Vector2i(120,100), 1);
    AnimationRight.AddFrames(sf::Vector2i(250,100), sf::Vector2i(120,100), 1);
    AnimationRight.AddFrames(sf::Vector2i(375,100), sf::Vector2i(120,100), 1);
    AnimationRight.AddFrames(sf::Vector2i(500,100), sf::Vector2i(120,100), 1);
    AnimationRight.AddFrames(sf::Vector2i(625,100), sf::Vector2i(120,100), 1);
    AnimationRight.AddFrames(sf::Vector2i(750,100), sf::Vector2i(120,100), 1);
    AnimationRight.AddFrames(sf::Vector2i(875,100), sf::Vector2i(120,100), 1);
    
    auto& AnimationLeft = Animator.CreateAnimation("MoveLeft", m_Player.playerTexture, sf::seconds(0.85),true);
    AnimationLeft.AddFrames(sf::Vector2i(935,100), sf::Vector2i(-120,100), 1);
    AnimationLeft.AddFrames(sf::Vector2i(810,100), sf::Vector2i(-120,100), 1);
    AnimationLeft.AddFrames(sf::Vector2i(685,100), sf::Vector2i(-120,100), 1);
    AnimationLeft.AddFrames(sf::Vector2i(560,100), sf::Vector2i(-120,100), 1);
    AnimationLeft.AddFrames(sf::Vector2i(435,100), sf::Vector2i(-120,100), 1);
    AnimationLeft.AddFrames(sf::Vector2i(310,100), sf::Vector2i(-120,100), 1);
    AnimationLeft.AddFrames(sf::Vector2i(185,100), sf::Vector2i(-120,100), 1);
    AnimationLeft.AddFrames(sf::Vector2i(60,100), sf::Vector2i(-120,100), 1);
    
    auto& AnimationIdleLeft = Animator.CreateAnimation("IdleLeft", m_Player.playerTexture, sf::seconds(1), false);
    AnimationIdleLeft.AddFrames(sf::Vector2i(1260,0), sf::Vector2i(-120,100), 11);
    
    auto& AnimationIdleRight = Animator.CreateAnimation("IdleRight", m_Player.playerTexture, sf::seconds(2), true);
    AnimationIdleRight.AddFrames(sf::Vector2i(0,0), sf::Vector2i(120,100), 11);
    
    auto& AnimationAttackRight = Animator.CreateAnimation("SimpleAttackRight", m_Player.playerTexture, sf::seconds(0.40),false);
    //    AnimationAttackRight.AddFrames(sf::Vector2i(0,200), sf::Vector2i(73,105), 1);
    //    AnimationAttackRight.AddFrames(sf::Vector2i(117,200), sf::Vector2i(73,105), 1); // more frame for the attack animation
    //    AnimationAttackRight.AddFrames(sf::Vector2i(225,200), sf::Vector2i(73,105), 1);
    AnimationAttackRight.AddFrames(sf::Vector2i(355,210), sf::Vector2i(120,100), 1);
    AnimationAttackRight.AddFrames(sf::Vector2i(470,210), sf::Vector2i(120,100), 1);
    AnimationAttackRight.AddFrames(sf::Vector2i(1070,210), sf::Vector2i(120,100), 1);
    AnimationAttackRight.AddFrames(sf::Vector2i(830,210), sf::Vector2i(120,100), 1);
    AnimationAttackRight.AddFrames(sf::Vector2i(1190,210), sf::Vector2i(120,100), 1);
    
    //    AnimationAttackRight.AddFrames(sf::Vector2i(320,959), sf::Vector2i(64,65), 1);
    
    auto& AnimationAttackLeft = Animator.CreateAnimation("SimpleAttackLeft", m_Player.playerTexture, sf::seconds(0.40),false);
    AnimationAttackLeft.AddFrames(sf::Vector2i(355+120,210), sf::Vector2i(-120,100), 1);
    AnimationAttackLeft.AddFrames(sf::Vector2i(470+120,210), sf::Vector2i(-120,100), 1);
    AnimationAttackLeft.AddFrames(sf::Vector2i(1070+120,210), sf::Vector2i(-120,100), 1);
    AnimationAttackLeft.AddFrames(sf::Vector2i(830+120,210), sf::Vector2i(-120,100), 1);
    AnimationAttackLeft.AddFrames(sf::Vector2i(1190+120,210), sf::Vector2i(-120,100), 1);
    
    auto& AnimationMagicFront = Animator.CreateAnimation("MagicFront", m_Player.playerTexture, sf::seconds(2),false);
    AnimationMagicFront.AddFrames(sf::Vector2i(0,0), sf::Vector2i(120,100), 11);
}
