int x_axis_pin = 6;
int Y_axis_pin = 5;
int pot = A0;

int point_delay = 1000;
#define NVertices 38

byte x_axis[NVertices] = {
  105, 105,  95,  86,  80,  78,  80,  86,  95, 105, 115, 124,
  130, 132, 134, 140, 149, 159, 169, 178, 184, 186, 184, 178,
  169, 159, 159, 157, 151, 142, 132, 132, 132, 122, 113, 107,
  105, 159
};

byte y_axis[NVertices] = {
  300, 214, 212, 206, 197, 187, 177, 168, 162, 160, 162, 168,
  177, 187, 177, 168, 162, 160, 162, 168, 177, 187, 197, 206,
  212, 214, 300, 310, 319, 325, 327, 319, 327, 325, 319, 310,
  300, 300
};

void setup() {
  // put your setup code here, to run once:
  pinMode(x_axis_pin, OUTPUT);
  pinMode(Y_axis_pin, OUTPUT);
  pinMode(pot, INPUT);

  TCCR0A = TCCR0A & B10100011 + TCCR0A | B10100011;
  TCCR0B = TCCR0B & B00000001 + TCCR0B | B00000001;
  TIMSK0 = TIMSK0 & B11111000;
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned char loopCount;
  point_delay = map(analogRead(pot), 0, 1024, 10, 2000);
  for(loopCount = 0; loopCount < NVertices; ++loopCount) {
    analogWrite(x_axis_pin, x_axis[loopCount]);
    analogWrite(Y_axis_pin, y_axis[loopCount] - 100);
    delayMicroseconds(point_delay);
  }
}
