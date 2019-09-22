#include "MongooseTimer.hpp"

void MongooseTimer::TimerCallback(void* params) {
  // 1. Cast params into timer
  MongooseTimer& timer = *(MongooseTimer*) params;

  // 2. Call the delegate method
  if(timer.delegate_ != nullptr) {
    LOG(LL_INFO, ("Firing callback for timer with id: %d", timer.timer_id_));
    timer.delegate_->DidFireTimer(timer);
  } else {
    LOG(LL_INFO, ("No delegate for timer with id: %d", timer.timer_id_));
  }

}

void MongooseTimer::Start(Timer::FireType fire_type, int interval_milliseconds) {
  // 1. Compute the repeat flag
  int repeat_flag = 0;
  switch(fire_type) {
    case Timer::FireType::kLoop:
      repeat_flag = MGOS_TIMER_REPEAT;
      break;
    case Timer::FireType::kOneShot:
      repeat_flag = 0;
      break;
  }

  // 2. Stop any already running timer
  Stop();

  // 3. Set the timer
  timer_id_ = mgos_set_timer(interval_milliseconds, repeat_flag, TimerCallback, (void*) this);

  LOG(LL_INFO, ("Started timer on %d ms interval with id: %d", interval_milliseconds, timer_id_));
}

void MongooseTimer::Stop() {
  LOG(LL_INFO, ("Stopping timer with id: %d", timer_id_));

  // 1. Check to see if the timer is already running
  if(timer_id_ != MGOS_INVALID_TIMER_ID) {
    // 2. Clear the timer
    mgos_clear_timer(timer_id_);
    timer_id_ = MGOS_INVALID_TIMER_ID;
  } // 3. Otherwise, there's no timer, so do nothing
}
