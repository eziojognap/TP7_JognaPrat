/* AUTOGENERATED FILE. DO NOT EDIT. */

/*=======Automagically Detected Files To Include=====*/
#include "unity.h"

int GlobalExpectCount;
int GlobalVerifyOrder;
char* GlobalOrderError;

/*=======External Functions This Runner Calls=====*/
extern void setUp(void);
extern void tearDown(void);
extern void test_Start_Up(void);
extern void test_ajustar_hora(void);
extern void test_increment_one_sec(void);
extern void test_increment_ten_sec(void);
extern void test_increment_one_min(void);
extern void test_increment_ten_min(void);
extern void test_increment_one_hour(void);
extern void test_increment_ten_hour(void);
extern void test_increment_one_day(void);
extern void test_ajustar_alarma(void);
extern void test_control_alarma(void);
extern void test_alarma_off(void);
extern void test_alarma_desactivada(void);
extern void test_snooze_alarm(void);


/*=======Mock Management=====*/
static void CMock_Init(void)
{
  GlobalExpectCount = 0;
  GlobalVerifyOrder = 0;
  GlobalOrderError = NULL;
}
static void CMock_Verify(void)
{
}
static void CMock_Destroy(void)
{
}

/*=======Setup (stub)=====*/
void setUp(void) {}

/*=======Teardown (stub)=====*/
void tearDown(void) {}

/*=======Test Reset Options=====*/
void resetTest(void);
void resetTest(void)
{
  tearDown();
  CMock_Verify();
  CMock_Destroy();
  CMock_Init();
  setUp();
}
void verifyTest(void);
void verifyTest(void)
{
  CMock_Verify();
}

/*=======Test Runner Used To Run Each Test=====*/
static void run_test(UnityTestFunction func, const char* name, UNITY_LINE_TYPE line_num)
{
    Unity.CurrentTestName = name;
    Unity.CurrentTestLineNumber = line_num;
#ifdef UNITY_USE_COMMAND_LINE_ARGS
    if (!UnityTestMatches())
        return;
#endif
    Unity.NumberOfTests++;
    UNITY_CLR_DETAILS();
    UNITY_EXEC_TIME_START();
    CMock_Init();
    if (TEST_PROTECT())
    {
        setUp();
        func();
    }
    if (TEST_PROTECT())
    {
        tearDown();
        CMock_Verify();
    }
    CMock_Destroy();
    UNITY_EXEC_TIME_STOP();
    UnityConcludeTest();
}

/*=======MAIN=====*/
int main(void)
{
  UnityBegin("test_reloj.c");
  run_test(test_Start_Up, "test_Start_Up", 33);
  run_test(test_ajustar_hora, "test_ajustar_hora", 44);
  run_test(test_increment_one_sec, "test_increment_one_sec", 56);
  run_test(test_increment_ten_sec, "test_increment_ten_sec", 69);
  run_test(test_increment_one_min, "test_increment_one_min", 82);
  run_test(test_increment_ten_min, "test_increment_ten_min", 96);
  run_test(test_increment_one_hour, "test_increment_one_hour", 110);
  run_test(test_increment_ten_hour, "test_increment_ten_hour", 124);
  run_test(test_increment_one_day, "test_increment_one_day", 137);
  run_test(test_ajustar_alarma, "test_ajustar_alarma", 150);
  run_test(test_control_alarma, "test_control_alarma", 165);
  run_test(test_alarma_off, "test_alarma_off", 188);
  run_test(test_alarma_desactivada, "test_alarma_desactivada", 216);
  run_test(test_snooze_alarm, "test_snooze_alarm", 239);

  return UnityEnd();
}
