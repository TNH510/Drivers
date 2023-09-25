/**
 * @file       bsp_fuel_gauge.h
 * @copyright  Copyright (C) 2020 ITR VN. All rights reserved.
 * @license    This project is released under the ITR License.
 * @version    01.00.00
 * @date       2020-09-22
 * @author     Hieu Tran Ngoc
 * @brief      Board Support Package for Fuel Gauge
 * @note       None
 * @example    None
 */

/* Define to prevent recursive inclusion ------------------------------------ */
#ifndef __BSP_FUEL_GAUGE_H
#define __BSP_FUEL_GAUGE_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ----------------------------------------------------------------- */
#include "base_type.h"
#include "lc709204f.h"

/* Public defines ----------------------------------------------------------- */

/* Public enumerate/structure ----------------------------------------------- */
/* Public macros ------------------------------------------------------------ */
/* Public variables --------------------------------------------------------- */
/* Public APIs -------------------------------------------------------------- */
base_status_t fuel_gauge_write_reg(uint8_t reg_address, uint16_t data);
base_status_t fuel_gauge_read_reg(uint8_t reg_address, uint16_t *data);

/* -------------------------------------------------------------------------- */
#ifdef __cplusplus
} /* extern "C" { */
#endif

#endif /* __BSP_FUEL_GAUGE_H */

/* End of file -------------------------------------------------------------- */
