#include "mbed.h"

DigitalIn ButtonA(PG_0); //Button A
DigitalIn ButtonB(PG_1); //Button B 
DigitalOut YellowLED(PC_6); //yellow Traffic 1

// main() runs in its own thread in the OS
int main()
{
    int btnA;
    int btnB;    
    // Turn OFF the yellow LED
    YellowLED = 0;

    while (true) {
    
        // Wait for the button to be pressed
        do {
            btnA = ButtonA; //Read button A
            btnB = ButtonB; //Read Button B
        } while (btnA == 0 || btnB == 0);


        //Toggle the yellow LED
        YellowLED = !YellowLED;

        //Wait for noise to settle
        wait_us(10000);

        // Wait for the button to be released
        do {
            btnA = ButtonA; //Read button A
            btnB = ButtonB; //Read button B
        } while (btnA == 1 || btnB == 1);

        //Wait for noise to settle
        wait_us(10000);
    }
}

