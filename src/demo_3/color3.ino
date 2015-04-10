// Init pin
int s0          = 5, 
s1          = 6, 
s2          = 4, 
s3          = 3,
output  = 2,
led        = 8;

unsigned int counter=0;

void setup() {
  Serial.begin(115200);

  pinMode(led, OUTPUT);
  setup_led();
  setup_frequencyScaling();
  setup_filter();

  attachInterrupt(0, ISR_INTO, LOW);
}

void setup_led() {
  digitalWrite(led, HIGH);
}

void setup_filter() {
  digitalWrite(s2, HIGH);
  digitalWrite(s3, LOW);
}

void setup_frequencyScaling() {
  digitalWrite(s0, LOW);
  digitalWrite(s1, HIGH);
}

void loop() {
  Serial.println(counter);
  counter = 0;
  delay(1000);
}

void ISR_INTO()
{
  counter++;
}

