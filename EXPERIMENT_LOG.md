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
the case.
