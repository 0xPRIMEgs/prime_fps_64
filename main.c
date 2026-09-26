#include <stdio.h>
#include <stdint.h>
#include <libdragon.h>

#include "prime_fps_64.c"

#define W 320
#define H 240

int main(void) {

    const resolution_t resolution = {
        W,
        H,
        false
    };

    display_init(
        resolution,
        DEPTH_16_BPP,
        3,
        GAMMA_NONE,
        FILTERS_RESAMPLE
    );

    rdpq_init();

    initFPS();

    while (1) {

        updateFPS();

        surface_t *disp = display_get();
        rdpq_attach(disp, NULL);

        rdpq_clear((color_t){0, 0, 0, 255});

        drawFPS();

        rdpq_detach_show();
    }

    return 0;
}
