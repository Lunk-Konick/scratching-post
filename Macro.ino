/*
  Macro Pad MK1

  An HID input pad with multiple input layers

  Board:
  - Arduino Pro Micro

  IO Extender
  - PCF8574 

  Backlights
   - WS2812B
      Use Adafruit NeoPixel Library
  
  Switch Layout:
  +----------------+
  |[17][18][19][20]|
  |[13][14][15][16]|
  |[ 9][10][11][12]|
  |[ 5][ 6][ 7][ 8]|
  |[ 1][ 2][ 3][ 4]|
  +----------------+
  
  
*/
#include <Wire.h> //built in I2C library for IO Extender How to found here https://www.arduino.cc/en/reference/wire AND https://www.electronicshub.org/interfacing-pcf8574-with-arduino/
#include "Keyboard.h" // Info found here https://www.arduino.cc/reference/en/language/functions/usb/keyboard/ AND http://www.asciitable.com/ 
#include <Adafruit_NeoPixel.h> // How To found here https://create.arduino.cc/projecthub/zanycadencedev/getting-started-with-arduino-and-neopixels-013360 AND https://github.com/adafruit/Adafruit_NeoPixel

//Set up IO Extender addresses
int ExtC = 3;
int Ext[3] = { 0x20, 0x21, 0x22 };


//Set up Backlight - LEDs are wired in the order of the keys
#define BakLi 9
#define BakLen 20
Adafruit_NeoPixel strip = Adafruit_NeoPixel(BakLen, BakLi,NEO_GBR + NEO_KHZ800);

//Keyboard Veriables
  //Key persistance values
  bool KM[20] = { false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false};
  int L = 0; // Current Layer indicator
  byte KA[8] = { 0b00000001, 0b00000010, 0b00000100, 0b00001000, 0b00010000, 0b00100000, 0b01000000, 0b10000000 }; // Key Read Binary Add values
  byte KR[3] = { }; //Key Read raw values
  char KP[20][3] = {
                  { '0', 'VT', 11 }, 
                  { 'DEL', 'NUL', 'NUL' },
                  { '.', 'NUL', 'NUL' },
                  { KEY_RETURN, 'NUL', 'NUL' },
                  { '1', 'NUL', 'NUL' },
                  { '2', 'NUL', 'NUL' },
                  { '3', 'NUL', 'NUL' },
                  { KEY_RETURN, 'NUL', 'NUL' },
                  { '4', 'NUL', 'NUL' },
                  { '5', 'NUL', 'NUL' },
                  { '6', 'NUL', 'NUL' },
                  { '+', 'NUL', 'NUL' },
                  { '7', 'NUL', 'NUL' },
                  { '8', 'NUL', 'NUL' },
                  { '9', 'NUL', 'NUL' },
                  { '-', 'NUL', 'NUL' },
                  { 'NUL', 'NUL', 'NUL' },
                  { 'NUL', 'NUL', 'NUL' },
                  { '/', 'NUL', 'NUL' },
                  { '*', 'NUL', 'NUL' },
                };  //Multi Dimentional Array for Key Values


void setup() 
{
  //IO Extender
    Wire.begin();  //Activate I2C communication on pins 2(SDA) and 3(SCL)
    for ( int c = 0; c < ExtC; c++ ) //loop through each externder to activate all for input
    {
      Wire.beginTransmission(Ext[c]); //Open communication from arduino to IO expander
      Wire.write(0xF);                //Write all high to activate inputs
      Wire.endTransmission();         //close communication
    }
  //Backlight
    // start the strip and blank it out
    strip.begin();
    strip.show();
  Keyboard.begin();
}

void loop() 
{
  //Backlight
    theaterChaseRainbow(50);
  //Keys
    grabInput();
}

void grabInput() { //Read from Extender
  for ( int c = 0; c < ExtC; c++ ) //Check all extenders
  {
    Wire.requestFrom(Ext[c], 1);
    if (Wire.available()) 
    {
      KR[c] = Wire.read();
    }
  }
}

void keyPress() {
  for ( int a = 0; a <= 16; a += 8 )
  {
    for ( int c = 0; c < 8; c++ )
    {
      if (KM[c + a]) 
      {
        if ( KR[c] & KA[c] ) { }
        else
        {
          Keyboard.release(KP[c + a][L]);
          KM[c + a]=false;
        }
      }
      else
      {
        if ( KR[c] & KA[c] ) 
        {
          Keyboard.press(KP[c + a][L]);
          KM[c + a]=true;
        }
        else { }
      }
    }
  }
}

// Rainbow-enhanced theater marquee. Pass delay time (in ms) between frames.
void theaterChaseRainbow(int wait) {
  int firstPixelHue = 0;     // First pixel starts at red (hue 0)
  for(int a=0; a<30; a++) {  // Repeat 30 times...
    for(int b=0; b<3; b++) { //  'b' counts from 0 to 2...
      strip.clear();         //   Set all pixels in RAM to 0 (off)
      // 'c' counts up from 'b' to end of strip in increments of 3...
      for(int c=b; c<strip.numPixels(); c += 3) {
        // hue of pixel 'c' is offset by an amount to make one full
        // revolution of the color wheel (range 65536) along the length
        // of the strip (strip.numPixels() steps):
        int      hue   = firstPixelHue + c * 65536L / strip.numPixels();
        uint32_t color = strip.gamma32(strip.ColorHSV(hue)); // hue -> RGB
        strip.setPixelColor(c, color); // Set pixel 'c' to value 'color'
      }
      strip.show();                // Update strip with new contents
      delay(wait);                 // Pause for a moment
      firstPixelHue += 65536 / 90; // One cycle of color wheel over 90 frames
    }
  }
}
