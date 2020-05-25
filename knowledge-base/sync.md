# SYNC

## CSYNC: Composite sync / clean sync

The horizontal and vertical sync signals combined into one signal and sent all by themselves as a standalone signal. This is generally the most desirable.

## Sync on composite video

The composite video signal is used for sync. It's basically like taking the brightness (luma), the colour (chroma) and the sync, and combining them all in one signal. This is how composite video normally works. The downside is that over the length of a cable, the chroma part of the composite video signal can couple in to the R/G/B lines and cause interference. This is undesirable. Also, some devices (like Extron devices) only support CSYNC.

## Sync on luma (Y)

The luma (the green wire in component video, or one of the two signals in S-Video) is used for sync.
This tends not to cause interference, so it's normally fine to use, as long as you don't have any devices that require CSYNC.
