/*
   TUTORIAL SEVEN SEGMENT PADA ARDUINO
   MENGGUNAKAN CHIP TM1637
   MENULIS DIGIT

   Pinout :
   CLK -> D10
   DIO -> D11
*/

#include <Arduino.h>
#include <TM1637Display.h>

// Module connection pins (Digital Pins)
#define CLK 10
#define DIO 11

#define TEST_DELAY   2000

//custom karakter
const uint8_t SEG_HORE[] = {
  SEG_C | SEG_E | SEG_F | SEG_G,                    // h
  SEG_C | SEG_D | SEG_E | SEG_G,                    // o
  SEG_E | SEG_G,                                    // r
  SEG_A | SEG_B | SEG_D | SEG_E | SEG_F | SEG_G     // e
};

TM1637Display display(CLK, DIO);

void setup()
{
}

void loop()
{
  uint8_t data[] = { 0xff, 0xff, 0xff, 0xff };
  display.setBrightness(0x0f);

  // menampilkan digit manual per digit
  data[0] = display.encodeDigit(6); //menampilkan angka 6 di digit ke 1
  data[1] = display.encodeDigit(7); //menampilkan angka 7 di digit ke 2
  data[2] = display.encodeDigit(8); //menampilkan angka 8 di digit ke 3
  data[3] = display.encodeDigit(9); //menampilkan angka 9 di digit ke 4
  display.setSegments(data);
  delay(TEST_DELAY);

  // Menampilkan angka 81 rata kanan
  display.showNumberDec(81, false);
  delay(TEST_DELAY);

  // Menampilkan angka 76 rata kanan didahului angka 0
  display.showNumberDec(76, true);
  delay(TEST_DELAY);

  //menampilkan huruf hex ECA
  display.showNumberHexEx(0xeca);
  delay(TEST_DELAY);

  //menampilkan huruf hex DIO
  display.showNumberHexEx(0xd10);
  delay(TEST_DELAY);

  display.setSegments(SEG_HORE);
  delay(TEST_DELAY);

}
