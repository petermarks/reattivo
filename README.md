# Reattivo

Reattivo is a Functional Reactive Programming (FRP) library for the Arduino
platform... well sort of. C++ aint exactly functional, so we use objects, but we
do make stuff happen by chaining function calls together.

This library is very immature, so will probably change unrecognisably before
it's done.

No docs yet, but here's a simple example sketch to get you going.

```Arduino
#include <reattivo.h>

DigitalOutput led(6);
DigitalInput  sw(16);
Toggler       t(false);
EdgeDetector  ed;
Debouncer     d;

void setup() {}

void loop() {
  led.write(t.toggle(ed.risingEdge(d.debounce(20, sw.read()))));
}
```

All feedback welcome - I'm a Haskell programmer, who hasn't done C++ for many
years, so apologies if my code sucks.
