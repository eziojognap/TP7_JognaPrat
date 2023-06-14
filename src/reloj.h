#include <stdint.h>
#include <stdbool.h>

typedef struct clock_s * clock_t;
clock_t ClockCreate(int tics_por_segundo);
bool ClockGetTime(clock_t reloj, uint8_t hora[], int size);
bool ClockSetTime(clock_t reloj, const uint8_t hora[], int size);

void ClockNewTick(clock_t clock);
void ClockNewSec(clock_t clock);
void ClockTenSec(clock_t clock);
void ClockNewMin(clock_t clock);


// void ClockSetUpAlarm(clock_t clock, uint8_t const * const time, uitn_t size);
// bool ClockGetAlarm(clock_t clock, uint8_t * time, uint8_t size);
// bool ClockToggleAlarm(clock_t clock);
