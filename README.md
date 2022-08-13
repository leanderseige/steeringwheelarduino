# Steering Wheel Arduino

A certain person asked for a PC steering wheel and I decided to not just buy one but to build our own steering wheel ourselves.

Following some excellent sources on the internet it was not too hard to build our own simple steering wheel.

![wheel video 1](https://github.com/leanderseige/steeringwheelarduino/blob/main/media/photo.jpg)

# Inspiration and sources

The main inspiration and sources came from @eglix video on YT https://www.youtube.com/watch?v=OD7MRSHHSPQ
and some of his 3D models of tooth wheels and holders: https://github.com/eglix/Projeler/tree/master/DIY_SIM_Wheel

# Software

As I learned how easy it is to program an Arduino Leonardo I chose to not use some of the existing binary tools flying around on the internet but to write my own software. One needs just a couple of lines to get everything working.

Just set up Arduino IDE and install the following two libraries:
* ArduinoJoystickLibrary (I installed it from the latest ZIP, https://github.com/MHeironimus/ArduinoJoystickLibrary/wiki)
* optional: TM1637 Driver (I installed it from within the IDE's library management, https://github.com/AKJ7/TM1637)

There are three source code files in src/
* minimal.ino - the very minimal version, just sets the Z-Axis Rotation
* minimal-button.ino - I added a button to calibrate the middle position of the wheel (this one is in production)
* minimal-button-led.ino - for full fancyness one can add two TM1637 compatible displays to see the values at any time

Windows recognizes the wheel while programming just right away.

![wheel video 1](https://github.com/leanderseige/steeringwheelarduino/blob/main/media/screenshot.jpg)

# Hardware

![wheel video 1](https://github.com/leanderseige/steeringwheelarduino/blob/main/media/inside1.jpg)

## Steering wheel

We got our wheel from a local car recycling yard. First we got a Volvo wheel including an airbag but people told us that it would be a bad idea to disassemble the airbag ourselves. I followed this advice and traded that wheel for another one without an airbag. We were lucky and found this nice Pulsar Victor sports steering wheel for just €30.

This wheel is mounted using five M5 screws. I designed a separate adapter for it to stick it on the 8mm threaded rod. The file is called wheel_adapter.ino

## Ball bearings

We recycled some old bearings from a skateboard. Inserted two ball bearings including spacers on each side of each wall.

## Other things

Threaded 8mm rod, washers and nuts as well as coated plywood came from a local hardware store.

## Rubber band

In order the pull the wheel back towards the center I invented a simple mechanism using a rubber band. The file for 3D-printing is called Rubber_Band_Mounts.stl I already had rubber band at hand from an earlier project. But here is the source anyway: https://www.amazon.de/gp/product/B089NJJZJL

## Electronics

Wiring is very easy. However, I do not guarantee the correctness of anything. Reproduce the circuit or use the software code on your own risk.

![LED displays](https://github.com/leanderseige/steeringwheelarduino/blob/main/circuit/circuitdiagram-color.png)

* I used an Arduino Leonardo clone from https://www.amazon.de/gp/product/B0786LJQ8K - In the first place I wired the potentiometer the wrong way and caused a short circuit on the power line. The voltage regulator on the Leonardo started to smell burned and functionality broke down. However, after fixing the wrong wiring the Leonardo went back to normal operation. We decided to not swap the Leonardo for a fresh one. If it survived this harsh baptism it would live for a long time with us, so we hope.

* Resistor and potentiometer (B100K) were already available.

* Arcade button: https://www.amazon.de/gp/product/B01MRWL6DW

* Optional LED display, TM1637 compatible: https://www.amazon.de/gp/product/B078S7Q6X7

![LED displays](https://github.com/leanderseige/steeringwheelarduino/blob/main/media/test_wiring_with_LEDs.jpg)
