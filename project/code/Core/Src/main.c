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

TIM_HandleTypeDef htim3;

UART_HandleTypeDef huart1;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART1_UART_Init(void);
static void MX_ADC1_Init(void);
static void MX_TIM3_Init(void);
/* USER CODE BEGIN PFP */
#ifdef __GNUC__
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif

PUTCHAR_PROTOTYPE {
	HAL_UART_Transmit(&huart1, (uint8_t*) &ch, 1, HAL_MAX_DELAY);
	return ch;
}
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void select_adc_channel(int channel) {
	ADC_ChannelConfTypeDef sConfig = { 0 };
	//sConfig.SamplingTime = ADC_SAMPLETIME_15CYCLES;
	sConfig.SamplingTime = ADC_SAMPLETIME_7CYCLES_5;
	switch (channel) {
	case 0:
		sConfig.Channel = ADC_CHANNEL_0;
		sConfig.Rank = 1;

		if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK) {
			Error_Handler();
		}
		break;

	case 1:
		/** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
		 */
		sConfig.Channel = ADC_CHANNEL_1;
		sConfig.Rank = 1;
		if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK) {
			Error_Handler();
		}
		break;
		/** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
		 */
	case 2:
		sConfig.Channel = ADC_CHANNEL_2;
		sConfig.Rank = 1;
		if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK) {
			Error_Handler();
		}
		break;
		/** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
		 */
	case 3:
		sConfig.Channel = ADC_CHANNEL_3;
		sConfig.Rank = 1;
		if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK) {
			Error_Handler();
		}
		break;
		/** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
		 */
	case 4:
		sConfig.Channel = ADC_CHANNEL_4;
		sConfig.Rank = 1;
		if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK) {
			Error_Handler();
		}
		break;
		/** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
		 */
	case 5:
		sConfig.Channel = ADC_CHANNEL_5;
		sConfig.Rank = 1;
		if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK) {
			Error_Handler();
		}
		break;
		/** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
		 */
	case 6:
		sConfig.Channel = ADC_CHANNEL_6;
		sConfig.Rank = 1;
		if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK) {
			Error_Handler();
		}
		break;
		/** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
		 */
	case 7:
		sConfig.Channel = ADC_CHANNEL_7;
		sConfig.Rank = 1;
		if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK) {
			Error_Handler();
		}
		break;
		/** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
		 */
	case 8:
		sConfig.Channel = ADC_CHANNEL_8;
		sConfig.Rank = 9;
		if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK) {
			Error_Handler();
		}
		break;
		/** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
		 */
	case 9:
		sConfig.Channel = ADC_CHANNEL_9;
		sConfig.Rank = 1;
		if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK) {
			Error_Handler();
		}
		break;
		/** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
		 */
	case 10:
		sConfig.Channel = ADC_CHANNEL_10;
		sConfig.Rank = 1;
		if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK) {
			Error_Handler();
		}
		break;
		/** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
		 */
	case 11:
		sConfig.Channel = ADC_CHANNEL_11;
		sConfig.Rank = 1;
		if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK) {
			Error_Handler();
		}
		break;
		/** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
		 */
	case 12:
		sConfig.Channel = ADC_CHANNEL_12;
		sConfig.Rank = 1;
		if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK) {
			Error_Handler();
		}
		break;
		/** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
		 */
	case 13:
		sConfig.Channel = ADC_CHANNEL_13;
		sConfig.Rank = 1;
		if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK) {
			Error_Handler();
		}
		break;
		/** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
		 */
	case 14:
		sConfig.Channel = ADC_CHANNEL_14;
		sConfig.Rank = 1;
		if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK) {
			Error_Handler();
		}
		break;
	case 15:
		sConfig.Channel = ADC_CHANNEL_15;
		sConfig.Rank = 1;
		if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK) {
			Error_Handler();
		}
		break;
	default:
		break;
	}
}

float unquantize_adc_val(uint32_t quantized_val, uint32_t mcu_V_q) {
	const float adc_max_val = 4095.0;


	// mcu_V_q expected to be around 4038 = ~3.2V
	// prob should assert this

	return ( ((float) quantized_val) / adc_max_val) * (( (float) mcu_V_q ) / adc_max_val);


}
/* USER CODE END 0 */

/**
 * @brief  The application entry point.
 * @retval int
 */
int main(void) {
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
	MX_USART1_UART_Init();
	MX_ADC1_Init();
	MX_TIM3_Init();
	/* USER CODE BEGIN 2 */
	printf("fully init'ed");

	uint32_t source_V_q;
	uint32_t mcu_V_q;

	float source_V;
	float mcu_V;
	float shunt_resistor_V;
	float circuit_I_A;
	float shunt_resistor_W;
	float mcu_W;




	/* USER CODE END 2 */

	/* Infinite loop */
	/* USER CODE BEGIN WHILE */
	while (1) {
		/* USER CODE END WHILE */

		/* USER CODE BEGIN 3 */

		printf("-------------------------------\r\n");
		for (uint16_t i = 0; i < 2; i++) {

			select_adc_channel(i);
			// Get each ADC value from the group (2 channels in this case)
			HAL_ADC_Start(&hadc1);
			// Wait for regular group conversion to be completed
			HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);


			// source 3.3v
			if (i == 0) {
				source_V_q = HAL_ADC_GetValue(&hadc1);
				printf("Quantized Source 3.3v [%u] value: %lu\r\n [unitless]\r\n", i, source_V_q);

			// voltage mcu gets after vdrop from resistor, around 3.277V from multimeter
			} else if (i == 1) {
				mcu_V_q = HAL_ADC_GetValue(&hadc1);
				printf("Quantized After resistor [%u] value: %lu [unitless]\r\n", i, mcu_V_q);

			}
		}

		//source_V = unquantize_adc_val(source_V_q, mcu_V_q);
		mcu_V = unquantize_adc_val(mcu_V_q, mcu_V_q);

		shunt_resistor_V = unquantize_adc_val(source_V_q - mcu_V_q, mcu_V_q);

		// current in circuit
		// I = V / R where R is assumed to be a (constant) 1 ohm resistor
		// therefore I = V

		circuit_I_A = shunt_resistor_V;

		shunt_resistor_W = circuit_I_A * shunt_resistor_V;
		mcu_W = mcu_V * circuit_I_A;







		printf("Shunt Resistor Voltage: %u [mV]\r\n", (uint16_t) (shunt_resistor_V * 1000));
		printf("MCU Voltage: %u [mV]\r\n", (uint16_t) (mcu_V * 1000));
		printf("Circuit current: %u [mA]\r\n", (uint16_t) (circuit_I_A * 1000));
		printf("Shunt Resistor Power: %u [mW]\r\n", (uint16_t) (shunt_resistor_W * 1000));
		printf("MCU power: %u [mW]\r\n", (uint16_t) (mcu_W * 1000));




		HAL_Delay(1000);

		/* USER CODE END 3 */
	}
}
/**
 * @brief System Clock Configuration
 * @retval None
 */
void SystemClock_Config(void) {
	RCC_OscInitTypeDef RCC_OscInitStruct = { 0 };
	RCC_ClkInitTypeDef RCC_ClkInitStruct = { 0 };
	RCC_PeriphCLKInitTypeDef PeriphClkInit = { 0 };

	/** Initializes the RCC Oscillators according to the specified parameters
	 * in the RCC_OscInitTypeDef structure.
	 */
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
	RCC_OscInitStruct.HSIState = RCC_HSI_ON;
	RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI_DIV2;
	RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL6;
	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
		Error_Handler();
	}

	/** Initializes the CPU, AHB and APB buses clocks
	 */
	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK
			| RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK) {
		Error_Handler();
	}
	PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_ADC;
	PeriphClkInit.AdcClockSelection = RCC_ADCPCLK2_DIV2;
	if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK) {
		Error_Handler();
	}
}

/**
 * @brief ADC1 Initialization Function
 * @param None
 * @retval None
 */
static void MX_ADC1_Init(void) {

	/* USER CODE BEGIN ADC1_Init 0 */

	/* USER CODE END ADC1_Init 0 */

	ADC_ChannelConfTypeDef sConfig = { 0 };

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
	if (HAL_ADC_Init(&hadc1) != HAL_OK) {
		Error_Handler();
	}

	/** Configure Regular Channel
	 */
	sConfig.Channel = ADC_CHANNEL_0;
	sConfig.Rank = ADC_REGULAR_RANK_1;
	sConfig.SamplingTime = ADC_SAMPLETIME_7CYCLES_5;
	if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK) {
		Error_Handler();
	}
	/* USER CODE BEGIN ADC1_Init 2 */

	/* USER CODE END ADC1_Init 2 */

}

/**
 * @brief TIM3 Initialization Function
 * @param None
 * @retval None
 */
static void MX_TIM3_Init(void) {

	/* USER CODE BEGIN TIM3_Init 0 */

	/* USER CODE END TIM3_Init 0 */

	TIM_ClockConfigTypeDef sClockSourceConfig = { 0 };
	TIM_MasterConfigTypeDef sMasterConfig = { 0 };

	/* USER CODE BEGIN TIM3_Init 1 */

	/* USER CODE END TIM3_Init 1 */
	htim3.Instance = TIM3;
	htim3.Init.Prescaler = 0;
	htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim3.Init.Period = 65535;
	htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	if (HAL_TIM_Base_Init(&htim3) != HAL_OK) {
		Error_Handler();
	}
	sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
	if (HAL_TIM_ConfigClockSource(&htim3, &sClockSourceConfig) != HAL_OK) {
		Error_Handler();
	}
	sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
	sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
	if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig)
			!= HAL_OK) {
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
static void MX_USART1_UART_Init(void) {

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
	if (HAL_UART_Init(&huart1) != HAL_OK) {
		Error_Handler();
	}
	/* USER CODE BEGIN USART1_Init 2 */

	/* USER CODE END USART1_Init 2 */

}

/**
 * @brief GPIO Initialization Function
 * @param None
 * @retval None
 */
static void MX_GPIO_Init(void) {
	/* USER CODE BEGIN MX_GPIO_Init_1 */
	/* USER CODE END MX_GPIO_Init_1 */

	/* GPIO Ports Clock Enable */
	__HAL_RCC_GPIOC_CLK_ENABLE();
	__HAL_RCC_GPIOD_CLK_ENABLE();
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();

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
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
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
void Error_Handler(void) {
	/* USER CODE BEGIN Error_Handler_Debug */
	/* User can add his own implementation to report the HAL error return state */
	__disable_irq();
	while (1) {
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
