#include "/var/lib/gems/3.0.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"
#include "src/reloj.h"
void test_Start_Up(void){

    static const uint8_t ESPERADO[] = {0,0,0,0,0,0};

    uint8_t hora[6] = {0xFF};



    clock_t reloj;

    reloj = ClockCreate(5);



    do {if (!(ClockGetTime(reloj,hora,6))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(19)));}} while(0);

    UnityAssertEqualIntArray(( const void*)((ESPERADO)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(20), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}



void test_ajustar_hora(void){

    static const uint8_t ESPERADO[] = {1,2,3,4,0,0};

    uint8_t hora[6];



    clock_t reloj = ClockCreate(5);

    ClockSetTime(reloj, ESPERADO, 4);



    do {if ((ClockSetTime(reloj, ESPERADO, 4))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(30)));}} while(0);

    do {if ((ClockGetTime(reloj,hora,6))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(31)));}} while(0);

    UnityAssertEqualIntArray(( const void*)((ESPERADO)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(32), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}
