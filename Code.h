//Credit to https://gist.github.com/jamesotron/ for original code
//I simply modified to run 2 LED's and run the colour changes a bit slower
const int redPin1 = 6;
const int greenPin1 = 5;
const int bluePin1 = 3;

const int redPin2 = 11;
const int greenPin2 = 10;
const int bluePin2 = 9;

void setup() {
  // Start off with the LED off.
  setColourRgb(0,0,0);
}

void loop() {
  unsigned int rgbColour[3];

  // Start off with red.
  rgbColour[0] = 255;
  rgbColour[1] = 0;
  rgbColour[2] = 0;  

  // Choose the colours to increment and decrement.
  for (int decColour = 0; decColour < 3; decColour += 1) {
    int incColour = decColour == 2 ? 0 : decColour + 1;

    // cross-fade the two colours.
    for(int i = 0; i < 255; i += 1) {
      rgbColour[decColour] -= 1;
      rgbColour[incColour] += 1;
      
      setColourRgb(rgbColour[0], rgbColour[1], rgbColour[2]);
      delay(100);
    }
  }
  delay(100);
}

void setColourRgb(unsigned int red, unsigned int green, unsigned int blue) {
  analogWrite(redPin1, red);
  analogWrite(greenPin1, green);
  analogWrite(bluePin1, blue);
  analogWrite(redPin2, red);
  analogWrite(greenPin2, green);
  analogWrite(bluePin2, blue);
 }