const int PIN_OUT = 13;
const int PIN_IN = A0;

const int SAMPLE_COUNT = 256;

int time[SAMPLE_COUNT];
int volt[SAMPLE_COUNT];

void measureFor(int duration, int sampling_period, int t0, int i) {
  for (int t = t0; t < t0 + duration; t += sampling_period, i++) {
    time[i] = t;
    volt[i] = analogRead(PIN_IN);
    delay(sampling_period);
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(PIN_OUT, OUTPUT);
}

void loop() {
  digitalWrite(PIN_OUT, HIGH);
  measureFor(500, 50, 0, 0);
  digitalWrite(PIN_OUT, LOW);
  measureFor(5000, 50, 500, 10);
  delay(4500);
  
  for (int i = 0; i < SAMPLE_COUNT; i++) {
    Serial.print("(");
    Serial.print(time[i]);
    Serial.print(",");
    Serial.print(volt[i] * (5.0/1023.0));
    Serial.println(")");
  }
}

