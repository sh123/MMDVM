/*
 *   Copyright (C) 2015,2016,2017,2018 by Jonathan Naylor G4KLX
 *   Copyright (C) 2015 by Jim Mclaughlin KI6ZUM
 *   Copyright (C) 2016 by Colin Durbridge G4EML
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

#include <libhackrf/hackrf.h>

#include "Config.h"
#include "Globals.h"
#include "IO.h"
#include "Log.h"

#if defined(HACKRF)

const uint16_t DC_OFFSET = 2048U;

static hackrf_device * iohackrf_device = NULL;

int iohackrf_rx_callback(hackrf_transfer *transfer)
{
    LogDebug("iohackrf_rx_callback()");
    return 0;
}

void CIO::initInt()
{
    LogDebug(__FUNCTION__);

    int result;

    LogDebug("Initializing HackRF...");
    if ((result = hackrf_init()) != HACKRF_SUCCESS) 
    {
        LogError("hackrf_init() failed: %s", hackrf_error_name((hackrf_error)result));
	exit(EXIT_FAILURE);
    }

    LogDebug("Opening HackRF...");
    if ((result = hackrf_open_by_serial(NULL, &iohackrf_device)) != HACKRF_SUCCESS)
    {
        LogError("hackrf_open_by_serial() failed: %s", hackrf_error_name((hackrf_error)result));
	exit(EXIT_FAILURE);
    }

    LogDebug("Sample rate: %d", IOHACKRF_SAMPLE_RATE_HZ);
    if ((result = hackrf_set_sample_rate(iohackrf_device, IOHACKRF_SAMPLE_RATE_HZ)) != HACKRF_SUCCESS) 
    {
        LogError("hackrf_set_sample_rate() failed: %s", hackrf_error_name((hackrf_error)result));
	exit(EXIT_FAILURE);
    }

    LogDebug("Baseband filter: %d", IOHACKRF_FILTER_BW_HZ);
    if ((result = hackrf_set_baseband_filter_bandwidth(iohackrf_device, IOHACKRF_FILTER_BW_HZ)) != HACKRF_SUCCESS) 
    {
        LogError("hackrf_set_baseband_filter_bandwidth() failed: %s", hackrf_error_name((hackrf_error)result));
	exit(EXIT_FAILURE);
    }

    LogDebug("HW sync: %d", IOHACKRF_HW_SYNC_ON);
    if ((result = hackrf_set_hw_sync_mode(iohackrf_device, IOHACKRF_HW_SYNC_ON ? 1 : 0)) != HACKRF_SUCCESS) 
    {
        LogError("hackrf_set_hw_sync_node() failed: %s", hackrf_error_name((hackrf_error)result));
	exit(EXIT_FAILURE);
    }

    LogDebug("VGA TX gain: %d", IOHACKRF_TX_VGA_GAIN);
    if ((result = hackrf_set_txvga_gain(iohackrf_device, IOHACKRF_TX_VGA_GAIN)) != HACKRF_SUCCESS) 
    {
        LogError("hackrf_set_txvga_gain() failed: %s", hackrf_error_name((hackrf_error)result));
	exit(EXIT_FAILURE);
    }

    LogDebug("VGA RX gain: %d", IOHACKRF_RX_VGA_GAIN);
    if ((result = hackrf_set_vga_gain(iohackrf_device, IOHACKRF_RX_VGA_GAIN)) != HACKRF_SUCCESS) 
    {
        LogError("hackrf_set_vga_gain() failed: %s", hackrf_error_name((hackrf_error)result));
	exit(EXIT_FAILURE);
    }

    LogDebug("LNA RX gain: %d", IOHACKRF_RX_LNA_GAIN);
    if ((result = hackrf_set_vga_gain(iohackrf_device, IOHACKRF_RX_LNA_GAIN)) != HACKRF_SUCCESS) 
    {
        LogError("hackrf_set_lna_gain() failed: %s", hackrf_error_name((hackrf_error)result));
	exit(EXIT_FAILURE);
    }

    LogDebug("Frequency: %d", IOHACKRF_FREQ_HZ);
    if ((result = hackrf_set_freq(iohackrf_device, IOHACKRF_FREQ_HZ)) != HACKRF_SUCCESS) 
    {
        LogError("hackrf_set_freq() failed: %s", hackrf_error_name((hackrf_error)result));
	exit(EXIT_FAILURE);
    }

    LogDebug("Amp enable: %d", IOHACKRF_AMP_ENABLE);
    if ((result = hackrf_set_amp_enable(iohackrf_device, (uint8_t)IOHACKRF_AMP_ENABLE)) != HACKRF_SUCCESS) 
    {
        LogError("hackrf_set_amp_enable() failed: %s", hackrf_error_name((hackrf_error)result));
	exit(EXIT_FAILURE);
    }

    LogDebug("Ant enable: %d", IOHACKRF_ANT_ENABLE);
    if ((result = hackrf_set_antenna_enable(iohackrf_device, (uint8_t)IOHACKRF_ANT_ENABLE)) != HACKRF_SUCCESS) 
    {
        LogError("hackrf_set_antenna_enable() failed: %s", hackrf_error_name((hackrf_error)result));
	exit(EXIT_FAILURE);
    }
}

void CIO::startInt()
{
    LogDebug(__FUNCTION__);

    int result;

    LogDebug("Starting RX...");

    if ((result = hackrf_start_rx(iohackrf_device, iohackrf_rx_callback, this)) != HACKRF_SUCCESS) 
    {
        LogError("hackrf_start_rx() failed: %s", hackrf_error_name((hackrf_error)result));
	exit(EXIT_FAILURE);
    }
}

void CIO::interrupt()
{
    LogDebug(__FUNCTION__);
}

bool CIO::getCOSInt()
{
    LogDebug(__FUNCTION__);
}

void CIO::setLEDInt(bool on)
{
    //LogDebug(__FUNCTION__);
}

void CIO::setPTTInt(bool on)
{
    LogDebug(__FUNCTION__);
}

void CIO::setCOSInt(bool on)
{
    LogDebug(__FUNCTION__);
}

void CIO::setDStarInt(bool on)
{
    LogDebug(__FUNCTION__);
}

void CIO::setDMRInt(bool on)
{
    LogDebug(__FUNCTION__);
}

void CIO::setYSFInt(bool on)
{
    LogDebug(__FUNCTION__);
}

void CIO::setP25Int(bool on)
{
    LogDebug(__FUNCTION__);
}

void CIO::setNXDNInt(bool on)
{
    LogDebug(__FUNCTION__);
}

void CIO::delayInt(unsigned int dly)
{
    LogDebug(__FUNCTION__);
}

#endif

