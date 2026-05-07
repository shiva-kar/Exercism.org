#include "space_age.h"

float age(planet_t planet, int64_t seconds){
    if(planet < 0 || planet > 7) return -1.0;
    float age;
    switch (planet){
        case MERCURY:
            age = (seconds/(31557600 * 0.2408467));
            break;
        case VENUS:
            age = (seconds/(31557600 * 0.61519726));
            break;
        case EARTH:
            age = (seconds/(31557600 * 1.0));
            break;
        case MARS:
            age = (seconds/(31557600 * 1.8808158));
            break;
        case JUPITER:
            age = (seconds/(31557600 * 11.862615));
            break;
        case SATURN:
            age = (seconds/(31557600 * 29.447498));
            break;
        case URANUS:
            age = (seconds/(31557600 * 84.016846));
            break;
        case NEPTUNE:
            age = (seconds/(31557600 * 164.79132));
            break;
    }
    return age;
}