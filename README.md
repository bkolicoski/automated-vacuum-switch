# Automated Load (Vacuum) Switch

Check out the build video of the project on YouTube
[https://youtu.be/dfmcjT2cFxc](https://youtu.be/dfmcjT2cFxc)

The schematic for the circuit is available on EasyEDA [https://easyeda.com/bkolicoski/Automated-Vacuum-Switch](https://easyeda.com/bkolicoski/Automated-Vacuum-Switch)

## Project Summary

Dealing with dust in the workshop requires constant turning on and off of your shop vac. This is a hustle for some so this task is often skipped. 

To mitigate this issue for me, I've created this automatic load sensing switch that when it detects a tool being used, automatically turns on the shop vac to gather the dust created. 

The switch is built with an Arduino (Attiny85) and a current sensor that monitors the load current consumption. Once a load is detected, it turns on a relay that then turns on the vacuum.

The entire project is housed in a junction box in order to be portable but if you have a centralized system it can be permanently embedded in your shop. 
