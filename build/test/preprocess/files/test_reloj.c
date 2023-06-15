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



    static 

          _Bool 

               luz;



void SimulateAlarmActivated(clock_t reloj){

    luz = 

         1

             ;

}



void test_Start_Up(void){

    static const uint8_t ESPERADO[] = {0,0,0,0,0,0};

    uint8_t hora[6] = {0xFF};



    clock_t reloj;

    reloj = ClockCreate(5,SimulateAlarmActivated);



    do {if (!(ClockGetTime(reloj,hora,6))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(40)));}} while(0);

    UnityAssertEqualIntArray(( const void*)((ESPERADO)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(41), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}



void test_ajustar_hora(void){

    static const uint8_t ESPERADO[] = {1,2,3,4,0,0};

    uint8_t hora[6];



    clock_t reloj = ClockCreate(5,SimulateAlarmActivated);

    ClockSetTime(reloj, ESPERADO, 4);



    do {if ((ClockSetTime(reloj, ESPERADO, 4))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(51)));}} while(0);

    do {if ((ClockGetTime(reloj,hora,6))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(52)));}} while(0);

    UnityAssertEqualIntArray(( const void*)((ESPERADO)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(53), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}



void test_increment_one_sec(void) {

    static const uint8_t ESPERADO[] = {1,2,3,4,0,1};

    uint8_t hora[6] = {1,2,3,4,0,0};



    clock_t reloj = ClockCreate(5,SimulateAlarmActivated);

    ClockSetTime(reloj, hora, 6);



    SimulateTime(1, reloj);

    ClockGetTime(reloj, hora, 6);



    UnityAssertEqualIntArray(( const void*)((ESPERADO)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(66), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}



void test_increment_ten_sec(void) {

    static const uint8_t ESPERADO[] = {1,2,3,4,1,0};

    uint8_t hora[6] = {1,2,3,4,0,0};



    clock_t reloj = ClockCreate(5,SimulateAlarmActivated);

    ClockSetTime(reloj, hora, 6);



    SimulateTime(10, reloj);

    ClockGetTime(reloj, hora, 6);



    UnityAssertEqualIntArray(( const void*)((ESPERADO)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(79), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}



void test_increment_one_min(void) {

    static const uint8_t ESPERADO[] = {0,0,0,1,0,0};

    uint8_t hora[6] = {0,0,0,0,0,0};



    clock_t reloj = ClockCreate(5,SimulateAlarmActivated);

    ClockSetTime(reloj, hora, 6);



    SimulateTime(60, reloj);

    ClockGetTime(reloj, hora, 6);



    UnityAssertEqualIntArray(( const void*)((ESPERADO)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(92), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);



}



void test_increment_ten_min(void) {

    static const uint8_t ESPERADO[] = {0,0,1,0,0,0};

    uint8_t hora[6] = {0,0,0,0,0,0};



    clock_t reloj = ClockCreate(5,SimulateAlarmActivated);

    ClockSetTime(reloj, hora, 6);



    SimulateTime(600, reloj);

    ClockGetTime(reloj, hora, 6);



    UnityAssertEqualIntArray(( const void*)((ESPERADO)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(106), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);



}



void test_increment_one_hour(void) {

    static const uint8_t ESPERADO[] = {0,1,0,0,0,0};

    uint8_t hora[6] = {0,0,0,0,0,0};



    clock_t reloj = ClockCreate(5,SimulateAlarmActivated);

    ClockSetTime(reloj, hora, 6);



    SimulateTime(3600, reloj);

    ClockGetTime(reloj, hora, 6);



    UnityAssertEqualIntArray(( const void*)((ESPERADO)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(120), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);



}



void test_increment_ten_hour(void) {

    static const uint8_t ESPERADO[] = {1,0,0,0,0,0};

    uint8_t hora[6] = {0,0,0,0,0,0};



    clock_t reloj = ClockCreate(5,SimulateAlarmActivated);

    ClockSetTime(reloj, hora, 6);



    SimulateTime(36000, reloj);

    ClockGetTime(reloj, hora, 6);



    UnityAssertEqualIntArray(( const void*)((ESPERADO)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(134), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

 }



void test_increment_one_day(void) {

    static const uint8_t ESPERADO[] = {0,0,0,0,0,0};

    uint8_t hora[6] = {0,0,0,0,0,0};



    clock_t reloj = ClockCreate(5,SimulateAlarmActivated);

    ClockSetTime(reloj, hora, 6);



    SimulateTime(86400, reloj);

    ClockGetTime(reloj, hora, 6);



    UnityAssertEqualIntArray(( const void*)((ESPERADO)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(147), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}



void test_ajustar_alarma(void){

    static const uint8_t ESPERADO[] = {1,2,3,4,0,0};



    uint8_t alarma[6];



    clock_t reloj = ClockCreate(5,SimulateAlarmActivated);

    ClockSetTime(reloj, ESPERADO, 4);



    do {if ((ClockSetUpAlarm(reloj, ESPERADO, 4))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(158)));}} while(0);

    do {if ((ClockGetAlarm(reloj,alarma,6))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(159)));}} while(0);



    UnityAssertEqualIntArray(( const void*)((ESPERADO)), ( const void*)((alarma)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(161), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}





void test_control_alarma(void){

    static const uint8_t ESPERADO[] = {1,2,3,4,0,0};

    static const uint8_t A_ESPERADA[] = {1,2,3,5,0,0};



    uint8_t alarma[6];

    uint8_t hora[6];



    clock_t reloj = ClockCreate(5,SimulateAlarmActivated);

    ClockSetTime(reloj, ESPERADO, 4);



    ClockSetUpAlarm(reloj, A_ESPERADA, 4);

    ClockGetAlarm(reloj,alarma,6);



    reloj->alarma->activada = 

                             1

                                 ;



    SimulateTime(60, reloj);

    ClockGetTime(reloj, hora, 6);



    UnityAssertEqualIntArray(( const void*)((A_ESPERADA)), ( const void*)((alarma)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(183), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);



    do {if ((luz)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(185)));}} while(0);

}



void test_alarma_off(void){

    static const uint8_t ESPERADO[] = {1,2,3,4,0,0};

    static const uint8_t A_ESPERADA[] = {1,2,3,5,0,0};



    uint8_t alarma[6];

    uint8_t hora[6];



    clock_t reloj = ClockCreate(5,SimulateAlarmActivated);

    ClockSetTime(reloj, ESPERADO, 4);



    ClockSetUpAlarm(reloj, A_ESPERADA, 4);

    ClockGetAlarm(reloj,alarma,6);



    reloj->alarma->activada = 

                             1

                                 ;



    SimulateTime(60, reloj);

    ClockGetTime(reloj, hora, 6);



    do {if ((luz)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(206)));}} while(0);



    SimulateTime(60, reloj);

    ClockGetTime(reloj, hora, 6);



    luz = 

         0

              ;



    do {if (!(luz)) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(213)));}} while(0);

}



void test_alarma_desactivada(void){

    static const uint8_t ESPERADO[] = {1,2,3,4,0,0};

    static const uint8_t A_ESPERADA[] = {1,2,3,5,0,0};



    uint8_t alarma[6];

    uint8_t hora[6];



    clock_t reloj = ClockCreate(5,SimulateAlarmActivated);

    ClockSetTime(reloj, ESPERADO, 4);



    ClockSetUpAlarm(reloj, A_ESPERADA, 4);

    ClockGetAlarm(reloj,alarma,6);



    reloj->alarma->activada = 

                             0

                                  ;



    SimulateTime(60, reloj);

    ClockGetTime(reloj, hora, 6);



    UnityAssertEqualIntArray(( const void*)((A_ESPERADA)), ( const void*)((alarma)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(234), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);



    do {if (!(luz)) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(236)));}} while(0);

}



void test_snooze_alarm(void){

    static const uint8_t ESPERADO[] = {1,2,3,4,0,0};

    static const uint8_t A_ESPERADA[] = {1,2,3,5,0,0};



    uint8_t alarma[6];

    uint8_t hora[6];



    clock_t reloj = ClockCreate(5,SimulateAlarmActivated);

    ClockSetTime(reloj, ESPERADO, 4);



    ClockSetUpAlarm(reloj, A_ESPERADA, 4);

    ClockGetAlarm(reloj,alarma,6);



    reloj->alarma->activada = 

                             1

                                 ;



    SimulateTime(60, reloj);

    ClockGetTime(reloj, hora, 6);



    do {if ((luz)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(257)));}} while(0);



    ClockActivateSnoozeAlarm(reloj);

    luz = 

         0

              ;

    do {if (!(luz)) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(261)));}} while(0);



    SimulateTime(60*5 , reloj);



    do {if ((luz)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(265)));}} while(0);

}
