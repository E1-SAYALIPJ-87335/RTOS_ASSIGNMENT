/*
	1. Create four task functions vLedTask1(), vLedTask2(), vLedTask3() and vLedTask4(), which will toggle
	four different LEDs with different rate.
	Create four real-time tasks to execute these functions.
*/

#include <stdint.h>
#include <stdio.h>
#include"FreeRTOSConfig.h"
#include"FreeRTOS.h"
#include"task.h"
#include"led.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

void vLedTask1(void *pvParam)
 {
 	portTickType xLastWakeuptime;
 	while(1)
 	{
 		xLastWakeuptime = xTaskGetTickCount();
 		// work
 		led_toggle(LED_GREEN);
 		vTaskDelayUntil(&xLastWakeuptime, 1000 / portTICK_RATE_MS);
 	}
 	vTaskDelete(NULL);
 }

void vLedTask2(void *pvParam)
 {
 	portTickType xLastWakeuptime;
 	while(1)
 	{
 		xLastWakeuptime = xTaskGetTickCount();
 		// work
 		led_toggle(LED_BLUE);
 		vTaskDelayUntil(&xLastWakeuptime, 2000 / portTICK_RATE_MS);
 	}
 	vTaskDelete(NULL);
 }

void vLedTask3(void *pvParam)
 {
 	portTickType xLastWakeuptime;
 	while(1)
 	{
 		xLastWakeuptime = xTaskGetTickCount();
 		// work
 		led_toggle(LED_RED);
 		vTaskDelayUntil(&xLastWakeuptime, 3000 / portTICK_RATE_MS);
 	}
 	vTaskDelete(NULL);
 }

void vLedTask4(void *pvParam)
 {
 	portTickType xLastWakeuptime;
 	while(1)
 	{
 		xLastWakeuptime = xTaskGetTickCount();
 		// work
 		led_toggle(LED_ORANGE);
 		vTaskDelayUntil(&xLastWakeuptime, 4000 / portTICK_RATE_MS);
 	}
 	vTaskDelete(NULL);
 }


int main(void)
{
	led_init(LED_GREEN);
	led_init(LED_BLUE);
	led_init(LED_RED);
	led_init(LED_ORANGE);

	xTaskCreate(vLedTask1, "Periodic", configMINIMAL_STACK_SIZE, NULL, 4, NULL);
	xTaskCreate(vLedTask2, "Periodic", configMINIMAL_STACK_SIZE, NULL, 4, NULL);
	xTaskCreate(vLedTask3, "Periodic", configMINIMAL_STACK_SIZE, NULL, 4, NULL);
	xTaskCreate(vLedTask4, "Periodic", configMINIMAL_STACK_SIZE, NULL, 4, NULL);

	vTaskStartScheduler();
	while(1);
}








