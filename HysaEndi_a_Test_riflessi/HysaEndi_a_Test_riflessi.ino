#define LED 13
#define BUTTON 7
int val = 0;



void setup() {
  // put your setup code here, to run once:
 
  pinMode (LED, OUTPUT);
  pinMode ( BUTTON, INPUT);
  

}  

void loop() {
  // put your main code here, to run repeatedly:
   val = digitalRead(BUTTON);

 if (val == HIGH)
 {
  digitalWrite (LED,LOW);
 }
 else
 {
  digitalWrite (LED,HIGH);
 }
}
