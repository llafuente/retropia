# dreamcast controllers spec

## dreamcast controller socket (Maple bus)

### Controller

<img src="sega-dreamcast-controller-socket-male.gif" />

Pinouts

|---|-------|-----------------------------------------------------|
| 1 | red   | serial data                                         |
| 2 | blue  | +5V                                                 |
| 3 | black | GND                                                 |
| 4 | green | sense (connected to GND inside controller/keyboard) |
| 5 | white | serial data (3v?)

The comunication is done in two phases
Phase 1: pin 1 is clock and pin 5 is data.
Phase 2, pin 5 is clock and pin 1 is data.

In each phase, which lasts for 0.5µs, a single bit of data is transferred

### VMU

<img src="sega-dreamcast-controller-socket-female.gif" />

## Protocol (Maple Bus)

The Maple Bus transfers the data serially. The serial protocol is of the synchronous variant, where each bit is explicitly clocked. In contrast to standard synchronous protocols, which use one wire for data and one for clock, the Maple Bus uses a scheme in which the two wires take turn in representing data and clock. Due to this scheme, the bandwidth for each signal is just 1MHz

### Idle

While on Idle state pin 1 and 5 will be 1

### Sync (wakeup)

Sync starts from idle and sends a bit sequence of: 100001

| Pin   | 1 | 2 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 |
|-------|---|---|---|---|---|---|---|---|----|----|----|
| Pin 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0  | 0  | 1  |
| Pin 5 | 1 | 1 | 0 | 1 | 0 | 1 | 0 | 1 | 0  | 1  | 1  |

After sync phase 1 starts.

### Checksum

8-bit bytewise XOR checksum. This checksum is sent immediately after the frame data

```c
// this need to be added as last byte
char maple_checksum(unsigned char *data, int size) {
  char lrc = 0;
  int i;
  for (i = 0; i < size; ++i) {
    lrc ^= data[i];
  }

  return lrc;
}
```

### Closing secuence

| Pin   | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |
|-------|---|---|---|---|---|---|---|---|---|
| Pin 1 | 1 | 1 | 1 | 0 | 1 | 0 | 1 | 0 | 1 |
| Pin 5 | 0 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 1 |

## references

[Maple bus patent](https://archive.org/stream/MaplePatent?ui=embed#page/n33/mode/2up)

[Dreamcast controller to USB build log](https://www.raphnet.net/programmation/dreamcast_usb/index_en.php)

[packet example](http://www.otenko.com/dreamcast/dreamcast-packet.png)

[Maple bus to usb adaptor](http://mc.pp.se/dc/dchid.html)

[Dreamcast Controller pinouts](http://mc.pp.se/dc/controller.html)

[Maple wire protocol](http://mc.pp.se/dc/maplewire.html)

[Similar documentation gathering](https://github.com/nukru/ACDCW/tree/master/Documentation)

[Sega Dreamcast Maplebus Transceiver](https://github.com/ismell/maplebus)

[Dreamcast controller to USB adapter firmware](https://github.com/raphnet/dreamcast_usb)

## Other projects

[Pi in a Dreamcast VMU Build - WIP](https://retropie.org.uk/forum/topic/9179/pi-in-a-dreamcast-vmu-build-wip)
