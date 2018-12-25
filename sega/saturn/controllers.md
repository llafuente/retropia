# saturn controllers spec

## sega saturn controller socket

<img src="sega-saturn-controller-socket.gif" />


| pin # | Name | Function  |
| 1     | VCC  | +5v (Out) |
| 2     | D1   | Data 1    |
| 3     | D0   | Data 0    |
| 4     | S0   | Select 0  |
| 5     | S1   | Select 1  |
| 6     | 5v   | +5v (Inp) |
| 7     | D3   | Data 3    |
| 8     | D2   | Data 2    |
| 9     | GND  | Ground    |

S0 and S1 are the signal pins.

## sega saturn 6 buttons controller (MK-80100 / MK-80114 / MK-80116 / MK-80301 / MK-80313 / RG-CP5 / RG-CP6)


| S0  | S1  | D0 | d1  | d2  | d3  |
| Off | Off | Z  |  Y  |  X  |  R  |
| On  | Off | B  |  C  |  A  |  St |
| Off | On  | Up |  Dn |  Lt |  Rt |
| On  | On  | -  |  -  |  -  |  L  |

## 3d control pad (Mk-80117 / HSS-0137)

## references

[Saturn Control Pad](https://segaretro.org/Control_Pad_(Saturn)

[Saturn 3D Control Pad](https://segaretro.org/3D_Control_Pad)

[Saturn Controller Protocol MK-80117 and Emulation](https://nfggames.com/forum2/index.php?topic=5055.0)

[controller schematics](https://gamesx.com/grafx/saturn.gif)

[Sega Saturn Pad Info](https://gamesx.com/controldata/saturn.htm)

[USB SFC/SNES and Saturn Controller](https://github.com/bkoropoff/sfcusb)
