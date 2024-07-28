/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** weather
*/

#include <stdbool.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Network.h>
#include <SFML/Graphics.h>

#ifndef WEATHER_H_
    #define WEATHER_H_

typedef struct weather_s {
    bool autumn;
    bool night;
    sfRectangleShape *autumn_filter;
    sfRectangleShape *night_filter;
} weather_t;

#endif /* !WEATHER_H_ */
