/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
//#include "cmsis_os.h"
#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"
#include "queue.h"
#include "semphr.h"
#include "event_groups.h"
#include "string.h"
#include "stdlib.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
UART_HandleTypeDef huart2;


/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);


// create task defines
TaskHandle_t HPThandler;
void HPT_TASK (void *pvParameters);

TaskHandle_t MPThandler;
void MPT_TASK (void *pvParameters);

TaskHandle_t LPThandler;
void LPT_TASK (void *pvParameters);

TaskHandle_t VLPThandler;
void VLPT_TASK (void *pvParameters);

// semaphore related
SemaphoreHandle_t CountingSem;

// resource related
int resource[3] = {111,222,333};
int indx = 0;

// uart related
uint8_t rx_data = 0;
/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void print(char *msg)
{
	HAL_UART_Transmit(&huart2, (uint8_t *)msg, strlen(msg), 100);
}
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART2_UART_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */
  CountingSem = xSemaphoreCreateCounting(3,0);
  if (CountingSem == NULL) HAL_UART_Transmit(&huart2, (uint8_t *) "Unable to Create Semaphore\n\n", 28, 100);
  else HAL_UART_Transmit(&huart2, (uint8_t *) "Counting Semaphore created successfully\n\n", 41, 1000);
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */
  // create TASKS

  xTaskCreate(HPT_TASK, "HPT", 128, NULL, 3, &HPThandler);
  xTaskCreate(MPT_TASK, "MPT", 128, NULL, 2, &MPThandler);
  xTaskCreate(LPT_TASK, "LPT", 128, NULL, 1, &LPThandler);
  xTaskCreate(VLPT_TASK, "VLPT", 128, NULL, 0, &VLPThandler);

  vTaskStartScheduler();
  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* definition and creation of defaultTask */


  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* Start scheduler */


  /* We should never get here as control is now taken by the scheduler */
  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL12;
  RCC_OscInitStruct.PLL.PREDIV = RCC_PREDIV_DIV1;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 38400;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  huart2.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart2.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, LD4_Pin|LD3_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : LD4_Pin LD3_Pin */
  GPIO_InitStruct.Pin = LD4_Pin|LD3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

}

void HPT_TASK (void *pvParameters)
{
	char sresource[3];
	int semcount = 0;
	char ssemcount[2];

	// Give 3 semaphores at the beginning..
	xSemaphoreGive(CountingSem);
	xSemaphoreGive(CountingSem);
	xSemaphoreGive(CountingSem);

	while (1)
	{
		char str[150];
		strcpy(str, "Entered HPT Task\n About to ACQUIRE the Semaphore\n ");
		semcount = uxSemaphoreGetCount(CountingSem);
		itoa (semcount, ssemcount, 10);
		strcat (str, "Tokens available are: ");
		strcat (str, ssemcount);
		strcat (str, "\n\n");
		HAL_UART_Transmit(&huart2, (uint8_t *)str, strlen (str), HAL_MAX_DELAY);

		xSemaphoreTake(CountingSem, portMAX_DELAY);

		itoa (resource[indx], sresource, 10);
		strcpy (str, "Leaving HPT Task\n Data ACCESSED is:: ");
		strcat (str, sresource);
		strcat (str, "\n Not releasing the Semaphore\n\n\n");
		HAL_UART_Transmit(&huart2, (uint8_t *)str, strlen (str), HAL_MAX_DELAY);

		indx++;
		if (indx>2) indx=0;

		vTaskDelay(3000);
//		vTaskDelete(NULL);
	}
}


void MPT_TASK (void *pvParameters)
{
	char sresource[3];
	int semcount = 0;
	char ssemcount[2];

	// Give 3 semaphores at the beginning..
	//xSemaphoreGive(CountingSem);
	//xSemaphoreGive(CountingSem);
	//xSemaphoreGive(CountingSem);

	while (1)
	{
		char str[150];
		strcpy(str, "Entered MPT Task\n About to ACQUIRE the Semaphore\n ");
		semcount = uxSemaphoreGetCount(CountingSem);
		itoa (semcount, ssemcount, 10);
		strcat (str, "Tokens available are: ");
		strcat (str, ssemcount);
		strcat (str, "\n\n");
		HAL_UART_Transmit(&huart2, (uint8_t *)str, strlen (str), HAL_MAX_DELAY);

		xSemaphoreTake(CountingSem, portMAX_DELAY);

		itoa (resource[indx], sresource, 10);
		strcpy (str, "Leaving MPT Task\n Data ACCESSED is:: ");
		strcat (str, sresource);
		strcat (str, "\n Not releasing the Semaphore\n\n\n");
		HAL_UART_Transmit(&huart2, (uint8_t *)str, strlen (str), HAL_MAX_DELAY);

		indx++;
		if (indx>2) indx=0;

		vTaskDelay(3000);
//		vTaskDelete(NULL);
	}
}



void LPT_TASK (void *pvParameters)
{
	char sresource[3];
	int semcount = 0;
	char ssemcount[2];

	// Give 3 semaphores at the beginning..
	//xSemaphoreGive(CountingSem);
	//xSemaphoreGive(CountingSem);
	//xSemaphoreGive(CountingSem);

	while (1)
	{
		char str[150];
		strcpy(str, "Entered LPT Task\n About to ACQUIRE the Semaphore\n ");
		semcount = uxSemaphoreGetCount(CountingSem);
		itoa (semcount, ssemcount, 10);
		strcat (str, "Tokens available are: ");
		strcat (str, ssemcount);
		strcat (str, "\n\n");
		HAL_UART_Transmit(&huart2, (uint8_t *)str, strlen (str), HAL_MAX_DELAY);

		xSemaphoreTake(CountingSem, portMAX_DELAY);

		itoa (resource[indx], sresource, 10);
		strcpy (str, "Leaving LPT Task\n Data ACCESSED is:: ");
		strcat (str, sresource);
		strcat (str, "\n Not releasing the Semaphore\n\n\n");
		HAL_UART_Transmit(&huart2, (uint8_t *)str, strlen (str), HAL_MAX_DELAY);

		indx++;
		if (indx>2) indx=0;

		vTaskDelay(3000);
//		vTaskDelete(NULL);
	}
}



void VLPT_TASK (void *pvParameters)
{
	char sresource[3];
	int semcount = 0;
	char ssemcount[2];

	// Give 3 semaphores at the beginning..
	//xSemaphoreGive(CountingSem);
	//xSemaphoreGive(CountingSem);
	//xSemaphoreGive(CountingSem);

	while (1)
	{
		char str[150];
		strcpy(str, "Entered VLHPT Task\n About to ACQUIRE the Semaphore\n ");
		semcount = uxSemaphoreGetCount(CountingSem);
		itoa (semcount, ssemcount, 10);
		strcat (str, "Tokens available are: ");
		strcat (str, ssemcount);
		strcat (str, "\n\n");
		HAL_UART_Transmit(&huart2, (uint8_t *)str, strlen (str), HAL_MAX_DELAY);

		xSemaphoreTake(CountingSem, portMAX_DELAY);

		itoa (resource[indx], sresource, 10);
		strcpy (str, "Leaving VLPT Task\n Data ACCESSED is:: ");
		strcat (str, sresource);
		strcat (str, "\n Not releasing the Semaphore\n\n\n");
		HAL_UART_Transmit(&huart2, (uint8_t *)str, strlen (str), HAL_MAX_DELAY);

		indx++;
		if (indx>2) indx=0;

		vTaskDelay(3000);
//		vTaskDelete(NULL);
	}
}


void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	HAL_UART_Receive_IT(huart, &rx_data, 1);
	if (rx_data == 'r')
	{
		// release the semaphore here
		 /* The xHigherPriorityTaskWoken parameter must be initialized to pdFALSE as
		 it will get set to pdTRUE inside the interrupt safe API function if a
		 context switch is required. */
		BaseType_t xHigherPriorityTaskWoken = pdFALSE;

		xSemaphoreGiveFromISR(CountingSem, &xHigherPriorityTaskWoken);  // ISR SAFE VERSION
		xSemaphoreGiveFromISR(CountingSem, &xHigherPriorityTaskWoken);  // ISR SAFE VERSION
		xSemaphoreGiveFromISR(CountingSem, &xHigherPriorityTaskWoken);  // ISR SAFE VERSION

		/* Pass the xHigherPriorityTaskWoken value into portEND_SWITCHING_ISR(). If
		 xHigherPriorityTaskWoken was set to pdTRUE inside xSemaphoreGiveFromISR()
		 then calling portEND_SWITCHING_ISR() will request a context switch. If
		 xHigherPriorityTaskWoken is still pdFALSE then calling
		 portEND_SWITCHING_ISR() will have no effect */

		portEND_SWITCHING_ISR( xHigherPriorityTaskWoken );
	}
}
/* USER CODE END 4 */

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */

 /**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM1 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM1) {
    HAL_IncTick();
  }
  /* USER CODE BEGIN Callback 1 */

  /* USER CODE END Callback 1 */
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
