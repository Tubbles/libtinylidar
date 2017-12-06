/*
    libtinylidar - A small library for interfacing tinyLiDAR from Arduino
    Copyright (C) 2017 Tubbles (thetubblesg@gmail.com)

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#if defined(ARDUINO_ARCH_AVR)
#else
  #error "This library only supports boards with an AVR processor."
#endif

struct Tiny_Lidar_Settings;

class Tiny_Lidar
{
public:
    enum Led_Mode
    {
        LED_DISABLED,
        LED_ENABLED,
        LED_BLINKING,
    } Led_Mode;

    enum Op_Mode
    {
        OP_CONTINUOUS,
        OP_SINGLE,
    } Op_Mode;

    enum Preset_Mode
    {
        PRESET_LONG_RANGE,
        PRESET_HIGH_SPEED,
        PRESET_HIGH_ACCURACY,
        PRESET_DEFAULT,
        PRESET_CUSTOM,
    } Preset_Mode;

    enum Calibrate_Mode
    {
        CALIBRATE_OFFSET,
        CALIBRATE_CROSSTALK,
    } Calibrate_Mode;

    enum Watchdog_Mode
    {
        WATCHDOG_ENABLED,
        WATCHDOG_DISABLED,
    } Watchdog_Mode;

    Tiny_Lidar(uint8_t An_I2C_Address);
    uint16_t Read_Distance();
    void Set_Led_Mode(Led_Mode A_Led_Mode);
    Led_Mode Get_Led_Mode();
    void Set_Conv_Mode(Op_Mode A_Conv_Mode);
    Op_Mode Get_Conv_Mode();
    void Change_I2C_Address(uint8_t An_I2C_Address);
    uint8_t Get_I2C_Address();
    void Reboot();
    void Reboot_Write_Led();
    void Reset_To_Factory_Settings();
    void Write_Custom_Config();
    void Set_Preset_Mode(Preset_Mode A_Preset_Mode);
    Preset_Mode Get_Preset_Mode();
    void Auto_Calibrate(Calibrate_Mode);
    void Set_Watchdog_Mode(Watchdog_Mode A_Watchdog_Mode);
    Watchdog_Mode Get_Watchdog_Mode();
    void Write_Settings(Tiny_Lidar_Settings A_Tiny_Lidar_Settings);
    Tiny_Lidar_Settings Query_Settings();
    static void Auto_Set_I2C_Addresses();
    static void Verify_I2C_Addresses();

private:
    Its_I2C_Address;
};

struct Tiny_Lidar_Settings
{
    Print(Stream A_Stream);
    
    Tiny_Lidar::Op_Mode Op_Mode;
    Tiny_Lidar::Preset_Mode Preset_Mode;
    uint16_t Signal_Rate_Limit;
    uint8_t Sigma_Estimate_Limit;
    uint16_t Timing_Budget;
"timing budget       ", 2
"vcsel               ", 1
"fw version          ", 3
"api version         ", 3
"flags               ", 1
"offset cal          ", 4
"xtalk cal           ", 4
};
