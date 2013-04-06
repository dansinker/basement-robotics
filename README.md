Basement Robotics: A 3d printed, arduino controlled robot arm
=================

![My image](http://dl.dropbox.com/u/6682410/IMG_20130328_210021.jpg)

So I built a little robot arm in my basement. All the parts that aren't motors are 3d printed. This repo, like the arm itself, is still a work in progress.

What's in this Repo?
-----------
This repo contains all files necessary to print the 3d arm parts and to program your Arduino to control the arm. Naturally, you will need to consult the shopping list for the various bits and pieces you're going to need to actually build the thing. Most importantly, this repo contains
* [Knob_robotclaw.ino](https://github.com/sinker/basement-robotics/blob/master/Knob_robotclaw.ino) this is the sketch to load into your Arduino.
* [stl_files_for_arm](https://github.com/sinker/basement-robotics/tree/master/stl_files_for_arm) These are every STL file needed to create 3d prints of the arm parts. There are a lot of files that could probably be brought into Makerware (or equivalent) and printed together. I haven't created any massive grouped files just because so many of these pieces had to be build separately and tweaked until they were right.

What's not in this Repo?
-----------
Check the Todo List at the bottom.

Shopping list
---------
* 1 Arduino, obviously.
* A good-sized breadboard.
* 4 hobbyist small-servos. [I bought from Sparkfun](https://www.sparkfun.com/products/9065), and these fit snugly the arms.
* 1 small stepper motor. [Again, Sparkfun](https://www.sparkfun.com/products/10551), and the base is sized to precisely fit this motor.
* 1 stepper motor controller. The code in this sketch is for controlling the [EasyDriver Stepper Motor](https://www.sparkfun.com/products/10267).
* 4 potentiometers. I am using three knobs for wrist, elbow, and shoulder control, and then one slide pot for the claw. You could also use a joystick, or all sliders, or whatever you want. 
* Jumper cable extensions. You're going to be creating a ratsnest of cables and, if you want the arm to have full movement, you're going to need to extend the servo connections and the stepper motor wire at a bare minimum.

Alternate Designs
---------
**Servo for the Base Rotation** You could very easily modify the base to be servo-controlled instead of stepper controlled. This has a number of plusses, mainly centered around exact numerical control of position. I personally found that the servos I had felt a little under-powered for rotating the entire arm, and also didn't give me a full 180 degree of motion because of the gear ratio I was using. A stepper, at the end of the day, got the job done easier. 

**Rotational wrist** One thing I don't think I'm building, but would love to see, is a wrist that can be rotated across the claw's center access.

**Linear claw motion** I'm still going to work on this one. I would like to modify the claw design to open and close completely linearly instead of the more pincer-like current design. 



TODO LIST
--------

* ~~upload all stl files~~ and images of each piece
* ~~create shopping list~~
* create circuit diagram
* assembly instructions
* ~~alternative design thoughts~~