//
// Created by asphox on 20/02/19.
//

#ifndef LIDARVISUALISATION_UTILS_H
#define LIDARVISUALISATION_UTILS_H

constexpr float PI = 3.14159265359;

constexpr float RAD_TO_DEG(float a)
{
    return a*180.0/PI;
}

constexpr float DEG_TO_RAD(float a)
{
    return a*PI/180.0;
}

#endif //LIDARVISUALISATION_UTILS_H
