#pragma once

#include "TankControllerLib.h"
#ifdef ARDUINO_CI

class TankControllerTest : public TankControllerProd {
public:
  TankControllerTest();
  ~TankControllerTest();
  virtual String className() const {
    return "TankControllerTest";
  }
  void setup();
  void loop();

private:
  int foo;
};

#endif
