/**
 * @file       lc709204f.h
 * @copyright  Copyright (C) 2020 ITR VN. All rights reserved.
 * @license    This project is released under the ITR License.
 * @version    01.00.00
 * @date       2020-09-21
 * @author     Hieu Tran Ngoc
 * @brief      Driver for LC709204F (Fuel gauge)
 * @note       None
 * @example    None
 */

/* Define to prevent recursive inclusion ------------------------------------ */
#ifndef __LC709204F_H
#define __LC709204F_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ----------------------------------------------------------------- */
#include "base_type.h"
#include "lc709204f_regs.h"

/* Public defines ----------------------------------------------------------- */
#define CHECK_STATUS(expr)              \
  do {                                  \
    base_status_t ret = (expr);         \
    if (BS_OK != ret) {                 \
      return (ret);                     \
    }                                   \
  } while (0)
/* Public enumerate/structure ----------------------------------------------- */
/**
 * @brief LC709204F struct
 */
typedef struct
{
  // Function pointers ---------------------------------------------------------
  base_status_t (*i2c_read_at)(uint8_t device_address, uint8_t reg_read, uint8_t *data_read, uint16_t size_data);
  base_status_t (*i2c_write_at)(uint8_t device_address, uint8_t reg_write, uint8_t *data_write, uint16_t size_data);
}
lc709204f_t;
/* Public macros ------------------------------------------------------------ */
/* Public variables --------------------------------------------------------- */
/* Public APIs -------------------------------------------------------------- */
/**
 * @brief Write lc709204f register
 *
 * @param lc709204f       lc709204f object
 * @param reg_address     Register Address
 * @param data            Write data
 * @return base_status_t  Status of function
 */
base_status_t lc709204f_write_reg(lc709204f_t *lc709204f, uint8_t reg_address, uint16_t data);

/**
 * @brief Read lc709204f register
 *
 * @param lc709204f       lc709204f object
 * @param reg_address     Register Address
 * @param data            Pointer to variable contain read data
 * @return base_status_t  Status of function
 */
base_status_t lc709204f_read_reg(lc709204f_t *lc709204f, uint8_t reg_address, uint16_t *data);

/**
 * @brief Initialize lc709204f driver
 * 
 * @param lc709204f       lc709204f object
 * @return base_status_t  Status of function
 */
base_status_t lc709204f_init(lc709204f_t *lc709204f);

/**
 * @brief Set lc709204f to sleep mode
 * 
 * @param lc709204f       lc709204f object
 * @return base_status_t  Status of function
 */
base_status_t lc709204f_sleep(lc709204f_t *lc709204f);

/**
 * @brief Set lc709204f to operate mode
 * 
 * @param lc709204f       lc709204f object
 * @return base_status_t  Status of function
 */
base_status_t lc709204f_operate(lc709204f_t *lc709204f);

/**
 * @brief Get cell voltage value
 * 
 * @param lc709204f       lc709204f object
 * @param cell_voltage    Pointer to variable contain voltage value (2.5V -> 5V)
 * @return base_status_t  Status of function
 */
base_status_t lc709204f_get_cell_voltage(lc709204f_t *lc709204f, float *cell_voltage);

/**
 * @brief Get RSOC value
 * 
 * @param lc709204f       lc709204f object
 * @param rsoc            Pointer to variable contain rsoc value (0% -> 100%)
 * @return base_status_t  Status of function
 */
base_status_t lc709204f_get_rsoc(lc709204f_t *lc709204f, uint8_t *rsoc);
base_status_t lc709204f_get_ite(lc709204f_t *lc709204f);
base_status_t lc709204f_get_battery_status(lc709204f_t *lc709204f);
base_status_t lc709204f_clear_battery_status(lc709204f_t *lc709204f);
base_status_t lc709204f_get_time_to_empty(lc709204f_t *lc709204f);
base_status_t lc709204f_get_state_of_health(lc709204f_t *lc709204f);
base_status_t lc709204f_set_cell_temperature(lc709204f_t *lc709204f);
base_status_t lc709204f_get_cell_temperature(lc709204f_t *lc709204f);
/* -------------------------------------------------------------------------- */
#ifdef __cplusplus
} /* extern "C" { */
#endif

#endif /* __LC709204F_H */

/* End of file -------------------------------------------------------------- */