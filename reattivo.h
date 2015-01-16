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

template<class T>
class Sampler
{
public:
  Sampler(T init);

  T sample(boolean active, T v);
private:
  T _sample;
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

class Pulser
{
public:
  Pulser();

  boolean pulse(unsigned long onTime, unsigned long offTime);
};

class Ticker
{
public:
  Ticker();

  boolean tick(unsigned long tickTime);
private:
  unsigned long _prev;
};

class AnalogInput
{
public:
  AnalogInput(int pin);

  int read();
private:
  int _pin;
};

class PWMOutput
{
public:
  PWMOutput(int pin);

  void write(int v);
private:
  int _pin;
};

class BoundedSum
{
public:
  BoundedSum();

  int calc(int floor, int cap, int v);
private:
  int _sum;
};

#endif