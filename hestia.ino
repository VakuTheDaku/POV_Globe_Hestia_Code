
#define Hall_Sensor A0          //A0 used with analog output, D2 with digital output
#define Hall_Sensor_D 3
#include <FastLED.h>
#define NUM_LEDS 38
#define DATA_PIN 13
int Val1=0,Val2=0;
#define CLOCK_PIN 13
unsigned char i;
unsigned char m;
unsigned int wait = 50;
unsigned int wait2 = 500;
bool hall = 0;
CRGB leds[NUM_LEDS];
bool H[8][5] = {
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 1, 1, 1, 1},
  {1, 1, 1, 1, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1}
};

bool E[8][5] = {
  {1, 1, 1, 1, 1},
  {1, 0, 0, 0, 0},
  {1, 0, 0, 0, 0},
  {1, 1, 1, 1, 1},
  {1, 1, 1, 1, 1},
  {1, 0, 0, 0, 0},
  {1, 0, 0, 0, 0},
  {1, 1, 1, 1, 1}
};
bool S[8][5] = {
  {1, 1, 1, 1, 1},
  {1, 0, 0, 0, 0},
  {1, 0, 0, 0, 0},
  {1, 1, 1, 1, 1},
  {0, 0, 0, 0, 1},
  {0, 0, 0, 0, 1},
  {0, 0, 0, 0, 1},
  {1, 1, 1, 1, 1},
};
bool T[8][5] = {
  {1, 1, 1, 1, 1},
  {0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0},
};
bool I[8][5] =  {
  {1, 1, 1, 1, 1},
  {0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0},
  {1, 1, 1, 1, 1}
};

bool A[8][5] = {
  {1, 1, 1, 1, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 1, 1, 1, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
};








void setup() {
   Serial.begin(9600);
  pinMode(Hall_Sensor_D,INPUT);
 
    FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
}



void loop() {
   Serial.print("HI");
   Val1=analogRead(Hall_Sensor);            //We read both values and display them raw on the serial monitor
   Serial.print(Val1);
   Val2=digitalRead(Hall_Sensor_D);
   Serial.print("\t");
   Serial.println(Val2);
   while(Val1>1021){
    hall=1;
    break;
   } 
  if (hall == 1) {
    for (m = 0; m < 5; m++) {
      for (i = 0; i < 8; i++) {
        if (H[i][m] == 1) {
          leds[i + 11] = CRGB::Violet;
        }
        else {
          leds[i + 11] = CRGB::Black;
        }
      }
      FastLED.show();
      delayMicroseconds(wait);
    }

    for (int i = 0; i < 38; i++) {
      leds[i] = CRGB ::Black;
    }
    FastLED.show();
    delayMicroseconds(wait2);

    for (m = 0; m < 5; m++) {
      for (i = 0; i < 8; i++) {
        if (E[i][m] == 1) {
          leds[i + 11] = CRGB::Indigo;
        }
        else {
          leds[i + 11] = CRGB::Black;
        }
      }
      FastLED.show();
      delayMicroseconds(wait);
    }

    for (int i = 0; i < 38; i++) {
      leds[i] = CRGB ::Black;
    }
    FastLED.show();
    delayMicroseconds(wait2);

    for (m = 0; m < 5; m++) {
      for (i = 0; i < 8; i++) {
        if (S[i][m] == 1) {
          leds[i + 11] = CRGB::Blue;
        }
        else {
          leds[i + 11] = CRGB::Black;
        }
      }
      FastLED.show();
      delayMicroseconds(wait);
    }

    for (int i = 0; i < 38; i++) {
      leds[i] = CRGB ::Black;
    }
    FastLED.show();
    delayMicroseconds(wait2);

    for (m = 0; m < 5; m++) {
      for (i = 0; i < 8; i++) {
        if (T[i][m] == 1) {
          leds[i + 11] = CRGB::Green;
        }
        else {
          leds[i + 11] = CRGB::Black;
        }
      }
      FastLED.show();
      delayMicroseconds(wait);
    }

    for (int i = 0; i < 38; i++) {
      leds[i] = CRGB ::Black;
    }
    FastLED.show();
    delayMicroseconds(wait2);


    for (m = 0; m < 5; m++) {
      for (i = 0; i < 8; i++) {
        if (I[i][m] == 1) {
          leds[i + 11] = CRGB::Yellow;
        }
        else {
          leds[i + 11] = CRGB::Black;
        }
      }
      FastLED.show();
      delayMicroseconds(wait);
    }

    for (int i = 0; i < 38; i++) {
      leds[i] = CRGB ::Black;
    }
    FastLED.show();
    delayMicroseconds(wait2);


    for (m = 0; m < 5; m++) {
      for (i = 0; i < 8; i++) {
        if (A[i][m] == 1) {
          leds[i + 11] = CRGB::Red;
        }
        else {
          leds[i + 11] = CRGB::Black;
        }
      }
      FastLED.show();
      delayMicroseconds(wait);
    }

    for (int i = 0; i < 38; i++) {
      leds[i] = CRGB ::Black;
    }
    FastLED.show();
    delayMicroseconds(wait2);


    for (int i = 0; i < 38; i++) {
      leds[i] = CRGB ::Red;
    }
    leds[18] = CRGB::Red;
    FastLED.show();
    delayMicroseconds(wait);

    for (int i = 0; i < 38; i++) {
      leds[i] = CRGB ::Black;
    }
    FastLED.show();
    delayMicroseconds(wait2);
    hall = 0;
  }
  
}
