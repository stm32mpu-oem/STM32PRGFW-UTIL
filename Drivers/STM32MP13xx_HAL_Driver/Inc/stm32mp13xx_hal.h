/**
  ******************************************************************************
  * @file    stm32mp13xx_hal.h
  * @author  MCD Application Team
  * @brief   This file contains all the functions prototypes for the HAL
  *          module driver.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef STM32MP13xx_HAL_H
#define STM32MP13xx_HAL_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32mp13xx_hal_conf.h"

/** @addtogroup STM32MP13xx_HAL_Driver
 * @{
 */

/** @addtogroup HAL
 * @{
 */

/* Exported types ------------------------------------------------------------*/
/** @defgroup HAL_Exported_Types HAL Exported Types
  * @{
  */
/** @defgroup HAL_Exported_Types_Group1 Tick Frequency
 * @{
 */
typedef enum
{
  HAL_TICK_FREQ_10HZ         = 100U,
  HAL_TICK_FREQ_100HZ        = 10U,
  HAL_TICK_FREQ_1KHZ         = 1U,
  HAL_TICK_FREQ_DEFAULT      = HAL_TICK_FREQ_1KHZ
} HAL_TickFreqTypeDef;
/**
 * @}
 */

/** @defgroup HAL_Exported_Types_Group2 HDP SW Signal
 * @{
 */

/**
 * @brief  HDP SW Signal SET and Bit RESET enumeration
 */
typedef enum
{
  HDP_SW_SIGNAL_RESET = 0,
  HDP_SW_SIGNAL_SET
} HDP_SwSignalState;
/**
 * @}
 */

/**
* @}
*/

/* Exported constants --------------------------------------------------------*/

/** @defgroup HAL_Exported_Constants HAL Exported Constants
  * @{
  */

/** @defgroup HAL_Exported_Constants_Group1 SYSCFG VREFBUF Voltage Scale
  * @{
  */
#define SYSCFG_VREFBUF_VOLTAGE_SCALE0   VREFBUF_CSR_VRS_OUT1   /*!< Voltage reference scale 0 (VREF_OUT1) */
#define SYSCFG_VREFBUF_VOLTAGE_SCALE1   VREFBUF_CSR_VRS_OUT2   /*!< Voltage reference scale 1 (VREF_OUT2) */
#define SYSCFG_VREFBUF_VOLTAGE_SCALE2   VREFBUF_CSR_VRS_OUT3   /*!< Voltage reference scale 2 (VREF_OUT3) */
#define SYSCFG_VREFBUF_VOLTAGE_SCALE3   VREFBUF_CSR_VRS_OUT4   /*!< Voltage reference scale 3 (VREF_OUT4) */


#define IS_SYSCFG_VREFBUF_VOLTAGE_SCALE(__SCALE__)  (((__SCALE__) == SYSCFG_VREFBUF_VOLTAGE_SCALE0) || \
                                                     ((__SCALE__) == SYSCFG_VREFBUF_VOLTAGE_SCALE1) || \
                                                     ((__SCALE__) == SYSCFG_VREFBUF_VOLTAGE_SCALE2) || \
                                                     ((__SCALE__) == SYSCFG_VREFBUF_VOLTAGE_SCALE3))


/**
  * @}
  */

/** @defgroup HAL_Exported_Constants_Group2 SYSCFG VREFBUF High Impedance
  * @{
  */
#define SYSCFG_VREFBUF_HIGH_IMPEDANCE_DISABLE  ((uint32_t)0x00000000U) /*!< VREF_plus pin is internally connected to Voltage reference buffer output */
#define SYSCFG_VREFBUF_HIGH_IMPEDANCE_ENABLE   VREFBUF_CSR_HIZ        /*!< VREF_plus pin is high impedance */

#define IS_SYSCFG_VREFBUF_HIGH_IMPEDANCE(__VALUE__)  (((__VALUE__) == SYSCFG_VREFBUF_HIGH_IMPEDANCE_DISABLE) || \
                                                      ((__VALUE__) == SYSCFG_VREFBUF_HIGH_IMPEDANCE_ENABLE))

#define IS_SYSCFG_VREFBUF_TRIMMING(__VALUE__)  (((__VALUE__) > 0U) && ((__VALUE__) <= VREFBUF_CCR_TRIM))

/**
  * @}
  */


/** @defgroup HAL_Exported_Constants_Group3 SYSCFG Ethernet Config
  * @{
  */
#if defined (SYSCFG_DUAL_ETH_SUPPORT)
#define SYSCFG_ETH1_MII                     ((uint32_t)0x00000000)          /*!< Select the Media Independent Interface */
#define SYSCFG_ETH1_RMII                    SYSCFG_PMCSETR_ETH1_SEL_2       /*!< Select the Reduced Media Independent Interface */
#define SYSCFG_ETH1_RGMII                   SYSCFG_PMCSETR_ETH1_SEL_0       /*!< Select the Reduced Gigabit Media Independent Interface */

#define SYSCFG_ETH2_MII                     ((uint32_t)0x00000000)          /*!< Select the Media Independent Interface */
#define SYSCFG_ETH2_RMII                    SYSCFG_PMCSETR_ETH2_SEL_2       /*!< Select the Reduced Media Independent Interface */
#define SYSCFG_ETH2_RGMII                   SYSCFG_PMCSETR_ETH2_SEL_0       /*!< Select the Reduced Gigabit Media Independent Interface */

#define IS_SYSCFG_ETHERNET_CONFIG(CONFIG) (((CONFIG) == SYSCFG_ETH1_MII)       || \
                                          ((CONFIG) == SYSCFG_ETH1_RMII)       || \
                                          ((CONFIG) == SYSCFG_ETH1_RGMII)      || \
                                          ((CONFIG) == SYSCFG_ETH2_MII)        || \
                                          ((CONFIG) == SYSCFG_ETH2_RMII)       || \
                                          ((CONFIG) == SYSCFG_ETH2_RGMII))
#endif

/**
  * @}
  */


/** @defgroup HAL_Exported_Constants_Group5 SYSCFG IOCompenstionCell Config
  * @{
  */
#define SYSCFG_CELL_CODE                    ((uint32_t)0x00000000)  /*!< Select Code from the cell */
#define SYSCFG_REGISTER_CODE                SYSCFG_CMPCR_SW_CTRL    /*!< Code from the SYSCFG compensation cell code register */

#define IS_SYSCFG_CODE_SELECT(SELECT) (((SELECT) == SYSCFG_CELL_CODE)|| \
                                        ((SELECT) == SYSCFG_REGISTER_CODE))

#define IS_SYSCFG_CODE_CONFIG(CONFIG) ((CONFIG) < (0x10U))

#define SYSCFG_MAIN_COMP_CELL               (0x1U << 1)
#define SYSCFG_SD1_COMP_CELL                (0x1U << 2)
#define SYSCFG_SD2_COMP_CELL                (0x1U << 3)


/** @brief  Check SYSCFG Main Compensation Cell Ready flag is set or not.
* @retval State of bit (1 or 0)
*/
#define __HAL_SYSCFG_MAIN_CMP_CELL_GET_FLAG() ((READ_BIT(SYSCFG->CMPCR, SYSCFG_CMPCR_READY) == (SYSCFG_CMPCR_READY)) ? 1U : 0U)

/** @brief  Check SYSCFG SDMMC1 Compensation Cell Ready flag is set or not.
* @retval State of bit (1 or 0)
*/
#define __HAL_SYSCFG_SD1_CMP_CELL_GET_FLAG() ((READ_BIT(SYSCFG->CMPSD1CR, SYSCFG_CMPSD1CR_READY) == (SYSCFG_CMPSD1CR_READY)) ? 1U : 0U)

/** @brief  Check SYSCFG SDMMC2 Compensation Cell Ready flag is set or not.
* @retval State of bit (1 or 0)
*/
#define __HAL_SYSCFG_SD2_CMP_CELL_GET_FLAG() ((READ_BIT(SYSCFG->CMPSD2CR, SYSCFG_CMPSD2CR_READY) == (SYSCFG_CMPSD2CR_READY)) ? 1U : 0U)

/**
  * @brief  Get Main I/O compensation cell value for PMOS transistors
  * @retval The Main I/O compensation cell value for PMOS transistors
  */
#define __HAL_SYSCFG_MAIN_CELL_GET_PMOS_CMP() (READ_BIT(SYSCFG->CMPCR, SYSCFG_CMPCR_APSRC))

/**
  * @brief  Get Main I/O compensation cell value for NMOS transistors
  * @retval Returned value is the Main I/O compensation cell value for NMOS transistors
  */
#define __HAL_SYSCFG_MAIN_CELL_GET_NMOS_CMP() (READ_BIT(SYSCFG->CMPCR, SYSCFG_CMPCR_ANSRC))

/**
  * @brief  Get SDMMC1 I/O compensation cell value for PMOS transistors
  * @retval The SDMMC1 I/O compensation cell value for PMOS transistors
  */
#define __HAL_SYSCFG_SD1_CELL_GET_PMOS_CMP() (READ_BIT(SYSCFG->CMPSD1CR, SYSCFG_CMPSD1CR_APSRC))

/**
  * @brief  Get SDMMC1 I/O compensation cell value for NMOS transistors
  * @retval Returned value is the SDMMC1 I/O compensation cell value for NMOS transistors
  */
#define __HAL_SYSCFG_SD1_CELL_GET_NMOS_CMP() (READ_BIT(SYSCFG->CMPSD1CR, SYSCFG_CMPSD1CR_ANSRC))

/**
  * @brief  Get SDMMC2 I/O compensation cell value for PMOS transistors
  * @retval The SDMMC2 I/O compensation cell value for PMOS transistors
  */
#define __HAL_SYSCFG_SD2_CELL_GET_PMOS_CMP() (READ_BIT(SYSCFG->CMPSD2CR, SYSCFG_CMPSD2CR_APSRC))

/**
  * @brief  Get SDMMC2 I/O compensation cell value for NMOS transistors
  * @retval Returned value is the SDMMC2 I/O compensation cell value for NMOS transistors
  */
#define __HAL_SYSCFG_SD2_CELL_GET_NMOS_CMP() (READ_BIT(SYSCFG->CMPSD2CR, SYSCFG_CMPSD2CR_ANSRC))

/**
  * @}
  */

/** @defgroup HAL_Exported_Constants_Group6 SYSCFG IOControl HighSpeed Config
  * @{
  */
#define SYSCFG_HIGHSPEED_TRACE_SIGNAL   (0x1U << 0)   /*!< High Speed Low Voltage Pad mode Enable when a TRACEx signal is selected in AFMUX */
#define SYSCFG_HIGHSPEED_QUADSPI_SIGNAL (0x1U << 1)   /*!< High Speed Low Voltage Pad mode Enable when a QUADSPI_x signal is selected in AFMUX */
#define SYSCFG_HIGHSPEED_ETH1_SIGNAL    (0x1U << 2)   /*!< High Speed Low Voltage Pad mode Enable when a ETH_x signal is selected in AFMUX */
#define SYSCFG_HIGHSPEED_ETH2_SIGNAL    (0x1U << 3)   /*!< High Speed Low Voltage Pad mode Enable when a ETH_x signal is selected in AFMUX */
#define SYSCFG_HIGHSPEED_SDMMC1_SIGNAL  (0x1U << 4)   /*!< High Speed Low Voltage Pad mode Enable when a SDMMCy_x signal is selected in AFMUX */
#define SYSCFG_HIGHSPEED_SDMMC2_SIGNAL  (0x1U << 5)   /*!< High Speed Low Voltage Pad mode Enable when a SDMMCy_x signal is selected in AFMUX */
#define SYSCFG_HIGHSPEED_SPI1_SIGNAL    (0x1U << 6)   /*!< High Speed Low Voltage Pad mode Enable when a SPIy_x signal is selected in AFMUX */
#define SYSCFG_HIGHSPEED_SPI2_SIGNAL    (0x1U << 7)   /*!< High Speed Low Voltage Pad mode Enable when a SPIy_x signal is selected in AFMUX */
#define SYSCFG_HIGHSPEED_SPI3_SIGNAL    (0x1U << 8)   /*!< High Speed Low Voltage Pad mode Enable when a SPIy_x signal is selected in AFMUX */
#define SYSCFG_HIGHSPEED_SPI4_SIGNAL    (0x1U << 9)   /*!< High Speed Low Voltage Pad mode Enable when a SPIy_x signal is selected in AFMUX */
#define SYSCFG_HIGHSPEED_SPI5_SIGNAL    (0x1U << 10)  /*!< High Speed Low Voltage Pad mode Enable when a SPIy_x signal is selected in AFMUX */
#define SYSCFG_HIGHSPEED_LTDC_SIGNAL    (0x1U << 11)  /*!< High Speed Low Voltage Pad mode Enable when a LTDCy_x signal is selected in AFMUX */

/**
  * @}
  */


/** @defgroup HAL_Exported_Constants_Group7 HDP Software signal define
  * @{
  */
#define HDP_SW_SIGNAL_0                 ((uint8_t)0x01U)  /* HDP Software signal 0 selected    */
#define HDP_SW_SIGNAL_1                 ((uint8_t)0x02U)  /* HDP Software signal 1 selected    */
#define HDP_SW_SIGNAL_2                 ((uint8_t)0x04U)  /* HDP Software signal 2 selected    */
#define HDP_SW_SIGNAL_3                 ((uint8_t)0x08U)  /* HDP Software signal 3 selected    */
#define HDP_SW_SIGNAL_4                 ((uint8_t)0x10U)  /* HDP Software signal 4 selected    */
#define HDP_SW_SIGNAL_5                 ((uint8_t)0x20U)  /* HDP Software signal 5 selected    */
#define HDP_SW_SIGNAL_6                 ((uint8_t)0x40U)  /* HDP Software signal 6 selected    */
#define HDP_SW_SIGNAL_7                 ((uint8_t)0x80U)  /* HDP Software signal 7 selected    */

/**
 * @}
 */

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/

/** @defgroup DBGMCU_Exported_Macros DBGMCU Exported Macros
  * @{
  */

/** @brief  Freeze/Unfreeze Peripherals in Debug mode
  */
#if defined(DBGMCU_APB4_FZ_DBG_IWDG2_STOP)
#define __HAL_DBGMCU_FREEZE_IWDG2()           SET_BIT(DBGMCU->APB4FZ1, DBGMCU_APB4_FZ_DBG_IWDG2_STOP)
#define __HAL_DBGMCU_UNFREEZE_IWDG2()         CLEAR_BIT(DBGMCU->APB4FZ1, DBGMCU_APB4_FZ_DBG_IWDG2_STOP)
#endif

#if defined(DBGMCU_APB1_FZ_DBG_TIM2_STOP)
#define __HAL_DBGMCU_FREEZE_TIM2()           SET_BIT(DBGMCU->APB1FZ1, DBGMCU_APB1_FZ_DBG_TIM2_STOP)
#define __HAL_DBGMCU_UNFREEZE_TIM2()         CLEAR_BIT(DBGMCU->APB1FZ1, DBGMCU_APB1_FZ_DBG_TIM2_STOP)
#endif
#if defined(DBGMCU_APB1_FZ_DBG_TIM3_STOP)
#define __HAL_DBGMCU_FREEZE_TIM3()           SET_BIT(DBGMCU->APB1FZ1, DBGMCU_APB1_FZ_DBG_TIM3_STOP)
#define __HAL_DBGMCU_UNFREEZE_TIM3()         CLEAR_BIT(DBGMCU->APB1FZ1, DBGMCU_APB1_FZ_DBG_TIM3_STOP)
#endif
#if defined(DBGMCU_APB1_FZ_DBG_TIM4_STOP)
#define __HAL_DBGMCU_FREEZE_TIM4()           SET_BIT(DBGMCU->APB1FZ1, DBGMCU_APB1_FZ_DBG_TIM4_STOP)
#define __HAL_DBGMCU_UNFREEZE_TIM4()         CLEAR_BIT(DBGMCU->APB1FZ1, DBGMCU_APB1_FZ_DBG_TIM4_STOP)
#endif
#if defined(DBGMCU_APB1_FZ_DBG_TIM5_STOP)
#define __HAL_DBGMCU_FREEZE_TIM5()           SET_BIT(DBGMCU->APB1FZ1, DBGMCU_APB1_FZ_DBG_TIM5_STOP)
#define __HAL_DBGMCU_UNFREEZE_TIM5()         CLEAR_BIT(DBGMCU->APB1FZ1, DBGMCU_APB1_FZ_DBG_TIM5_STOP)
#endif
#if defined(DBGMCU_APB1_FZ_DBG_TIM6_STOP)
#define __HAL_DBGMCU_FREEZE_TIM6()           SET_BIT(DBGMCU->APB1FZ1, DBGMCU_APB1_FZ_DBG_TIM6_STOP)
#define __HAL_DBGMCU_UNFREEZE_TIM6()         CLEAR_BIT(DBGMCU->APB1FZ1, DBGMCU_APB1_FZ_DBG_TIM6_STOP)
#endif
#if defined(DBGMCU_APB1_FZ_DBG_TIM7_STOP)
#define __HAL_DBGMCU_FREEZE_TIM7()           SET_BIT(DBGMCU->APB1FZ1, DBGMCU_APB1_FZ_DBG_TIM7_STOP)
#define __HAL_DBGMCU_UNFREEZE_TIM7()         CLEAR_BIT(DBGMCU->APB1FZ1, DBGMCU_APB1_FZ_DBG_TIM7_STOP)
#endif
#if defined(DBGMCU_APB1_FZ_DBG_LPTIM1_STOP)
#define __HAL_DBGMCU_FREEZE_LPTIM1()           SET_BIT(DBGMCU->APB1FZ1, DBGMCU_APB1_FZ_DBG_LPTIM1_STOP)
#define __HAL_DBGMCU_UNFREEZE_LPTIM1()         CLEAR_BIT(DBGMCU->APB1FZ1, DBGMCU_APB1_FZ_DBG_LPTIM1_STOP)
#endif
#if defined(DBGMCU_APB1_FZ_DBG_I2C1_STOP)
#define __HAL_DBGMCU_FREEZE_I2C1()           SET_BIT(DBGMCU->APB1FZ1, DBGMCU_APB1_FZ_DBG_I2C1_STOP)
#define __HAL_DBGMCU_UNFREEZE_I2C1()         CLEAR_BIT(DBGMCU->APB1FZ1, DBGMCU_APB1_FZ_DBG_I2C1_STOP)
#endif
#if defined(DBGMCU_APB1_FZ_DBG_I2C2_STOP)
#define __HAL_DBGMCU_FREEZE_I2C2()           SET_BIT(DBGMCU->APB1FZ1, DBGMCU_APB1_FZ_DBG_I2C2_STOP)
#define __HAL_DBGMCU_UNFREEZE_I2C2()         CLEAR_BIT(DBGMCU->APB1FZ1, DBGMCU_APB1_FZ_DBG_I2C2_STOP)
#endif

#if defined(DBGMCU_APB2_FZ_DBG_TIM1_STOP)
#define __HAL_DBGMCU_FREEZE_TIM1()           SET_BIT(DBGMCU->APB2FZ1, DBGMCU_APB2_FZ_DBG_TIM1_STOP)
#define __HAL_DBGMCU_UNFREEZE_TIM1()         CLEAR_BIT(DBGMCU->APB2FZ1, DBGMCU_APB2_FZ_DBG_TIM1_STOP)
#endif
#if defined(DBGMCU_APB2_FZ_DBG_TIM8_STOP)
#define __HAL_DBGMCU_FREEZE_TIM8()           SET_BIT(DBGMCU->APB2FZ1, DBGMCU_APB2_FZ_DBG_TIM8_STOP)
#define __HAL_DBGMCU_UNFREEZE_TIM8()         CLEAR_BIT(DBGMCU->APB2FZ1, DBGMCU_APB2_FZ_DBG_TIM8_STOP)
#endif
#if defined(DBGMCU_APB2_FZ_DBG_FDCAN_STOP)
#define __HAL_DBGMCU_FREEZE_FDCAN()           SET_BIT(DBGMCU->APB2FZ1, DBGMCU_APB2_FZ_DBG_FDCAN_STOP)
#define __HAL_DBGMCU_UNFREEZE_FDCAN()         CLEAR_BIT(DBGMCU->APB2FZ1, DBGMCU_APB2_FZ_DBG_FDCAN_STOP)
#endif

#if defined(DBGMCU_APB3_FZ_DBG_LPTIM2_STOP)
#define __HAL_DBGMCU_FREEZE_LPTIM2()           SET_BIT(DBGMCU->APB3FZ1, DBGMCU_APB3_FZ_DBG_LPTIM2_STOP)
#define __HAL_DBGMCU_UNFREEZE_LPTIM2()         CLEAR_BIT(DBGMCU->APB3FZ1, DBGMCU_APB3_FZ_DBG_LPTIM2_STOP)
#endif
#if defined(DBGMCU_APB3_FZ_DBG_LPTIM3_STOP)
#define __HAL_DBGMCU_FREEZE_LPTIM3()           SET_BIT(DBGMCU->APB3FZ1, DBGMCU_APB3_FZ_DBG_LPTIM3_STOP)
#define __HAL_DBGMCU_UNFREEZE_LPTIM3()         CLEAR_BIT(DBGMCU->APB3FZ1, DBGMCU_APB3_FZ_DBG_LPTIM3_STOP)
#endif
#if defined(DBGMCU_APB3_FZ_DBG_LPTIM4_STOP)
#define __HAL_DBGMCU_FREEZE_LPTIM4()           SET_BIT(DBGMCU->APB3FZ1, DBGMCU_APB3_FZ_DBG_LPTIM4_STOP)
#define __HAL_DBGMCU_UNFREEZE_LPTIM4()         CLEAR_BIT(DBGMCU->APB3FZ1, DBGMCU_APB3_FZ_DBG_LPTIM4_STOP)
#endif
#if defined(DBGMCU_APB3_FZ_DBG_LPTIM5_STOP)
#define __HAL_DBGMCU_FREEZE_LPTIM5()           SET_BIT(DBGMCU->APB3FZ1, DBGMCU_APB3_FZ_DBG_LPTIM5_STOP)
#define __HAL_DBGMCU_UNFREEZE_LPTIM5()         CLEAR_BIT(DBGMCU->APB3FZ1, DBGMCU_APB3_FZ_DBG_LPTIM5_STOP)
#endif

#if defined(DBGMCU_APB5_FZ_DBG_IWDG1_STOP)
#define __HAL_DBGMCU_FREEZE_IWDG1()           SET_BIT(DBGMCU->APB5FZ1, DBGMCU_APB5_FZ_DBG_IWDG1_STOP)
#define __HAL_DBGMCU_UNFREEZE_IWDG1()         CLEAR_BIT(DBGMCU->APB5FZ1, DBGMCU_APB5_FZ_DBG_IWDG1_STOP)
#endif
#if defined(DBGMCU_APB5_FZ_DBG_RTC_STOP)
#define __HAL_DBGMCU_FREEZE_RTC()           SET_BIT(DBGMCU->APB5FZ1, DBGMCU_APB5_FZ_DBG_RTC_STOP)
#define __HAL_DBGMCU_UNFREEZE_RTC()         CLEAR_BIT(DBGMCU->APB5FZ1, DBGMCU_APB5_FZ_DBG_RTC_STOP)
#endif

#if defined(DBGMCU_APB6_FZ_DBG_I2C3_STOP)
#define __HAL_DBGMCU_FREEZE_I2C3()           SET_BIT(DBGMCU->APB6FZ1, DBGMCU_APB6_FZ_DBG_I2C3_STOP)
#define __HAL_DBGMCU_UNFREEZE_I2C3()         CLEAR_BIT(DBGMCU->APB6FZ1, DBGMCU_APB6_FZ_DBG_I2C3_STOP)
#endif
#if defined(DBGMCU_APB6_FZ_DBG_I2C4_STOP)
#define __HAL_DBGMCU_FREEZE_I2C4()           SET_BIT(DBGMCU->APB6FZ1, DBGMCU_APB6_FZ_DBG_I2C4_STOP)
#define __HAL_DBGMCU_UNFREEZE_I2C4()         CLEAR_BIT(DBGMCU->APB6FZ1, DBGMCU_APB6_FZ_DBG_I2C4_STOP)
#endif
#if defined(DBGMCU_APB6_FZ_DBG_I2C5_STOP)
#define __HAL_DBGMCU_FREEZE_I2C5()           SET_BIT(DBGMCU->APB6FZ1, DBGMCU_APB6_FZ_DBG_I2C5_STOP)
#define __HAL_DBGMCU_UNFREEZE_I2C5()         CLEAR_BIT(DBGMCU->APB6FZ1, DBGMCU_APB6_FZ_DBG_I2C5_STOP)
#endif
#if defined(DBGMCU_APB6_FZ_DBG_TIM12_STOP)
#define __HAL_DBGMCU_FREEZE_TIM12()           SET_BIT(DBGMCU->APB6FZ1, DBGMCU_APB6_FZ_DBG_TIM12_STOP)
#define __HAL_DBGMCU_UNFREEZE_TIM12()         CLEAR_BIT(DBGMCU->APB6FZ1, DBGMCU_APB6_FZ_DBG_TIM12_STOP)
#endif
#if defined(DBGMCU_APB6_FZ_DBG_TIM13_STOP)
#define __HAL_DBGMCU_FREEZE_TIM13()           SET_BIT(DBGMCU->APB6FZ1, DBGMCU_APB6_FZ_DBG_TIM13_STOP)
#define __HAL_DBGMCU_UNFREEZE_TIM13()         CLEAR_BIT(DBGMCU->APB6FZ1, DBGMCU_APB6_FZ_DBG_TIM13_STOP)
#endif
#if defined(DBGMCU_APB6_FZ_DBG_TIM14_STOP)
#define __HAL_DBGMCU_FREEZE_TIM14()           SET_BIT(DBGMCU->APB6FZ1, DBGMCU_APB6_FZ_DBG_TIM14_STOP)
#define __HAL_DBGMCU_UNFREEZE_TIM14()         CLEAR_BIT(DBGMCU->APB6FZ1, DBGMCU_APB6_FZ_DBG_TIM14_STOP)
#endif
#if defined(DBGMCU_APB6_FZ_DBG_TIM15_STOP)
#define __HAL_DBGMCU_FREEZE_TIM15()           SET_BIT(DBGMCU->APB6FZ1, DBGMCU_APB6_FZ_DBG_TIM15_STOP)
#define __HAL_DBGMCU_UNFREEZE_TIM15()         CLEAR_BIT(DBGMCU->APB6FZ1, DBGMCU_APB6_FZ_DBG_TIM15_STOP)
#endif
#if defined(DBGMCU_APB6_FZ_DBG_TIM16_STOP)
#define __HAL_DBGMCU_FREEZE_TIM16()           SET_BIT(DBGMCU->APB6FZ1, DBGMCU_APB6_FZ_DBG_TIM16_STOP)
#define __HAL_DBGMCU_UNFREEZE_TIM16()         CLEAR_BIT(DBGMCU->APB6FZ1, DBGMCU_APB6_FZ_DBG_TIM16_STOP)
#endif
#if defined(DBGMCU_APB6_FZ_DBG_TIM17_STOP)
#define __HAL_DBGMCU_FREEZE_TIM17()           SET_BIT(DBGMCU->APB6FZ1, DBGMCU_APB6_FZ_DBG_TIM17_STOP)
#define __HAL_DBGMCU_UNFREEZE_TIM17()         CLEAR_BIT(DBGMCU->APB6FZ1, DBGMCU_APB6_FZ_DBG_TIM17_STOP)
#endif

/**
   * @}
   */

/** @defgroup HDP_Exported_Macros HDP Exported Macros
   * @{
   */

/** @addtogroup HDP_Enable
  * @{
  */
#define __HAL_HDP_ENABLE()                                         SET_BIT(HDP->HDP_CTRL, HDP_CTRL_EN)
/**
  * @}
  */



/** @addtogroup HDP_Configure_SW_Programmable_Signals
  * @{
  */

/** @brief  This macros allows atomic write of HDP_GPOVAL register
            It uses HDP_GPOSET and HDP_GPOCLR regsiters to toogle
  *
  * @param  __HDP_SW_Signal__: specifies the sw signal bit to be written.
  *          This parameter can be one of HDP_SW_SIGNAL_x(s) where x can be (0..7).
  * @param  __HDP_SwSignalState__: specifies the value to be written to the selected bit.
  *          This parameter can be one of the HDP_SwSignalState enum values:
  *            @arg HDP_SW_SIGNAL_RESET: to clear the signal pin
  *            @arg HDP_SW_SIGNAL_SET: to set the signal pin
  */
#define __HAL_HDP_ATOMIC_WRITE_GPOVAL(__HDP_SW_Signal__, __HDP_SwSignalState__)      \
                              do {                                                                 \
                                  if ((__HDP_SwSignalState__) != HDP_SW_SIGNAL_RESET)                                         \
                                  {                                                                \
                                    WRITE_REG(HDP->HDP_GPOSET, (uint8_t)(__HDP_SW_Signal__));            \
                                  }                                                                \
                                  else                                                             \
                                  {                                                                \
                                    WRITE_REG(HDP->HDP_GPOCLR, (uint8_t)(__HDP_SW_Signal__));            \
                                  }                                                                \
                              } while(0)

/** @brief  This macros allows non-atomic write of HDP_GPOVAL register
  *
  * @param __GPOValue__: specifies the value to set in HDP_GPOVAL register
  *
  */
#define __HAL_HDP_NON_ATOMIC_WRITE_GPOVAL(__GPOValue__)               WRITE_REG(HDP->HDP_GPOVAL, (uint8_t)(__GPOValue__))

/** @brief  This macros returns value of HDP_GPOVAL register
  *
  * @retval the value to set in HDP_GPOVAL register
  */
#define __HAL_HDP_READ_GPOVAL()                                    READ_REG(HDP->HDP_GPOVAL)

/**
  * @}
  */

/** @addtogroup HDP0_MUX0_Config
  * @{
  */
#define __HAL_HDP0_SELECT_PWR_PWRWAKE_SYS()                        MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX0, ((uint32_t) 0x00000000))
#define __HAL_HDP0_SELECT_PWR_STOP_FORBIDDEN()                     MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX0, ((uint32_t) HDP_MUX_MUX0_0))
#define __HAL_HDP0_SELECT_PWR_STDBY_WAKEUP()                       MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX0, ((uint32_t) HDP_MUX_MUX0_1))
#define __HAL_HDP0_SELECT_PWR_ENCOMP_VDDCORE()                     MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX0, ((uint32_t) HDP_MUX_MUX0_1 | HDP_MUX_MUX0_0))
#define __HAL_HDP0_SELECT_BSEC_OUT_SEC_NIDEN()                     MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX0, ((uint32_t) HDP_MUX_MUX0_2))
#define __HAL_HDP0_SELECT_EXTI_SYS_WAKEUP()                        MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX0, ((uint32_t) HDP_MUX_MUX0_2 | HDP_MUX_MUX0_0))
#define __HAL_HDP0_SELECT_DDRCTRL_IP_REQ()                         MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX0, ((uint32_t) HDP_MUX_MUX0_3))
#define __HAL_HDP0_SELECT_PWR_DDR_RET_ENABLE_N()                   MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX0, ((uint32_t) HDP_MUX_MUX0_3 | HDP_MUX_MUX0_0))
#define __HAL_HDP0_SELECT_DTS_CLK_PTAT()                           MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX0, ((uint32_t) HDP_MUX_MUX0_3 | HDP_MUX_MUX0_1))
#define __HAL_HDP0_SELECT_SRAM3CTRL_TAMP_ERASE_ACT()               MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX0, ((uint32_t) HDP_MUX_MUX0_3 | HDP_MUX_MUX0_2))
#define __HAL_HDP0_SELECT_GPOVAL_0()                               MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX0, ((uint32_t) HDP_MUX_MUX0_3 | HDP_MUX_MUX0_2 | HDP_MUX_MUX0_1 | HDP_MUX_MUX0_0))

/**
  * @}
  */

/** @addtogroup HDP1_MUX1_Config
  * @{
  */
#define __HAL_HDP1_SELECT_PWR_SEL_VTH_VDDCPU()                     MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX1, ((uint32_t) 0x00000000))
#define __HAL_HDP1_SELECT_PWR_MPU_RAM_LOWSPEED()                   MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX1, ((uint32_t) HDP_MUX_MUX1_0))
#define __HAL_HDP1_SELECT_CA7_nAXIERRIRQ()                         MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX1, ((uint32_t) HDP_MUX_MUX1_1))
#define __HAL_HDP1_SELECT_PWR_OKIN_MR()                            MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX1, ((uint32_t) HDP_MUX_MUX1_1 | HDP_MUX_MUX1_0))
#define __HAL_HDP1_SELECT_BSEC_OUT_SEC_DBGEN()                     MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX1, ((uint32_t) HDP_MUX_MUX1_2))
#define __HAL_HDP1_SELECT_EXTI_C1_WAKEUP()                         MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX1, ((uint32_t) HDP_MUX_MUX1_2 | HDP_MUX_MUX1_0))
#define __HAL_HDP1_SELECT_RCC_PWRDS_MPU()                          MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX1, ((uint32_t) HDP_MUX_MUX1_2 | HDP_MUX_MUX1_1))
#define __HAL_HDP1_SELECT_DDRCTRL_DFI_CTRLUPD_REQ()                MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX1, ((uint32_t) HDP_MUX_MUX1_3))
#define __HAL_HDP1_SELECT_DDRCTRL_CACTIVE_DDRC_ASR()               MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX1, ((uint32_t) HDP_MUX_MUX1_3 | HDP_MUX_MUX1_0))
#define __HAL_HDP1_SELECT_SRAM3CTRL_HW_ERASE_ACT()                 MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX1, ((uint32_t) HDP_MUX_MUX1_3 | HDP_MUX_MUX1_2))
#define __HAL_HDP1_SELECT_NIC400_S0_BREADY()                       MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX1, ((uint32_t) HDP_MUX_MUX1_3 | HDP_MUX_MUX1_2 | HDP_MUX_MUX1_0))
#define __HAL_HDP1_SELECT_GPOVAL_1()                               MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX1, ((uint32_t) HDP_MUX_MUX1_3 | HDP_MUX_MUX1_2 | HDP_MUX_MUX1_1 | HDP_MUX_MUX1_0))

/**
  * @}
  */

/** @addtogroup HDP2_MUX2_Config
  * @{
  */
#define __HAL_HDP2_SELECT_PWR_PWRWAKE_MPU()                        MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX2, ((uint32_t) 0x00000000))
#define __HAL_HDP2_SELECT_PWR_MPU_CLOCK_DISABLE_ACK()              MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX2, ((uint32_t) HDP_MUX_MUX2_0))
#define __HAL_HDP2_SELECT_CA7_nDBGRESET_i()                        MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX2, ((uint32_t) HDP_MUX_MUX2_1))
#define __HAL_HDP2_SELECT_BSEC_IN_RSTCORE_n()                      MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX2, ((uint32_t) HDP_MUX_MUX2_2))
#define __HAL_HDP2_SELECT_BSEC_OUT_SEC_BSC_DIS()                   MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX2, ((uint32_t) HDP_MUX_MUX2_2 | HDP_MUX_MUX2_0))
#define __HAL_HDP2_SELECT_DDRCTRL_DFI_INIT_COMPLETE()              MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX2, ((uint32_t) HDP_MUX_MUX2_3))
#define __HAL_HDP2_SELECT_DDRCTRL_PERF_OP_IS_REFRESH()             MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX2, ((uint32_t) HDP_MUX_MUX2_3 | HDP_MUX_MUX2_0))
#define __HAL_HDP2_SELECT_DDRCTRL_GSKP_DFI_LP_REQ()                MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX2, ((uint32_t) HDP_MUX_MUX2_3 | HDP_MUX_MUX2_1))
#define __HAL_HDP2_SELECT_SRAM3CTRL_SW_ERASE_ACT()                 MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX2, ((uint32_t) HDP_MUX_MUX2_3 | HDP_MUX_MUX2_2))
#define __HAL_HDP2_SELECT_NIC400_S0_BVALID()                       MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX2, ((uint32_t) HDP_MUX_MUX2_3 | HDP_MUX_MUX2_2 | HDP_MUX_MUX2_0))
#define __HAL_HDP2_SELECT_GPOVAL_2()                               MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX2, ((uint32_t) HDP_MUX_MUX2_3 | HDP_MUX_MUX2_2 | HDP_MUX_MUX2_1 | HDP_MUX_MUX2_0))

/**
  * @}
  */

/** @addtogroup HDP3_MUX3_Config
  * @{
  */
#define __HAL_HDP3_SELECT_PWR_SEL_VTH_VDDCORE()                    MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX3, ((uint32_t) 0x00000000))
#define __HAL_HDP3_SELECT_PWR_MPU_CLOCK_DISABLE_REQ()              MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX3, ((uint32_t) HDP_MUX_MUX3_0))
#define __HAL_HDP3_SELECT_CA7_nPMUIRQ0()                           MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX3, ((uint32_t) HDP_MUX_MUX3_1))
#define __HAL_HDP3_SELECT_CA7_nFIQOUT0()                           MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX3, ((uint32_t) HDP_MUX_MUX3_1 | HDP_MUX_MUX3_0))
#define __HAL_HDP3_SELECT_BSEC_OUT_SEC_DFTLOCK()                   MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX3, ((uint32_t) HDP_MUX_MUX3_2))
#define __HAL_HDP3_SELECT_BSEC_OUT_SEC_JTAG_DIS()                  MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX3, ((uint32_t) HDP_MUX_MUX3_2 | HDP_MUX_MUX3_0 ))
#define __HAL_HDP3_SELECT_RCC_PWRDS_SYS()                          MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX3, ((uint32_t) HDP_MUX_MUX3_2 | HDP_MUX_MUX3_1))
#define __HAL_HDP3_SELECT_SRAM3CTRL_TAMP_ERASE_REQ()               MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX3, ((uint32_t) HDP_MUX_MUX3_2 | HDP_MUX_MUX3_1 | HDP_MUX_MUX3_0))
#define __HAL_HDP3_SELECT_DDRCTRL_STAT_DDRC_REG_SELREF_TYPE_0()    MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX3, ((uint32_t) HDP_MUX_MUX3_3))
#define __HAL_HDP3_SELECT_DTS_VALOBUS1_0()                         MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX3, ((uint32_t) HDP_MUX_MUX3_3 | HDP_MUX_MUX3_1))
#define __HAL_HDP3_SELECT_DTS_VALOBUS2_0()                         MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX3, ((uint32_t) HDP_MUX_MUX3_3 | HDP_MUX_MUX3_1 | HDP_MUX_MUX3_0))
#define __HAL_HDP3_SELECT_TAMP_POTENTIAL_TAMP_ERFCFG()             MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX3, ((uint32_t) HDP_MUX_MUX3_3 | HDP_MUX_MUX3_2))
#define __HAL_HDP3_SELECT_NIC400_S0_WREADY()                       MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX3, ((uint32_t) HDP_MUX_MUX3_3 | HDP_MUX_MUX3_2 | HDP_MUX_MUX3_0))
#define __HAL_HDP3_SELECT_NIC400_S0_RREADY()                       MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX3, ((uint32_t) HDP_MUX_MUX3_3 | HDP_MUX_MUX3_2 | HDP_MUX_MUX3_1))
#define __HAL_HDP3_SELECT_GPOVAL_3()                               MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX3, ((uint32_t) HDP_MUX_MUX3_3 | HDP_MUX_MUX3_2 | HDP_MUX_MUX3_1 | HDP_MUX_MUX3_0))

/**
  * @}
  */

/** @addtogroup HDP4_MUX4_Config
  * @{
  */
#define __HAL_HDP4_SELECT_PWR_STOP2_ACTIVE()                       MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX4, ((uint32_t) HDP_MUX_MUX4_0))
#define __HAL_HDP4_SELECT_CA7_nl2RESET_i()                         MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX4, ((uint32_t) HDP_MUX_MUX4_1))
#define __HAL_HDP4_SELECT_CA7_nPORESET_VARM_i()                    MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX4, ((uint32_t) HDP_MUX_MUX4_1 | HDP_MUX_MUX4_0))
#define __HAL_HDP4_SELECT_BSEC_OUT_SEC_DFTEN()                     MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX4, ((uint32_t) HDP_MUX_MUX4_2))
#define __HAL_HDP4_SELECT_BSEC_OUT_SEC_DBGSWENABLE()               MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX4, ((uint32_t) HDP_MUX_MUX4_2 | HDP_MUX_MUX4_0))
#define __HAL_HDP4_SELECT_ETH1_OUT_PMT_INTR_0()                    MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX4, ((uint32_t) HDP_MUX_MUX4_2 | HDP_MUX_MUX4_1))
#define __HAL_HDP4_SELECT_ETH2_OUT_PMT_INTR_0()                    MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX4, ((uint32_t) HDP_MUX_MUX4_2 | HDP_MUX_MUX4_1 | HDP_MUX_MUX4_0))
#define __HAL_HDP4_SELECT_DDRCTRL_STAT_DDRC_REG_SELREF_TYPE_1()    MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX4, ((uint32_t) HDP_MUX_MUX4_3))
#define __HAL_HDP4_SELECT_DDRCTRL_CACTIVE_0()                      MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX4, ((uint32_t) HDP_MUX_MUX4_3 | HDP_MUX_MUX4_0))
#define __HAL_HDP4_SELECT_DTS_VALOBUS1_1()                         MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX4, ((uint32_t) HDP_MUX_MUX4_3 | HDP_MUX_MUX4_1))
#define __HAL_HDP4_SELECT_DTS_VALOBUS2_1()                         MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX4, ((uint32_t) HDP_MUX_MUX4_3 | HDP_MUX_MUX4_1 | HDP_MUX_MUX4_0))
#define __HAL_HDP4_SELECT_TAMP_nRESET_SRAM_ERFCFG()                MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX4, ((uint32_t) HDP_MUX_MUX4_3 | HDP_MUX_MUX4_2))
#define __HAL_HDP4_SELECT_NIC400_S0_WLAST()                        MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX4, ((uint32_t) HDP_MUX_MUX4_3 | HDP_MUX_MUX4_2 | HDP_MUX_MUX4_0))
#define __HAL_HDP4_SELECT_NIC400_S0_RLAST()                        MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX4, ((uint32_t) HDP_MUX_MUX4_3 | HDP_MUX_MUX4_2 | HDP_MUX_MUX4_1))
#define __HAL_HDP4_SELECT_GPOVAL_4()                               MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX4, ((uint32_t) HDP_MUX_MUX4_3 | HDP_MUX_MUX4_2 | HDP_MUX_MUX4_1 | HDP_MUX_MUX4_0))

/**
  * @}
  */

/** @addtogroup HDP5_MUX5_Config
  * @{
  */
#define __HAL_HDP5_SELECT_CA7_STANDBYWFIL2()                       MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX5, ((uint32_t) 0x00000000))
#define __HAL_HDP5_SELECT_PWR_VTH_VDDCORE_ACK()                    MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX5, ((uint32_t) HDP_MUX_MUX5_0))
#define __HAL_HDP5_SELECT_CA7_nCORERESET_i()                       MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX5, ((uint32_t) HDP_MUX_MUX5_1))
#define __HAL_HDP5_SELECT_CA7_nIRQOUT0()                           MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX5, ((uint32_t) HDP_MUX_MUX5_1 | HDP_MUX_MUX5_0))
#define __HAL_HDP5_SELECT_BSEC_IN_PWROK()                          MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX5, ((uint32_t) HDP_MUX_MUX5_2))
#define __HAL_HDP5_SELECT_BSEC_OUT_SEC_DEVICEEN()                  MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX5, ((uint32_t) HDP_MUX_MUX5_2 | HDP_MUX_MUX5_0))
#define __HAL_HDP5_SELECT_ETH1_OUT_LPI_INTR_0()                    MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX5, ((uint32_t) HDP_MUX_MUX5_2 | HDP_MUX_MUX5_1))
#define __HAL_HDP5_SELECT_ETH2_OUT_LPI_INTR_0()                    MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX5, ((uint32_t) HDP_MUX_MUX5_2 | HDP_MUX_MUX5_1 | HDP_MUX_MUX5_0))
#define __HAL_HDP5_SELECT_DDRCTRL_CACTIVE_DDRC()                   MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX5, ((uint32_t) HDP_MUX_MUX5_3))
#define __HAL_HDP5_SELECT_DDRCTRL_WR_CREDIT_CNT_4_0()              MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX5, ((uint32_t) HDP_MUX_MUX5_3 | HDP_MUX_MUX5_0))
#define __HAL_HDP5_SELECT_DTS_VALOBUS1_2()                         MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX5, ((uint32_t) HDP_MUX_MUX5_3 | HDP_MUX_MUX5_1))
#define __HAL_HDP5_SELECT_DTS_VALOBUS2_2()                         MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX5, ((uint32_t) HDP_MUX_MUX5_3 | HDP_MUX_MUX5_1 | HDP_MUX_MUX5_0))
#define __HAL_HDP5_SELECT_PKA_iTAMP_OUT()                          MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX5, ((uint32_t) HDP_MUX_MUX5_3 | HDP_MUX_MUX5_2))
#define __HAL_HDP5_SELECT_NIC400_S0_WVALID()                       MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX5, ((uint32_t) HDP_MUX_MUX5_3 | HDP_MUX_MUX5_2 | HDP_MUX_MUX5_0))
#define __HAL_HDP5_SELECT_NIC400_S0_RVALID()                       MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX5, ((uint32_t) HDP_MUX_MUX5_3 | HDP_MUX_MUX5_2 | HDP_MUX_MUX5_1))
#define __HAL_HDP5_SELECT_GPOVAL_5()                               MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX5, ((uint32_t) HDP_MUX_MUX5_3 | HDP_MUX_MUX5_2 | HDP_MUX_MUX5_1 | HDP_MUX_MUX5_0))
/**
  * @}
  */

/** @addtogroup HDP6_MUX6_Config
  * @{
  */
#define __HAL_HDP6_SELECT_CA7_STANDBYWFE0()                        MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX6, ((uint32_t) 0x00000000))
#define __HAL_HDP6_SELECT_PWR_VTH_VDDCPU_ACK()                     MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX6, ((uint32_t) HDP_MUX_MUX6_0))
#define __HAL_HDP6_SELECT_CA7_EVENTO()                             MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX6, ((uint32_t) HDP_MUX_MUX6_1))
#define __HAL_HDP6_SELECT_BSEC_IN_TAMPER_DET()                     MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX6, ((uint32_t) HDP_MUX_MUX6_2))
#define __HAL_HDP6_SELECT_BSEC_OUT_SEC_SPNIDEN()                   MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX6, ((uint32_t) HDP_MUX_MUX6_2 | HDP_MUX_MUX6_0))
#define __HAL_HDP6_SELECT_ETH1_OUT_MAC_SPEED_O1()                  MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX6, ((uint32_t) HDP_MUX_MUX6_2 | HDP_MUX_MUX6_1))
#define __HAL_HDP6_SELECT_ETH2_OUT_MAC_SPEED_O1()                  MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX6, ((uint32_t) HDP_MUX_MUX6_2 | HDP_MUX_MUX6_1 | HDP_MUX_MUX6_0))
#define __HAL_HDP6_SELECT_DDRCTRL_CSYSACK_DDRC()                   MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX6, ((uint32_t) HDP_MUX_MUX6_3))
#define __HAL_HDP6_SELECT_DDRCTRL_LPR_CREDIT_CNT_4_0()             MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX6, ((uint32_t) HDP_MUX_MUX6_3 | HDP_MUX_MUX6_0))
#define __HAL_HDP6_SELECT_DTS_VALOBUS1_3()                         MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX6, ((uint32_t) HDP_MUX_MUX6_3 | HDP_MUX_MUX6_1))
#define __HAL_HDP6_SELECT_DTS_VALOBUS2_3()                         MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX6, ((uint32_t) HDP_MUX_MUX6_3 | HDP_MUX_MUX6_1 | HDP_MUX_MUX6_0))
#define __HAL_HDP6_SELECT_SAES_TAMPER_OUT()                        MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX6, ((uint32_t) HDP_MUX_MUX6_3 | HDP_MUX_MUX6_2))
#define __HAL_HDP6_SELECT_NIC400_S0_AWREADY()                      MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX6, ((uint32_t) HDP_MUX_MUX6_3 | HDP_MUX_MUX6_2 | HDP_MUX_MUX6_0))
#define __HAL_HDP6_SELECT_NIC400_S0_ARREADY()                      MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX6, ((uint32_t) HDP_MUX_MUX6_3 | HDP_MUX_MUX6_2 | HDP_MUX_MUX6_1))
#define __HAL_HDP6_SELECT_GPOVAL_6()                               MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX6, ((uint32_t) HDP_MUX_MUX6_3 | HDP_MUX_MUX6_2 | HDP_MUX_MUX6_1 | HDP_MUX_MUX6_0))

/**
  * @}
  */

/** @addtogroup HDP7_MUX7_Config
  * @{
  */
#define __HAL_HDP7_SELECT_CA7_STANDBYWFI0()                        MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX7, ((uint32_t) 0x00000000))
#define __HAL_HDP7_SELECT_PWR_RCC_VCPU_RDY()                       MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX7, ((uint32_t) HDP_MUX_MUX7_0))
#define __HAL_HDP7_SELECT_CA7_EVENTI()                             MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX7, ((uint32_t) HDP_MUX_MUX7_1))
#define __HAL_HDP7_SELECT_CA7_DBGACK0()                            MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX7, ((uint32_t) HDP_MUX_MUX7_1 | HDP_MUX_MUX7_0))
#define __HAL_HDP7_SELECT_BSEC_OUT_FUSE_OK()                       MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX7, ((uint32_t) HDP_MUX_MUX7_2))
#define __HAL_HDP7_SELECT_BSEC_OUT_SEC_SPIDEN()                    MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX7, ((uint32_t) HDP_MUX_MUX7_2 | HDP_MUX_MUX7_0))
#define __HAL_HDP7_SELECT_ETH1_OUT_MAC_SPEED_O0()                  MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX7, ((uint32_t) HDP_MUX_MUX7_2 | HDP_MUX_MUX7_1))
#define __HAL_HDP7_SELECT_ETH2_OUT_MAC_SPEED_O0()                  MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX7, ((uint32_t) HDP_MUX_MUX7_2 | HDP_MUX_MUX7_1 | HDP_MUX_MUX7_0))
#define __HAL_HDP7_SELECT_DDRCTRL_CSYSREQ_DDRC()                   MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX7, ((uint32_t) HDP_MUX_MUX7_3))
#define __HAL_HDP7_SELECT_DDRCTRL_HPR_CREDIT_CNT_4_0()             MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX7, ((uint32_t) HDP_MUX_MUX7_3 | HDP_MUX_MUX7_0))
#define __HAL_HDP7_SELECT_DTS_VALOBUS1_4()                         MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX7, ((uint32_t) HDP_MUX_MUX7_3 | HDP_MUX_MUX7_1))
#define __HAL_HDP7_SELECT_DTS_VALOBUS2_4()                         MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX7, ((uint32_t) HDP_MUX_MUX7_3 | HDP_MUX_MUX7_1 | HDP_MUX_MUX7_0))
#define __HAL_HDP7_SELECT_RNG_TAMPER_OUT()                         MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX7, ((uint32_t) HDP_MUX_MUX7_3 | HDP_MUX_MUX7_2))
#define __HAL_HDP7_SELECT_NIC400_S0_AWAVALID()                     MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX7, ((uint32_t) HDP_MUX_MUX7_3 | HDP_MUX_MUX7_2 | HDP_MUX_MUX7_0))
#define __HAL_HDP7_SELECT_NIC400_S0_ARAVALID()                     MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX7, ((uint32_t) HDP_MUX_MUX7_3 | HDP_MUX_MUX7_2 | HDP_MUX_MUX7_1))
#define __HAL_HDP7_SELECT_GPOVAL_7()                               MODIFY_REG(HDP->HDP_MUX, HDP_MUX_MUX7, ((uint32_t) HDP_MUX_MUX7_3 | HDP_MUX_MUX7_2 | HDP_MUX_MUX7_1 | HDP_MUX_MUX7_0))
/**
  * @}
  */

/**
  * @}
  */


/** @defgroup HAL_Private_Macros HAL Private Macros
  * @{
  */
#define IS_TICKFREQ(FREQ) (((FREQ) == HAL_TICK_FREQ_10HZ)  || \
                           ((FREQ) == HAL_TICK_FREQ_100HZ) || \
                           ((FREQ) == HAL_TICK_FREQ_1KHZ))
/**
  * @}
  */

/* Exported variables --------------------------------------------------------*/

/** @addtogroup HAL_Exported_Variables
  * @{
  */
extern __IO uint32_t uwTick;
extern uint32_t uwTickPrio;
extern HAL_TickFreqTypeDef uwTickFreq;
/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @defgroup HAL_Exported_Functions HAL Exported Functions
  * @{
  */

/* Initialization and de-initialization functions  ******************************/
/** @defgroup HAL_Exported_Functions_Group1 Initialization and de-initialization functions
  * @{
  */
HAL_StatusTypeDef HAL_Init(void);
HAL_StatusTypeDef HAL_DeInit(void);
void HAL_MspInit(void);
void HAL_MspDeInit(void);
HAL_StatusTypeDef HAL_InitTick(uint32_t TickPriority);

/**
  * @}
  */

/* Peripheral Control functions  ************************************************/
/** @defgroup HAL_Exported_Functions_Group2 Peripheral Control functions
  * @{
  */
void HAL_IncTick(void);
void HAL_Delay(uint32_t Delay);
uint32_t HAL_GetTick(void);
uint32_t HAL_GetTickPrio(void);
HAL_StatusTypeDef HAL_SetTickFreq(HAL_TickFreqTypeDef Freq);
HAL_TickFreqTypeDef HAL_GetTickFreq(void);
void HAL_SuspendTick(void);
void HAL_ResumeTick(void);
uint32_t HAL_GetHalVersion(void);
uint32_t HAL_GetREVID(void);
uint32_t HAL_GetDEVID(void);
uint32_t HAL_GetUIDw0(void);
uint32_t HAL_GetUIDw1(void);
uint32_t HAL_GetUIDw2(void);
void HAL_SYSCFG_ETHInterfaceSelect(uint32_t SYSCFG_ETHInterface);
void HAL_SYSCFG_EnableBOOST(void);
void HAL_SYSCFG_DisableBOOST(void);
void HAL_EnableCompensationCell(void);
void HAL_DisableCompensationCell(void);
void HAL_SYSCFG_EnableIOSpeedOptimize(uint32_t SYSCFG_HighSpeedSignal);
void HAL_SYSCFG_DisableIOSpeedOptimize(uint32_t SYSCFG_HighSpeedSignal);
void HAL_SYSCFG_EnableCompensationCell(uint32_t CompCells);
void HAL_SYSCFG_DisableCompensationCell(uint32_t CompCells);
void HAL_SYSCFG_CompensationCodeSelect(uint32_t CompCells, uint32_t SYSCFG_CompCode);
void HAL_SYSCFG_CompensationCodeConfig(uint32_t CompCell, uint32_t SYSCFG_PMOSCode, uint32_t SYSCFG_NMOSCode);
HAL_StatusTypeDef HAL_SYSCFG_EnableIOCompensation(uint32_t CompCells);
void HAL_SYSCFG_DisableIOCompensation(uint32_t CompCells);
void HAL_EnableDBGLPMode(void);
void HAL_DisableDBGLPMode(void);
void HAL_EnableDBGWakeUp(void);
void HAL_DisableDBGWakeUp(void);
void HAL_SYSCFG_VREFBUF_VoltageScalingConfig(uint32_t VoltageScaling);
void HAL_SYSCFG_VREFBUF_HighImpedanceConfig(uint32_t Mode);
void HAL_SYSCFG_VREFBUF_TrimmingConfig(uint32_t TrimmingValue);
HAL_StatusTypeDef HAL_SYSCFG_EnableVREFBUF(void);
void HAL_SYSCFG_DisableVREFBUF(void);

/**
 * @}
 */

/**
 * @}
 */

/**
 * @}
 */

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif /* STM32MP13xx_HAL_H */
