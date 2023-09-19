#include <HID-Project.h>
#include <HID-Settings.h> //Libraries for the keyboard emulation

#include <Adafruit_NeoPixel.h> // Library for controlling the  RGB LED

#define buttonPin 7 //input pin for pushbutton

bool buttonState; // Stores the debounced state of the button
bool lastButtonState = HIGH; // Stores the last state of the button to see if the state has changed

unsigned long lastDebounceTime = 0; //The last time, in milliseconds, that the debounce routine was run
unsigned long debounceDelay = 25; //Time to wait before accepting a change in reading as real and not interference

unsigned long pixelHue = 0; // The HSV hue of the RGB led

boolean pressed = false;

#define LED_PIN 15
#define EFFECT_SPEED 3

Adafruit_NeoPixel led(1, LED_PIN, NEO_GRB + NEO_KHZ800); //Initialize the LED object


void setup() {
  pinMode(buttonPin, INPUT_PULLUP); //Set the pin for the button as an input, and turn on the internal pullup resistor

  Keyboard.begin(); //Initialize the keyboard

  led.begin(); //Initialize the LED and set brightness to max
  led.show();
  led.setBrightness(255);
}

void loop(){
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

// we'll only act on a button press if button is high and pressed is false

  if (!pressed && buttonState == HIGH) {   
    // turn LED on: and set pressed true
    pressed = true;    

  } 
  else if (pressed && buttonState == LOW) {
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press('a');
    delay(100);
    Keyboard.releaseAll();
    delay(100);
    Keyboard.print("PASSWORD\n");
    // turn LED off: and reset pressed flag
    pressed = false;
  }
}
