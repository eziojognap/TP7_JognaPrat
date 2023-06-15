#include "reloj.h"
#include <string.h>
#include <stdio.h>

void ClockControlAlarm(clock_t clock);

struct alarm_s {
    uint8_t alarma_actual[6];
    bool valida;
    bool activada;
    Alarm_activate activar_alarma_f;
};

struct clock_s {
    uint8_t hora_actual[6];
    bool valida;
    uint32_t tick;
    uint16_t tick_x_sec;
    struct alarm_s alarma[1];
};

clock_t ClockCreate(int tics_por_segundo, Alarm_activate alarma){ // define la cantidad de ticks por segundo del reloj
    static struct clock_s self[1];
    memset(self, 0, sizeof(self));

    self->tick_x_sec = tics_por_segundo;

    self->alarma->activar_alarma_f = alarma;

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
    ClockTenSec(clock);
    ClockNewMin(clock);
    ClockTenMin(clock);
    ClockNewHour(clock);
    ClockTenHour(clock);
    ClockNewDay(clock);
}

void ClockNewSec(clock_t clock){
    if (clock->tick == clock->tick_x_sec){
        clock->hora_actual[5]++;    // incremento un segundo
        clock->tick = 0;
        // printf("segundo\n");
    }
}

void ClockTenSec(clock_t clock){
    if(clock->hora_actual[5] == 10){ // incrementa una decena
        clock->hora_actual[5] = 0;
        clock->hora_actual[4]++;
        // printf("10 seg\n");
    }
}

void ClockNewMin(clock_t clock){
    if(clock->hora_actual[4] == 6){
        clock->hora_actual[4] = 0;
        clock->hora_actual[5] = 0;
        clock->hora_actual[3]++;
        // printf("min\n\n");
        ClockControlAlarm(clock);
    }
}

void ClockTenMin(clock_t clock){
    if(clock->hora_actual[3] == 10){ // incrementa una decena
        clock->hora_actual[3] = 0;
        clock->hora_actual[2]++;
        // printf("decena de min\n\n");
    }
}

void ClockNewHour(clock_t clock){
    if(clock->hora_actual[2] == 6){
        clock->hora_actual[2] = 0;
        clock->hora_actual[3] = 0;
        clock->hora_actual[1]++;
        // printf("hora\n");
    }
}

void ClockTenHour(clock_t clock){
    if(clock->hora_actual[1] == 10){ // incrementa una decena
        clock->hora_actual[1] = 0;
        clock->hora_actual[0]++;
    }
}

void ClockNewDay(clock_t clock){
    if(clock->hora_actual[1] == 4){
        if(clock->hora_actual[0] == 2){
            clock->hora_actual[0] = 0;
            clock->hora_actual[1] = 0;
            // clock->dia++;
        }
    }
}

bool ClockSetUpAlarm(clock_t reloj, const  uint8_t * alarma, int size){
    memcpy(reloj->alarma->alarma_actual, alarma, size);
    reloj->alarma->valida = true;
    return reloj->alarma->valida;
}

bool ClockGetAlarm(clock_t reloj, uint8_t * hora, int size){
    memcpy(hora, reloj->alarma->alarma_actual, size);
    return reloj->alarma->valida;
}

void ClockControlAlarm(clock_t clock){
    if(clock->alarma->activada == true){    // si esta habilitada la alarma
        if(memcmp(clock->hora_actual, clock->alarma->alarma_actual, sizeof(clock->hora_actual)) == 0){
            clock->alarma->activar_alarma_f (clock);
        }
    }
}