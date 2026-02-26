# LickOmeter

This is a guide to build your own motorized LickOmeter based on the arduino capacitive sensor library. Measuring the capacity allows detection of individual licks and therefore direct reward acceptance in the context of many different behavioral research experiments. The repository provides all necessary information to reproduce this device and coding exercises for the general understanding of the resulting data.

---

## System Integration

The device modular integration in existing experimental instruments using 5V Digital/Analog TTL signaling via coaxial BNC cables (e.g. with NI-DAQ, cDAQ or dSpace Microlabox) or using Serial Communication via a USB cable (e.g. Python, MATLAB, Bonsai). For the future, integration in the bPod system is planned.

The current firmware allows to control the position of the lickspout with a 5V Digital via a coaxial BNC cable (0V):

0V (LOW) -> Lickspout OUT  
5V (HIGH) -> Lickspout IN

Coupling the Lick-OUT signal with a syringe pump, peristaltic pump or solenoid valve allows controlled application of reward.

Modification of this firmware would also allow to control the lickspout with Serial Communication via USB.

---

## Lickspout Motorization

Currently, two actuators are implemented for custom use cases. The rotary actuator directly couples servo motor rotation to the lickspout, while the linear actuator transforms servo motor rotation via a gear-rack system to linear motion.

### Rotary Actuator

<p align="center">
  <img src="./Images/Rotary_Action.gif" height="250">
  <img src="./Images/Rotary_Action.png" height="250">
</p>

**Figure 1:** Rotary actuator can show or hide the lickspot to a specimen in a headfixed experimental setup with for example imaging of neuronal activity in behavioral research.

### Linear Actuator

<p align="center">
  <img src="./Images/Linear_Action.gif" height="175">
  <img src="./Images/Linear_Action.png" height="175">
</p>

**Figure 2:** Linear actuator adapted from [OHRBETS Repository](https://github.com/agordonfennell/OHRBETS) with modified Lickspout holder for [Hugo Basile Delta Maze](https://ugobasile.com/products/categories/mazes-tracking/delta-maze). Modified holder is available [here](/Manufacturing_Files/Linear_Action/).

---

## Electronics

![Schematic of LickOmeter](/Images/schematic.png)

Lickspout (grey) holder was redesigned to fit a delta maze.

### Capacitive Sensor Exercises

[Capacitive Sensor Exercises](./Capacitive_Sensor_Exercises) (Adding a threshold for touch induced triggering)

---

## Bill of Materials:

### For Prototyping and Exercises:

|Item|description|amount|link|
|---|---|---|---|
|LED||||
|LED||||


### For Enclosure with Power Supply:

|Item|description|amount|link|
|---|---|---|---|
|Electronics Box|||[Link](https://www.conrad.de/de/p/donau-elektronik-kgb15-523132-universal-gehaeuse-135-x-95-x-45-polystyrol-eps-grau-1-st-523132.html?insert=VQ)|

### For Rotary Actuator:

|Item|description|amount|link|
|---|---|---|---|
|Servo MG995 |||[Link](https://www.conrad.de/de/p/whadda-wpm600-entwicklungsboard-1-st-2481919.html?insert=VQ#productDownloads)|

### For Linear Actuator:

|Item|description|amount|link|
|---|---|---|---|
|||||



---


LED 
BNC
Cannula
Servo Motor
powersupply
arduino uno rev3
resistor

For prototype
BNC block
power barrel plug block

box parts
box

Requirements:
Basic Arduino Skills - link to arduino introduction here

fuse and fuse holder



switch
led holder
BNC 2x
barrel plug

some mount for cannula

linear solution?

Servo for rotary actuation

https://www.conrad.de/de/p/whadda-wpm603-entwicklungsboard-1-st-2481920.html?insert=VQ

180 degrees servo for linear actuator:



etc.

SYRINGE NEEDLE, 12-GAUGE STAINLESS STEEL

Syringe all glass fortuna optima luer-lock-tip (Z31456-1EA, Lot 20228270), Sigma-aldrich glass syringe for soymilk and pump

https://www.sigmaaldrich.com/DE/de/search/z314536-1ea?focus=products&page=1&perpage=30&sort=relevance&term=z314536-1ea&type=product

Stainless steel 304 syringe needle gauge 18, L2 in (Z113042-1EA, Lot. 3110) lick spout sigma aldrich

https://www.sigmaaldrich.com/DE/de/product/aldrich/z113042


syringe pump

https://newerainstruments.com/products/syringe-pumps/pumps

(oscilloscope and triggering device)


Including examples to learn how the capacitive sensor works and how the data can be processed online and interpreted.

-- Link to exercises here

Modular integration into established behavioral experiments and microscopy setups.


## Possible Future Updates

Following ideas are planned to be implemented in the future:

- Compatibility with [Sanworks bPod](https://sanworks.io) system
- Servo control via Serial Communication
- Custom PCB Design

## Links and Resources

- The linear actuator was modified from the [OHRBETS](https://github.com/agordonfennell/OHRBETS) repository.

- The designed was inspired by this a [blog post](https://scanbox.org/2016/04/14/a-simple-lick-o-meter-and-liquid-reward-delivery-system/) of Dario Ringach, PhD at UCLA ([Ringach Lab](http://ringachlab.net)).

- There is official documentation of the [Arduino Capacitive Sensor Library](https://playground.arduino.cc/Main/CapacitiveSensor/) and a [GitHub Repository](https://github.com/PaulStoffregen/CapacitiveSensor) of the maintainer Paul Stoffregen.

- There is official documentation of the [Arduino Servo Library](https://www.arduino.cc/reference/en/libraries/servo/) and an [Arduino Libraries GitHub Repository](https://github.com/arduino-libraries/Servo).

- There is official documentation of the [attachedInterrupt function](https://www.arduino.cc/reference/en/language/functions/external-interrupts/attachinterrupt/ ).

---

## References

References Grü Kra Beck etc.

iBehave Network

Example for implementation Bela Repositories
https://github.com/BelaErlinghagen/Multiport_Lickport

https://github.com/BelaErlinghagen/MultiportArena

## Contact

We provide workshops and are happy if others want to contribute
