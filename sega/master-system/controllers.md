# Sega Master System (SMS) Controllers

## Socket: Arari port (DE-9 / DB-9)

<img src="./atari-joystick-port.png" />

No select signal is needed unlike megadrive.

| Pin # | Signal Name |
|-------|-------------|
| 1     | D0          |
| 2     | D1          |
| 3     | D2          |
| 4     | D3          |
| 5     | +5V         |
| 6     | D4          |
| 7     | Select (TH) |
| 8     | GND         |
| 9     | D5          |

SMS use:
* 0v signal => pressed
* 5v signal => released

## Controller (MODEL-3020)

<img src="master-system-controller.jpg" />

<img src="master-system-controller-disassembled.jpg" />

SMS controller board wire pin 5 (5v) to all other pins.

When pressed pull down that pin to ground.

| Pin # | Usage       |
|-------|-------------|
| D0    | Up          |
| D1    | Down        |
| D2    | Left        |
| D3    | Right       |
| D4    | 1           |
| D5    | 2           |

## Light Phaser

<img src="master-system-light-phaser.jpg" />

Pins used:

| Pin # | Usage        |
|-------|--------------|
| D4    | trigger      |
| TH    | light sensor |


## References

[The Genesis / Megadrive Joypad Protocol](https://db-electronics.ca/console-tech/sega-genesis-megadrive/joypad/)

[Atari interface](https://deskthority.net/wiki/Atari_interface#Sega_16-bit)

[Light Phaser](https://segaretro.org/Light_Phaser)

[DE-9 Port](https://segaretro.org/DE-9)

[Nes controller mod to SMS](https://atariage.com/forums/topic/249794-tutorial-nes-controller-mod-to-work-on-sega-master-system/)
