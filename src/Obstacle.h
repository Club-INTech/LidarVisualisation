//
// Created by asphox on 20/02/19.
//

#ifndef LIDARVISUALISATION_OBSTACLE_H
#define LIDARVISUALISATION_OBSTACLE_H

#include <SFML/Graphics.hpp>
#include <cmath>
#include "CoordinateGrid.h"

class Obstacle : public sf::Drawable
{
private:
    float m_r = 0;
    float m_angle = 0;
    float m_radius = 10;

    sf::CircleShape m_shape;
    CoordinateGrid& m_grid;

    void update();

    virtual void draw(sf::RenderTarget&, sf::RenderStates ) const final;
public:

    Obstacle(CoordinateGrid&);

    void setPolarPosition(float r,float angle);
};


#endif //LIDARVISUALISATION_OBSTACLE_H
