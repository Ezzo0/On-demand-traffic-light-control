
# On-demand-traffic-light-control

This is an on-demand smart traffic light system for the embedded systems profissional track by Egypt FWD and udacity.  This system aims to implement an on-demand traffic light control with a pedestrian  button, crosswalk button, for allowing pedestrians to cross the road as they have the  highest priority. 

The system has two modes:

1- Normal mode.

2- Pedestrian mode.

- Normal mode:
In this mode pedestrian’s traffic lights is off and the cars’ traffic lights is activated and has the following sequence: green, yellow, red, yellow, …and so on. The yellow LED will blink for five seconds before moving to green or red LEDs.In the second mode system can detect the state at which the button by pedestrians and act based on this information. These states are green, yellow, and red on cars’ traffic light.
- Pedestrian mode:

1- Green state & Yellow state:

If pressed when the cars' green LED is on or the cars' yellow LED is blinking, the pedestrian red LED will be on then both yellow LEDs start to blink for five seconds, then the cars' red LED and pedestrian green LEDs are on for five seconds, this means that pedestrian must wait until the green LED is on. At the end, the cars' red LED will be off and both yellow LEDs start blinking for 5 seconds and the pedestrian's green LED is still 
on, then the pedestrian green LED will be off and both the pedestrian red LED and the cars' green LED will be on.

2- Red state:

If pressed when the cars' red LED is on, the pedestrian's green LED and the cars' red LEDs will be on for five seconds, this means that pedestrians can cross the street while the pedestrian's green LED is on, then the pedestrian green LED will be off and both the pedestrian red LED and the cars' green LED will be on.


## System Flowchat 

![flowchart2](https://user-images.githubusercontent.com/93541012/191134309-dfa8941c-88ba-4460-9263-4a7987100afa.jpg)


## Simulation
https://user-images.githubusercontent.com/93541012/191136084-1e93e253-8a2f-443d-a6f3-18fc9b561c3c.mp4
