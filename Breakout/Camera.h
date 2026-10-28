#pragma once
#include <SFML/Graphics.hpp>


class GameManager;  // forward declaration



class Camera {
public:
    Camera(sf::RenderWindow* window, GameManager* gameManager);
    ~Camera();
    void update(float dt);
    void render();
    void shake();

    float shakeVal;
    sf::Vector2f offset;
    float offsetRot;
    sf::Time time = sf::seconds(4);
private:

    sf::RenderWindow* _window;
    sf::View _view;
    sf::Vector2f _centre;
    
    GameManager* _gameManager;  // Reference to the GameManager
};

