# parallel vs serial connectors

- serial: one byte at a time
- parallel: multiple bytes at a time

before, parallel ports were more used, but have been displaced by serial technologies:

- USB: unversal Serial bus. Current method of choice for simple devices (mice, keyboard, flash storage )
- SATA: unversal Serial bus. Current method for HD connection.
- PCIe: connexions directly on the motherboard

when the term serial port is used nowadays it refers to serial interfaces
similar to the very old <http://en.wikipedia.org/wiki/RS-232>

# northbridge vs southbridge

- northbridge vs southbridge: http://en.wikipedia.org/wiki/Southbridge_%28computing%29
- the 8080 pinout: <http://www.cpu-world.com/info/Pinouts/8088.html>

# usb

serial

Has a class system. If a hardware fits into one of those classes,
there is no need to install any driver since the interface is already specified.
Sample classes:

- mouse
- keyboard
- storage device (hd, flash)
- network

usb 1.0 has only 4 wires:

- ground
- power
- signal pairs

however newer standars have more cables.

Data transfers are made in a standard manner.
Data is coded via a TODO scheme (if signal changes, 1, else 0).

input and output is done in chuncks called URBs (USB request block)

# bus

name for several parallel wires used to communicate information between hardware

often busses have a differnt clock rate of their own, lower than the cpu clock rate and dividing it.
since hardware response is so much slower than the processor timelengths

# pci

standard replaced in 2007 by PCIe

specifies cables and software interfaces for connected hardware

was very prevalant.

bridges connnect one bus into another to extend the number of available busses

each pci peripherial is identified by 3 numbers:

- bus number
- device number
- function number

each device contains info on:

- vendor id (standardized by the PCI special interest group)
- device id given by each verndor for its devices
- device class

using vendor id and device id, the system can determine the exact type of hardware

## linux

on linux, you can get info on pci and pci-like devices via `lspci`

the kernel also exports pci information under `/sys/devices/pci0000:00` which you can `cat` away.

# cpu

the cpu communicates with devices in the following way:

- set origin or destination address in the address bus
- set the output data in the data bus
- send control signals on the control bus specifying which operation should be carried out
