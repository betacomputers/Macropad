# Macropad
My first time working on a hardware electronics project. Still learning PCB design. The current design for this macropad has 9 keys, a rotary encoder, an OLED display and is backlit with 4 LEDs, running on QMK firmware.

## Features
* 2 Part case: top printed in white PLA, bottom printed in clear HT filament
* 9 Keys
* EC11 Rotary encoder
* 2 WS2812B RGB LEDs
* 128x32 OLED Display

## Cad Model
Made in Fusion360.
PCB is mounted to the bottom of the case with 4 M3 bolts and 5x4mm heat inserts. Top and bottom of the case are connected with snap fit joints.

<img width="686" height="609" alt="Screenshot 2026-08-28 at 5 32 21 PM" src="https://github.com/user-attachments/assets/6c976e0c-f44c-4305-a910-71d9d2827a73" />


## PCB
Made in KiCad.
My first attempt at making a PCB, no idea how it'll turn out. All DRC errors appear to be related to KiCads default clearance settings for the LEDs being too large.

Schematic:

<img width="897" height="666" alt="Screenshot 2026-08-28 at 5 32 55 PM" src="https://github.com/user-attachments/assets/bd05ed72-72e5-405e-acc4-9323e77c3815" />


Footprint:

<img width="490" height="618" alt="Screenshot 2026-08-28 at 5 33 23 PM" src="https://github.com/user-attachments/assets/8e7a5c82-787c-4d42-831c-0b4f3656996a" />


3D View (top, bottom):

<img width="439" height="531" alt="Screenshot 2026-08-28 at 5 33 41 PM" src="https://github.com/user-attachments/assets/e36120aa-b73d-49bc-9665-bca14660b4f9" />
<img width="419" height="521" alt="Screenshot 2026-08-28 at 5 34 07 PM" src="https://github.com/user-attachments/assets/d5919173-9679-4662-af55-bec68be2baec" />


## BOM
* 10x 1N4148 Diodes
* 9x MX-Style switches
* 9x DSA keycaps
* 4x SK6812 MINI-E LEDs
* 4x M3 screws
* 4x M3x5mx4mm heatset inserts
* 1x EC11 Rotary encoder
* 1x 0.91 inch OLED display
* 1x Seeed XIAO RP2040
