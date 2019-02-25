//
// Created by asphox on 20/02/19.
//

#ifndef LIDARVISUALISATION_OBSTACLE_H
#define LIDARVISUALISATION_OBSTACLE_H

#include <SFML/Graphics.hpp>
#include "Modes.h"
#include <cmath>

class CoordinateGrid;

class Obstacle : public sf::Drawable
{
private:
    friend class Telegram;
    float m_r = 0;
    float m_angle = 0;
    float m_radius = 10;

    sf::CircleShape m_shape;

    virtual void draw(sf::RenderTarget&, sf::RenderStates ) const final;
public:

    Obstacle();


    void adaptToGrid(const CoordinateGrid& grid, MODE mode);


    void setPolarPosition(float r,float angle);
};


#endif //LIDARVISUALISATION_OBSTACLE_H
