#include "reloj.h"
#include "unity.h"

// void SimulateTime(uint32_t secods){
//     for(int second = 0; index < seconds; seconds++){
//         for(int index= 0;index < TICKS_PER_SECOND; index++){
//             ClockTick(reloj);
//         }
//     }
// }

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

// void test_increment_