#define space 2
#define r 3
#define w 4
#define a 5
#define s 6
#define d 7

int bdelay =100;

//Toggle the digital output pins.
void toggle(int pin, int dms, int cyc) {
  unsigned long mtime = 0;
  for (int i = 0; i < cyc; i++) {
    mtime = millis();
    while (millis() < mtime + dms) {
      digitalWrite(pin, HIGH);
    }
    mtime = millis();
    while (millis() - mtime < dms / 2) {
      digitalWrite(pin, LOW);
    }
  }
}



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial1.begin(9600);
  pinMode(space, OUTPUT);
  pinMode(r, OUTPUT);
  pinMode(w, OUTPUT);
  pinMode(a, OUTPUT);
  pinMode(s, OUTPUT);
  pinMode(d, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  char st;

  if (Serial.available() > 0) {
    st = Serial.read();
    Serial1.write(st);

    if (st == 'W') {
      toggle(w, bdelay, 1);
    }
    else if (st == 'A') {
      toggle(a, bdelay, 1);
    }
    else if (st == 'S') {
      toggle(s, bdelay, 1);
    }
    else if (st == 'D') {
      toggle(d, bdelay, 1);
    }
    else if (st == 'P') {
      toggle(space, bdelay, 1);
    }
    else if (st == 'Q') {
      toggle(r, bdelay, 3);
      toggle(space, bdelay, 3);
    }
    else {
    }
  }


}
