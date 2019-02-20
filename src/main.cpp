//
// Created by asphox on 20/02/19.
//

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include "TitleStatus.h"
#include "CoordinateGrid.h"
#include  "Obstacle.h"
#include "iostream"

int main()
{

    char buffer[1000];

    bool m_connected = false;
    sf::TcpSocket socket;
    socket.setBlocking(true);
    sf::RenderWindow window(sf::VideoMode(800, 800), "");
    TitleStatus titleStatus(window,"LidarVisualisation","Waiting lidar on 127.0.0.1:17865 ... ");
    CoordinateGrid grid(window);

    std::vector<Obstacle> arraynul;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if( !m_connected && socket.connect("127.0.0.1",17865) == sf::Socket::Status::Done )
        {
            m_connected = true;
            socket.setBlocking(false);
            titleStatus.setStatus("Connected !");
        }

        if( m_connected )
        {
            std::string str;
            std::size_t r;
            arraynul.clear();
           char c = 0x00;
           int i = 0;
           while( c != '\n' )
           {
               socket.receive(&c,1,r);
               if( c != 0x00 )
                 str+=c;
           }
           str = str.substr(2);

           while( str.length() )
           {
               int pos = str.find(':');
               float r = std::stof(str.substr(0,pos));
               str = str.substr(pos+1);
               pos = str.find(';');
               if( pos == -1)
                   pos = str.find('\n');
               float angle = std::stof(str.substr(0,pos));
               str = str.substr(pos+1);
               Obstacle obs(grid);
               obs.setPolarPosition(r/1000.0,angle);
               arraynul.push_back(obs);
           }
        }

        window.clear(sf::Color::Black);

        window.draw(grid);

        for( auto& it : arraynul )
        {
            window.draw(it);
        }
        window.display();
    }

    return 0;
}