#include "reloj.h"
#include <string.h>

struct clock_s {
    uint8_t hora_actual[6];
    bool valida;
    uint8_t tick;
    uint16_t tick_x_sec;

};

clock_t ClockCreate(int tics_por_segundo){ // define la cantidad de ticks por segundo del reloj
    static struct clock_s self[1];
    memset(self, 0, sizeof(self));

    self->tick_x_sec = tics_por_segundo;
    return self;
}

bool ClockGetTime(clock_t reloj, uint8_t * hora, int size){
    memcpy(hora, reloj->hora_actual, size);
    return reloj->valida;
}

bool ClockSetTime(clock_t reloj, const  uint8_t * hora, int size){
    memcpy(reloj->hora_actual, hora, size);
    reloj->valida = true;
    return reloj->valida;
}

void ClockNewTick(clock_t clock){
    clock->tick++;
    ClockNewSec(clock);
}

void ClockNewSec(clock_t clock){
    if (clock->tick == clock->tick_x_sec){
        if(clock->hora_actual[5] == 9){ // incrementa una decena
            clock->hora_actual[5] = 0;
            clock->hora_actual[4]++;
        } else {    
            clock->hora_actual[5]++;    // incremento un segundo
            clock->tick = 0;
        }
    }

}