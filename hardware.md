# Hardware

## Parallel vs serial connectors

- serial: one byte at a time
- parallel: multiple bytes at a time

Before, parallel ports were more used, but have been displaced by serial technologies:

- USB:  universal Serial bus. Current method of choice for simple devices (mice, keyboard, flash storage)
- SATA: universal Serial bus. Current method for HD connection.
- PCIe: connexions directly on the motherboard

When the term serial port is used nowadays it refers to serial interfaces
similar to the very old <http://en.wikipedia.org/wiki/RS-232>

## Northbridge vs southbridge

- Northbridge vs southbridge: <http://en.wikipedia.org/wiki/Southbridge_%28computing%29>
- The 8080 pinout: <http://www.cpu-world.com/info/Pinouts/8088.html>

## USB

Serial

Has a class system. If a hardware fits into one of those classes,
there is no need to install any driver since the interface is already specified.
Sample classes:

- mouse
- keyboard
- storage device (hd, flash)
- network

USB 1.0 has only 4 wires:

- ground
- power
- signal pairs

However newer standards have more cables.

Data transfers are made in a standard manner.
Data is coded via a TODO scheme (if signal changes, 1, else 0).

Input and output is done in chunks called URBs, USB request blocks.

## Bus

Name for several parallel wires used to communicate information between hardware.

Often buses have a different clock rate of their own, lower than the CPU clock rate and dividing it,
since hardware response is so much slower than the processor time lengths.

## PCI

Standard replaced in 2007 by PCIe.

Specifies cables and software interfaces for connected hardware.

Was very prevalent.

Bridges connect one bus into another to extend the number of available buses.

Each PCI peripheral is identified by 3 numbers:

- bus number
- device number
- function number

Each device contains info on:

- vendor id (standardized by the PCI special interest group)
- device id given by each vendor for its devices
- device class

Using vendor id and device id, the system can determine the exact type of hardware.

### Linux

On Linux, you can get info on PCI and PCI-LIKE devices via `lspci`.

The kernel also exports PCI information under `/sys/devices/pci0000:00` which you can `cat` away.

## CPU

The CPU communicates with devices in the following way:

- set origin or destination address in the address bus
- set the output data in the data bus
- send control signals on the control bus specifying which operation should be carried out
