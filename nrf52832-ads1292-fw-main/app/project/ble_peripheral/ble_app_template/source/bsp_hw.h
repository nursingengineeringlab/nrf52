/**
 * @file       bsp.h
 * @copyright  Copyright (C) 2020 ThuanLe. All rights reserved.
 * @license    This project is released under the ThuanLe License.
 * @version    1.0.0
 * @date       2021-01-23
 * @author     Thuan Le
 * @brief      Board Support Package (BSP)
 * @note       None
 * @example    None
 */

/* Define to prevent recursive inclusion ------------------------------ */
#ifndef __BSP_HW_H
#define __BSP_HW_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ----------------------------------------------------------- */
#include <stdint.h>
#include <stdbool.h>
#include "nrf_drv_twi.h"
#include "nrf_drv_spi.h"
#include "nrf_drv_gpiote.h"
#include "nrf_delay.h"
#include "app_timer.h"

#include "nrf_log.h"
#include "nrf_log_ctrl.h"
#include "nrf_log_default_backends.h"

#include "bsp_io_11.h"

/* Public defines ----------------------------------------------------- */
// #define TEMPERATURE_BOARD

/* Public enumerate/structure ----------------------------------------- */
/**
 * @brief Base status structure
 */
typedef enum
{
  BS_OK = 0x00,
  BS_ERROR_PARAMS,
  BS_ERROR
}
base_status_t;

/**
 * @brief Bool structure
 */
typedef enum
{
  BS_FALSE = 0x00,
  BS_TRUE  = 0x01
}
bool_t;

/* Public macros ------------------------------------------------------ */
#define CHECK(expr, ret)            \
  do {                              \
    if (!(expr)) {                  \
      NRF_LOG_ERROR("%s", #expr);   \
      return (ret);                 \
    }                               \
  } while (0)

#define CHECK_STATUS(expr)          \
  do {                              \
    base_status_t ret = (expr);     \
    if (BS_OK != ret) {             \
      NRF_LOG_ERROR("%s", #expr);   \
      return (ret);                 \
    }                               \
  } while (0)

/* Public variables --------------------------------------------------- */
/* Public function prototypes ----------------------------------------- */
/**
 * @brief         Board support package init
 *
 * @param[in]     None
 *
 * @attention     None
 *
 * @return        None
 */
void bsp_hw_init(void);

/**
 * @brief         I2C read
 *
 * @param[in]     slave_addr    Slave address
 * @param[in]     reg_addr      Register address
 * @param[in]     p_data        Pointer to handle of data
 * @param[in]     len           Data length
 *
 * @attention     None
 *
 * @return
 * - 0      Succes
 * - 1      Error
 */
int bsp_i2c_write(uint8_t slave_addr, uint8_t reg_addr, uint8_t *p_data, uint32_t len);

/**
 * @brief         I2C write
 *
 * @param[in]     slave_addr    Slave address
 * @param[in]     reg_addr      Register address
 * @param[in]     p_data        Pointer to handle of data
 * @param[in]     len           Data length
 *
 * @attention     None
 *
 * @return
 * - 0      Succes
 * - 1      Error
 */
int bsp_i2c_read(uint8_t slave_addr, uint8_t reg_addr, uint8_t *p_data, uint32_t len);

/**
 * @brief         SPI transmit and receive
 *
 * @param[in]     tx_data       Transmit data
 * @param[in]     rx_data       Receive data
 * @param[in]     len           Data length
 *
 * @attention     None
 *
 * @return
 * - 0      Succes
 * - 1      Error
 */
base_status_t bsp_spi_1_transmit_receive(uint8_t *tx_data, uint8_t *rx_data, uint16_t len);
base_status_t bsp_spi_2_transmit_receive(uint8_t *tx_data, uint8_t *rx_data, uint16_t len);

void bsp_delay_ms(uint32_t ms);

void bsp_gpio_write(uint8_t pin , uint8_t state);

/* -------------------------------------------------------------------------- */
#ifdef __cplusplus
} // extern "C"
#endif
#endif // __BSP_HW_H

/* End of file -------------------------------------------------------- */
