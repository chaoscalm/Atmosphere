#ifndef FUSEE_I2C_H
#define FUSEE_I2C_H

#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#define I2C234_BASE 0x7000C000
#define I2C56_BASE 0x7000D000

typedef struct {
    uint32_t I2C_I2C_CNFG_0;
    uint32_t I2C_I2C_CMD_ADDR0_0;
    uint32_t I2C_I2C_CMD_ADDR1_0;
    uint32_t I2C_I2C_CMD_DATA1_0;
    uint32_t I2C_I2C_CMD_DATA2_0;
    uint32_t _0x14;
    uint32_t _0x18;
    uint32_t I2C_I2C_STATUS_0;
    uint32_t I2C_I2C_SL_CNFG_0;
    uint32_t I2C_I2C_SL_RCVD_0;
    uint32_t I2C_I2C_SL_STATUS_0;
    uint32_t I2C_I2C_SL_ADDR1_0;
    uint32_t I2C_I2C_SL_ADDR2_0;
    uint32_t I2C_I2C_TLOW_SEXT_0;
    uint32_t _0x38;
    uint32_t I2C_I2C_SL_DELAY_COUNT_0;
    uint32_t I2C_I2C_SL_INT_MASK_0;
    uint32_t I2C_I2C_SL_INT_SOURCE_0;
    uint32_t I2C_I2C_SL_INT_SET_0;
    uint32_t _0x4C;
    uint32_t I2C_I2C_TX_PACKET_FIFO_0;
    uint32_t I2C_I2C_RX_FIFO_0;
    uint32_t I2C_PACKET_TRANSFER_STATUS_0;
    uint32_t I2C_FIFO_CONTROL_0;
    uint32_t I2C_FIFO_STATUS_0;
    uint32_t I2C_INTERRUPT_MASK_REGISTER_0;
    uint32_t I2C_INTERRUPT_STATUS_REGISTER_0;
    uint32_t I2C_I2C_CLK_DIVISOR_REGISTER_0;
    uint32_t I2C_I2C_INTERRUPT_SOURCE_REGISTER_0;
    uint32_t I2C_I2C_INTERRUPT_SET_REGISTER_0;
    uint32_t I2C_I2C_SLV_TX_PACKET_FIFO_0;
    uint32_t I2C_I2C_SLV_RX_FIFO_0;
    uint32_t I2C_I2C_SLV_PACKET_STATUS_0;
    uint32_t I2C_I2C_BUS_CLEAR_CONFIG_0;
    uint32_t I2C_I2C_BUS_CLEAR_STATUS_0;
    uint32_t I2C_I2C_CONFIG_LOAD_0;
    uint32_t _0x90;
    uint32_t I2C_I2C_INTERFACE_TIMING_0_0;
    uint32_t I2C_I2C_INTERFACE_TIMING_1_0;
    uint32_t I2C_I2C_HS_INTERFACE_TIMING_0_0;
    uint32_t I2C_I2C_HS_INTERFACE_TIMING_1_0;
} tegra_i2c_t;

#define I2C1_REGS ((volatile tegra_i2c_t *)(I2C234_BASE + 0x000))
#define I2C2_REGS ((volatile tegra_i2c_t *)(I2C234_BASE + 0x400))
#define I2C3_REGS ((volatile tegra_i2c_t *)(I2C234_BASE + 0x500))
#define I2C4_REGS ((volatile tegra_i2c_t *)(I2C234_BASE + 0x700))
#define I2C5_REGS ((volatile tegra_i2c_t *)(I2C56_BASE + 0x000))
#define I2C6_REGS ((volatile tegra_i2c_t *)(I2C56_BASE + 0x100))

void i2c_init(unsigned int id);
bool i2c_query(unsigned int id, uint8_t device, uint8_t r, void *dst, size_t dst_size);
bool i2c_send(unsigned int id, uint8_t device, uint8_t r, void *src, size_t src_size);

void i2c_send_pmic_cpu_shutdown_cmd(void);
bool i2c_query_ti_charger_bit_7(void);
void i2c_clear_ti_charger_bit_7(void);
void i2c_set_ti_charger_bit_7(void);

#endif
