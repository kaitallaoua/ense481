/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */


/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include <string.h>
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
ADC_HandleTypeDef hadc1;
ADC_HandleTypeDef hadc2;

CAN_HandleTypeDef hcan;

I2C_HandleTypeDef hi2c1;
I2C_HandleTypeDef hi2c2;

SPI_HandleTypeDef hspi1;
SPI_HandleTypeDef hspi2;

TIM_HandleTypeDef htim1;
TIM_HandleTypeDef htim2;
TIM_HandleTypeDef htim3;

UART_HandleTypeDef huart1;
UART_HandleTypeDef huart2;
UART_HandleTypeDef huart3;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART1_UART_Init(void);
static void MX_ADC1_Init(void);
static void MX_ADC2_Init(void);
static void MX_CAN_Init(void);
static void MX_I2C1_Init(void);
static void MX_I2C2_Init(void);
static void MX_SPI1_Init(void);
static void MX_SPI2_Init(void);
static void MX_TIM1_Init(void);
static void MX_TIM2_Init(void);
static void MX_TIM3_Init(void);
static void MX_USART2_UART_Init(void);
static void MX_USART3_UART_Init(void);
/* USER CODE BEGIN PFP */
#ifdef __GNUC__
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif

PUTCHAR_PROTOTYPE
{
  HAL_UART_Transmit(&huart1, (uint8_t *)&ch, 1, HAL_MAX_DELAY);
  return ch;
}


/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

uint16_t source_V_q;
uint16_t mcu_V_q;
uint16_t shunt_resistor_V_q;
uint16_t shunt_resistor_mV;
uint16_t mcu_mV;

uint16_t circuit_mA;

uint16_t mcu_mW;
uint16_t shunt_resistor_uW;

char UART1_rxBuffer[3] = {0};
const uint32_t CLI_timeout_ms = 100*1000;
const uint32_t delay_in_test_for_ms = 10*1000;
const uint32_t time_per_periph_ms = 5* 1000;


/**
  * @brief Select ADC1 channel function
  * @param None
  * @retval None
  */
void select_adc_channel(int channel)
{
    ADC_ChannelConfTypeDef sConfig = {0};
    //sConfig.SamplingTime = ADC_SAMPLETIME_15CYCLES;
    sConfig.SamplingTime = ADC_SAMPLETIME_7CYCLES_5;
    switch (channel)
    {
        case 0:
            sConfig.Channel = ADC_CHANNEL_0;
              sConfig.Rank = 1;

              if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
              {
                Error_Handler();
              }
              break;

        case 1:
              /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
              */
              sConfig.Channel = ADC_CHANNEL_1;
              sConfig.Rank = 1;
              if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
              {
                Error_Handler();
              }
              break;
              /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
              */
        case 2:
              sConfig.Channel = ADC_CHANNEL_2;
              sConfig.Rank = 1;
              if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
              {
                Error_Handler();
              }
              break;
              /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
              */
        case 3:
              sConfig.Channel = ADC_CHANNEL_3;
              sConfig.Rank = 1;
              if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
              {
                Error_Handler();
              }
              break;
              /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
              */
        case 4:
              sConfig.Channel = ADC_CHANNEL_4;
              sConfig.Rank = 1;
              if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
              {
                Error_Handler();
              }
              break;
              /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
              */
        case 5:
              sConfig.Channel = ADC_CHANNEL_5;
              sConfig.Rank = 1;
              if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
              {
                Error_Handler();
              }
              break;
              /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
              */
        case 6:
              sConfig.Channel = ADC_CHANNEL_6;
              sConfig.Rank = 1;
              if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
              {
                Error_Handler();
              }
              break;
              /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
              */
        case 7:
              sConfig.Channel = ADC_CHANNEL_7;
              sConfig.Rank = 1;
              if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
              {
                Error_Handler();
              }
              break;
              /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
              */
        case 8:
              sConfig.Channel = ADC_CHANNEL_8;
              sConfig.Rank = 9;
              if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
              {
                Error_Handler();
              }
              break;
              /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
              */
        case 9:
              sConfig.Channel = ADC_CHANNEL_9;
              sConfig.Rank = 1;
              if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
              {
                Error_Handler();
              }
              break;
              /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
              */
        case 10:
              sConfig.Channel = ADC_CHANNEL_10;
              sConfig.Rank = 1;
              if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
              {
                Error_Handler();
              }
              break;
              /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
              */
        case 11:
              sConfig.Channel = ADC_CHANNEL_11;
              sConfig.Rank = 1;
              if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
              {
                Error_Handler();
              }
              break;
              /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
              */
        case 12:
              sConfig.Channel = ADC_CHANNEL_12;
              sConfig.Rank = 1;
              if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
              {
                Error_Handler();
              }
              break;
              /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
              */
        case 13:
              sConfig.Channel = ADC_CHANNEL_13;
              sConfig.Rank = 1;
              if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
              {
                Error_Handler();
              }
              break;
              /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
              */
        case 14:
              sConfig.Channel = ADC_CHANNEL_14;
              sConfig.Rank = 1;
              if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
              {
                Error_Handler();
              }
              break;
        case 15:
              sConfig.Channel = ADC_CHANNEL_15;
              sConfig.Rank = 1;
              if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
              {
                Error_Handler();
              }
              break;
        default:
            break;
    }
}

void print_pwr(void) {

	  printf("-------------------------------\r\n");
	  for (uint16_t i = 0; i < 2; i++) {



			  select_adc_channel(i);
			  // Get each ADC value from the group (2 channels in this case)
			  HAL_ADC_Start(&hadc1);
			  // Wait for regular group conversion to be completed
			  HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);

			  if (i == 0) {
				  source_V_q = HAL_ADC_GetValue(&hadc1);
				  printf("Quantized Source Voltage [%u] value: %u [unitless]\r\n", (uint16_t) i, (uint16_t) source_V_q);
			  } else if (i == 1) {
				  mcu_V_q = HAL_ADC_GetValue(&hadc1);
				  printf("Quantized MCU Voltage [%u] value: %u [unitless]\r\n", (uint16_t) i, (uint16_t) mcu_V_q);
			  }
		  }

		  shunt_resistor_V_q = source_V_q - mcu_V_q;
		  shunt_resistor_mV = (uint16_t) (((float) (shunt_resistor_V_q * 1000)) / 4095.0) * 3.3;
		  mcu_mV = (uint16_t) (((float) (mcu_V_q * 1000)) / 4095.0) * 3.3;


		  printf("shunt resistor voltage: %u [mV]\r\n", shunt_resistor_mV);
		  printf("mcu voltage: %u [mV]\r\n", mcu_mV);

		  // since 1 ohm (assumed constant) shunt resistor
		  // I = V / R
		  // I = V
		  circuit_mA = shunt_resistor_mV;
		  printf("Circuit current: %u [mA]\r\n", circuit_mA);

		  mcu_mW = circuit_mA * (mcu_mV / 1000);

		  shunt_resistor_uW = circuit_mA * (shunt_resistor_mV);

		  printf("shunt resistor power: %u [uW]\r\n", shunt_resistor_uW);
		  printf("mcu power: %u [mW]\r\n", mcu_mW);



}

void print_help(void) {
	printf("Help: \r\n");
	printf("    max : power consumption test enabling all clocks and peripherals\r\n");
	printf("    typ : power consumption test for this program: USART1, ADC1, TIM3\r\n");
	printf("    min : power consumption test all peripherals disabled (except TIM4), only CPU enabled CANNOT GATHER INFO IN THIS MODE\r\n");
	printf("    pwr : free-running print of power readings\r\n");
	printf("    ver : print version info\r\n");
	printf("    hel : this message\r\n");

}

void print_version(void) {
	printf("Version: REV B April 1th, 2024\r\n");
}

// power consumption test enabling all clocks and peripherals
void test_max(void) {
	printf("Entering typical test mode, ensure external power meter connected. Each periph will delay for %lu ms\r\n", time_per_periph_ms);

	MX_GPIO_Init();
	printf("GPIO INIT\r\n");
	HAL_Delay(time_per_periph_ms);

	MX_USART1_UART_Init();
	printf("USART1 INIT\r\n");
	HAL_Delay(time_per_periph_ms);

	MX_ADC1_Init();
	printf("ADC1 INIT\r\n");
	HAL_Delay(time_per_periph_ms);

	MX_ADC2_Init();
	printf("ADC2 INIT\r\n");
	HAL_Delay(time_per_periph_ms);

	MX_CAN_Init();
	printf("CANBUS INIT\r\n");
	HAL_Delay(time_per_periph_ms);

	MX_I2C1_Init();
	printf("I2C1 INIT\r\n");
	HAL_Delay(time_per_periph_ms);

	MX_I2C2_Init();
	printf("I2C2 INIT\r\n");
	HAL_Delay(time_per_periph_ms);

	MX_SPI1_Init();
	printf("SPI1 INIT\r\n");
	HAL_Delay(time_per_periph_ms);

	MX_SPI2_Init();
	printf("SPI2 INIT\r\n");
	HAL_Delay(time_per_periph_ms);

	MX_TIM1_Init();
	printf("TIM1 INIT\r\n");
	HAL_Delay(time_per_periph_ms);

	MX_TIM2_Init();
	printf("TIM2 INIT\r\n");
	HAL_Delay(time_per_periph_ms);

	MX_TIM3_Init();
	printf("TIM3 INIT\r\n");
	HAL_Delay(time_per_periph_ms);

	MX_USART2_UART_Init();
	printf("USART2 INIT\r\n");
	HAL_Delay(time_per_periph_ms);

	MX_USART3_UART_Init();
	printf("USART3 INIT\r\n");
	HAL_Delay(time_per_periph_ms);


	printf("DeINIT non typical periph\r\n");
	HAL_Delay(time_per_periph_ms);

	HAL_ADC_DeInit(&hadc2);
	HAL_CAN_DeInit(&hcan);
	HAL_I2C_DeInit(&hi2c1);
	HAL_I2C_DeInit(&hi2c2);
	HAL_SPI_DeInit(&hspi1);
	HAL_SPI_DeInit(&hspi2);
	HAL_TIM_Base_DeInit(&htim1);
	HAL_TIM_Base_DeInit(&htim2);
	HAL_TIM_Base_DeInit(&htim3);
	HAL_UART_DeInit(&huart2);
	HAL_UART_DeInit(&huart3);

	printf("Max Test Done\r\n");
}

// power consumption test for this program: USART1, ADC1, TIM3
void test_typ(void) {
	printf("Entering typical test mode, ensure external power meter connected. Each periph will delay for %lu ms\r\n", time_per_periph_ms);
	HAL_Delay(time_per_periph_ms);

	printf("Typical Test Done\r\n");

}

// power consumption test all peripherals disabled, only CPU enabled
void test_min(void) {
	printf("Entering typical minimum mode, ensure external power meter connected. Will auto exit in %lu ms\r\n", delay_in_test_for_ms);
	HAL_Delay(delay_in_test_for_ms);

	HAL_UART_DeInit(&huart1);
	// printf's wont work..
	HAL_Delay(delay_in_test_for_ms);

	HAL_ADC_DeInit(&hadc1);
	HAL_Delay(10*1000);

	MX_GPIO_Init();
	MX_USART1_UART_Init();
	MX_ADC1_Init();

	printf("Minimum Test Done\r\n");

}

void test_pwr(void) {
	printf("Entering free-running power mode, press `q` three times quickly to exit\r\n");
	while (1) {

		print_pwr();
		HAL_UART_Receive (&huart1, (uint8_t*) UART1_rxBuffer, 3, 2000);

		if (strcmp(UART1_rxBuffer, "qqq") == 0) {
			printf("Exiting `pwr` mode\r\n");
			return;

		}
	}


}

// CLI commands
// max, typ, min, pwr
void read_cli(void) {
	for (uint8_t i = 0; i < 3; i++) {
		UART1_rxBuffer[0] = 0;
	}
	// need to type the command in the timeout
	while(HAL_UART_Receive (&huart1, (uint8_t*) UART1_rxBuffer, 3, CLI_timeout_ms) != HAL_OK);
	printf("Your command: %s\r\n", UART1_rxBuffer);

	if (strcmp(UART1_rxBuffer, "max") == 0) {
		test_max();

	}

	if (strcmp(UART1_rxBuffer, "typ") == 0) {
		test_typ();
	}

	if (strcmp(UART1_rxBuffer, "min") == 0) {
		test_min();

	}

	if (strcmp(UART1_rxBuffer, "pwr") == 0) {
		test_pwr();

	}

	if (strcmp(UART1_rxBuffer, "ver") == 0) {
		print_version();

	}

	if (strcmp(UART1_rxBuffer, "hel") == 0) {
		print_help();

	}

}











/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
/**
  * @brief The power metering application entry point
  * Text editor settings are maintained by the IDE
  * Development Enviroment: maintained by the IDE
  * Compiler: gcc (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0
  * Options: Viewable in File->Preferences->C/C++ Build->Settings
  * Libraries: CMSIS Driver, stm32cube HAL
  * CPU Config: nothing special
  * Version Control: recommended to checkout latest commit in master or latest stable release.
  * @retval int
  */
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
  MX_USART1_UART_Init();
  MX_ADC1_Init();
  MX_ADC2_Init();
  MX_CAN_Init();
  MX_I2C1_Init();
  MX_I2C2_Init();
  MX_SPI1_Init();
  MX_SPI2_Init();
  MX_TIM1_Init();
  MX_TIM2_Init();
  MX_TIM3_Init();
  MX_USART2_UART_Init();
  MX_USART3_UART_Init();
  /* USER CODE BEGIN 2 */


  // above autogenerated code should not be modified, it will be overwritten on changes
  // for consistency, disable the non-typical periphrials
  HAL_ADC_DeInit(&hadc2);
  HAL_CAN_DeInit(&hcan);
  HAL_I2C_DeInit(&hi2c1);
  HAL_I2C_DeInit(&hi2c2);
  HAL_SPI_DeInit(&hspi1);
  HAL_SPI_DeInit(&hspi2);
  HAL_TIM_Base_DeInit(&htim1);
  HAL_TIM_Base_DeInit(&htim2);
  HAL_TIM_Base_DeInit(&htim3);
  HAL_UART_DeInit(&huart2);
  HAL_UART_DeInit(&huart3);




  // display firmware version+build info
  printf("REV B April 1th, 2024\r\n\r\n");
  printf("Power Consumption CLI\r\n");



  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */


  // should not get here
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	  read_cli();

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
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI_DIV2;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL6;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_ADC;
  PeriphClkInit.AdcClockSelection = RCC_ADCPCLK2_DIV2;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief ADC1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_ADC1_Init(void)
{

  /* USER CODE BEGIN ADC1_Init 0 */

  /* USER CODE END ADC1_Init 0 */

  ADC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN ADC1_Init 1 */

  /* USER CODE END ADC1_Init 1 */

  /** Common config
  */
  hadc1.Instance = ADC1;
  hadc1.Init.ScanConvMode = ADC_SCAN_DISABLE;
  hadc1.Init.ContinuousConvMode = DISABLE;
  hadc1.Init.DiscontinuousConvMode = DISABLE;
  hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc1.Init.NbrOfConversion = 1;
  if (HAL_ADC_Init(&hadc1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Regular Channel
  */
  sConfig.Channel = ADC_CHANNEL_0;
  sConfig.Rank = ADC_REGULAR_RANK_1;
  sConfig.SamplingTime = ADC_SAMPLETIME_7CYCLES_5;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ADC1_Init 2 */

  /* USER CODE END ADC1_Init 2 */

}

/**
  * @brief ADC2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_ADC2_Init(void)
{

  /* USER CODE BEGIN ADC2_Init 0 */

  /* USER CODE END ADC2_Init 0 */

  ADC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN ADC2_Init 1 */

  /* USER CODE END ADC2_Init 1 */

  /** Common config
  */
  hadc2.Instance = ADC2;
  hadc2.Init.ScanConvMode = ADC_SCAN_DISABLE;
  hadc2.Init.ContinuousConvMode = ENABLE;
  hadc2.Init.DiscontinuousConvMode = DISABLE;
  hadc2.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc2.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc2.Init.NbrOfConversion = 1;
  if (HAL_ADC_Init(&hadc2) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Regular Channel
  */
  sConfig.Channel = ADC_CHANNEL_15;
  sConfig.Rank = ADC_REGULAR_RANK_1;
  sConfig.SamplingTime = ADC_SAMPLETIME_1CYCLE_5;
  if (HAL_ADC_ConfigChannel(&hadc2, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ADC2_Init 2 */

  /* USER CODE END ADC2_Init 2 */

}

/**
  * @brief CAN Initialization Function
  * @param None
  * @retval None
  */
static void MX_CAN_Init(void)
{

  /* USER CODE BEGIN CAN_Init 0 */

  /* USER CODE END CAN_Init 0 */

  /* USER CODE BEGIN CAN_Init 1 */

  /* USER CODE END CAN_Init 1 */
  hcan.Instance = CAN1;
  hcan.Init.Prescaler = 16;
  hcan.Init.Mode = CAN_MODE_NORMAL;
  hcan.Init.SyncJumpWidth = CAN_SJW_1TQ;
  hcan.Init.TimeSeg1 = CAN_BS1_1TQ;
  hcan.Init.TimeSeg2 = CAN_BS2_1TQ;
  hcan.Init.TimeTriggeredMode = DISABLE;
  hcan.Init.AutoBusOff = DISABLE;
  hcan.Init.AutoWakeUp = DISABLE;
  hcan.Init.AutoRetransmission = DISABLE;
  hcan.Init.ReceiveFifoLocked = DISABLE;
  hcan.Init.TransmitFifoPriority = DISABLE;
  if (HAL_CAN_Init(&hcan) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN CAN_Init 2 */

  /* USER CODE END CAN_Init 2 */

}

/**
  * @brief I2C1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C1_Init(void)
{

  /* USER CODE BEGIN I2C1_Init 0 */

  /* USER CODE END I2C1_Init 0 */

  /* USER CODE BEGIN I2C1_Init 1 */

  /* USER CODE END I2C1_Init 1 */
  hi2c1.Instance = I2C1;
  hi2c1.Init.ClockSpeed = 100000;
  hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C1_Init 2 */

  /* USER CODE END I2C1_Init 2 */

}

/**
  * @brief I2C2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C2_Init(void)
{

  /* USER CODE BEGIN I2C2_Init 0 */

  /* USER CODE END I2C2_Init 0 */

  /* USER CODE BEGIN I2C2_Init 1 */

  /* USER CODE END I2C2_Init 1 */
  hi2c2.Instance = I2C2;
  hi2c2.Init.ClockSpeed = 100000;
  hi2c2.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c2.Init.OwnAddress1 = 0;
  hi2c2.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c2.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c2.Init.OwnAddress2 = 0;
  hi2c2.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c2.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C2_Init 2 */

  /* USER CODE END I2C2_Init 2 */

}

/**
  * @brief SPI1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI1_Init(void)
{

  /* USER CODE BEGIN SPI1_Init 0 */

  /* USER CODE END SPI1_Init 0 */

  /* USER CODE BEGIN SPI1_Init 1 */

  /* USER CODE END SPI1_Init 1 */
  /* SPI1 parameter configuration*/
  hspi1.Instance = SPI1;
  hspi1.Init.Mode = SPI_MODE_MASTER;
  hspi1.Init.Direction = SPI_DIRECTION_2LINES;
  hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi1.Init.NSS = SPI_NSS_SOFT;
  hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_2;
  hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi1.Init.CRCPolynomial = 10;
  if (HAL_SPI_Init(&hspi1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI1_Init 2 */

  /* USER CODE END SPI1_Init 2 */

}

/**
  * @brief SPI2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI2_Init(void)
{

  /* USER CODE BEGIN SPI2_Init 0 */

  /* USER CODE END SPI2_Init 0 */

  /* USER CODE BEGIN SPI2_Init 1 */

  /* USER CODE END SPI2_Init 1 */
  /* SPI2 parameter configuration*/
  hspi2.Instance = SPI2;
  hspi2.Init.Mode = SPI_MODE_MASTER;
  hspi2.Init.Direction = SPI_DIRECTION_2LINES;
  hspi2.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi2.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi2.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi2.Init.NSS = SPI_NSS_SOFT;
  hspi2.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_2;
  hspi2.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi2.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi2.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi2.Init.CRCPolynomial = 10;
  if (HAL_SPI_Init(&hspi2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI2_Init 2 */

  /* USER CODE END SPI2_Init 2 */

}

/**
  * @brief TIM1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM1_Init(void)
{

  /* USER CODE BEGIN TIM1_Init 0 */

  /* USER CODE END TIM1_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM1_Init 1 */

  /* USER CODE END TIM1_Init 1 */
  htim1.Instance = TIM1;
  htim1.Init.Prescaler = 0;
  htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim1.Init.Period = 65535;
  htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim1.Init.RepetitionCounter = 0;
  htim1.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
  if (HAL_TIM_Base_Init(&htim1) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim1, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim1, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM1_Init 2 */

  /* USER CODE END TIM1_Init 2 */

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
  htim2.Init.Prescaler = 0;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 65535;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
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
  * @brief TIM3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM3_Init(void)
{

  /* USER CODE BEGIN TIM3_Init 0 */

  /* USER CODE END TIM3_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM3_Init 1 */

  /* USER CODE END TIM3_Init 1 */
  htim3.Instance = TIM3;
  htim3.Init.Prescaler = 0;
  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim3.Init.Period = 65535;
  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
  if (HAL_TIM_Base_Init(&htim3) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim3, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM3_Init 2 */

  /* USER CODE END TIM3_Init 2 */

}

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 115200;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

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
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/**
  * @brief USART3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART3_UART_Init(void)
{

  /* USER CODE BEGIN USART3_Init 0 */

  /* USER CODE END USART3_Init 0 */

  /* USER CODE BEGIN USART3_Init 1 */

  /* USER CODE END USART3_Init 1 */
  huart3.Instance = USART3;
  huart3.Init.BaudRate = 115200;
  huart3.Init.WordLength = UART_WORDLENGTH_8B;
  huart3.Init.StopBits = UART_STOPBITS_1;
  huart3.Init.Parity = UART_PARITY_NONE;
  huart3.Init.Mode = UART_MODE_TX_RX;
  huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart3.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart3) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART3_Init 2 */

  /* USER CODE END USART3_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin : PC13 */
  GPIO_InitStruct.Pin = GPIO_PIN_13;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI15_10_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM4 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM4) {
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
	  printf("Bricked");
	  HAL_Delay(1000);
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
