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

template<class T>
Sampler<T>::Sampler(T init) : _sample(init) {
}

template<class T>
T Sampler<T>::sample(boolean active, T v) {
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

Pulser::Pulser() {
}

boolean Pulser::pulse(unsigned long onTime, unsigned long offTime) {
  return millis() % (onTime + offTime) < onTime;
}

Ticker::Ticker() : _prev(0) {
}

boolean Ticker::tick(unsigned long tickTime) {
  // WARN: has instability when tickTime is varying
  unsigned long current = millis();
  boolean result = current % tickTime == 0 && current > _prev;
  _prev = current;
  return result;
}

AnalogInput::AnalogInput(int pin) : _pin(pin) {
}

int AnalogInput::read() {
  return analogRead(_pin);
}

PWMOutput::PWMOutput(int pin) : _pin(pin) {
}

void PWMOutput::write(int v) {
  analogWrite(_pin, v);
}

BoundedSum::BoundedSum() : _sum(0) {
}

int BoundedSum::calc(int floor, int cap, int v) {
  _sum = min(cap, max(floor, _sum + v));
  return _sum;
}