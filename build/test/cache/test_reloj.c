#include "src/reloj.c"
#include "/var/lib/gems/3.0.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"
#include "src/reloj.h"






void SimulateTime(uint32_t seconds, clock_t reloj){





    for(int second = 0; second < seconds; second++){

        for(int index= 0; index < 5; index++){

            ClockNewTick(reloj);

        }

    }

}



void test_Start_Up(void){

    static const uint8_t ESPERADO[] = {0,0,0,0,0,0};

    uint8_t hora[6] = {0xFF};



    clock_t reloj;

    reloj = ClockCreate(5);



    do {if (!(ClockGetTime(reloj,hora,6))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(35)));}} while(0);

    UnityAssertEqualIntArray(( const void*)((ESPERADO)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(36), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}



void test_ajustar_hora(void){

    static const uint8_t ESPERADO[] = {1,2,3,4,0,0};

    uint8_t hora[6];



    clock_t reloj = ClockCreate(5);

    ClockSetTime(reloj, ESPERADO, 4);



    do {if ((ClockSetTime(reloj, ESPERADO, 4))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(46)));}} while(0);

    do {if ((ClockGetTime(reloj,hora,6))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(47)));}} while(0);

    UnityAssertEqualIntArray(( const void*)((ESPERADO)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(48), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}



void test_increment_one_sec(void) {

    static const uint8_t ESPERADO[] = {1,2,3,4,0,1};

    uint8_t hora[6] = {1,2,3,4,0,0};



    clock_t reloj = ClockCreate(5);

    ClockSetTime(reloj, hora, 6);



    SimulateTime(1, reloj);

    ClockGetTime(reloj, hora, 6);



    UnityAssertEqualIntArray(( const void*)((ESPERADO)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(61), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}



void test_increment_ten_sec(void) {

    static const uint8_t ESPERADO[] = {1,2,3,4,1,0};

    uint8_t hora[6] = {1,2,3,4,0,0};



    clock_t reloj = ClockCreate(5);

    ClockSetTime(reloj, hora, 6);



    SimulateTime(10, reloj);

    ClockGetTime(reloj, hora, 6);



    UnityAssertEqualIntArray(( const void*)((ESPERADO)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(74), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}



void test_increment_one_min(void) {

    static const uint8_t ESPERADO[] = {0,0,0,1,0,0};

    uint8_t hora[6] = {0,0,0,0,0,0};



    clock_t reloj = ClockCreate(5);

    ClockSetTime(reloj, hora, 6);



    SimulateTime(60, reloj);

    ClockGetTime(reloj, hora, 6);



    UnityAssertEqualIntArray(( const void*)((ESPERADO)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(87), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);



}
