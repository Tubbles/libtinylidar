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

#include "tinylidar.hh"

enum
{
    op_read_distance = 'D',
    op_led_disable = 'E',
    op_led_enable = 'F',
    op_led_on = 'G',
    op_mode = 'M',
    op_mode_continuous = 'C',
    op_mode_single = 'S',
    op_change_address = 'R',
    op_reboot = 'X',
    op_reboot_save_led = 'Y',
    op_reset1 = 'R',
    op_reset2 = 'E',
    op_reset3 = 'S',
    op_reset4 = 'E',
    op_reset5 = 'T',
}

Tiny_Lidar::Tiny_Lidar(uint8_t An_I2C_Address) :
Its_I2C_Address(An_I2C_Address)
{
    
}
