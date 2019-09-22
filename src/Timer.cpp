#include "Timer.hpp"
#include "mgos.h"

void Timer::Init(TimerDelegate& delegate) {
  LOG(LL_INFO, ("Intializing timer"));
  delegate_ = &delegate;
}
