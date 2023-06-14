#include <stdint.h>
#include <stdbool.h>

typedef struct clock_s * clock_t;
typedef struct alarm_s * alarm_t;

typedef void (*Alarm_activate)(clock_t clock);

clock_t ClockCreate(int tics_por_segundo, Alarm_activate alarma);

bool ClockGetTime(clock_t reloj, uint8_t hora[], int size);
bool ClockSetTime(clock_t reloj, const uint8_t hora[], int size);

void ClockNewTick(clock_t clock);
void ClockNewSec(clock_t clock);
void ClockTenSec(clock_t clock);
void ClockNewMin(clock_t clock);
void ClockTenMin(clock_t clock);
void ClockNewHour(clock_t clock);
void ClockTenHour(clock_t clock);
void ClockNewDay(clock_t clock);

bool ClockGetAlarm(clock_t reloj, uint8_t alarma[], int size);
bool ClockSetUpAlarm(clock_t reloj, const uint8_t alarma[], int size);
