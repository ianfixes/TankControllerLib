#include "Arduino.h"
#include "ArduinoUnitTests.h"

#ifdef ARDUINO_CI
#include "Adafruit_MAX31865_CI.h"
#else
#include "Adafruit_MAX31865.h"
#endif

unittest(readRTD_TC_TempProbe) {
  std::cout << std::endl;
  uint16_t expectedRTD = 0;
  TempProbe_TC tempProbe;
  uint16_t testRTD = tempProbe.getResistance();
  assert(testRTD == expectedRTD);
  std::cout << std::endl;
}

unittest(getTemp_TC_TempProbe) {
  std::cout << std::endl;
  float expectedTemp = -242.02;
  TempProbe_TC tempProbe;
  float testTemp = tempProbe.getTemperature();
  assert(testTemp == expectedTemp);
  std::cout << std::endl;
}

unittest(readFault_TC_TempProbe) {
  std::cout << std::endl;
  TempProbe_TC tempProbe;
  uint8_t testFault = tempProbe.readFault();
  assertEqual(0, testFault);
  uint8_t expectedFault = 1;
  tempProbe.setFault(expectedFault);
  testFault = tempProbe.readFault();
  assert(testFault == expectedFault);
  std::cout << std::endl;
}

unittest(clearFault_TC_TempProbe) {
  std::cout << std::endl;
  uint8_t setFault = 1;
  uint8_t expectedFault = 0;
  TempProbe_TC tempProbe;
  tempProbe.setFault(setFault);
  tempProbe.clearFault();
  uint8_t testFault = tempProbe.readFault();
  assert(testFault == expectedFault);
  std::cout << std::endl;
}

unittest_main()