//
//  Menu.cpp
//  The Etheral Land II
//
//  Created by Quentin Le Gal on 02/02/2017.
//  Copyright © 2017 Quentin Le Gal. All rights reserved.
//

#include "Menu.hpp"

#include "Menu.hpp"

Menu::Menu() {
    
}

int Menu::Play(sf::RenderWindow &Window, std::vector<sf::Texture> &Textures, sf::Font &font, Player &Hero) {
    
    sf::Texture texture;
    bool start = false;
    m_name = "Your Name";
    sf::Clock clock;
    sf::Sprite sprite, Button1, Button2, Button3, Button4, Button5, Button6;
    std::vector<sf::Sprite> Sprites;
    std::vector<Animator*> Animations;
    Animator Background(sprite),ButtonAnimator(Button1),ButtonAnimator2(Button2),ButtonAnimator3(Button3),ButtonAnimator4(Button4),ButtonAnimator5(Button5),ButtonAnimator6(Button6);
    
    texture.loadFromFile(resourcePath() + "SolaireBackground.png");
    GetPlayerTextures(Textures);
    
    //    SetUpElems(Background, ButtonAnimator, ButtonAnimator2);
    
    auto& backgroundAnimation = Background.CreateAnimation("background", texture, sf::seconds(2), true);
    backgroundAnimation.AddFrames(sf::Vector2i(0,0), sf::Vector2i(960,512), 10);
    backgroundAnimation.AddFrames(sf::Vector2i(0,512), sf::Vector2i(960,512), 10);
    m_class = 0;
    
    CreateButton(Textures[4], ButtonAnimator);
    CreateButton(Textures[4], ButtonAnimator2);
    CreateButton(Textures[4], ButtonAnimator3);
    CreateButton(Textures[4], ButtonAnimator4);
    CreateButton(Textures[4], ButtonAnimator5);
    CreateButton(Textures[4], ButtonAnimator6);
    ButtonAnimator6.SwitchAnimation("ButtonOff");
    
    Animations.push_back(&Background);
    Animations.push_back(&ButtonAnimator);
    Animations.push_back(&ButtonAnimator2);
    Animations.push_back(&ButtonAnimator3);
    Animations.push_back(&ButtonAnimator4);
    Animations.push_back(&ButtonAnimator5);
    Animations.push_back(&ButtonAnimator6);
    
    sprite.setScale(1920./960., 1080./512.);
    
    Button1.setPosition(400, 400);
    Button2.setPosition(400, 500);
    Button3.setPosition(400, 600);
    Button4.setPosition(400, 700);
    Button5.setPosition(400, 200);
    Button6.setPosition(780, 900);
    Button5.setScale(1.5, 1);
    Button6.setScale(1.2, 1);
    
    sf::Text opt1("Crusader", font, 45);
    opt1.setFillColor(sf::Color::White);
    opt1.setPosition(sf::Vector2f(400+150-opt1.getGlobalBounds().width/2,400+34-opt1.getGlobalBounds().height/2));
    
    sf::Text opt2("Ranger", font, 45);
    opt2.setFillColor(sf::Color::White);
    opt2.setPosition(sf::Vector2f(400+150-opt2.getGlobalBounds().width/2,500+34-opt1.getGlobalBounds().height/2));
    
    sf::Text opt3("Rogue", font, 45);
    opt3.setFillColor(sf::Color::White);
    opt3.setPosition(sf::Vector2f(400+150-opt3.getGlobalBounds().width/2,600+34-opt1.getGlobalBounds().height/2));
    
    sf::Text opt4("Mage", font, 45);
    opt4.setFillColor(sf::Color::White);
    opt4.setPosition(sf::Vector2f(400+150-opt4.getGlobalBounds().width/2,700+34-opt1.getGlobalBounds().height/2));
    
    sf::Text opt5("Your Name", font, 45);
    opt5.setFillColor(sf::Color::White);
    opt5.setPosition(sf::Vector2f(400+Button5.getLocalBounds().width/4*1.5-opt5.getLocalBounds().width/2,200+34-opt1.getGlobalBounds().height/2));
    
    sf::Text opt6("Select a Class", font, 45);
    opt6.setFillColor(sf::Color::White);
    opt6.setPosition(sf::Vector2f(773+Button6.getLocalBounds().width/4*1.2-opt6.getLocalBounds().width/2,900+34-opt1.getGlobalBounds().height/2));
    
    sf::Text opt7("Description of this class\nthis is a very nice\nclass with a lot of stuff", font, 35);
    opt7.setFillColor(sf::Color::White);
    opt7.setPosition(sf::Vector2f(1200, 500));
    
    
    //    Sprites = SetTextures(Textures);
    
    sf::Uint8 light = 120; // 255 = initial brightness, 0 = black
    
    while (Window.isOpen())
    {
        sf::Event event;
        sf::Time deltatime = clock.restart();
        
        if (m_class > 0 && m_class < 6)
            ButtonAnimator6.SwitchAnimation("ButtonOn");
        else
            ButtonAnimator6.SwitchAnimation("ButtonOff");
        while (Window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) { Window.close(); }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                Window.close();
            }
            if (event.type == sf::Event::MouseMoved) {
                
            }
            if (event.type == sf::Event::TextEntered && ButtonAnimator5.GetCurrentAnimationName() ==
                "ButtonOff") {
                if (event.text.unicode < 128) {
                    if (event.text.unicode < 127 && event.text.unicode > 19)
                        m_name = m_name + static_cast<char>(event.text.unicode);
                    if (event.text.unicode == 8 )
                        m_name.pop_back();
                }
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                MouseAction(Window, event, Animations);
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
                sprite.setColor(sf::Color(light, light, light));
                start = true;
            }
            if (event.type == sf::Event::MouseButtonReleased) {
            }
            
        }
        if (opt5.getString() == "" && ButtonAnimator5.GetCurrentAnimationName() !=
            "ButtonOff")
            m_name = "Your Name";
        else
            opt5.setString(m_name);
        
        opt5.setPosition(sf::Vector2f(400+Button5.getLocalBounds().width/2*1.5-opt5.getLocalBounds().width/2,200+34-opt1.getGlobalBounds().height/2));
        
        
        Background.update(deltatime);
        ButtonAnimator.update(deltatime);
        ButtonAnimator2.update(deltatime);
        ButtonAnimator3.update(deltatime);
        ButtonAnimator4.update(deltatime);
        ButtonAnimator5.update(deltatime);
        ButtonAnimator6.update(deltatime);
        Window.clear();
        Window.draw(sprite);
        DrawChar(Window);
        
        if (start) {
            Window.draw(Button1);
            Window.draw(Button2);
            Window.draw(Button3);
            Window.draw(Button4);
            Window.draw(Button5);
            Window.draw(Button6);
            Window.draw(opt1);
            Window.draw(opt2);
            Window.draw(opt3);
            Window.draw(opt4);
            Window.draw(opt5);
            Window.draw(opt6);
            Window.draw(opt7);
        }
        if (m_start) {
            Hero.Init(opt5.getString(), "", m_Player_class, Textures);
            return 1;
        }
        Window.display();
    }
    return 1;
}

void Menu::MouseAction(sf::RenderWindow &Window, sf::Event &event, std::vector<Animator*> &Animations) {
    sf::Vector2i pixelPos = sf::Mouse::getPosition(Window);
    sf::Vector2f worldPos = Window.mapPixelToCoords(pixelPos);
    sf::Vector2i Itembounds;
    
    if (Animations[6]->GetCurrentAnimationName() == "ButtonOn" && Animations[6]->returnSprite().getGlobalBounds().contains(worldPos)) {
        m_start = true;
        Animations[6]->SwitchAnimation("ButtonOff");
    }
    for (int i = 0; i != Animations.size(); i++) {
        if (Animations[i]->GetCurrentAnimationName() != "background") {
            if (Animations[i]->returnSprite().getGlobalBounds().contains(worldPos) && i != 5) {
                m_class = i;
                Animations[i]->SwitchAnimation("ButtonOff");
            }
            if (Animations[i]->returnSprite().getGlobalBounds().contains(worldPos) && i != 5 && i != 6) {
                m_Player_class = i;
                Animations[i]->SwitchAnimation("ButtonOff");
            }
            if (Animations[i]->returnSprite().getGlobalBounds().contains(worldPos) && i == 5) {
                Animations[i]->SwitchAnimation("ButtonOff");
            }
        }
    }
    printf("%d\n", m_class);
    Animations[m_class]->SwitchAnimation("ButtonOn");
}

void Menu::MouseEvent(sf::RenderWindow &window, sf::Event &event, sf::Sprite &Button, Animator &Animator) {
    sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
    // convert it to world coordinates
    sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);
    if (Button.getGlobalBounds().contains(worldPos) && Animator.GetCurrentAnimationName() != "ButtonOff"){
        Animator.SwitchAnimation("ButtonOff");
    }
    if (!Button.getGlobalBounds().contains(worldPos) && Animator.GetCurrentAnimationName() != "ButtonOn"){
        Animator.SwitchAnimation("ButtonOn");
    }
}

void Menu::CreateButton(sf::Texture &Texture, Animator &ButtonAnimator) {
    auto& ButtonOn = ButtonAnimator.CreateAnimation("ButtonOn", Texture, sf::seconds(0.2), true);
    ButtonOn.AddFrames(sf::Vector2i(299,55), sf::Vector2i(299,85), 1);
    auto& ButtonOff = ButtonAnimator.CreateAnimation("ButtonOff", Texture, sf::seconds(0.2), true);
    ButtonOff.AddFrames(sf::Vector2i(0,55), sf::Vector2i(299,85), 1);
}

void Menu::DrawChar(sf::RenderWindow &Window) {
    sf::Sprite sprite;
    switch (m_class) {
        case 1:
            sprite.setTexture(m_PlayerTextures.Crusader);
            sprite.setTextureRect(sf::IntRect(0, 0, 53, 95));
            sprite.setScale(2.5, 2.5);
            sprite.setPosition(900, 460);
            break;
        case 2:
            sprite.setTexture(m_PlayerTextures.Ranger);
            sprite.setTextureRect(sf::IntRect(0, 0, 51, 77));
            sprite.setScale(2.5, 2.5);
            sprite.setPosition(900, 500);
            break;
        case 3:
            sprite.setTexture(m_PlayerTextures.Rogue);
            sprite.setTextureRect(sf::IntRect(0, 0, 53, 77));
            sprite.setScale(2.5, 2.5);
            sprite.setPosition(900, 500);
            break;
        case 4:
            sprite.setTexture(m_PlayerTextures.Mage);
            sprite.setTextureRect(sf::IntRect(0, 0, 51, 87));
            sprite.setScale(2.2, 2.2);
            sprite.setPosition(910, 510);
            break;
        default:
            sprite.setTextureRect(sf::IntRect(0, 0, 1, 1));
            
            return;
            break;
    }
    Window.draw(sprite);
}

void Menu::GetPlayerTextures(std::vector<sf::Texture> textures) {
    m_PlayerTextures.Crusader = textures[0];
    m_PlayerTextures.Mage = textures[1];
    m_PlayerTextures.Rogue = textures[2];
    m_PlayerTextures.Ranger = textures[3];
}
