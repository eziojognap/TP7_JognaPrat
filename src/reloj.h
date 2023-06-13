#include <stdint.h>
#include <stdbool.h>

typedef struct clock_s * clock_t;
clock_t ClockCreate(int tics_por_segundo);
bool ClockGetTime(clock_t reloj, uint8_t hora[], int size);
bool ClockSetTime(clock_t reloj, const uint8_t hora[], int size);
