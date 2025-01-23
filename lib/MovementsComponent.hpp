#ifndef MOVEMENTSCOMPONENT_HPP
#define MOVEMENTSCOMPONENT_HPP

#include "Linker.hpp"

//enum States {
//	Walking,
//	Running,
//};

class MovementsComponent {
private:
    
    const sf::Keyboard::Scancode upKey;
    const sf::Keyboard::Scancode downKey;
    const sf::Keyboard::Scancode rightKey;
    const sf::Keyboard::Scancode leftKey;

    float speed;
    float acceleration;

public:
    
    MovementsComponent() :
        upKey(sf::Keyboard::Scan::W),
        downKey(sf::Keyboard::Scan::S),
        rightKey(sf::Keyboard::Scan::D),
        leftKey(sf::Keyboard::Scan::A)  {}

    void MoveLeft(sf::Transformable* object) {
        object->move();
    }
    void MoveRight(sf::Transformable* object) {
        object->move();
    }
    void MoveUp(sf::Transformable* object) {
        object->move();
    }
    void MoveDown(sf::Transformable* object) {
        object->move();
    }

};

#endif // MOVEMENTSCOMPONENT_HPP