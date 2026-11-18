#prgma once

/*
 MobaLedLib Dummy Extensions
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

 Copyright (C) 2026  Jürgen Winkler: MobaLedLib@gmx.at

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
 Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301 USA
 -------------------------------------------------------------------------------------------------------------
*/

#if !defined(AVR) && !defined(ESP32) && !defined(ARDUINO_RASPBERRY_PI_PICO)
#error Platform is not supported
#endif

#include <MLLExtension.h>

class DummyExtension : public MLLExtension
{
	private:
  ledNr_t ledNr;
  uint8_t heat;
  uint8_t brightness;
  uint8_t inCh;

	public:
  DummyExtension(ledNr_t ledNr, uint8_t inCh, uint8_t brightness) {
    this->ledNr = ledNr;
    this->brightness = brightness;
    this->inCh = inCh;
    this->heat = 0;
	}
	
	void setup(MobaLedLib_C& mobaLedLib) {
    memset(Get_LEDPtr(mobaLedLib,  ledNr), 0, 3);
	}

	void loop(MobaLedLib_C& mobaLedLib) 
  {
    if (mobaLedLib.Trigger20fps > 0)
    {
      CRGB* pRGB = Get_LEDPtr(mobaLedLib,  ledNr);
      bool isOn = Inp_Is_On(mobaLedLib.Get_Input(this->inCh));
      if (isOn)
      { 
        pRGB->r++; 
        pRGB->g=0;
        pRGB->b=0;
      }
      else
      {
        pRGB->r=0;
        pRGB->g=255;
        pRGB->b=255;
      }
    }
  }
};
