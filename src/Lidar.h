//
// Created by asphox on 25/02/19.
//

#ifndef LIDARVISUALISATION_LIDAR_H
#define LIDARVISUALISATION_LIDAR_H

#include <iostream>
#include <SFML/Network.hpp>
#include "CoordinateGrid.h"
#include "Telegram.h"
#include "Modes.h"

class Lidar
{
private:
    bool m_connected = false;
    MODE m_mode      = MODE::OBSTACLES;

    Telegram m_obstacles;
    sf::TcpSocket m_socket;
    CoordinateGrid& m_grid;

    bool computeRaw(std::string&);
    bool computeObstacles(std::string&);

public:
    Lidar(CoordinateGrid&);

    Lidar(CoordinateGrid&, const std::string& ip, int port);

    bool connect(const std::string& ip, int port);

    void disconnect();

    bool update();

    void setMode( MODE mode );

    inline Telegram& getObstacles() { return m_obstacles; }

    inline bool connected() const { return m_connected; }


};


#endif //LIDARVISUALISATION_LIDAR_H
