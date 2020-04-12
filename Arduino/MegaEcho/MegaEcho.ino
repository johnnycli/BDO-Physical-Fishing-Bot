#define space 2
#define r 3
#define w 4
#define a 5
#define s 6
#define d 7

bool lootnreset = true;
bool combo = false;
int currind = 0;
char list[10];

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


void inputcombo() {

}

//After combo input. Tap R to collect and space to restart.
void resetroutine() {
  toggle(r, 500, 3);
  toggle(space, 500, 3);
}



void setup() {
  //Start the serial bus for debug and data recption
  Serial.begin(9600);
  Serial1.begin(9600);

  //Initialization of pin modes
  pinMode(space, OUTPUT);
  pinMode(r, OUTPUT);
  pinMode(w, OUTPUT);
  pinMode(a, OUTPUT);
  pinMode(s, OUTPUT);
  pinMode(d, OUTPUT);

  //Reset all output pins to LOW.
  digitalWrite(space, LOW);
  digitalWrite(r, LOW);
  digitalWrite(w, LOW);
  digitalWrite(a, LOW);
  digitalWrite(s, LOW);
  digitalWrite(d, LOW);
}

void loop() {
  char st;
  if (Serial.available() > 0) {
    st = Serial.read();
    Serial1.write(st);
    if (st == 'B') {
      currind = 0;
      for (int i = 0; i < 10; i++) {
        list[i] = (char)0;
      }
    } else {
      list[currind] = st;
      currind++;
    }
  }else{
    Serial.write('n');
  }
}


//----------------------------------------------------tap r and space for more fishing----------------------------------------
