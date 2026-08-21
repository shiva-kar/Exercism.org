#include "resistor_color_trio.h"

resistor_value_t color_code(resistor_band_t *bands) {
    uint64_t raw = (bands[0] * 10 + bands[1]);
    for (uint16_t i = 0; i < bands[2]; i++) raw *= 10;    
    
    resistor_unit_t unit = OHMS;
    if (raw % 1000000000 == 0 && raw >= 1000000000) {
        raw /= 1000000000;
        unit = GIGAOHMS;
    } else if (raw % 1000000 == 0 && raw >= 1000000) {
        raw /= 1000000;
        unit = MEGAOHMS;
    } else if (raw % 1000 == 0 && raw >= 1000) {
        raw /= 1000;
        unit = KILOOHMS;
    }

    return (resistor_value_t){ .value = (uint16_t)raw, .unit = unit };
}