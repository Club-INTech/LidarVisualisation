//
// Created by asphox on 20/02/19.
//

#ifndef LIDARVISUALISATION_TITLESTATUS_H
#define LIDARVISUALISATION_TITLESTATUS_H

#include <SFML/Graphics.hpp>
#include <string>

class TitleStatus
{
private:
    sf::RenderWindow& m_window;
    std::string m_title;
    std::string m_status;

    void update();

public:
    TitleStatus() = default;
    TitleStatus(sf::RenderWindow& window, const std::string& title, const std::string& status);

    std::string get() const;

    void setTitle( const std::string& title );

    void setStatus( const std::string& status );

    void set( const std::string& title, const std::string& status );

};


#endif //LIDARVISUALISATION_TITLESTATUS_H
