# SNES Controllers

## SHVC-005, SNS-005, SNESP-005

<img src="./snes-controller.jpg" />

## Pinout (Console side)

### Connector / Socket

<img src="./snes-controller-socket.jpg" />

```
╭────────╮
│○○○○|○○○|
╰────────╯
╭────────╮
│1234|567|
╰────────╯
```


| Pin | Description | Color [1]  | Color [2] |
| --- | ----------- | ---------- | --------- |
| 1   | +5v         | White      | Green     |
| 2   | Clock       | Yellow     | yellow    |
| 3   | Latch       | Orange     | white     |
| 4   | Data        | Red        | red       |
|-----|-------------|------------|-----------|
| 5   | ?           | no wire    |           |
| 6   | ?           | no wire    |           |
| 7   | Ground      | Brown      | black     |


[1] Original pad
[2] Extension

# Protocol

Every 16.67ms (or about 60Hz), the SNES CPU sends out a 12μs wide, positive
going data latch pulse on pin 3. This instructs the ICs in the controller
to latch the state of all buttons internally. 6μs after the
fall of the data latch pulse, the CPU sends out 16 data clock pulses on
pin 2. These are 50% duty cycle with 12μs per full cycle. The controllers
serially shift the latched button states out pin 4 on every rising edge
of the clock, and the CPU samples the data on every falling edge.

NOTE: "High" means the button is NOT depressed.

At the end of the 16 cycle sequence, the serial data line is driven low
until the next data latch pulse. The only slight deviation from this
protocol is apparent in the first clock cycle. Because the clock is
normally high, the first transition it makes after latch signal is
a high-to-low transition. Since data for the first button (B in this
case) will be latched on this transition, it's data must actually be
driven earlier. The SNES controllers drive data for the first button
at the falling edge of latch. Data for all other buttons is driven at
the rising edge of clock. Hopefully the following timing diagram will
serve to illustrate this. Only 4 of the 16 clock cycles are shown for
brevity.

| Clock Cycle | Button Reported    |
| ----------- | ------------------ |
| 1           | B                  |
| 2           | Y                  |
| 3           | Select             |
| 4           | Start              |
| 5           | Up on joypad       |
| 6           | Down on joypad     |
| 7           | Left on joypad     |
| 8           | Right on joypad    |
| 9           | A                  |
| 10          | X                  |
| 11          | L                  |
| 12          | R                  |
| 13          | none (always high) |
| 14          | none (always high) |
| 15          | none (always high) |
| 16          | none (always high) |

## references

[Super Nintendo Entertainment System: pinouts & protocol](https://gamefaqs.gamespot.com/snes/916396-super-nintendo/faqs/5395)

[Snes CONtroller Emulator using Arduino](https://github.com/jtrinklein/SConE)

[NES/SNES protocol](http://uzebox.org/files/NES-controller-Hydra-Ch6All-v1.0.pdf)

[Official SNES Controllers variations](https://boardgamegeek.com/wiki/page/thing:94408)
