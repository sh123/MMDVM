/*
 *   Copyright (C) 2016,2017 by Jonathan Naylor G4KLX
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include "Config.h"
#include "Globals.h"

#include "SerialPort.h"

#if defined(HACKRF)

void CSerialPort::beginInt(uint8_t n, int speed)
{
  switch (n) {
    case 1U:
      break;
    case 2U:
      break;
    case 3U:
      break;
    default:
      break;
  }
}

int CSerialPort::availableInt(uint8_t n)
{
  switch (n) {
    case 1U:
      return true;
    case 2U:
      return true;
    case 3U:
      return true;
    default:
      return false;
  }
}

int CSerialPort::availableForWriteInt(uint8_t n)
{
  switch (n) {
    case 1U:
      return true;
    case 2U:
      return true;
    case 3U:
      return true;
    default:
      return false;
  }
}

uint8_t CSerialPort::readInt(uint8_t n)
{
  switch (n) {
    case 1U:
      return 0;
    case 2U:
      return 0;
    case 3U:
      return 0;
    default:
      return 0U;
  }
}

void CSerialPort::writeInt(uint8_t n, const uint8_t* data, uint16_t length, bool flush)
{
  switch (n) {
    case 1U:
      break;
    case 2U:
      break;
    case 3U:
      break;
    default:
      break;
  }
}

#endif

