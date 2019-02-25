//
// Created by asphox on 25/02/19.
//

#ifndef LIDARVISUALISATION_TELEGRAM_H
#define LIDARVISUALISATION_TELEGRAM_H

#include <vector>
#include <SFML/Graphics.hpp>
#include "Obstacle.h"
#include "Modes.h"

class CoordinateGrid;

class Telegram : public sf::Drawable
{
private:
    std::vector<Obstacle> m_obstacles;
    MODE                  m_mode;

    virtual void draw(sf::RenderTarget&, sf::RenderStates) const final;

public:
    Telegram() = default;
    Telegram( std::vector<Obstacle>&& , MODE );

    void adaptToGrid(const CoordinateGrid&);

    inline void push( const Obstacle& obstacle ){ m_obstacles.push_back(obstacle); }

    inline void setMode( MODE mode ){ m_mode = mode; }

    inline MODE getMode() const { return m_mode; }

    inline void clear() { m_obstacles.clear(); }

    inline Obstacle& at(size_t i) { return m_obstacles[i]; }

    inline size_t getSize() const { return m_obstacles.size(); }
};


#endif //LIDARVISUALISATION_TELEGRAM_H
