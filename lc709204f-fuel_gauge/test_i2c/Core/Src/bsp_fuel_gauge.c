/**
 * @file       bsp_fuel_gauge.c
 * @copyright  Copyright (C) 2020 ITR VN. All rights reserved.
 * @license    This project is released under the ITR License.
 * @version    01.00.00
 * @date       2020-09-22
 * @author     Hieu Tran Ngoc
 * @brief      Board Support Package for Fuel Gauge
 * @note       None
 * @example    None
 */

/* Public includes ---------------------------------------------------------- */
#include "bsp_fuel_gauge.h"
#include "bsp_i2c.h"
/* Private includes --------------------------------------------------------- */
/* Private defines ---------------------------------------------------------- */
/* Private enumerate/structure ---------------------------------------------- */
/* Private macros ----------------------------------------------------------- */
/* Public variables --------------------------------------------------------- */
/* Private variables -------------------------------------------------------- */

static lc709204f_t lc709204f = { .i2c_write_at = bsp_i2c1_write_mem, .i2c_read_at = bsp_i2c1_read_mem };

// static fuel_gauge_interrupt_callback_t fuel_gauge_callback = NULL;

/* Private prototypes ------------------------------------------------------- */

// static void bsp_imu_gpio_init(void);
// static void bsp_imu_interrupt_callback(void);

/* Public implementations --------------------------------------------------- */
base_status_t fuel_gauge_write_reg(uint8_t reg_address, uint16_t data)
{
  return lc709204f_write_reg(&lc709204f, reg_address, data);
}

base_status_t fuel_gauge_read_reg(uint8_t reg_address, uint16_t *data)
{
  return lc709204f_read_reg(&lc709204f, reg_address, data);
}
/* Private implementations -------------------------------------------------- */

// static void bsp_fuel_gauge_interrupt_callback(void)
// {
//   // // Clears the triggered pin interrupt
//   // Cy_GPIO_ClearInterrupt(IMU_INTERRUPT_PORT, IMU_INTERRUPT_NUM);
//   // NVIC_ClearPendingIRQ(imu_interrupt_1_cfg.intrSrc);

//   // fuel_gauge_callback();
// }

/* End of file -------------------------------------------------------------- */