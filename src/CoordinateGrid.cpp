//
// Created by asphox on 20/02/19.
//

#include "CoordinateGrid.h"

CoordinateGrid::CoordinateGrid(sf::RenderTarget& target)
:   m_render(target)
{
    stretch_X = target.getSize().x/(MAX_RADIUS_METERS*2);
    stretch_Y = target.getSize().y/(MAX_RADIUS_METERS*2);

    m_axis_x.setSize(sf::Vector2f(target.getSize().x,2));
    m_axis_x.setOrigin(m_axis_x.getSize().x/2,1);
    m_axis_x.setPosition(target.getSize().x/2,target.getSize().y/2);

    m_axis_y.setSize(sf::Vector2f(2,target.getSize().y));
    m_axis_y.setOrigin(1,m_axis_y.getSize().y/2);
    m_axis_y.setPosition(target.getSize().x/2,target.getSize().y/2);

    m_axis_min_deg.setSize(sf::Vector2f(1,target.getSize().x));
    m_axis_min_deg.setOrigin(0,0);
    m_axis_min_deg.rotate(-MIN_DEG-ADAPTATION_DEG);
    m_axis_min_deg.setPosition(target.getSize().x/2,target.getSize().y/2);
    m_axis_min_deg.setFillColor(sf::Color::Yellow);

    m_axis_max_deg.setSize(sf::Vector2f(1,target.getSize().x));
    m_axis_max_deg.setOrigin(0,0);
    m_axis_max_deg.rotate(ADAPTATION_DEG-MAX_DEG);
    m_axis_max_deg.setPosition(target.getSize().x/2,target.getSize().y/2);
    m_axis_max_deg.setFillColor(sf::Color::Yellow);

    m_1m_radius_circle.setRadius(1);
    m_1m_radius_circle.scale(stretch_X,stretch_Y);
    m_1m_radius_circle.setOrigin(m_1m_radius_circle.getRadius(),m_1m_radius_circle.getRadius());
    m_1m_radius_circle.setPosition(target.getSize().x/2,target.getSize().y/2);
    m_1m_radius_circle.setOutlineThickness(1/stretch_X);
    m_1m_radius_circle.setFillColor(sf::Color::Transparent);

    m_2m_radius_circle.setRadius(1);
    m_2m_radius_circle.scale(stretch_X*2,stretch_Y*2);
    m_2m_radius_circle.setOrigin(m_2m_radius_circle.getRadius(),m_2m_radius_circle.getRadius());
    m_2m_radius_circle.setPosition(target.getSize().x/2,target.getSize().y/2);
    m_2m_radius_circle.setOutlineThickness(1/stretch_X);
    m_2m_radius_circle.setFillColor(sf::Color::Transparent);

    m_3m_radius_circle.setRadius(1);
    m_3m_radius_circle.scale(stretch_X*3,stretch_Y*3);
    m_3m_radius_circle.setOrigin(m_3m_radius_circle.getRadius(),m_3m_radius_circle.getRadius());
    m_3m_radius_circle.setPosition(target.getSize().x/2,target.getSize().y/2);
    m_3m_radius_circle.setOutlineThickness(1/stretch_X);
    m_3m_radius_circle.setFillColor(sf::Color::Transparent);


}

void CoordinateGrid::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_axis_x,states);
    target.draw(m_axis_y,states);
    target.draw(m_axis_min_deg,states);
    target.draw(m_axis_max_deg,states);
    target.draw(m_1m_radius_circle,states);
    target.draw(m_2m_radius_circle,states);
    target.draw(m_3m_radius_circle,states);
}

sf::Vector2f CoordinateGrid::realPolarToWindowCartesian(float r, float angle) const
{
    angle-=DEG_TO_RAD(ADAPTATION_DEG/2);
    return sf::Vector2f(-stretch_X*r*cosf(angle),stretch_Y*r*sinf(angle));
}