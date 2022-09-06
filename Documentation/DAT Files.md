# Introduction

The DAT file (.dat) tells YSFlight how an aircraft or ground object is supposed to behave. This page details all of the different DAT Variables, their required inputs, and in general what they are used for.


# Line And In-Line Comments in DAT Files

All DAT Files allow lines to be commented out if the row begins with "REM". Additionally comments can be added in-line if preceded with "#".

# Aircraft DAT Variables

All of the aircraft DAT Variables are defined in this section. In addition to the constraints and information in the sections below, also see the [table below](#Aircraft-DAT-Variable-Summary) for specific requirements in terms of the units and inputs.

<br>

## IDENTIFY

> IDENTIFY "DIAMOND_ECLIPSE"

The in-game name of the aircraft, which is displayed to users in the aircraft selection menu and also via aircraft target circles if enabled on a server. Alpha-numeric characters are allowed, along with special characters. 

**Note:** YSFlight only recognizes the first 32 characters of the IDENTIFY String. If you have multiple aircraft where the IDENTIFY string is identical for the first 32 characters, YSFlight will load the same aircraft with the same name as the first encountered in all aircraft .lst files combined.

<br>

## SUBSTNAM

> SUBSTNAM "F-18C_HORNET"

The name of the plane (as specified in the IDENTIFY line of a .dat file) can be listed here. The plane chosen will substitute the grey block plane that is generated when an unknown (client side) plane is flown on a server. 

**NOTE:** Current best practice is to only use the stock aircraft, as most players still keep their stock aircraft installed. Selecting another aircraft that the user doesn't have, defeats the purpose of this feature.

<br>

## CATEGORY

> CATEGORY FIGHTER

CATEGORY has two functions:

- Filter the list of models in the aircraft selection menu
- Control targeted angle of bank for the autopilot.
- Kill Score

The permitted inputs and the hard-coded auto-pilot bank angle are defined below:.

| CATEGORY | Bank Angle (rad) | Bank Angle (deg) | Kill Score |
| -- | :-: | :-: | :-: |
| AEROBATIC | $\pi \times \frac{8}{18}$ | 80 | 5 |
| ATTACKER |  $\frac{\pi}{3}$ | 60 | 30 | 30 |
| FIGHTER |  $\pi \times \frac{8}{18}$ | 80 | 20 |
| HEAVYBOMBER |  $\frac{\pi}{6}$ | 30 | 40 |
| NORMAL |  $\frac{\pi}{6}$ | 30 | 5 |
| TRAINER |  $\frac{\pi}{3}$ | 60 | 10 |
| UTILIY | $\frac{\pi}{6}$ | 30 | 5 |
| WW2ATTACKER | Unknown | Unknown | 30 |
| WW2BOMBER |  $\frac{\pi}{6}$ | 30 | 40 |
| WW2DIVEBOMBER | Unknown | Unknown | 30 |
| WW2FIGHTER |   $\pi \times \frac{8}{18}$ | 80 | 20 |


<br>

## AFTBURNR

> AFTBURNR TRUE

Indicates if the engine has an afterburner or not. Required for all engine types.

<br>

## THRAFTBN

> THRAFTBN 20.0t

Defines the maximum thrust an afterburning jet engine will produce in afterburner at sea-level.

<br>

## THRMILIT

> THRMILIT 12.0t

Defines the maximum thrust a jet engine will produce without afterburner at sea-level.

<br>

## THRSTREV

> THRSTREV 0.2

Defines how efficient the reverse thrust of an engine is.

<br>

## PROPELLR

> PROPELLR 150HP

Defines how powerful a propeller engine is.

## PROPVMIN

> PROPVMIN 70kt

Defines the transition point between slow and high-speed propeller thrust calculations. If not defined YSFlight defaults to 30 m/s.

<br>

## PROPEFCY

> PROPEFCY 0.8

Defines how efficient the a propeller engine is. Defaults to 0.7 if not defined in DAT files.

<br>

## WEIGHCLN

> WEIGHCLN 630kg

Defines the empty weight (no fuel or payload) of the aircraft.

<br>

## WEIGFUEL

> WEIGFUEL 100kg

Defines the maximum weight of the fuel that can be loaded in the internal tanks. 

**NOTE:** External fuel tank weights are separate and defined in the weapons section of the DAT File.

<br>

## WEIGLOAD

> WEIGLOAD 300kg

The weight of the payload of the aircraft.

<br>

## FUELABRN

> FUELABRN 2.5kg

The weight of fuel burned per second at maximum afterburner throttle setting at sea-level.

<br>

## FUELMILI

> FUELMILI 0.015kg

The weight of fuel burned per second at maximum non-afterburner throttle setting at sea-level.

<br>

## COCKPITP

> COCKPITP -0.21m  0.40m  2.05m

The coordinates of the cockpit view point (first F1 view point). 

See the [Coordinate System Definition](#-YSFlight-Coordinate-System) for more about the order of inputs.

<br>

## EXCAMERA

> EXCAMERA "DORSAL" 0m 2.5m 2.25m 180deg 5deg 0deg OUTSIDE

Defines the name, location and orientation of an extra F1 view point. Options for INSIDE and OUTSIDE define how  the view is rendered relative to the cockpit model or the external visual file.

Multiple EXCAMERAs can be defined with multiple lines

See the [Coordinate System Definition](#-YSFlight-Coordinate-System) for more about the order of inputs.

<br>

## INSTPANL

> INSTPANL aircraft/eclipse.ist

Custom instrument panels (.ist) can be added to the cockpit. 

<br>

## ISPNLPOS

> ISPNLPOS -0.21m  0.40m  2.355404m

Define the position of the center of the custom instrument panel. 

See the [Coordinate System Definition](#-YSFlight-Coordinate-System) for more about the order of inputs.

<br>

## ISPNLSCL

> ISPNLSCL 0.38

Define the scaling factor to be applied to the instrument panel to fit it into the cockpit.

<br>

## SCRNCNTR

> SCRNCNTR 0.0 0.24

The position of the viewpoint relative to the center of the viewport. To explain this, sitting in front of your computer, hold up a piece of paper in front of you. The area covered by that piece of paper is the viewport - the window which you see from the cockpit in YSFlight. Now keep your head and your eyes at the same spot, but move that piece of paper around. Your viewpoint (i.e. your eyes) has not moved, but the viewport is moving. A positive Y value (X, Y) means the view point is above the centre of the viewport, which is the same has having the viewport moved downwards. This is useful in giving you more view area below - i.e. inside the cockpit - and lets you display the instruments larger without having them going off the bottom of the window.

<br>

## LEFTGEAR

> LEFTGEAR -1.94m -2.03m -0.71m

Defines the location of the left main landing gear interface with the ground. If not defined, YSFlight uses an equivalent to:

> LEFTGEAR -3m -1m -3m

See the [Coordinate System Definition](#-YSFlight-Coordinate-System) for more about the order of inputs.

<br>

## RIGHGEAR

> RIGHGEAR 1.94m -2.03m -0.71m

Defines the location of the right main landing gear interface with the ground. If not defined, YSFlight uses an equivalent to:

> RIGHGEAR 3m -1m -3m

See the [Coordinate System Definition](#-YSFlight-Coordinate-System) for more about the order of inputs.

<br>

## WHELGEAR

> WHELGEAR 0.00m -2.06m 5.16m

Defines the location of the nose or tail landing gear interface with the ground. If not defined, YSFlight uses an equivalent to:

> WHELGEAR 0m -1m 2m

See the [Coordinate System Definition](#-YSFlight-Coordinate-System) for more about the order of inputs.

<br>

## ARRESTER

> ARRESTER 0.00m -1.76m -3.79m

Defines the position of the arresting gear hookpoint. If not defined, YSFlight uses an equivalent to:

> ARRESTER 0m -3m -1m

See the [Coordinate System Definition](#-YSFlight-Coordinate-System) for more about the order of inputs.

<br>

## MACHNGUN

> MACHNGUN  2.8m -0.23m  2.35m  #MACHINE GUN POSITION

Defines the muzzle position of the first machine gun.

See the [Coordinate System Definition](#-YSFlight-Coordinate-System) for more about the order of inputs.

<br>

## MACHNGNX

> MACHNGN2  2.03m -0.59m  2.59m  #MACHINE GUN POSITION <br>MACHNGN3  2.22m -0.58m  2.59m  #MACHINE GUN POSITION<br>MACHNGN4  2.40m -0.56m  2.59m  #MACHINE GUN POSITION<br>MACHNGN5 -1.87m -0.61m  2.59m  #MACHINE GUN POSITION<br>MACHNGN6 -2.03m -0.59m  2.59m  #MACHINE GUN POSITION<br>MACHNGN7 -2.22m -0.58m  2.59m  #MACHINE GUN POSITION<br>MACHNGN8 -2.40m -0.56m  2.59m  #MACHINE GUN POSITION

Defines the muzzle position of the second through eighth machine gun with a limit of 8 machine guns defined (when including MACHINGUN).

See the [Coordinate System Definition](#-YSFlight-Coordinate-System) for more about the order of inputs.

<br>

## GUNINTVL

> GUNINTVL 0.075

Defines the interval (in seconds) between bullets firing. Note that all MACHNGUN and MACHNGNX weapons fire at the same time. If not defined, YSFlight defaults to 0.075.

<br>

## GUNDIREC

> GUNDIREC  0.0m 0.0m -1.0m    

Defines the direction (unit vector) of the MACHNGUN. Note: Setting to 0m 0m 0m shoots directly north or south regardless of aircraft attitude 

See the [Coordinate System Definition](#-YSFlight-Coordinate-System) for more about the order of inputs.

<br>

## SMOKEGEN

> SMOKEGEN  0.0m  0.0m -15.17m  

Defines the location of the smoke point origin. Multiple smoke points can be defined using repeated SMOKEGEN lines.

See the [Coordinate System Definition](#-YSFlight-Coordinate-System) for more about the order of inputs.

<br>

## VAPORPO0

> VAPORPO0  5.1m  0.55m -5.60m 

Define the location of the wing-tip vapor origin when the variable geometry wings are swept fully back. If not defined, YSFlight defaults to:

> VAPORPO0  5m  0m 0m

See the [Coordinate System Definition](#-YSFlight-Coordinate-System) for more about the order of inputs.

<br>

## VAPORPO1

> VAPORPO1  8.6m  0.55m -3.20m  #VAPOR POSITION (Wings Spread)

Define the location of the wing-tip vapor origin when the variable geometry wings are swept fully forward.If not defined, YSFlight defaults to:

> VAPORPO1  5m  0m 0m

See the [Coordinate System Definition](#-YSFlight-Coordinate-System) for more about the order of inputs.

**Note:** For aircraft without variable geometry wings, use the same location for VAPORPO0 and VAPORPO1.

<br>

## HTRADIUS

> HTRADIUS  8.0m                #OUTSIDE SPHERE RADIUS

This is maximum distance from which YSFlight will attempt collision detection. Imagine a sphere centred around your aircraft (centre at 0,0,0) with a radius equals to HTRADIUS. Make sure this sphere is large enough to enclose the entire model, but not so large that YSFlight will be performing unnecessary calculations for collision detection when two objects are far enough apart that collision, with the model, is impossible. Also changes the default camera distance in F8 or F7 view and the switch between visual and coarse models.

**Note:** YSFlight will not perform collision detection if the distance between object A and object B is greater than the sum of their HTRADIUS.


<br>

## STALHORN

> STALHORN TRUE                 #STALL WARNING HORN

Enables stall warning sound when true

<br>

## GEARHORN

> GEARHORN FALSE                #NO LANDING-GEAR WARNING HORN (for low-altitude aerobatics)

Enables landing gear horn when true. Horn sounds when gear is up, flaps are down, and the aircraft is in a descent below 500ft

<br>

## FLAPPOSI

> FLAPPOSI 0.0                  #FLAP POSITION 1 <br> FLAPPOSI 0.4                  #FLAP POSITION 2 <br> FLAPPOSI 1.0                  #FLAP POSITION 3

Overrides the default 25 percent incriment in flap extension or retraction with the (default) W and S keys. Allows for custom extension positions. Requires multiple entries to include 0 and 1 for the percent (as a decimal) 

<br>

## TRIGGERX

> TRIGGER1 GUN<br>TRIGGER2 AAM<br>TRIGGER3 AGM<br>TRIGGER4 SMK

Defines the order in which weapons will appear in the player's HUD. Currently not functional.

<br>

## STRENGTH

> STRENGTH 12

Defines the amount of damage that the aircraft can absorb before it is destroyed. If not defined in the DAT file, it defaults to 10.


<br>

## CRITAOAP

> CRITAOAP  20deg               #CRITICAL AOA POSITIVE

Defines the angle of attack (positive, nose-up direction) at which the aircraft aerodynamically stalls.

<br>

## CRITAOAM

> CRITAOAM -15deg               #CRITICAL AOA NEGATIVE

Defines the angle of attack (negative, nose-down direction) at which the aircraft aerodynamically stalls.

<br>

## MAXCDAOA

> MAXCDAOA 40deg        

Defines the angle of attack at which maximum $C_D$ is reached on the $C_D$ vs $\alpha$ curve. If not defined, YSFlight uses 45 degrees.

<br>

## FLATCLR1

> FLATCLR1 3deg                 #Cl stays the same this angle beyond critical AOA (plus side)

<br>

## FLATCLR2

> FLATCLR2 3deg                 #Cl stays the same this angle beyond critical AOA (minus side)

<br>

## CLDECAY1

> CLDECAY1 15deg                #After flat Cl range, Cl decays to zero in this range of angle (plus side)

<br>

## CLDECAY2

> CLDECAY2 10deg                #After flat Cl range, Cl decays to zero in this range of angle (minus side)


<br>

## CRITSPED

> CRITSPED 0.9MACH

The speed at which the aircraft meets supersonic drag

<br>

## MAXSPEED

> MAXSPEED 2.5MACH 

The maximum speed the aircraft can fly. Used for calculating Drag Coefficient.

<br>

## HASSPOIL

> HASSPOIL TRUE  

A flag if the aircraft has an extendable spoiler.

<br>

## RETRGEAR

> RETRGEAR TRUE 

A flag if the landing gear is retractable.

<br>

## VARGEOMW

> VARGEOMW FALSE

A flag if the aircraft has variable geometry wings that need to sweep based on air speed.

<br>

## CLVARGEO

> CLVARGEO 0.0

The increase in $C_L$ when the wings are fully swept forward. When Wings are at an intermediate position, the $C_L$ is scaled proportionately. 

<br>

## CDVARGEO

> CDVARGEO 0.0   

The increase in $C_D$ when the wings are fully swept forward. When Wings are at an intermediate position, the $C_D$ is scaled proportionately. 

<br>

## CLBYFLAP

> CLBYFLAP 0.1 

The increase in $C_L$ when the flaps are fully lowered. When flaps are at an intermediate position, the $C_L$ is scaled proportionately. 

<br>

## CDBYFLAP

> CDBYFLAP 0.2  

The increase in $C_D$ when the flaps are fully lowered. When flaps are at an intermediate position, the $C_D$ is scaled proportionately. 

<br>

## CDBYGEAR

> CDBYGEAR 0.5           

The increase in $C_D$ when the landing gear are lowered.

<br>

## CDSPOILR

> CDSPOILR 2.0

The increase in $C_D$ when the spoiler is deployed.

<br>

## WINGAREA

> WINGAREA 70m^2 

The wing area for the aircraft, used in the lift and drag calculations. Cannot be 0 or negative.

<br>

## VGWSPED1

> VGWSPED1 0.5MACH

The speed at which the Variable Geometry Wing begins to sweep back. The default speed, if the variable is not defined in the DAT File is 0.3 Mach (at Sea level) / 198 Knots True Air Speed.

<br>

## VGWSPED2

> VGWSPED2 0.85MACH

The speed at which the Variable Geometry Wing reaches fully swept back. The default speed, if the variable is not defined in the DAT File is 0.8 Mach (at Sea level) / 528 Knots True Air Speed.


<br>

## MXIPTAOA

> MXIPTAOA 23.0deg 

The maximum angle of attack (positive and negative) that the player can command.

<br>

## MXIPTSSA

> MXIPTSSA 5.0deg 

The maximum angle of side-slip (positive and negative) that the player can command.

<br>

## MXIPTROL

> MXIPTROL 360.0deg

The maximum instantaneous roll rate that the player can command.

<br>

## THRSTVCTR

> TRSTVCTR TRUE

Indication if the aircraft has thrust vectoring, or off-axis thrust vector. 

**NOTE:** Helicopters use this tag set to TRUE and identical TRSTDIR0 and TRSTDIR1 values.

<br>

## TRSTDIR0

> TRSTDIR0 0.0m 0.0m 1.0m

The thrust unit vector for the engine when in the non-vectored orientation.

See the [Coordinate System Definition](#-YSFlight-Coordinate-System) for more about the order of inputs.

**NOTE:** Helicopters use identical TRSTDIR0 and TRSTDIR1 values.

<br>

## TRSTDIR1

> TRSTDIR1 0.0m 1.0m 0.0m 

The thrust unit vector for the engine when in the fully-vectored orientation.

See the [Coordinate System Definition](#-YSFlight-Coordinate-System) for more about the order of inputs.

**NOTE:** Helicopters use identical TRSTDIR0 and TRSTDIR1 values.

<br>

## MANESPD1

> MANESPD1 60kt 

The minimum airspeed (indicated air speed) needed for any aerodynamic control over the flight path

<br>

## MANESPD2

> MANESPD2 85kt 

The minimum air speed (indicated air speed) needed for fully controlled flight.

<br>

## PSTMPTCH

>PSTMPTCH 10deg 

The rate of pitch possible in the post-stall region of the $C_L$ vs $\alpha$ curve.(deg/s). 

**NOTE:** Only used for Helicopters, VTOL aircraft and super-maneuverable aircraft (like the F-22).

<br>

## PSTMYAW_

> PSTMYAW_ 10deg 

The rate of yaw possible in post-stall region of the $C_L$ vs $\alpha$ curve. (deg/s)

**NOTE:** Only used for Helicopters, VTOL aircraft and super-maneuverable aircraft (like the F-22).

<br>

## PSTMROLL

> PSTMROLL 10deg  

The rate of roll possible in post-stall region of the $C_L$ vs $\alpha$ curve. (deg/s)

**NOTE:** Only used for Helicopters, VTOL aircraft and super-maneuverable aircraft (like the F-22).


<br>

## PSTMPWR1

> PSTMPWR1 0.2  

The minimum throttle setting to have direct attitude control in the post-stall region of the $C_L$ vs $\alpha$ curve.

If not defined in the DAT file, YSFlight defaults to 0.15.

**NOTE:** For helicopters, this should be set to zero.


<br>

## PSTMPWR2

> PSTMPWR1 0.8  

The minimum throttle setting to have fully effective direct attitude control in the post-stall region of the $C_L$ vs $\alpha$ curve.

If not defined in the DAT File, YSFlight defaults to 0.8.

**NOTE:** For helicopters, this should be set to zero.

<br>

## CPITMANE

> CPITMANE 8.0

The pitch maneuverability constant controls how quickly the aircraft reacts to a pitch input. A lower value means a slower response to pitch inputs.

<br>

## CPITSTAB

> CPITSTAB 2.0

The pitch stability constant damps out pitch inputs when pitch inputs are returned to neutral.

<br>

## CYAWMANE

> CYAWMANE 5.0

The Yaw Maneuverability constant controls how responsive the yaw is and how fast the aircraft will reach maximum input side slip angle with a full yaw input. A lower value means a slower reaction to yaw inputs.

<br>

## CYAWSTAB

> CYAWSTAB 3.0

The yaw stability constant controls how stable the yaw axis is and how quickly the aircraft will return to a neutral side slip angle when the pedal input is released.

<br>

## CROLLMAN

> CROLLMAN 3.0

The roll maneuverability constant controls how quickly the aircraft will reach maximum roll rate. A lower value means a slower reaction to roll inputs.

<br>

## CTLLDGEA

> CTLLDGEA TRUE

Control if the landing gear will be down when the aircraft spawns.

<br>

## CTLBRAKE

> CTLBRAKE FALSE 

Control if the brake will be engaged when the aircraft spawns.

<br>

## CTLSPOIL

> CTLSPOIL 0.0

Control how far the spoiler is extended when the aircraft spawns. 0 is fully retracted and 1 is fully extended.

<br>

## CTLABRNR

> CTLABRNR FALSE

Control if the afterburner is engaged when the aircraft spawns.

<br>

## CTLTHROT

> CTLTHROT 0.0 

Set the throttle position when the aircraft spawns.

<br>

## CTLIFLAP

> CTLIFLAP 0.0 

Control how far the flap is extended when the aircraft spawns. 0 is fully retracted and 1 is fully extended.

<br>

## CTLINVGW

> CTLINVGW 1.0

Control how far the variable geometry wings are extended when the aircraft spawns. 0 is fully swept and 1 is fully extended.

<br>


## CTLATVGW

> CTLATVGW TRUE

Allow the user to override the automatic speed-controlled variable geometry wing movement.

<br>


## HRDPOINT

> HRDPOINT -0.893m -1.141m 1.169m B500*2 AGM65*2 AIM120*2 AIM9*2 AIM9X*2 $INTERNAL<br> 
> HRDPOINT 0m -1.465m 0.675m FUEL&1200

There are three parts to the Hardpoint definition lines. 

### Hardpoint location

The position of the hardpoint defines where the weapon SRF model origin (0,0,0) will render.

See the [Coordinate System Definition](#-YSFlight-Coordinate-System) for more about the order of inputs.

### Permitted Weapons

Only one weapon type is allowed on a hardpoint at a time. For all weapons besides external fuel tanks, multiple weapons of the same type may be loaded on a hardpoint. For external fuel tanks, the quantity of fuel (in kg) is defined as shown in the second example, but if not defined, YSFlight will use 800kg. For all other weapons the maximum quantity of the weapon that can be loaded is defined with an asterix * and then the number.

### Internal Weapons

Some hardpoints can be defined as INTERNAL which means that for all bombs on that hardpoint, the bomb bay doors need to be open before the bomb can be dropped. If the weapon bay is closed when the player tries to drop a bomb, the weapon bay will be automatically opened and then the player must command another bomb drop.


<br>


## GUNSIGHT

> GUNSIGHT TRUE

Allows the aircraft to have a radar ranging gunsight. YSFlight assumes TRUE if not defined in the DAT File.

<br>


## GUNPOWER

> GUNPOWER 4

Defines how much damage each bullet does. If not defined, GUNPOWER defaults to 1.

<br>


## 

>

<br>


## 

>

<br>


## 

>

<br>


## 

>

<br>


## 

>

<br>





# Aircraft DAT Variable Summary

| Variable        | Required? | Input                                | Unit Type |
|-----------------|-----------|--------------------------------------|-----------|
| IDENTIFY        | Yes       | String in quotation marks            | N/A       |
| SUBSTNAM        | No        | String in quotation marks            | N/A       |
| CATEGORY        | Yes       | Pre-defined String                   | N/A       |
| AFTBURNR        | Yes       | TRUE/FALSE                           | Boolean   |
| THRAFTBN        | Yes*      | Number                               | Weight    |
| THRMILIT        | Yes*      | Number                               | Weight    |
| PROPELLR        | Yes**     | Number                               | Power     |
| PROPVMIN        | Yes**     | Number                               | Speed     |
|        PROPEFCY | No**      | Number                               | N/A       |
|                 |           |                                      |           |
|                 |           |                                      |           |
|                 |           |                                      |           |
|                 |           |                                      |           |
|                 |           |                                      |           |
|                 |           |                                      |           |
|                 |           |                                      |           |
|                 |           |                                      |           |
|                 |           |                                      |           |
|                 |           |                                      |           |
|                 |           |                                      |           |
|                 |           |                                      |           |
|                 |           |                                      |           |
|                 |           |                                      |           |
| *               |           | For Jet Engine Aircraft              |           |
| **              |           | For simple propeller engine aircraft |           |



# YSFlight Coordinate System

For dimensions, the following order is used for coordinates:

- Left / Right, Positive Right
- Up / Down, Positive Up
- Fore / Aft, Positive Forward


For angles, the following order is used:

- Rotate about the vertical axis, Positive ==TBD==
- Rotate about the hotizontal axis, Positive Down
- Rotate about the logitudinal axis, Positive ==TBD==


For Vectors, the following order is used. 
- Left / Right, Positive Right
- Up / Down, Positive Up
- Fore / Aft, Positive Forward

Note: Most vectors defined in DAT files are [unit vectors](https://en.wikipedia.org/wiki/Unit_vector), but some are used to define velocity.