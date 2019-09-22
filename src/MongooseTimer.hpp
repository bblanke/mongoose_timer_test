#ifndef MONGOOSE_TIMER_H
#define MONGOOSE_TIMER_H

// External imports
#include "mgos.h"
#include "mgos_timers.h"

#include "Timer.hpp"

class MongooseTimer: public Timer {
private:
  mgos_timer_id timer_id_;
  static void TimerCallback(void* params);
public:
  MongooseTimer(): Timer(), timer_id_(MGOS_INVALID_TIMER_ID) {}
  void Start(Timer::FireType fire_type, int interval_milliseconds);
  void Stop();
};

#endif
