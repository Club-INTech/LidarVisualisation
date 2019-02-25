//
// Created by asphox on 20/02/19.
//
#include <iostream>
#include "Obstacle.h"
#include "CoordinateGrid.h"

Obstacle::Obstacle()
{
    m_shape.setRadius(m_radius);
    m_shape.setFillColor(sf::Color::Red);
}

void Obstacle::adaptToGrid(const CoordinateGrid& grid, MODE mode)
{
    if(mode == MODE::OBSTACLES)
        m_shape.setRadius(m_radius);
    else if(mode == MODE::RAW)
        m_shape.setRadius(2);
    m_shape.setOrigin(-grid.getCenter().x+m_shape.getRadius(),-grid.getCenter().y+m_shape.getRadius());
    m_shape.setPosition(grid.realPolarToWindowCartesian(m_r,m_angle));
}

void Obstacle::setPolarPosition(float r, float angle)
{
    m_r = r;
    m_angle = angle;
}

void Obstacle::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    if( m_r != 0 )
        target.draw(m_shape,states);
}