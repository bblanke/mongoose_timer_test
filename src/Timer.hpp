#ifndef TIMER_H
#define TIMER_H

class TimerDelegate;
/**
 * An abstract class that represents a timer
 * @param log_interface object used to log events and messages
 */
class Timer {
protected:
  TimerDelegate* delegate_; //!< Delegate to which timer events should be sent
public:
  //!< The fire type of the timer
  enum FireType {
    kLoop, //!< Fire repeatedly on the specified interval
    kOneShot //!< Fire once after the specified interval
  };
public:
  Timer() {}

  /**
   * Initializes the timer by setting its delegate
   * @param delegate The delegate object to which events will be sent.
   */
  void Init(TimerDelegate& delegate);

  /**
   * Virtual function to start the timer in the implementer's SDK
   * @param fire_type             fire type of the timer
   * @param interval_milliseconds the interval at which the timer fires, in milliseconds
   */
  virtual void Start(FireType fire_type, int interval_milliseconds) = 0;

  /**
   * Virtual function to stop the timer in the implementer's SDK
   */
  virtual void Stop() = 0;
};

/**
 * An object that can respond to timer events
 */
class TimerDelegate {
public:
  /**
   * Called when the timer fires
   * @param timer A reference to the fired timer
   */
  virtual void DidFireTimer(Timer& timer) = 0;
};

#endif
