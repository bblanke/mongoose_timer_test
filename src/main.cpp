#include "mgos.h"
#include "MongooseTimer.hpp"
#include "Timer.hpp"

class TestClass: TimerDelegate {
private:
  Timer& test_timer_;
  Timer** timers_under_test_;
  int size_;
  int fire_count_;
public:
  TestClass(Timer& test_timer, Timer** timers, int size): test_timer_(test_timer), timers_under_test_(timers), size_(size), fire_count_(size) {
    for(int i = 0; i < size_; i++) {
      timers_under_test_[i]->Init(*this);
    }

    test_timer.Init(*this);
  }

  void BeginTesting() {
    test_timer_.Start(Timer::FireType::kLoop, 10000);
  }

  void Test() {
    if(fire_count_ != size_) {
      LOG(LL_ERROR, ("DID NOT FIRE ALL TIMERS LAST ROUND; %d missing.", (size_ - fire_count_)));
    }
    fire_count_ = 0;
    for(int i = 0; i < size_; i++) {
      mgos_msleep(100);
      timers_under_test_[i]->Start(Timer::FireType::kOneShot, 1000);
    }
  }
public:
  void DidFireTimer(Timer& timer) {
    if(&timer == &test_timer_) {
      LOG(LL_INFO, ("Testing:"));
      Test();
    } else {
      fire_count_ ++;
    }
  }
};

enum mgos_app_init_result mgos_app_init(void) {

  static MongooseTimer timer_a = MongooseTimer();
  static MongooseTimer timer_b = MongooseTimer();
  static MongooseTimer timer_c = MongooseTimer();
  static MongooseTimer timer_d = MongooseTimer();
  static MongooseTimer timer_e = MongooseTimer();
  static MongooseTimer timer_f = MongooseTimer();
  static MongooseTimer timer_g = MongooseTimer();
  static MongooseTimer timer_h = MongooseTimer();
  static MongooseTimer timer_i = MongooseTimer();
  static MongooseTimer timer_j = MongooseTimer();
  static MongooseTimer timer_k = MongooseTimer();
  static MongooseTimer timer_l = MongooseTimer();
  static MongooseTimer timer_m = MongooseTimer();
  static MongooseTimer timer_n = MongooseTimer();
  static MongooseTimer timer_o = MongooseTimer();

  static Timer* timers_under_test[] = {
    (Timer*) &timer_a,
    (Timer*) &timer_b,
    (Timer*) &timer_c,
    (Timer*) &timer_d,
    (Timer*) &timer_e,
    (Timer*) &timer_f,
    (Timer*) &timer_g,
    (Timer*) &timer_h,
    (Timer*) &timer_i,
    (Timer*) &timer_j,
    (Timer*) &timer_k,
    (Timer*) &timer_l,
    (Timer*) &timer_m,
    (Timer*) &timer_n,
    (Timer*) &timer_o
  };
  static MongooseTimer test_timer = MongooseTimer();

  static TestClass test_class = TestClass(test_timer, timers_under_test, 15);

  test_class.BeginTesting();

  return MGOS_APP_INIT_SUCCESS;
}
