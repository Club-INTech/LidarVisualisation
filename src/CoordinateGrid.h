//
// Created by asphox on 20/02/19.
//

#ifndef LIDARVISUALISATION_COORDINATEGRID_H
#define LIDARVISUALISATION_COORDINATEGRID_H

#include <SFML/Graphics.hpp>
#include <cmath>
#include "Telegram.h"
#include "Utils.h"

class CoordinateGrid : public sf::Drawable
{
private:

    static constexpr float MAX_RADIUS_M = 3;
    static constexpr float MIN_DEG = -135;
    static constexpr float MAX_DEG = 135;
    static constexpr float ADAPTATION_DEG = 180;

    sf::RenderTarget& m_render;
    float stretch_X = 0;
    float stretch_Y = 0;

    virtual void draw(sf::RenderTarget&, sf::RenderStates) const final;

    sf::RectangleShape  m_axis_x;
    sf::RectangleShape  m_axis_y;
    sf::RectangleShape  m_axis_min_deg;
    sf::RectangleShape  m_axis_max_deg;
    sf::CircleShape     m_1m_radius_circle;
    sf::CircleShape     m_2m_radius_circle;
    sf::CircleShape     m_3m_radius_circle;

    Telegram*           m_telegram = nullptr;

public:
    CoordinateGrid(sf::RenderTarget&);

    sf::Vector2f realPolarToWindowCartesian( float r, float angle ) const ;

    inline void setTelegram(Telegram& telegram) { m_telegram = &telegram; }

    inline sf::Vector2f getCenter() const
    {
        return sf::Vector2f(m_render.getSize().x/2,m_render.getSize().y/2);
    }

};


#endif //LIDARVISUALISATION_COORDINATEGRID_H
