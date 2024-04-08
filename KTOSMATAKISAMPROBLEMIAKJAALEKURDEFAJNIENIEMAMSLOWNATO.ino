#define S0_PIN 3
#define S1_PIN 4
#define S2_PIN 5
#define S3_PIN 6
#define OUT_PIN  2

int ledState = LOW;
unsigned long previousMillis = 0;
unsigned long interval = 1000;
int przel1 = 8;  //ustawianie pinow z przelacznikami
int przel2 = 9;
int przel3 = 10;
int przelm1 = 13;
int przelm2 = 1;
int przelm3 = 7;
int przelm4 = 11;
int przelm5 = 12;
void setup() {
  // put your setup code here, to run once:
  // Set the S0, S1, S2, S3 Pins as Output
  pinMode(S0_PIN, OUTPUT);
  pinMode(S1_PIN, OUTPUT);
  pinMode(S2_PIN, OUTPUT);
  pinMode(S3_PIN, OUTPUT);
  //Set OUT_PIN as Input
  pinMode(OUT_PIN, INPUT);
  // Set Pulse Width scaling to 20%
  digitalWrite(S0_PIN, HIGH);
  digitalWrite(S1_PIN, LOW);
  pinMode(przel1, OUTPUT);
  pinMode(przel2, OUTPUT);
  pinMode(przel3, OUTPUT);
  pinMode(przelm1, OUTPUT);
  pinMode(przelm2, OUTPUT);
  pinMode(przelm3, OUTPUT);
  pinMode(przelm4, OUTPUT);
  pinMode(przelm5, OUTPUT);
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
 int r, g, b, rt, gt, bt;     // declare red,green,blue as integers
rt=0,gt=0,bt=0;
digitalWrite(przel1, HIGH);       // wlacz przelacznik
  digitalWrite(przel3, HIGH);
    delay(500);  
      digitalWrite(przel3, LOW);        // wylacz przelacz
         
  digitalWrite(przel2, HIGH);       // wlacz przelacznik
  delay(200);
  digitalWrite(przel1, LOW);        // wylacz przelacz
    delay(120);  
  digitalWrite(przel2, LOW);        // wylacz przelaczniknik


  delay(2500);                       // czekaj 3 sekundy
  for (int i=0;i<10;i++){
  r = process_red_value();
  g = process_green_value();
  b = process_blue_value();
  rt=rt+r;
  gt=gt+g;
  bt=bt+b;
  Serial.print("r = ");  // print each frequency value for r,g and b
  Serial.print(r);
  Serial.print(" ");
  Serial.print("g = ");
  Serial.print(g);
  Serial.print(" ");
  Serial.print("b = ");
  Serial.print(b);
  Serial.print(" ");
  Serial.println();
}
Serial.print("rt = ");  // print each frequency value for r,g and b
  Serial.print(int(rt/10));
  Serial.print(" ");
  Serial.print("gt = ");
  Serial.print(int(gt/10));
  Serial.print(" ");
  Serial.print("bt = ");
  Serial.print(int(bt/10));
  Serial.print(" ");
  Serial.println();
  if (int(rt/10) < 170 & int(rt/10) > 129 & int(gt/10) < 256 & int(gt/10) > 230)
  {
    Serial.println("red block");
    delay(200);
  }
     else if (int(rt/10) < 230 & int(rt/10) > 195 & int(gt/10) < 270 & int(gt/10) > 234)
  {
    Serial.println("blue Block");
  }
    else if (int(rt/10) < 210 & int(rt/10) > 195 & int(gt/10) < 235 & int(gt/10) > 220)
  {
    Serial.println("green Block");
    delay(1000);
    digitalWrite(przelm3, HIGH);        // wylacz przelacz
    delay(1000);  
    digitalWrite(przelm3, LOW);        // wylacz przelaczniknik
  }
    else
  {
    Serial.println("no");
    delay(200);
  }
  rt=0,gt=0,bt=0;


  delay(2500);                       // czekaj 3 sekundy
}
int process_red_value()
{
  digitalWrite(S2_PIN, LOW);
  digitalWrite(S3_PIN, LOW);
  int pulse_length = pulseIn(OUT_PIN, LOW);
  return pulse_length;
}
int process_green_value()
{
  digitalWrite(S2_PIN, HIGH);
  digitalWrite(S3_PIN, HIGH);
  int pulse_length = pulseIn(OUT_PIN, LOW);
  return pulse_length;
}
int process_blue_value()
{
  digitalWrite(S2_PIN, LOW);
  digitalWrite(S3_PIN, HIGH);
  int pulse_length = pulseIn(OUT_PIN, LOW);
  return pulse_length;
}