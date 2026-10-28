#include "Camera.h"
#include "GameManager.h" // avoid cicular dependencies

Camera::Camera(sf::RenderWindow* window, GameManager* gameManager)
    : _window(window), _gameManager(gameManager)
{
    _view = _window->getView();
    _centre = sf::Vector2f(_view.getSize().x / 2, _view.getSize().y / 2);
    _view.setCenter(_centre);

    shakeVal = 0;
    offset = sf::Vector2f(0, 0);
}

Camera::~Camera()
{}

void Camera::update(float dt)
{
    if (shakeVal <= 0)
    {
        _view.setCenter(_centre);
        _view.setRotation(0);
        _window->setView(_view);
        return; //stop update
    }

    //juice effects
    offset.x = ((rand() % 100) - 50) * shakeVal; //random num between -10 and 10
    offset.y = ((rand() % 100) - 50) * shakeVal;
    offsetRot = ((rand() % 1) - 0.5) * shakeVal; //random num between -0.5 and 0.5

    _view.setCenter(sf::Vector2f(_view.getCenter() + offset));
    _view.setRotation(_view.getRotation() + offsetRot);
    _window->setView(_view);

    //time += sf::seconds(dt);
    shakeVal -= 0.1;
}

void Camera::render()
{
    
}

void Camera::shake()
{
    shakeVal += 1;
    //time = sf::seconds(0);
}