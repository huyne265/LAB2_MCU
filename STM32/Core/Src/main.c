/* USER CODE BEGIN Header */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include<sorfware_timer.h>
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
TIM_HandleTypeDef htim2;

/* USER CODE BEGIN PV */
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM2_Init(void);
/* USER CODE BEGIN PFP */
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */


void clear7SEG(){
	  HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, GPIO_PIN_SET);
}
void display7SEG(int num){
    	  switch(num){
    	  	  case 0:
    	  		  HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, GPIO_PIN_RESET);
    	  		  HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, GPIO_PIN_RESET);
    	  		  HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, GPIO_PIN_RESET);
    	  		  HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, GPIO_PIN_RESET);
    	  		  HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, GPIO_PIN_RESET);
    	  		  HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, GPIO_PIN_RESET);
    	  		  HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, GPIO_PIN_SET);
    	  		  break;
    	  	  case 1:
    	  		  HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, GPIO_PIN_SET);
    	  		  HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, GPIO_PIN_RESET);
    	  		  HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, GPIO_PIN_RESET);
    	  		  HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, GPIO_PIN_SET);
    	  		  HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, GPIO_PIN_SET);
    	  		  HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, GPIO_PIN_SET);
    	  		  HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, GPIO_PIN_SET);
    	  		  break;
    	  	  case 2:
    	  		  HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, GPIO_PIN_RESET);
    	  		  HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, GPIO_PIN_RESET);
    	  		  HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, GPIO_PIN_SET);
    	  		  HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, GPIO_PIN_RESET);
    	  		  HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, GPIO_PIN_RESET);
    	  		  HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, GPIO_PIN_SET);
    	  		  HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, GPIO_PIN_RESET);
    	  		  break;
    	  	  case 3:
    	  		  HAL_GPIO_WritePin(a_GPIO_Port, GPIO_PIN_0, GPIO_PIN_RESET);
    	  		  HAL_GPIO_WritePin(b_GPIO_Port, GPIO_PIN_1, GPIO_PIN_RESET);
    	  		  HAL_GPIO_WritePin(c_GPIO_Port, GPIO_PIN_2, GPIO_PIN_RESET);
    	  		  HAL_GPIO_WritePin(d_GPIO_Port, GPIO_PIN_3, GPIO_PIN_RESET);
    	  		  HAL_GPIO_WritePin(e_GPIO_Port, GPIO_PIN_4, GPIO_PIN_SET);
    	  		  HAL_GPIO_WritePin(f_GPIO_Port, GPIO_PIN_5, GPIO_PIN_SET);
    	  		  HAL_GPIO_WritePin(g_GPIO_Port, GPIO_PIN_6, GPIO_PIN_RESET);
    	  		  break;
    	  	  case 4:
    	  		  HAL_GPIO_WritePin(a_GPIO_Port, GPIO_PIN_0, GPIO_PIN_SET);
    	  		  HAL_GPIO_WritePin(b_GPIO_Port, GPIO_PIN_1, GPIO_PIN_RESET);
    	  		  HAL_GPIO_WritePin(c_GPIO_Port, GPIO_PIN_2, GPIO_PIN_RESET);
    	  		  HAL_GPIO_WritePin(d_GPIO_Port, GPIO_PIN_3, GPIO_PIN_SET);
    	  		  HAL_GPIO_WritePin(e_GPIO_Port, GPIO_PIN_4, GPIO_PIN_SET);
    	  		  HAL_GPIO_WritePin(f_GPIO_Port, GPIO_PIN_5, GPIO_PIN_RESET);
    	  		  HAL_GPIO_WritePin(g_GPIO_Port, GPIO_PIN_6, GPIO_PIN_RESET);
    	  		  break;
    	  	  case 5:
    	  		  HAL_GPIO_WritePin(a_GPIO_Port, GPIO_PIN_0, GPIO_PIN_RESET);
    	  		  HAL_GPIO_WritePin(b_GPIO_Port, GPIO_PIN_1, GPIO_PIN_SET);
    	  		  HAL_GPIO_WritePin(c_GPIO_Port, GPIO_PIN_2, GPIO_PIN_RESET);
    	  		  HAL_GPIO_WritePin(d_GPIO_Port, GPIO_PIN_3, GPIO_PIN_RESET);
    	  		  HAL_GPIO_WritePin(e_GPIO_Port, GPIO_PIN_4, GPIO_PIN_SET);
    	  		  HAL_GPIO_WritePin(f_GPIO_Port, GPIO_PIN_5, GPIO_PIN_RESET);
    	  		  HAL_GPIO_WritePin(g_GPIO_Port, GPIO_PIN_6, GPIO_PIN_RESET);
    	  		  break;
    	  	  case 6:
    	  		  HAL_GPIO_WritePin(a_GPIO_Port, GPIO_PIN_0, GPIO_PIN_RESET);
    	  		  HAL_GPIO_WritePin(b_GPIO_Port, GPIO_PIN_1, GPIO_PIN_SET);
    	  		  HAL_GPIO_WritePin(c_GPIO_Port, GPIO_PIN_2, GPIO_PIN_RESET);
    	  		  HAL_GPIO_WritePin(d_GPIO_Port, GPIO_PIN_3, GPIO_PIN_RESET);
    	  		  HAL_GPIO_WritePin(e_GPIO_Port, GPIO_PIN_4, GPIO_PIN_RESET);
    	  		  HAL_GPIO_WritePin(f_GPIO_Port, GPIO_PIN_5, GPIO_PIN_RESET);
    	  		  HAL_GPIO_WritePin(g_GPIO_Port, GPIO_PIN_6, GPIO_PIN_RESET);
    	  		  break;
    	  	  case 7:
    	  		  HAL_GPIO_WritePin(a_GPIO_Port, GPIO_PIN_0, GPIO_PIN_RESET);
    	  		  HAL_GPIO_WritePin(b_GPIO_Port, GPIO_PIN_1, GPIO_PIN_RESET);
    	  		  HAL_GPIO_WritePin(c_GPIO_Port, GPIO_PIN_2, GPIO_PIN_RESET);
    	  		  HAL_GPIO_WritePin(d_GPIO_Port, GPIO_PIN_3, GPIO_PIN_SET);
    	  		  HAL_GPIO_WritePin(e_GPIO_Port, GPIO_PIN_4, GPIO_PIN_SET);
    	  		  HAL_GPIO_WritePin(f_GPIO_Port, GPIO_PIN_5, GPIO_PIN_SET);
    	  		  HAL_GPIO_WritePin(g_GPIO_Port, GPIO_PIN_6, GPIO_PIN_SET);
    	  		  break;
    	  	  case 8:
    	  		  HAL_GPIO_WritePin(a_GPIO_Port, GPIO_PIN_0, GPIO_PIN_RESET);
    	  		  HAL_GPIO_WritePin(b_GPIO_Port, GPIO_PIN_1, GPIO_PIN_RESET);
    	  		  HAL_GPIO_WritePin(c_GPIO_Port, GPIO_PIN_2, GPIO_PIN_RESET);
    	  		  HAL_GPIO_WritePin(d_GPIO_Port, GPIO_PIN_3, GPIO_PIN_RESET);
    	  		  HAL_GPIO_WritePin(e_GPIO_Port, GPIO_PIN_4, GPIO_PIN_RESET);
    	  		  HAL_GPIO_WritePin(f_GPIO_Port, GPIO_PIN_5, GPIO_PIN_RESET);
    	  		  HAL_GPIO_WritePin(g_GPIO_Port, GPIO_PIN_6, GPIO_PIN_RESET);
    	  		  break;
    	  	  case 9:
    	  		  HAL_GPIO_WritePin(a_GPIO_Port, GPIO_PIN_0, GPIO_PIN_RESET);
    	  		  HAL_GPIO_WritePin(b_GPIO_Port, GPIO_PIN_1, GPIO_PIN_RESET);
    	  		  HAL_GPIO_WritePin(c_GPIO_Port, GPIO_PIN_2, GPIO_PIN_RESET);
    	  		  HAL_GPIO_WritePin(d_GPIO_Port, GPIO_PIN_3, GPIO_PIN_RESET);
    	  		  HAL_GPIO_WritePin(e_GPIO_Port, GPIO_PIN_4, GPIO_PIN_SET);
    	  		  HAL_GPIO_WritePin(f_GPIO_Port, GPIO_PIN_5, GPIO_PIN_RESET);
    	  		  HAL_GPIO_WritePin(g_GPIO_Port, GPIO_PIN_6, GPIO_PIN_RESET);
    	  		  break;
    	  	  default:
    	  		  clear7SEG();
    	  		  break;
    	  	  }
      }
void writeEn(int num){
	switch(num){
	case 0:
				HAL_GPIO_WritePin(En0_GPIO_Port, En0_Pin, 0);
				HAL_GPIO_WritePin(En1_GPIO_Port, En1_Pin, 1);
				HAL_GPIO_WritePin(En2_GPIO_Port, En2_Pin, 1);
				HAL_GPIO_WritePin(En3_GPIO_Port, En3_Pin, 1);
				break;
	case 1:
				HAL_GPIO_WritePin(En0_GPIO_Port, En0_Pin, 1);
				HAL_GPIO_WritePin(En1_GPIO_Port, En1_Pin, 0);
				HAL_GPIO_WritePin(En2_GPIO_Port, En2_Pin, 1);
				HAL_GPIO_WritePin(En3_GPIO_Port, En3_Pin, 1);
				break;
	case 2:
				HAL_GPIO_WritePin(En0_GPIO_Port, En0_Pin, 1);
				HAL_GPIO_WritePin(En1_GPIO_Port, En1_Pin, 1);
				HAL_GPIO_WritePin(En2_GPIO_Port, En2_Pin, 0);
				HAL_GPIO_WritePin(En3_GPIO_Port, En3_Pin, 1);
				break;
	case 3:
				HAL_GPIO_WritePin(En0_GPIO_Port, En0_Pin, 1);
				HAL_GPIO_WritePin(En1_GPIO_Port, En1_Pin, 1);
				HAL_GPIO_WritePin(En2_GPIO_Port, En2_Pin, 1);
				HAL_GPIO_WritePin(En3_GPIO_Port, En3_Pin, 0);
				break;
	default:
				HAL_GPIO_WritePin(En0_GPIO_Port, En0_Pin, 1);
				HAL_GPIO_WritePin(En1_GPIO_Port, En1_Pin, 1);
				HAL_GPIO_WritePin(En2_GPIO_Port, En2_Pin, 1);
				HAL_GPIO_WritePin(En3_GPIO_Port, En3_Pin, 1);
				break;
	}
}
void initState(){
	  clear7SEG();
	  writeEn(-1);
	  HAL_GPIO_WritePin(DOT_GPIO_Port, DOT_Pin, 1);
	  HAL_GPIO_WritePin(RED_LED_GPIO_Port, RED_LED_Pin, 1);
}
	const int MAX_LED = 4;
	int index_led = 0;
	int led_buffer[4] = {1,2,3,4};
void update7SEG(int index){
		switch(index){
			case 0:
				display7SEG(led_buffer[0]);
				writeEn(0);
				break;
			case 1:
				display7SEG(led_buffer[1]);
				writeEn(1);
				break;
			case 2:
				display7SEG(led_buffer[2]);
				writeEn(2);
				break;
			case 3:
				display7SEG(led_buffer[3]);
				writeEn(3);
				break;
			default:
				clear7SEG();
				writeEn(-1);
				break;
		}
}
void updateClockBuffer(int hour, int minute){
	led_buffer[0] = hour /10;
	led_buffer[1] = hour % 10;
	led_buffer[2] = minute /10;
	led_buffer[3] = minute % 10;
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
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_Base_Start_IT(&htim2);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  int hour = 15, minute = 8 , second = 50;
  setTimer(0, 1000); // 7SEG
  setTimer(1, 10); // RED_LED
  setTimer(2, 1000); // DOT
  setTimer(3, 1000); // Clock
  initState();
  while(1){
	  if(timer_flag[1] == 1){
		setTimer(1, 500);
		HAL_GPIO_TogglePin(RED_LED_GPIO_Port, RED_LED_Pin);
	  }
	  if(timer_flag[2] == 1){
		setTimer(2, 1000);
		HAL_GPIO_TogglePin(DOT_GPIO_Port, DOT_Pin);
	  }
	  if(timer_flag[3] == 1){
		  setTimer(3, 1000);
		  second++;
		  if(second >= 60){
			  second = 0;
			  minute++;
		  }
		  if(minute >= 60){
			  minute = 0;
			  hour++;
		  }
		  if(hour >= 24) hour = 0;
		  updateClockBuffer(hour, minute);
	  }
  }
    /* USER CODE END WHILE */
    /* USER CODE BEGIN 3 */
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
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */
  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */
  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 7999;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 9;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */
  /* USER CODE END TIM2_Init 2 */

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
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, DOT_Pin|RED_LED_Pin|En0_Pin|En1_Pin
                          |En2_Pin|En3_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, a_Pin|b_Pin|c_Pin|d_Pin
                          |e_Pin|f_Pin|g_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : DOT_Pin RED_LED_Pin En0_Pin En1_Pin
                           En2_Pin En3_Pin */
  GPIO_InitStruct.Pin = DOT_Pin|RED_LED_Pin|En0_Pin|En1_Pin
                          |En2_Pin|En3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : a_Pin b_Pin c_Pin d_Pin
                           e_Pin f_Pin g_Pin */
  GPIO_InitStruct.Pin = a_Pin|b_Pin|c_Pin|d_Pin
                          |e_Pin|f_Pin|g_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
const int CYCLE = 1000;
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	if(index_led >= MAX_LED) index_led = 0;
	if(timer_flag[0] == 1){
		setTimer(0, CYCLE);
	}
	if(timer_counter[0] == CYCLE/10) update7SEG(index_led++);
	else if(timer_counter[0] == CYCLE*3/4 /10) update7SEG(index_led++);
	else if(timer_counter[0] == CYCLE/2 /10) update7SEG(index_led++);
	else if(timer_counter[0] == CYCLE/4 /10) update7SEG(index_led++);
	timerRun();
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
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
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
