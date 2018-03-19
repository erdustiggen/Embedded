In section one (GPIOs) we have 16 interrupt lines. They are line0 to line15 and they also represent pin number. 
This means, PA0 is connected to Line0 and PA13 is connected to Line13.

You have to know that PB0 is also connected to Line0 and PC0 also and so on. This is for all pins on board.
All Px0 (where x is GPIO name) pins are connected to Line0 and let’s say all Px3 are connected to Line3 on the Interrupt channel.

IMPORTANT: You can not use two pins on one line simultaneously:

PA0 and PB0 and PC0 and so on, are connected to Line0, so you can use only one pin at one time to handle interrupt from there.
PA0 and PA5 are connected to different lines, they can be used at the same time.

Each line can trigger an interrupt on rising, falling or rising_falling enge on signal.


