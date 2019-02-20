//
// Created by asphox on 20/02/19.
//

#include "TitleStatus.h"

TitleStatus::TitleStatus(sf::RenderWindow& window, const std::string& title, const std::string& status )
:   m_window(window)
,   m_title(title)
,   m_status(status)
{
    update();
}

std::string TitleStatus::get() const
{
    return m_title+" ["+m_status+"]";
}

void TitleStatus::setTitle( const std::string& title )
{
    m_title = title;
    update();
}

void TitleStatus::setStatus( const std::string& status )
{
    m_status = status;
    update();
}

void TitleStatus::set(const std::string& title, const std::string& status )
{
    m_title = title;
    m_status = status;
    update();
}

void TitleStatus::update()
{
    m_window.setTitle(get());
}