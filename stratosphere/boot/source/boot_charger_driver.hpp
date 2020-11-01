/*
 * Copyright (c) 2018-2020 Atmosphère-NX
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once
#include "boot_bq24193_charger.hpp"
#include "boot_i2c_utils.hpp"

namespace ams::boot {

    class ChargerDriver {
        private:
            static constexpr u32 GpioPadName_Bq24193Charger = 0xA;
        private:
            i2c::driver::I2cSession i2c_session;
        public:
            ChargerDriver() {
                R_ABORT_UNLESS(i2c::driver::OpenSession(std::addressof(this->i2c_session), i2c::DeviceCode_Bq24193));

                //boot::gpio::Configure(GpioPadName_Bq24193Charger);
                //boot::gpio::SetDirection(GpioPadName_Bq24193Charger, GpioDirection_Output);
            }

            ~ChargerDriver() {
                i2c::driver::CloseSession(this->i2c_session);
            }
        private:
            Result Read(u8 addr, u8 *out_data);
            Result Write(u8 addr, u8 val);
            Result ReadWrite(u8 addr, u8 mask, u8 val);

            Result SetInputCurrentLimit(bq24193::InputCurrentLimit current);
            Result SetForce20PercentChargeCurrent(bool force);
            Result SetPreChargeCurrentLimit(u32 current);
            Result SetTerminationCurrentLimit(u32 current);
            Result SetMinimumSystemVoltageLimit(u32 voltage);
            Result SetWatchdogTimerSetting(bq24193::WatchdogTimerSetting setting);
            Result SetChargingSafetyTimerEnabled(bool enabled);
            Result ResetWatchdogTimer();
            Result SetBoostModeCurrentLimit(bq24193::BoostModeCurrentLimit current);
            Result SetHiZEnabled(bool enabled);

        public:
            Result Initialize();
            Result Initialize(bool set_input_current_limit);
            Result SetChargeVoltageLimit(u32 voltage);
            Result SetFastChargeCurrentLimit(u32 current);
            Result SetChargeEnabled(bool enabled);
            Result SetChargerConfiguration(bq24193::ChargerConfiguration config);
            Result GetInputCurrentLimit(bq24193::InputCurrentLimit *out);
            Result GetChargeVoltageLimit(u32 *out);
    };

}
