/**
 * @file       lc709204f_regs.h
 * @copyright  Copyright (C) 2020 ITR VN. All rights reserved.
 * @license    This project is released under the ITR License.
 * @version    01.00.00
 * @date       2020-09-21
 * @author     Hieu Tran Ngoc
 * @brief      Registers of LC709204F (Fuel gauge)
 * @note       None
 * @example    None
 */

/* Define to prevent recursive inclusion ------------------------------------ */
#ifndef __LC709204F_REGS_H
#define __LC709204F_REGS_H

#ifdef __cplusplus
extern "C"
{
#endif

/* Includes ----------------------------------------------------------------- */
#include "base_type.h"
/* Public defines ----------------------------------------------------------- */
/* LC709204F Registers */
#define LC709204F_REG_TIME_TO_EMPTY         0x03
#define LC709204F_REG_BEFORE_RSOC           0x04
#define LC709204F_REG_TIME_TO_FULL          0x05
#define LC709204F_REG_TSENSE1_THERMB        0x06
#define LC709204F_REG_INITIAL_RSOC          0x07
#define LC709204F_REG_CELL_TEMP             0x08
#define LC709204F_REG_CELL_VOLTAGE          0x09
#define LC709204F_REG_CURRENT_DIR           0x0A
#define LC709204F_REG_APA                   0x0B
#define LC709204F_REG_APT                   0x0C
#define LC709204F_REG_RSOC                  0x0D
#define LC709204F_REG_TSENSE2_THERMB        0x0E
#define LC709204F_REG_ITE                   0x0F
#define LC709204F_REG_IC_VERSION            0x11
#define LC709204F_REG_CHANGE_PARAM          0x12
#define LC709204F_REG_ALARM_LOW_RSOC        0x13
#define LC709204F_REG_ALARM_LOW_CELL_VLT    0x14
#define LC709204F_REG_IC_POWERMODE          0x15
#define LC709204F_REG_STATUS_BIT            0x16
#define LC709204F_REG_CYCLE_COUNT           0x17
#define LC709204F_REG_BATTERY_STATUS        0x19
#define LC709204F_REG_NUMBER_PARAM          0x1A
#define LC709204F_REG_TERM_CURRENT_RATE     0x1C
#define LC709204F_REG_EMPTY_CELL_VOLTAGE    0x1D
#define LC709204F_REG_ITE_OFFSET            0x1E
#define LC709204F_REG_ALARM_HIGH_CELL_VLT   0x1F
#define LC709204F_REG_ALARM_LOW_TEMP        0x20
#define LC709204F_REG_ALARM_HIGH_TEMP       0x21
#define LC709204F_REG_TOTAL_RUN_TIME_L      0x24
#define LC709204F_REG_TOTAL_RUN_TIME_H      0x25
#define LC709204F_REG_ACC_TEMPERATURE_L     0x26
#define LC709204F_REG_ACC_TEMPERATURE_H     0x27
#define LC709204F_REG_ACC_RSOC_L            0x28
#define LC709204F_REG_ACC_RSOC_H            0x29
#define LC709204F_REG_MAX_CELL_VOLTAGE      0x2A
#define LC709204F_REG_MIN_CELL_VOLTAGE      0x2B
#define LC709204F_REG_MAX_CELL_TEMP_TSENSE1 0x2C
#define LC709204F_REG_MIN_CELL_TEMP_TSENSE1 0x2D
#define LC709204F_REG_AMB_TEMP_TSENSE2      0x30
#define LC709204F_REG_STATE_OF_HEALTH       0x32
#define LC709204F_REG_USER_ID_L             0x36
#define LC709204F_REG_USER_ID_H             0x37

/* LC709204F I2C ADDRESS */
#define LC709204F_ADDRESS_7_BITS                   0x16

/* Public enumerate/structure ----------------------------------------------- */

/* Public macros ------------------------------------------------------------ */
/* Public variables --------------------------------------------------------- */
/* Public APIs -------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
#ifdef __cplusplus
} /* extern "C" { */
#endif

#endif /* __LC709204F_REGS_H */

/* End of file -------------------------------------------------------------- */
