# LickOmeter

This is a guide to build your own motorized lickometer based on the arduino capacitive sensor library.


Requirements:
Basic Arduino Skills - link to arduino introduction here


## Motorization of Lickspout


<p align="center">
  <img src="./Images/Rotary_Action.gif" height="250">
  <img src="./Images/Rotary_Action.png" height="250">
</p>

**Figure 1:** Rotary actuator to hide and show the lickspout to headfixed specimens in a behavior experiment for neuroscience research.


<p align="center">
  <img src="./Images/Linear_Action.gif" height="200">
  <img src="./Images/Linear_Action.png" height="200">
</p>

**Figure 2:** Linear actuator adapted from [OHRBETS Repository](https://github.com/agordonfennell/OHRBETS) with modified Lickspout holder for [Hugo Basile Delta Maze](https://ugobasile.com/products/categories/mazes-tracking/delta-maze). Modified holder is available [here](/Manufacturing_Files/Linear_Action/).




## Electronics

![Schematic of LickOmeter](/Images/schematic.png)

Lickspout (grey) holder was redesigned to fit a delta maze.





test

---

Bill of materials:

For Prototyping:

|Item|description|amount|link|
|---|---|---|---|
|LED||||
|LED||||


For a closed and independently powered Box:

|Item|description|amount|link|
|---|---|---|---|
|Electronics Box|||[Link](https://www.conrad.de/de/p/donau-elektronik-kgb15-523132-universal-gehaeuse-135-x-95-x-45-polystyrol-eps-grau-1-st-523132.html?insert=VQ)|

For linear action:

|Item|description|amount|link|
|---|---|---|---|
|||||

For rotary action:

|Item|description|amount|link|
|---|---|---|---|
|Servo MG995 |||[Link](https://www.conrad.de/de/p/whadda-wpm600-entwicklungsboard-1-st-2481919.html?insert=VQ#productDownloads)|

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

Via digital analog signals or via serial communication



Modified Version of the Following Sources:
Device: https://scanbox.org/2016/04/14/a-simple-lick-o-meter-and-liquid-reward-delivery-system/
(The code of the Manual above did not work)
Code: https://playground.arduino.cc/Main/CapacitiveSensor/




Modified the Linear actuator from here:

https://github.com/agordonfennell/OHRBETS


Links to necessary resources and libraries:

The current design was modified from the following source:

- https://scanbox.org/2016/04/14/a-simple-lick-o-meter-and-liquid-reward-delivery-system/


Capacitive sensor library main source (GitHub):

- https://github.com/PaulStoffregen/CapacitiveSensor

Capacitive sensor library examples:

- https://playground.arduino.cc/Main/CapacitiveSensor/


Servo library:

- https://www.arduino.cc/reference/en/libraries/servo/

Servo Library original source (GitHub):

- https://github.com/arduino-libraries/Servo

Documentation of attached interrupt:

- https://www.arduino.cc/reference/en/language/functions/external-interrupts/attachinterrupt/


References Grü Kra Beck etc.


Example for implementation Bela Repositories
https://github.com/BelaErlinghagen/Multiport_Lickport

https://github.com/BelaErlinghagen/MultiportArena

Contact here 
We provide workshops