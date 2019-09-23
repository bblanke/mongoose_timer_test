# Experiment Log
## Bailey Blankenship | 9-22-19

### Can we reproduce?
Yes. I didn't commit initially; the first test involved 10 timers.
One round of setting/triggering was successful; the remainder were not.
There was consistently one timer that was overwritten.

### Does the number of timers affect the number of timers overwritten?
Yes. When I increased the number of timers to 15, up to 4 were overwritten.
Sometimes, only 1 was overwritten.
Commit: ab030be59db388954aee7675c55fcbba39a2ac46

### Does this problem happen when timers are consecutively set?
Sometimes. When there's 1 timer overwritten, this appears to consistently be
the case. When there are 4, they aren't necessarily consecutive.

### What's the cause of this?
Big question, Bailey. Here's what you know:
- It looks like somehow the timer_id of different timers is being re-used
- This led to you wrapping timer_id with getters and setters.
- It's clear that at some point, mgos_set_timer initializes a new timer in
  the block where a timer was just set; this duplicates the timer id and
  overwrites the timer. It appears that after a certain point, timers
  re-use their ids, which perpetually makes the overwritten timers stay
  overwritten forever.

###  Why are timers getting overwritten?
Looks like it's happening in mgos_set_timer. They calloc() a block for the
timer, and its memory address is the mgos_timer_id returned. It looks like
it's calloc-ing a block that hasn't been free'd yet.
