#ifndef __LIS2DS12_CFN_H
#define __LIS2DS12_CFN_H

#include "stdio.h"
#include "LIS2DS12_ACC_driver.h"
#include "stm32g4xx_hal.h"

#ifndef __ARCHDEP__TYPES
#define __ARCHDEP__TYPES

typedef unsigned char u8_t;
typedef unsigned short int u16_t;
typedef unsigned int u32_t;
typedef int i32_t;
typedef short int i16_t;
typedef signed char i8_t;

#endif /*__ARCHDEP__TYPES*/

status_t LIS2DS12_CFn_IsDeviceReady(void *handle);
status_t LIS2DS12_CFn_Initialize(void *handle);
status_t LIS2DS12_CFn_Data_Collection(void *handle, i16_t *buff);


#endif /*__LIS2DS12_CFN_H*/

