//
// Created by asphox on 20/02/19.
//

#include "Obstacle.h"

Obstacle::Obstacle(CoordinateGrid& grid)
:   m_grid(grid)
{
    m_shape.setRadius(m_radius);
    m_shape.setFillColor(sf::Color::Red);
}

void Obstacle::update()
{
    m_shape.setOrigin(-m_grid.getCenter().x+m_radius,-m_grid.getCenter().y+m_radius);
    m_shape.setPosition(m_grid.realPolarToWindowCartesian(m_r,m_angle));

   m_shape.setRadius(m_radius);
}

void Obstacle::setPolarPosition(float r, float angle)
{
    m_r = r;
    m_angle = angle;
    update();
}

void Obstacle::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    if( m_r != 0 )
        target.draw(m_shape,states);
}