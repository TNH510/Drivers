/**
 ************************************************************************
 * @file    base_type.h
 * @brief   <Brief description>
 * @details <Detailed description>
 *
 * @author  <first_name_1> <last_name_1>
 *
 ************************************************************************
 * @attention
 *  Confidential Information - Limited Distribution
 *   to Authorized Persons Only
 *
 * @copyright Copyright (C) 2019 ITR - All rights reserved.
 *
 ************************************************************************
 */

/* Define to prevent recursive inclusion ------------------------------ */
#ifndef BASE_TYPE_H
#define BASE_TYPE_H

/* Includes ----------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

/* Public defines ----------------------------------------------------- */

/* Public enumerate/structure ----------------------------------------- */
typedef enum
{
  BS_OK      = 0x00,
  BS_ERROR   = 0x01,
  BS_BUSY    = 0x02,
  BS_TIMEOUT = 0x03
}
base_status_t;

/* Public macros ------------------------------------------------------ */
/* Public variables --------------------------------------------------- */
/* Public function prototypes ----------------------------------------- */

#endif // BASE_TYPE_H

/* End of file -------------------------------------------------------- */
