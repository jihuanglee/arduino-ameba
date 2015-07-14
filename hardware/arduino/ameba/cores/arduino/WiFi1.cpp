/*
  WiFi.cpp - Library for Arduino Wifi shield.
  Copyright (c) 2011-2014 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include "variant.h"

#include "WiFi1.h"
#include "wifi_drv1.h"

WiFiClass1::WiFiClass1()
{
}

void WiFiClass1::init()
{
	wiFiDrv1.wifiDriverInit();
}


int8_t WiFiClass1::scanNetworks()
{
	uint8_t attempts = 10;
	uint8_t numOfNetworks = 0;

	if ( wiFiDrv1.startScanNetworks() == WL_FAILURE)
		return WL_FAILURE;
 	do
 	{
 		delay(2000);
 		numOfNetworks = wiFiDrv1.getScanNetworks();
 	}
	while (( numOfNetworks == 0)&&(--attempts>0));
	return numOfNetworks;
}

int WiFiClass1::begin(char* ssid)
{
	this->begin(ssid, NULL);
}

int WiFiClass1::begin(char* ssid, const char *passphrase)
{
	int8_t status;

	if (passphrase == NULL )
		status =  wiFiDrv1.wifiSetPassphrase(ssid, strlen(ssid), NULL, 0);
	else
		status =  wiFiDrv1.wifiSetPassphrase(ssid, strlen(ssid), passphrase, strlen(passphrase));
	
	if ( status == WL_SUCCESS ) {
		DiagPrintf("connect successfully\r\n");
	}
	return status;


}



WiFiClass1 WiFi1;
