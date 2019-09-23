#ifndef MONGOOSE_TIMER_H
#define MONGOOSE_TIMER_H

// External imports
#include "mgos.h"
#include "mgos_timers.h"

#include "Timer.hpp"
#include "MongooseTimerID.hpp"

class MongooseTimer: public Timer {
private:
  MongooseTimerID timer_id_;
  static void TimerCallback(void* params);
public:
  MongooseTimer(): Timer() {}
  void Start(Timer::FireType fire_type, int interval_milliseconds);
  void Stop();
};

#endif
