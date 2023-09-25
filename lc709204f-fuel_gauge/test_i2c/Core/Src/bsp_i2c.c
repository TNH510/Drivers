/**
 * @file       bsp_i2c.c
 * @copyright  Copyright (C) 2019 Fiot Co., Ltd. All rights reserved.
 * @license    This project is released under the QuyLe License.
 * @version    1.0.0
 * @date       2023-08-19
 * @author     quyle-itr-intern
 *
 * @brief      handle i2c
 *
 * @note
 */

/* Includes ----------------------------------------------------------- */
#include "bsp_i2c.h"

/* Private defines ---------------------------------------------------- */
#define BSP_I2C_TIMEOUT     100

/* Private enumerate/structure ---------------------------------------- */

#if BSP_I2C1 == 1
extern I2C_HandleTypeDef hi2c1;
#endif

/* Private macros ----------------------------------------------------- */

/* Public variables --------------------------------------------------- */

/* Private variables -------------------------------------------------- */

/* Private function prototypes ---------------------------------------- */

/* Function definitions ----------------------------------------------- */
bool bsp_i2c1_is_device_ready(uint8_t address_device)
{
  return (HAL_I2C_IsDeviceReady(&hi2c1, address_device, 5, BSP_I2C_TIMEOUT) == HAL_ERROR) ? false : true;
}

bool bsp_i2c1_is_busy()
{
  return (HAL_I2C_GetState(&hi2c1) == HAL_I2C_STATE_BUSY) ? false : true;
}

bool bsp_i2c1_write_mem(uint8_t address_slave, uint8_t reg_write, uint8_t *data_write, uint16_t size_data)
{
  /* Get status bus I2C */
  if (HAL_I2C_GetState(&hi2c1) == HAL_I2C_STATE_BUSY)
    return false;
  /* Transmit data */
  if (HAL_I2C_Mem_Write(&hi2c1, address_slave, reg_write, I2C_MEMADD_SIZE_8BIT, data_write, size_data, BSP_I2C_TIMEOUT) == HAL_ERROR)
    return false;
  return true;
}

bool bsp_i2c1_read_mem(uint8_t address_slave, uint8_t reg_read, uint8_t *data_read, uint16_t size_data)
{
  /* Get status bus I2C */
  if (HAL_I2C_GetState(&hi2c1) == HAL_I2C_STATE_BUSY)
    return false;
  /* Transmit data */
  if (HAL_I2C_Mem_Read(&hi2c1, address_slave, reg_read, I2C_MEMADD_SIZE_8BIT, data_read, size_data, BSP_I2C_TIMEOUT) != HAL_OK)
    return false;
  return true;
}

/* End of file -------------------------------------------------------- */
