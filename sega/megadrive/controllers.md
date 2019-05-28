# megadrive controllers specs

## megadrive controller socket (Arari port)

<img src="../master-system/atari-joystick-port.png" />

| Pin # | Signal Name |
| 1     | D0          |
| 2     | D1          |
| 3     | D2          |
| 4     | D3          |
| 5     | +5V         |
| 6     | D4          |
| 7     | Select (TH) |
| 8     | GND         |
| 9     | D5          |


* pressed = 0v
* released = 5v

## megadrive: 3 Button controller

| Signal (Select) | 5V    | 0V    |
| D0              | Up    | Up    |
| D1              | Down  | Down  |
| D2              | Left  | 0     |
| D3              | Right | 0     |
| D4              | B     | A     |
| D5              | C     | Start |


## megadrive: 6 Button controller

| Cycle #         | 0     | 1     | 2     | 3     | 4     | 5     | 6    | 7     |
| Signal (Select) | 5V    | 0V    | 5V    | 0V    | 5V    | 0V    | 5V   | 0V    |
| D0              | Up    | Up    | Up    | Up    | Up    | 0     | Z    | –     |
| D1              | Down  | Down  | Down  | Down  | Down  | 0     | X    | –     |
| D2              | Left  | 0     | Left  | 0     | Left  | 0     | Y    | –     |
| D3              | Right | 0     | Right | 0     | Right | 0     | Mode | –     |
| D4              | B     | A     | B     | A     | B     | A     | B    | A     |
| D5              | C     | Start | C     | Start | C     | Start | C    | Start |

6 buttons behave the same as 3 button the first two states.
The game may try to read the rest to be 6 button compatible, if not the controller
reset to the first state in about 27us


# references

[The Genesis / Megadrive Joypad Protocol](https://db-electronics.ca/console-tech/sega-genesis-megadrive/joypad/)

[Atari interface](https://deskthority.net/wiki/Atari_interface#Sega_16-bit)

[How to communicate with a Genesis Multi-tap.](https://www.raphnet.net/divers/documentation/genesis_multitap.txt)
