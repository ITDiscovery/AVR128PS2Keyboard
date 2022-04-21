void setup() {
  // put your setup code here, to run once:
  PORTA.PIN2CTRL  = 0b01001011; //INVEN = 0, INLVL=1 (TTL), PULLUPEN = 1, ISC=[2:0] = 3 trigger falling
  pinMode(PIN_PD7,OUTPUT);
    
}

ISR(PORTA_PORT_vect) {
  byte flags = PORTA.INTFLAGS;
  PORTA.INTFLAGS = flags; //clear flags
  if (flags & 0x04) {
    digitalWriteFast(PIN_PD7,CHANGE);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
 //Serial.println(clockcnt);  
}
