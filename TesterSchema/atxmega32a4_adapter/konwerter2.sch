EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:special
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:Podstawowe
LIBS:atxmega_adapter-cache
EELAYER 27 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 3 3
Title ""
Date "18 feb 2014"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L BSS138 Q?
U 1 1 53035E40
P 4900 3250
F 0 "Q?" H 4900 3101 40  0000 R CNN
F 1 "BSS138" H 4900 3400 40  0000 R CNN
F 2 "SOT-23" H 4770 3352 29  0000 C CNN
F 3 "" H 4900 3250 60  0000 C CNN
	1    4900 3250
	0    1    1    0   
$EndComp
$Comp
L R R?
U 1 1 53035E5E
P 4600 3050
F 0 "R?" V 4680 3050 40  0000 C CNN
F 1 "10k" V 4607 3051 40  0000 C CNN
F 2 "~" V 4530 3050 30  0000 C CNN
F 3 "~" H 4600 3050 30  0000 C CNN
	1    4600 3050
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 53035E75
P 5250 3050
F 0 "R?" V 5330 3050 40  0000 C CNN
F 1 "10k" V 5257 3051 40  0000 C CNN
F 2 "~" V 5180 3050 30  0000 C CNN
F 3 "~" H 5250 3050 30  0000 C CNN
	1    5250 3050
	1    0    0    -1  
$EndComp
Wire Wire Line
	4600 2700 4600 2800
Wire Wire Line
	4600 2750 4850 2750
Wire Wire Line
	4850 2750 4850 3050
Wire Wire Line
	5100 3350 5400 3350
Wire Wire Line
	5250 3350 5250 3300
Wire Wire Line
	4600 3300 4600 3350
Wire Wire Line
	4450 3350 4700 3350
$Comp
L +3.3V #PWR?
U 1 1 53035E8C
P 4600 2700
F 0 "#PWR?" H 4600 2660 30  0001 C CNN
F 1 "+3.3V" H 4600 2810 30  0000 C CNN
F 2 "" H 4600 2700 60  0000 C CNN
F 3 "" H 4600 2700 60  0000 C CNN
	1    4600 2700
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR?
U 1 1 53035E9B
P 5250 2700
F 0 "#PWR?" H 5250 2800 30  0001 C CNN
F 1 "VCC" H 5250 2800 30  0000 C CNN
F 2 "" H 5250 2700 60  0000 C CNN
F 3 "" H 5250 2700 60  0000 C CNN
	1    5250 2700
	1    0    0    -1  
$EndComp
Wire Wire Line
	5250 2800 5250 2700
Connection ~ 4600 2750
Connection ~ 4600 3350
Connection ~ 5250 3350
Text HLabel 5400 3350 2    60   Input ~ 0
HTXD
Text HLabel 4450 3350 0    60   Input ~ 0
LTXD
$Comp
L BSS138 Q?
U 1 1 53035EDB
P 4900 4100
F 0 "Q?" H 4900 3951 40  0000 R CNN
F 1 "BSS138" H 4900 4250 40  0000 R CNN
F 2 "SOT-23" H 4770 4202 29  0000 C CNN
F 3 "" H 4900 4100 60  0000 C CNN
	1    4900 4100
	0    1    1    0   
$EndComp
$Comp
L R R?
U 1 1 53035EE1
P 4600 3900
F 0 "R?" V 4680 3900 40  0000 C CNN
F 1 "10k" V 4607 3901 40  0000 C CNN
F 2 "~" V 4530 3900 30  0000 C CNN
F 3 "~" H 4600 3900 30  0000 C CNN
	1    4600 3900
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 53035EE7
P 5250 3900
F 0 "R?" V 5330 3900 40  0000 C CNN
F 1 "10k" V 5257 3901 40  0000 C CNN
F 2 "~" V 5180 3900 30  0000 C CNN
F 3 "~" H 5250 3900 30  0000 C CNN
	1    5250 3900
	1    0    0    -1  
$EndComp
Wire Wire Line
	4600 3550 4600 3650
Wire Wire Line
	4600 3600 4850 3600
Wire Wire Line
	4850 3600 4850 3900
Wire Wire Line
	5100 4200 5400 4200
Wire Wire Line
	5250 4200 5250 4150
Wire Wire Line
	4600 4150 4600 4200
Wire Wire Line
	4450 4200 4700 4200
$Comp
L +3.3V #PWR?
U 1 1 53035EF4
P 4600 3550
F 0 "#PWR?" H 4600 3510 30  0001 C CNN
F 1 "+3.3V" H 4600 3660 30  0000 C CNN
F 2 "" H 4600 3550 60  0000 C CNN
F 3 "" H 4600 3550 60  0000 C CNN
	1    4600 3550
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR?
U 1 1 53035EFA
P 5250 3550
F 0 "#PWR?" H 5250 3650 30  0001 C CNN
F 1 "VCC" H 5250 3650 30  0000 C CNN
F 2 "" H 5250 3550 60  0000 C CNN
F 3 "" H 5250 3550 60  0000 C CNN
	1    5250 3550
	1    0    0    -1  
$EndComp
Wire Wire Line
	5250 3650 5250 3550
Connection ~ 4600 3600
Connection ~ 4600 4200
Connection ~ 5250 4200
Text HLabel 5400 4200 2    60   Input ~ 0
HRXD
Text HLabel 4450 4200 0    60   Input ~ 0
LRXD
$EndSCHEMATC
