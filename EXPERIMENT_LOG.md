# Experiment Log
## Bailey Blankenship | 9-22-19

### Can we reproduce?
Yes. I didn't commit initially; the first test involved 10 timers.
One round of setting/triggering was successful; the remainder were not.
There was consistently one timer that was overwritten.

### Does the number of timers affect the number of timers overwritten?
Yes. When I increased the number of timers to 15, up to 4 were overwritten.
Sometimes, only 1 was overwritten.
Commit: 
