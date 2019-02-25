//
// Created by asphox on 20/02/19.
//

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include "TitleStatus.h"
#include "CoordinateGrid.h"
#include "Lidar.h"
#include "iostream"

static const std::string version = "LidarVisualisation version 0.1, by Intech";

int main(int argc, char* argv[])
{
    uint16_t W = 800, H = 800;
    std::string ip_address = "127.0.0.1";
    int port = 17865;
    uint32_t timeout_ms = 10000;
    std::string arg;
    for( int i = 1 ; i < argc ; i++ )
    {
        arg = argv[i];
        if( arg == "-w" )
        {
            if( i+1 < argc )
            {
                arg = argv[i+1];
                int pos = arg.find('x');
                W = std::stof(arg.substr(0,pos));
                arg = arg.substr(pos+1);
                H = std::stof(arg);
            }
        }
        else if( arg == "-a" )
        {
            if( i+1 < argc )
            {
                ip_address = argv[i+1];
            }
        }
        else if( arg == "-p" )
        {
            if( i+1 < argc )
            {
                port = std::stoi(argv[i+1]);
            }
        }
        else if( arg == "-v" )
        {
            std::cout << version << std::endl;
            return 0;
        }
        else if( arg == "-t" )
        {
            if( i+1 < argc )
            {
                timeout_ms = std::stoi(argv[i+1]);
            }
        }
    }

    sf::RenderWindow window(sf::VideoMode(W, H), "");
    window.setFramerateLimit(30);
    TitleStatus titleStatus(window,"LidarVisualisation","Waiting lidar on 127.0.0.1:17865 ... ");
    CoordinateGrid grid(window);
    Lidar lidar(grid);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if( event.type == sf::Event::KeyReleased )
            {
                if( event.key.code == sf::Keyboard::R )
                    lidar.setMode(MODE::RAW);
                else if( event.key.code == sf::Keyboard::O )
                    lidar.setMode(MODE::OBSTACLES);
            }
        }

        if( !lidar.connected() && lidar.connect(ip_address,port) )
        {
            titleStatus.setStatus("Connected !");
        }

        if( lidar.connected() )
        {
            if(lidar.update())
            {
                grid.setTelegram(lidar.getObstacles());
            }
        }

        window.clear(sf::Color::Black);

        window.draw(grid);

        window.display();
    }

    return 0;
}