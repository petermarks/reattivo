#ifndef riattivo_h
#define riattivo_h

#import <Arduino.h>

class DigitalInput
{
public:
  DigitalInput(int pin);

  boolean read();
private:
  int _pin;
};

class DigitalOutput
{
public:
  DigitalOutput(int pin);

  void write(boolean v);
private:
  int _pin;
};

class Toggler
{
public:
  Toggler(boolean init);

  boolean toggle(boolean active);
private:
  boolean _toggled;
};

class EdgeDetector
{
public:
  EdgeDetector();

  boolean risingEdge(boolean v);
  boolean fallingEdge(boolean v);
private:
  boolean _prev;
};

class BooleanSampler 
{
public:
  BooleanSampler(boolean init);

  boolean sample(boolean active, boolean v);
private:
  boolean _sample;
};

class Debouncer
{
public:
  Debouncer();

  boolean debounce(unsigned long time, boolean v);

private:
  unsigned long _settleTime;
  boolean _sample;
};

#endif