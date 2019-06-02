# nRF52XXX

https://www.nordicsemi.com/Products/Low-power-short-range-wireless/Bluetooth-low-energy

| nRF52811                        | nRF52810                | nRF52832                       | nRF52840                        |
|---------------------------------|-------------------------|--------------------------------|---------------------------------|
| 2.48                            | 2.21                    | 2.83                           | 4.40                            |
| 64 MHz Cortex-M4                | 64 MHz Cortex-M4        | 64 MHz Cortex-M4F              | 64 MHz Cortex-M4F               |
| 192 KB Flash, 24 KB RAM         | 192 KB Flash, 24 KB RAM | 512/256 KB Flash, 64/32 KB RAM | 1 MB Flash, 256 KB RAM          |
| 2.4 GHz Transceiver             | 2.4 GHz Transceiver     | 2.4 GHz Transceiver            | 2.4 GHz Transceiver             |
| 2 Mbps, 1 Mbps, Long Range      | 2 Mbps, 1 Mbps          | 2 Mbps, 1 Mbps                 | 2 Mbps, 1 Mbps, Long Range      |
| Bluetooth 5.1 Direction Finding | Bluetooth 5             | Bluetooth 5, Bluetooth mesh    | Bluetooth 5, Bluetooth mesh     |
| ANT, 802.15.4, Thread, Zigbee   | ANT                     | ANT                            | ANT, 802.15.4, Thread, Zigbee   |
| +4 dBm TX Power                 | +4 dBm TX Power         | +4 dBm TX Power                | +8 dBm TX Power                 |
| 128-bit AES CCM                 | 128-bit AES CCM         | 128-bit AES CCM                | 128-bit AES CCM, ARM CryptoCell |
| UART, SPI, TWI, PDM             | UART, SPI, TWI, PDM     | UART, SPI, TWI, PDM, I2S       | UART, SPI, TWI, PDM, I2S, QSPI  |
| PWM                             | PWM                     | PWM                            | PWM                             |
| 12-bit ADC                      | 12-bit ADC              | 12-bit ADC                     | 12-bit ADC                      |
| NO                              | NO                      | NFC-A                          | NFC-A                           |
| NO                              | NO                      | NO                             | USB 2.0                         |

Just for reference the nrf51 line price

| chip  |  nRF51822 | nRF51422 | nRF51824 |
| price |  3.07     | 2.60     | 6.19     |

## Boards

[nRF52-DK](https://www.nordicsemi.com/About-us/BuyOnline?search_token=nRF52-DK&series_token=nRF52832)

[Arduino Nano 33 BLE (nRF52840)](https://store.arduino.cc/nano-33-ble)

[E73-2G4M04S1A (nRF52810)](https://www.aliexpress.com/item/E73-TBA-Test-Board-Small-Size-Bluetooth-ARM-nRF52810-2-4Ghz-2-5mW-IPX-PCB-Antenna/32968740105.html?spm=2114.search0104.3.2.3d2b5c57Af6CGE&ws_ab_test=searchweb0_0,searchweb201602_5_10065_10068_10547_319_10891_317_10548_10696_10084_453_454_10083_10618_10307_10820_10821_10301_10303_537_536_10059_10884_10887_321_322_10103,searchweb201603_53,ppcSwitch_0&algo_expid=45480bbc-a249-412a-9579-6d33760da543-0&algo_pvid=45480bbc-a249-412a-9579-6d33760da543&transAbTest=ae803_3) - [User manual](https://fccid.io/2ALPH-E73/User-Manual/User-manual-3768078)

[SparkFun nRF52832 Breakout](https://www.sparkfun.com/products/13990)


[Adafruit Feather nRF52 Bluefruit LE](https://www.adafruit.com/product/3406) - [schematics](https://cdn-learn.adafruit.com/assets/assets/000/052/793/original/microcontrollers_revgsch.png?1523067417)

[BBC micro: bit nRF51822 KL26Z](https://nl.aliexpress.com/item/BBC-micro-bit-nRF51822-KL26Z-Bluetooth-16kB-RAM-256kB-Flash-Cortex-M0-Pocket-sized-Computer-for/32825332709.html?aff_platform=api&cpt=1559511905100&onelink_item_from=32825332709&onelink_thrd=0.0&onelink_page_from=ITEM_DETAIL&onelink_item_to=32825332709&pvid=b19327ba-4765-4be3-898b-1b1c67434328&onelink_duration=0.904088&sk=bIKIogFm&aff_trace_key=46fd8baf85f24832b416e76ce2139daa-1559511905100-06073-bIKIogFm&onelink_status=noneresult&scm=1007.22893.125764.0&terminal_id=5a2294482a0f49e8b3ffe42343127dde&onelink_page_to=ITEM_DETAIL)

## Tutorials

[nrf52840](https://www.novelbits.io/nrf52840-usb-dongle-tutorial-2/)

[Measuring Lithium battery voltage with nRF52](https://devzone.nordicsemi.com/nordic/b/blog/posts/measuring-lithium-battery-voltage-with-nrf52)

## Examples

[HID keyboard](https://gist.github.com/bigjosh/5d8575f26988228dcf9d40c3795d0928)

[nRF51822 BLE Heartrate and Battery Service example](https://gist.github.com/micooke/f54a18908f8dbc1f9b9f4dcfabf43201)
