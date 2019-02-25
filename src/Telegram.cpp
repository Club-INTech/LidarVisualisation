//
// Created by asphox on 25/02/19.
//

#include "Telegram.h"
#include "CoordinateGrid.h"

Telegram::Telegram(std::vector<Obstacle>&& obstacles , MODE mode)
:m_obstacles(obstacles)
,m_mode(mode)
{}

void Telegram::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for(auto& it : m_obstacles)
    {
        target.draw(it,states);
    }
}

void Telegram::adaptToGrid(const CoordinateGrid& grid)
{
    for( auto& it : m_obstacles )
    {
        it.adaptToGrid(grid,m_mode);
    }
}