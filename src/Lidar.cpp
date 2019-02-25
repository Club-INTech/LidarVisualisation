//
// Created by asphox on 25/02/19.
//

#include "Lidar.h"


Lidar::Lidar(CoordinateGrid& grid)
:m_grid(grid)
{}

Lidar::Lidar(CoordinateGrid& grid, const std::string &ip, int port)
:m_grid(grid)
{
    connect(ip,port);
}

bool Lidar::connect(const std::string &ip, int port)
{
    m_connected = m_socket.connect(ip,port) == sf::Socket::Status::Done;
    return m_connected;
}

void Lidar::disconnect()
{
    m_socket.disconnect();
}

bool Lidar::computeRaw(std::string& str)
{
    Obstacle    tmp_obstacle;
    m_obstacles.clear();
    m_obstacles.setMode(MODE::RAW);

    long int pos = 0;
    str = str.substr(1);
    float r;
    float angle;
    try
    {
        while( str.length() )
        {
            pos = str.find(':');
            r = std::stof(str.substr(0,pos));
            str = str.substr(pos+1);
            pos = str.find(';');
            if( pos == -1 ) pos = str.find('\n');
            angle = std::stof(str.substr(0,pos));
            str = str.substr(pos+1);
            tmp_obstacle.setPolarPosition(r/1000,angle);
            m_obstacles.push(tmp_obstacle);
        }
        return true;
    }
    catch( std::invalid_argument& e )
    {
        return false;
    }
}

bool Lidar::computeObstacles(std::string& str)
{
    Obstacle    tmp_obstacle;
    m_obstacles.clear();
    m_obstacles.setMode(MODE::OBSTACLES);

    long int pos = 0;
    str = str.substr(1);
    float r;
    float angle;
    try
    {
        while( str.length() )
        {
            pos = str.find(':');
            r = std::stof(str.substr(0,pos));
            str = str.substr(pos+1);
            pos = str.find(';');
            if( pos == -1 ) pos = str.find('\n');
            angle = std::stof(str.substr(0,pos));
            str = str.substr(pos+1);
            tmp_obstacle.setPolarPosition(r/1000.0,angle);
            m_obstacles.push(tmp_obstacle);
        }
        return true;
    }
    catch( std::invalid_argument& e )
    {
        return false;
    }
}

void Lidar::setMode(MODE mode)
{
    m_mode = mode;
    if( mode == MODE::OBSTACLES )
    {
        m_socket.send("!!O\n",4);
    }
    else if( mode == MODE::RAW )
    {
        m_socket.send("!!R\n",4);
    }
}

bool Lidar::update()
{
    std::string buffer;
    std::size_t nbrBytesReceived;

    char tmp_c = 0x00;
    while( tmp_c != '\n' )
    {
        m_socket.receive(&tmp_c,1,nbrBytesReceived);
        if( tmp_c != 0x00 ) {
            buffer+=tmp_c;
        }
    }

    if( buffer[0] == '!' && buffer[1] == '!' && buffer[buffer.length()-1] == '\n' )
    {
        buffer = buffer.substr(2);
        switch(m_mode)
        {
            case MODE::RAW :        return computeRaw(buffer);
            case MODE::OBSTACLES :  return computeObstacles(buffer);
            default  :              return false;
        }
    }
    return false;
}




