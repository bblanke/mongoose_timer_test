#ifndef TIMER_ID_H
#define TIMER_ID_H

#include "mgos.h"
#include "mgos_timers.h"

class MongooseTimerID {
private:
  mgos_timer_id timer_id_;
public:
  MongooseTimerID(): timer_id_(MGOS_INVALID_TIMER_ID) {}
  mgos_timer_id Get() {
    return timer_id_;
  }
  void Set(mgos_timer_id timer_id) {
    LOG(LL_INFO, ("Changing timer id from %d to %d", timer_id_, timer_id));
    timer_id_ = timer_id;
  }
};

#endif
