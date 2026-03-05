#include "resistor_color.h"

int color_code(resistor_band_t color){
    return color;
}
resistor_band_t* colors(){
    static resistor_band_t colors[10];
    resistor_band_t *temp = colors;
    for(int i = 0; i < 10; i++){
        *temp = i;
        temp++;
    }
    return colors;
}