#import <Arduino.h>
#import "reattivo.h"

DigitalInput::DigitalInput(int pin) {
  _pin = pin;
  pinMode(_pin, INPUT);
}

boolean DigitalInput::read() {
  return digitalRead(_pin);
}

DigitalOutput::DigitalOutput(int pin) {
  _pin = pin;
  pinMode(_pin, OUTPUT);
}

void DigitalOutput::write(boolean v) {
  digitalWrite(_pin, v);
}

Toggler::Toggler(boolean init) {
  _toggled = init;
}

boolean Toggler::toggle(boolean active) {
  if (active) _toggled = !_toggled;
  return _toggled;
}

EdgeDetector::EdgeDetector() : _prev(false) {
}

boolean EdgeDetector::risingEdge(boolean v) {
  boolean edge = v && !_prev;
  _prev = v;
  return edge;
}

boolean EdgeDetector::fallingEdge(boolean v) {
  boolean edge = !v && _prev;
  _prev = v;
  return edge;
}

BooleanSampler::BooleanSampler(boolean init) : _sample(init) {
}

boolean BooleanSampler::sample(boolean active, boolean v) {
  if (active) _sample = v;
  return _sample;
}

Debouncer::Debouncer() : _settleTime(0), _sample(false) {
}

boolean Debouncer::debounce(unsigned long time, boolean v) {
  // TODO: handle overflow
  if (millis() > _settleTime) {
    if (v != _sample) _settleTime = millis() + time;
    _sample = v;
  }
  return _sample;
}