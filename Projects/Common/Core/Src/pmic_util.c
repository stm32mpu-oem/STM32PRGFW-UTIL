/**
  ******************************************************************************
  * @file    pmic_util.c
  * @author  GPM Application Team
  * @brief   Pmic utility functions
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "pmic_util.h"

/* Global variables ----------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/
/* Private defines -----------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
static I2C_HandleTypeDef hi2c;
/* Private function prototypes -----------------------------------------------*/
/* Functions Definition ------------------------------------------------------*/

/**
  * @brief  Intialize the IO and I2C instance for PMIC.
  * @param  None
  * @retval None.
  */
void PMIC_Util_Init(void)
{
  GPIO_InitTypeDef  gpio_init_structure;

  /*** Configure the GPIOs ***/
  /* Enable GPIO clock */

  BUS_I2C_SCL_GPIO_CLK_ENABLE();
  BUS_I2C_SDA_GPIO_CLK_ENABLE();

  gpio_init_structure.Mode = GPIO_MODE_AF_OD;
  gpio_init_structure.Pull = GPIO_NOPULL;
  gpio_init_structure.Speed = GPIO_SPEED_FREQ_HIGH;

  /* Configure I2C SCL clock as alternate function */
  gpio_init_structure.Alternate = BUS_I2C_SCL_AF;
  gpio_init_structure.Pin = BUS_I2C_SCL_PIN;
  HAL_GPIO_Init(BUS_I2C_SCL_GPIO_PORT, &gpio_init_structure);

  /* Configure I2C SDA data as alternate function */
  gpio_init_structure.Alternate = BUS_I2C_SDA_AF;
  gpio_init_structure.Pin = BUS_I2C_SDA_PIN;
  HAL_GPIO_Init(BUS_I2C_SDA_GPIO_PORT, &gpio_init_structure);

  /*** Configure the I2C peripheral ***/
  /* Enable I2C clock */
  BUS_I2C_CLK_ENABLE();

  /* Force the I2C peripheral clock reset */
  BUS_I2C_FORCE_RESET();

  /* Release the I2C peripheral clock reset */
  BUS_I2C_RELEASE_RESET();

  /* Enable and set I2Cx Interrupt to a lower priority */
#if defined(CORE_CA7)
  IRQ_SetPriority((IRQn_ID_t)BUS_I2C_EV_IRQn, 0);
  IRQ_Enable((IRQn_ID_t)BUS_I2C_EV_IRQn);
  IRQ_SetPriority((IRQn_ID_t)BUS_I2C_ER_IRQn, 0);
  IRQ_Enable((IRQn_ID_t)BUS_I2C_ER_IRQn);
#endif /* CORE_CA7 */

  hi2c.Instance              = BUS_I2C_INSTANCE;
  hi2c.Init.Timing           = BUS_I2Cx_TIMING;
  hi2c.Init.OwnAddress1      = OWN_I2C_SLAVE_ADDRESS;
  hi2c.Init.AddressingMode   = I2C_ADDRESSINGMODE_7BIT;
  hi2c.Init.DualAddressMode  = I2C_DUALADDRESS_DISABLE;
  hi2c.Init.OwnAddress2      = 0U;
  hi2c.Init.OwnAddress2Masks = I2C_OA2_NOMASK;
  hi2c.Init.GeneralCallMode  = I2C_GENERALCALL_DISABLE;
  hi2c.Init.NoStretchMode    = I2C_NOSTRETCH_DISABLE;

  HAL_I2C_Init(&hi2c);
}

/**
  * @brief api to perform read write operations on PMIC
  * @param addr: address of the memory from which to read or write the PMIC.
  * @param ops: operation to perform PMIC_SHADOW_WRITE or PMIC_SHADOW_READ.
  * @retval none
  */
void PMIC_Util_ReadWrite(uint8_t *addr, pmic_nvm_ops_t ops)
{
  uint8_t data;
  uint16_t count = 0U;

  switch (ops)
  {
    case PMIC_SHADOW_READ:
      for (uint8_t idx = 0; idx < PMIC_NVM_SIZE; idx++)
      {
        if (HAL_I2C_Mem_Read(&hi2c, PMIC_I2C_ADDRESS,
                             PMIC_NVM_SHDW_START_ADDR + idx, I2C_MEMADD_SIZE_8BIT, &data, 1, 1000) == 0U)
        {
          *(addr + idx) = data;
        }
        else
        {
          while (1) {}; /* Error */
        }
      }
      break;

    case PMIC_SHADOW_WRITE:
      for (uint8_t idx = 0; idx < PMIC_NVM_SIZE; idx++)
      {
        data = *(addr + idx);
        HAL_I2C_Mem_Write(&hi2c, PMIC_I2C_ADDRESS, PMIC_NVM_SHDW_START_ADDR + idx,
                          I2C_MEMADD_SIZE_8BIT, &data, 1, 1000);
      }
      break;

    default:
      break;
  }

  if (ops == PMIC_SHADOW_WRITE)
  {

    data = 0xfd;

    HAL_I2C_Mem_Write(&hi2c, PMIC_I2C_ADDRESS, PMIC_NVM_CR, I2C_MEMADD_SIZE_8BIT, &data, 1, 100);

    count = PMIC_SR_REG_TIMEOUT;

    for (count = 0; count < PMIC_SR_REG_TIMEOUT; count++)
    {

      HAL_I2C_Mem_Read(&hi2c, PMIC_I2C_ADDRESS, PMIC_NVM_SR, I2C_MEMADD_SIZE_8BIT, &data, 1, 100);

      if ((PMIC_NVM_BUSY_MSK & data) == 0U)
      {
        break;
      }

    }

    if ((PMIC_NVM_BUSY_MSK & data) != 0U)
    {
      while (1); /* hold the code so that a system reset can be performed. */
    }
  }
}
