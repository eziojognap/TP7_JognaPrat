// REFERENCIA PRUEBAS
// YA - Al inicializar el reloj está en 00:00 y con hora invalida.
// YA - Al ajustar la hora el reloj queda en hora y es válida.
// YA - Después de n ciclos de reloj la hora avanza un segundo, diez segundos, un minutos, diez minutos, una hora, diez horas y un día completo.
// YA - Fijar la hora de la alarma y consultarla.

// Fijar la alarma y avanzar el reloj para que suene.
// Fijar la alarma, deshabilitarla y avanzar el reloj para no suene.
// Hacer sonar la alarma y posponerla.
// Hacer sonar la alarma y cancelarla hasta el otro dia..

#include "reloj.h"
#include "unity.h"
#include "reloj.c"

#define TICKS_PER_SECOND 5

void SimulateTime(uint32_t seconds, clock_t reloj){
//    clock_t reloj;

    for(int second = 0; second < seconds; second++){
        for(int index= 0; index < TICKS_PER_SECOND; index++){
            ClockNewTick(reloj);
        }
    }
}

void test_Start_Up(void){
    static const uint8_t ESPERADO[] = {0,0,0,0,0,0}; // lo que espera recibir
    uint8_t hora[6] = {0xFF};
    
    clock_t reloj;
    reloj = ClockCreate(5); // Con 5 tics avanza un segundo

    TEST_ASSERT_FALSE(ClockGetTime(reloj,hora,6));
    TEST_ASSERT_EQUAL_UINT8_ARRAY(ESPERADO,hora,6);
}

void test_ajustar_hora(void){
    static const uint8_t ESPERADO[] = {1,2,3,4,0,0}; // lo que espera recibir
    uint8_t hora[6];
    
    clock_t reloj = ClockCreate(5);
    ClockSetTime(reloj, ESPERADO, 4);
    
    TEST_ASSERT_TRUE(ClockSetTime(reloj, ESPERADO, 4));
    TEST_ASSERT_TRUE(ClockGetTime(reloj,hora,6));
    TEST_ASSERT_EQUAL_UINT8_ARRAY(ESPERADO,hora,6);
}

void test_increment_one_sec(void) {
    static const uint8_t ESPERADO[] = {1,2,3,4,0,1}; // lo que espera recibir
    uint8_t hora[6] = {1,2,3,4,0,0}; // inicializa la hora en ese valor

    clock_t reloj = ClockCreate(5);
    ClockSetTime(reloj, hora, 6);

    SimulateTime(1, reloj); // simula un segundo
    ClockGetTime(reloj, hora, 6); // consulto la hora para ver si incremento en el reloj

    TEST_ASSERT_EQUAL_UINT8_ARRAY (ESPERADO, hora, 6);
}

void test_increment_ten_sec(void) {
    static const uint8_t ESPERADO[] = {1,2,3,4,1,0}; // lo que espera recibir
    uint8_t hora[6] = {1,2,3,4,0,0}; // inicializa la hora en ese valor

    clock_t reloj = ClockCreate(5);
    ClockSetTime(reloj, hora, 6);

    SimulateTime(10, reloj); // simula un segundo
    ClockGetTime(reloj, hora, 6); // consulto la hora para ver si incremento en el reloj

    TEST_ASSERT_EQUAL_UINT8_ARRAY (ESPERADO, hora, 6);
}

void test_increment_one_min(void) {
    static const uint8_t ESPERADO[] = {0,0,0,1,0,0}; // lo que espera recibir
    uint8_t hora[6] = {0,0,0,0,0,0}; // inicializa la hora en ese valor

    clock_t reloj = ClockCreate(5);
    ClockSetTime(reloj, hora, 6);

    SimulateTime(60, reloj); // simula 60 segundos
    ClockGetTime(reloj, hora, 6); // consulto la hora para ver si incremento en el reloj

    TEST_ASSERT_EQUAL_UINT8_ARRAY (ESPERADO, hora, 6);
    // printf("ulitima prueba");
}

void test_increment_ten_min(void) {
    static const uint8_t ESPERADO[] = {0,0,1,0,0,0}; // lo que espera recibir
    uint8_t hora[6] = {0,0,0,0,0,0}; // inicializa la hora en ese valor

    clock_t reloj = ClockCreate(5);
    ClockSetTime(reloj, hora, 6);

    SimulateTime(600, reloj); // simula 60 segundos
    ClockGetTime(reloj, hora, 6); // consulto la hora para ver si incremento en el reloj

    TEST_ASSERT_EQUAL_UINT8_ARRAY (ESPERADO, hora, 6);
    // printf("ulitima prueba");
}

void test_increment_one_hour(void) {
    static const uint8_t ESPERADO[] = {0,1,0,0,0,0}; // lo que espera recibir
    uint8_t hora[6] = {0,0,0,0,0,0}; // inicializa la hora en ese valor

    clock_t reloj = ClockCreate(5);
    ClockSetTime(reloj, hora, 6);

    SimulateTime(3600, reloj); // simula 60 segundos
    ClockGetTime(reloj, hora, 6); // consulto la hora para ver si incremento en el reloj

    TEST_ASSERT_EQUAL_UINT8_ARRAY (ESPERADO, hora, 6);
    // printf("ulitima prueba");
}

void test_increment_ten_hour(void) {
    static const uint8_t ESPERADO[] = {1,0,0,0,0,0}; // lo que espera recibir
    uint8_t hora[6] = {0,0,0,0,0,0}; // inicializa la hora en ese valor

    clock_t reloj = ClockCreate(5);
    ClockSetTime(reloj, hora, 6);

    SimulateTime(36000, reloj); // simula 60 segundos
    ClockGetTime(reloj, hora, 6); // consulto la hora para ver si incremento en el reloj

    TEST_ASSERT_EQUAL_UINT8_ARRAY (ESPERADO, hora, 6);
 }

void test_increment_one_day(void) {
    static const uint8_t ESPERADO[] = {0,0,0,0,0,0}; // lo que espera recibir
    uint8_t hora[6] = {0,0,0,0,0,0}; // inicializa la hora en ese valor

    clock_t reloj = ClockCreate(5);
    ClockSetTime(reloj, hora, 6);

    SimulateTime(86400, reloj); // simula un dia
    ClockGetTime(reloj, hora, 6); // consulto la hora para ver si incremento en el reloj

    TEST_ASSERT_EQUAL_UINT8_ARRAY (ESPERADO, hora, 6);
}

void test_ajustar_alarma(void){
    static const uint8_t ESPERADO[] = {1,2,3,4,0,0}; // lo que espera recibir
    
    uint8_t alarma[6];
    
    clock_t reloj = ClockCreate(5);
    ClockSetTime(reloj, ESPERADO, 4);
    
    TEST_ASSERT_TRUE(ClockSetUpAlarm(reloj, ESPERADO, 4));
    TEST_ASSERT_TRUE(ClockGetAlarm(reloj,alarma,6));
    
    TEST_ASSERT_EQUAL_UINT8_ARRAY(ESPERADO,alarma,6);
}

// Fijar la alarma y avanzar el reloj para que la funcion de control cambie de estado
void test_control_alarma(void){
    static const uint8_t ESPERADO[] = {1,2,3,4,0,0}; // lo que espera recibir
    static const uint8_t A_ESPERADA[] = {1,2,3,5,0,0}; // lo que espera recibir
    
    uint8_t alarma[6];
    uint8_t hora[6];
    
    clock_t reloj = ClockCreate(5);
    ClockSetTime(reloj, ESPERADO, 4);
    
    ClockSetUpAlarm(reloj, A_ESPERADA, 4);
    ClockGetAlarm(reloj,alarma,6);
    
    SimulateTime(60, reloj); // simula un min
    ClockGetTime(reloj, hora, 6); // consulto la hora para ver si incremento en el reloj
    
    TEST_ASSERT_EQUAL_UINT8_ARRAY(A_ESPERADA,alarma,6);

    TEST_ASSERT_TRUE(ClockControlAlarm(reloj));

}

void test_alarma_on(void){
    static const uint8_t ESPERADO[] = {1,2,3,4,0,0}; // lo que espera recibir
    static const uint8_t A_ESPERADA[] = {1,2,3,5,0,0}; // lo que espera recibir
    
    uint8_t alarma[6];
    uint8_t hora[6];
    
    clock_t reloj = ClockCreate(5);
    ClockSetTime(reloj, ESPERADO, 4);
    
    ClockSetUpAlarm(reloj, A_ESPERADA, 4);
    ClockGetAlarm(reloj,alarma,6);
    
    SimulateTime(60, reloj); // simula un min
    ClockGetTime(reloj, hora, 6); // consulto la hora para ver si incremento en el reloj
    
    reloj->alarma->activada = ClockControlAlarm(reloj);

    TEST_ASSERT_TRUE(reloj->alarma->activada);
}

void test_alarma_off(void){
    static const uint8_t ESPERADO[] = {1,2,3,4,0,0}; // lo que espera recibir
    static const uint8_t A_ESPERADA[] = {1,2,3,5,0,0}; // lo que espera recibir
    
    uint8_t alarma[6];
    uint8_t hora[6];
    
    clock_t reloj = ClockCreate(5);
    ClockSetTime(reloj, ESPERADO, 4);
    
    ClockSetUpAlarm(reloj, A_ESPERADA, 4);
    ClockGetAlarm(reloj,alarma,6);
    
    SimulateTime(60, reloj); // simula un min
    ClockGetTime(reloj, hora, 6); // consulto la hora para ver si incremento en el reloj
    
    TEST_ASSERT_TRUE(ClockControlAlarm(reloj));

    SimulateTime(60, reloj); // simula un min
    ClockGetTime(reloj, hora, 6); // consulto la hora para ver si incremento en el reloj

    TEST_ASSERT_TRUE(ClockControlAlarm(reloj));
}

