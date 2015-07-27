EESchema Schematic File Version 2
LIBS:aLaMode_v3-rescue
LIBS:aLaMode
LIBS:Conn-raspberry
LIBS:power
LIBS:aLaMode_v3-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 4 4
Title "aLaMode_v3"
Date "2015-07-27"
Rev "3"
Comp "WyoLum :: http://wyolum.com/projects/alamode/"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Connection ~ 5850 1225
Wire Wire Line
	5625 1225 5950 1225
Wire Wire Line
	5625 1225 5625 1375
Wire Wire Line
	7850 3650 8000 3650
Wire Wire Line
	8000 3650 8000 4100
Wire Wire Line
	8000 4100 7900 4100
Wire Wire Line
	3950 2175 5225 2175
Wire Wire Line
	5225 2175 5225 1325
Wire Wire Line
	5225 1325 5950 1325
Wire Wire Line
	5850 1225 5850 1025
Wire Wire Line
	5850 1425 5850 2050
Wire Wire Line
	5850 1425 5950 1425
Wire Wire Line
	5900 4100 6600 4100
Connection ~ 2125 2125
Wire Wire Line
	2125 2175 2125 2125
Wire Wire Line
	2300 1650 2300 1475
Wire Wire Line
	1500 1575 3450 1575
Wire Wire Line
	3250 2475 1500 2475
Wire Wire Line
	3750 1875 3750 1475
Wire Wire Line
	3600 3500 3600 3275
Wire Wire Line
	1500 3500 3600 3500
Wire Wire Line
	3250 2975 1500 2975
Wire Wire Line
	3250 2775 1500 2775
Wire Wire Line
	3250 2575 1500 2575
Wire Wire Line
	6600 5100 4900 5100
Wire Wire Line
	4900 5100 4900 2975
Wire Wire Line
	4900 2975 3950 2975
Wire Wire Line
	3950 2775 8700 2775
Wire Wire Line
	8700 2775 8700 4600
Wire Wire Line
	3950 2575 8500 2575
Wire Wire Line
	8500 2575 8500 4400
Wire Wire Line
	8500 4400 7900 4400
Wire Wire Line
	6600 4200 5200 4200
Wire Wire Line
	5200 4200 5200 2375
Wire Wire Line
	5200 2375 3950 2375
Wire Wire Line
	8200 4300 7900 4300
Wire Wire Line
	6600 4300 5100 4300
Wire Wire Line
	5100 4300 5100 2475
Wire Wire Line
	5100 2475 3950 2475
Wire Wire Line
	7900 4500 8600 4500
Wire Wire Line
	8600 4500 8600 2675
Wire Wire Line
	8600 2675 3950 2675
Wire Wire Line
	6600 5000 5000 5000
Wire Wire Line
	5000 5000 5000 2875
Wire Wire Line
	5000 2875 3950 2875
Wire Wire Line
	6600 5200 4800 5200
Wire Wire Line
	4800 5200 4800 3075
Wire Wire Line
	4800 3075 3950 3075
Wire Wire Line
	1500 2675 3250 2675
Wire Wire Line
	1500 2875 3250 2875
Wire Wire Line
	1500 3075 3250 3075
Wire Wire Line
	3450 1575 3450 1875
Wire Wire Line
	3250 2375 1500 2375
Wire Wire Line
	8700 4600 7900 4600
Wire Wire Line
	3750 1475 2300 1475
Wire Wire Line
	1925 1650 1925 1575
Connection ~ 1925 1575
Wire Wire Line
	1925 2050 1925 2125
Wire Wire Line
	1925 2125 2300 2125
Wire Wire Line
	2300 2125 2300 2050
Wire Wire Line
	2125 3600 2125 3500
Connection ~ 2125 3500
Wire Wire Line
	5625 1875 5625 1925
Wire Wire Line
	5625 1925 5850 1925
Connection ~ 5850 1925
Connection ~ 5625 1325
Wire Wire Line
	7850 3550 8000 3550
Wire Wire Line
	8000 3550 8000 3225
Wire Wire Line
	8000 3225 7400 3225
NoConn ~ 7850 3750
$Comp
L CONN_3 P16
U 1 1 500FBDD3
P 7500 3650
F 0 "P16" V 7450 3650 50  0000 C CNN
F 1 "5V_LINK" V 7550 3650 50  0000 C CNN
F 2 "alamode_fp:Header_U6OE_SMT" V 7650 3650 50  0001 C CNN
F 3 "" H 7500 3650 60  0001 C CNN
	1    7500 3650
	-1   0    0    -1  
$EndComp
Text Label 8000 3650 0    40   ~ 0
Rpi_5V0
Text Notes 6450 3550 0    40   Italic 8
allows hooking up Ras-Pi 5V \nto a La Mode board
Text Label 7400 3225 0    40   ~ 0
5V0
Text Notes 6450 1250 0    60   Italic 12
this jumper enables/disables the Voltage Translator U6, \nthereby allowing/dis-allowing communication \nbetween the Raspberry -Pi and a La Mode\nEDIT:Permanenty shorted(23-08-2012)
$Comp
L BCM2835_GPIO P1
U 1 1 4FD9E5BC
P 7250 4700
F 0 "P1" H 7250 5400 60  0000 C CNN
F 1 "BCM2835_GPIO" V 7250 4700 50  0000 C CNN
F 2 "alamode_fp:Header_GPIO" V 7350 4700 50  0001 C CNN
F 3 "" H 7250 4700 60  0001 C CNN
	1    7250 4700
	1    0    0    -1  
$EndComp
$Comp
L R R13
U 1 1 4FD98CE2
P 5625 1625
F 0 "R13" V 5705 1625 50  0000 C CNN
F 1 "10k" V 5625 1625 50  0000 C CNN
F 2 "alamode_fp:r_0805" H 5625 1625 60  0001 C CNN
F 3 "" H 5625 1625 60  0001 C CNN
	1    5625 1625
	1    0    0    -1  
$EndComp
NoConn ~ 10350 4600
$Comp
L CONN_8 P3
U 1 1 4FD8C311
P 10700 4950
F 0 "P3" H 10650 5400 60  0000 C CNN
F 1 "LAN_JTAG" V 10750 4950 60  0000 C CNN
F 2 "alamode_fp:Header_GPU_JTAG" H 10700 4950 60  0001 C CNN
F 3 "" H 10700 4950 60  0001 C CNN
	1    10700 4950
	1    0    0    -1  
$EndComp
Text Label 5850 1025 0    40   ~ 0
Rpi_3V3
$Comp
L GND #PWR022
U 1 1 4FD8C28A
P 5850 2050
F 0 "#PWR022" H 5850 2050 30  0001 C CNN
F 1 "GND" H 5850 1980 30  0001 C CNN
F 2 "" H 5850 2050 60  0001 C CNN
F 3 "" H 5850 2050 60  0001 C CNN
	1    5850 2050
	1    0    0    -1  
$EndComp
$Comp
L CONN_3 P11
U 1 1 4FD8C245
P 6300 1325
F 0 "P11" V 6250 1325 50  0000 C CNN
F 1 "U6_OE" V 6350 1325 50  0000 C CNN
F 2 "alamode_fp:Header_U6OE_SMT" H 6300 1275 60  0001 C CNN
F 3 "" H 6300 1325 60  0001 C CNN
	1    6300 1325
	1    0    0    -1  
$EndComp
Text Label 5900 4100 0    40   ~ 0
Rpi_3V3
$Comp
L GND #PWR023
U 1 1 4FD62C0F
P 2125 2175
F 0 "#PWR023" H 2125 2175 30  0001 C CNN
F 1 "GND" H 2125 2105 30  0001 C CNN
F 2 "" H 2125 2175 60  0001 C CNN
F 3 "" H 2125 2175 60  0001 C CNN
	1    2125 2175
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR024
U 1 1 4FD62BFD
P 2125 3600
F 0 "#PWR024" H 2125 3600 30  0001 C CNN
F 1 "GND" H 2125 3530 30  0001 C CNN
F 2 "" H 2125 3600 60  0001 C CNN
F 3 "" H 2125 3600 60  0001 C CNN
	1    2125 3600
	1    0    0    -1  
$EndComp
$Comp
L C C13
U 1 1 4FD62BCC
P 2300 1850
F 0 "C13" H 2150 1950 50  0000 L CNN
F 1 "100n" H 2100 1750 50  0000 L CNN
F 2 "alamode_fp:c_0805" H 2300 1850 60  0001 C CNN
F 3 "" H 2300 1850 60  0001 C CNN
	1    2300 1850
	-1   0    0    1   
$EndComp
$Comp
L C C12
U 1 1 4FD62B83
P 1925 1850
F 0 "C12" H 1775 1950 50  0000 L CNN
F 1 "100n" H 1725 1750 50  0000 L CNN
F 2 "alamode_fp:c_0805" H 1925 1850 60  0001 C CNN
F 3 "" H 1925 1850 60  0001 C CNN
	1    1925 1850
	-1   0    0    1   
$EndComp
Text Label 4150 3075 0    40   ~ 0
Rpi_SCK
Text Label 4150 2975 0    40   ~ 0
Rpi_MISO
Text Label 4150 2875 0    40   ~ 0
Rpi_MOSI
Text Label 4150 2775 0    40   ~ 0
Rpi_RST
Text Label 4150 2675 0    40   ~ 0
Rpi_Rx
Text Label 4150 2575 0    40   ~ 0
Rpi_Tx
Text Label 4150 2475 0    40   ~ 0
Rpi_SCL
Text Label 4150 2375 0    40   ~ 0
Rpi_SDA
Text Label 2850 1475 0    40   ~ 0
Rpi_3V3
Text Label 2850 1575 0    40   ~ 0
5V0
Text Label 2850 3075 0    40   ~ 0
SCK
Text HLabel 1500 3075 0    40   Input ~ 0
SCK
Text HLabel 1500 2975 0    40   Input ~ 0
MISO
Text Label 2850 2975 0    40   ~ 0
MISO
Text Label 2850 2875 0    40   ~ 0
MOSI
Text HLabel 1500 2875 0    40   Input ~ 0
MOSI
Text HLabel 1500 2775 0    40   Output ~ 0
RESET
Text Label 2850 2775 0    40   ~ 0
RESET
Text HLabel 1500 1575 0    40   BiDi ~ 0
5V0
Text Label 5900 5200 0    40   ~ 0
Rpi_SCK
Text Label 5900 5100 0    40   ~ 0
Rpi_MISO
Text Label 5900 5000 0    40   ~ 0
Rpi_MOSI
Text Label 8200 4600 0    40   ~ 0
Rpi_RST
$Comp
L TSX0108 U6
U 1 1 4FD5DAA4
P 3600 2575
F 0 "U6" H 3600 2975 40  0000 C CNN
F 1 "TXS0108" H 3600 2875 40  0000 C CNN
F 2 "alamode_fp:tssop-20" H 3600 2575 60  0001 C CNN
F 3 "" H 3600 2575 60  0001 C CNN
	1    3600 2575
	-1   0    0    -1  
$EndComp
Text Label 2850 2675 0    40   ~ 0
TXD
Text Label 2850 2575 0    40   ~ 0
RXD
Text Label 2850 3500 0    40   ~ 0
GND
Text HLabel 1500 3500 0    40   BiDi ~ 0
GND
Text HLabel 1500 2675 0    40   Input ~ 0
TXD
Text HLabel 1500 2575 0    40   Output ~ 0
RXD
NoConn ~ 7900 4800
NoConn ~ 7900 4900
NoConn ~ 7900 5100
NoConn ~ 7900 5300
NoConn ~ 7900 5200
NoConn ~ 6600 4800
NoConn ~ 6600 4700
NoConn ~ 6600 4600
NoConn ~ 6600 4400
Text Label 8200 4300 0    40   ~ 0
GND
Text Label 8200 4500 0    40   ~ 0
Rpi_Rx
Text Label 8200 4400 0    40   ~ 0
Rpi_Tx
Text HLabel 1500 2475 0    40   Input ~ 0
SCL
Text HLabel 1500 2375 0    40   Input ~ 0
SDA
Text Label 2850 2475 0    40   ~ 0
SCL
Text Label 2850 2375 0    40   ~ 0
SDA
Text Label 5900 4300 0    40   ~ 0
Rpi_SCL
Text Label 5900 4200 0    40   ~ 0
Rpi_SDA
Text Notes 6900 5550 0    60   Italic 12
NOTE : GPIO voltage levels are 3v3 and are not 5v tolerant.
NoConn ~ 7900 4200
NoConn ~ 7900 4700
NoConn ~ 7900 5000
NoConn ~ 6600 5300
NoConn ~ 6600 4900
NoConn ~ 6600 4500
NoConn ~ 10350 5300
NoConn ~ 10350 5200
NoConn ~ 10350 5100
NoConn ~ 10350 5000
NoConn ~ 10350 4900
NoConn ~ 10350 4800
NoConn ~ 10350 4700
NoConn ~ 9500 5300
NoConn ~ 9500 5200
NoConn ~ 9500 5100
NoConn ~ 9500 5000
NoConn ~ 9500 4900
NoConn ~ 9500 4800
NoConn ~ 9500 4700
NoConn ~ 9500 4600
$Comp
L CONN_8 P2
U 1 1 4FBF744D
P 9850 4950
F 0 "P2" H 9800 5400 60  0000 C CNN
F 1 "GPU_JTAG" V 9900 4950 60  0000 C CNN
F 2 "alamode_fp:Header_GPU_JTAG" H 9850 4950 60  0001 C CNN
F 3 "" H 9850 4950 60  0001 C CNN
	1    9850 4950
	1    0    0    -1  
$EndComp
$Comp
L PWR_FLAG #FLG025
U 1 1 51B85026
P 6300 3950
F 0 "#FLG025" H 6300 4220 30  0001 C CNN
F 1 "PWR_FLAG" H 6300 4180 30  0000 C CNN
F 2 "" H 6300 3950 60  0000 C CNN
F 3 "" H 6300 3950 60  0000 C CNN
	1    6300 3950
	1    0    0    -1  
$EndComp
Wire Wire Line
	6300 3950 6300 4100
Connection ~ 6300 4100
Text Notes 6200 1150 0    60   ~ 12
DNP
$EndSCHEMATC
