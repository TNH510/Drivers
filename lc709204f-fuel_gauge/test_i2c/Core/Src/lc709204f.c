/**
 * @file       lc709204f.c
 * @copyright  Copyright (C) 2020 ITR VN. All rights reserved.
 * @license    This project is released under the ITR License.
 * @version    01.00.00
 * @date       2020-09-21
 * @author     Hieu Tran Ngoc
 * @brief      Driver for LC709204F (Fuel gauge)
 * @note       None
 * @example    None
 */

/* Public includes ---------------------------------------------------------- */
#include "lc709204f.h"

/* Private includes --------------------------------------------------------- */
/* Private defines ---------------------------------------------------------- */

/* Private enumerate/structure ---------------------------------------------- */
/* Private macros ----------------------------------------------------------- */
/* Public variables --------------------------------------------------------- */
/* Private variables -------------------------------------------------------- */

/* Private prototypes ------------------------------------------------------- */

/* Public implementations --------------------------------------------------- */
base_status_t lc709204f_init(lc709204f_t *lc709204f)
{
  /* Write 0xZZZZ to reg 0x0B (Write APA) */

  /* Write 0x000Z to reg 0x12 (Write change of the parameter) */

  /* Write 0x00ZZ to reg 0x1C (Write termination current rate) */

  /* Write 0xZZZZ to reg 0x1D (Write empty cell voltage) */

  /* Write alarm thresholds to 0x13, 0x14, 0x1F-0x21 */

  /* Write 0x0001 to reg 0x15 (Write IC power mode, set operational mode) */

  /* Write 0x0000 to reg 0x19, reset initialaized bit (Write battery status) */

  return BS_OK;
}

base_status_t lc709204f_sleep(lc709204f_t *lc709204f)
{
  /* Value in sleep mode */
  return lc709204f_write_reg(lc709204f, LC709204F_REG_IC_POWERMODE, 0x0002);
}

base_status_t lc709204f_operate(lc709204f_t *lc709204f)
{
  /* Value in operational mode */
  return lc709204f_write_reg(lc709204f, LC709204F_REG_IC_POWERMODE, 0x0001);
}

base_status_t lc709204f_get_cell_voltage(lc709204f_t *lc709204f, float *cell_voltage)
{
  /* 0x09C4 -> 0x1388 (2500 -> 5000) */
  /* 2.5V -> 5V */
  uint16_t value;
  lc709204f_read_reg(lc709204f, LC709204F_REG_CELL_VOLTAGE, &value);
  *cell_voltage = value / 1000.0;  // Voltage

  return BS_OK;
}
base_status_t lc709204f_get_rsoc(lc709204f_t *lc709204f, uint8_t *rsoc)
{
  /* 0x00 -> 0x64 (0 -> 100)*/
  /* 0% --> 100% */
  uint16_t value;
  lc709204f_read_reg(lc709204f, LC709204F_REG_RSOC, &value);
  *rsoc = value;  // Percent

  return BS_OK;
}

base_status_t lc709204f_get_ite(lc709204f_t *lc709204f);
base_status_t lc709204f_get_battery_status(lc709204f_t *lc709204f);
base_status_t lc709204f_clear_battery_status(lc709204f_t *lc709204f);
base_status_t lc709204f_get_time_to_empty(lc709204f_t *lc709204f);
base_status_t lc709204f_get_state_of_health(lc709204f_t *lc709204f);
base_status_t lc709204f_set_cell_temperature(lc709204f_t *lc709204f);
base_status_t lc709204f_get_cell_temperature(lc709204f_t *lc709204f);
/* Private implementations -------------------------------------------------- */
base_status_t lc709204f_write_reg(lc709204f_t *lc709204f, uint8_t reg_address, uint16_t data)
{
  uint8_t send_buffer[2];
  /* Byte low */
  send_buffer[0] = data & 0xFF;

  /* Byte high */
  send_buffer[1] = (data >> 8) & 0xFF;

  /* Send data */
  lc709204f->i2c_write_at(LC709204F_ADDRESS_7_BITS, reg_address, send_buffer, 2);
  return BS_OK;
}

base_status_t lc709204f_read_reg(lc709204f_t *lc709204f, uint8_t reg_address, uint16_t *data)
{
  uint8_t receive_buffer[2];

  /* Receive data */
  lc709204f->i2c_read_at(LC709204F_ADDRESS_7_BITS, reg_address, receive_buffer, 2);
  *data = (receive_buffer[0] & 0x00FF) | ((receive_buffer[1] << 8) & 0xFF00);

  return BS_OK;
}
/* End of file -------------------------------------------------------------- */
