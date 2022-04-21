#define CLKPin PIN_PA2 //D+
#define DATAPin PIN_PA3 //D-
byte clkcnt=0;
byte scancode=0;
byte keyrdy=0;

void setup() {
  // put your setup code here, to run once:
  PORTA.PIN2CTRL  = 0b01001011; //INVEN = 0, INLVL=1 (TTL), PULLUPEN = 1, ISC=[2:0] = 3 trigger falling
  pinMode(DATAPin,INPUT_PULLUP);
  pinMode(PIN_PD7,OUTPUT);
  Serial.begin(115200);
  Serial.println("Test Begins:");
}

// Falling Edge on PAx
ISR(PORTA_PORT_vect) {
  byte flags = PORTA.INTFLAGS;
  PORTA.INTFLAGS = flags; //clear flags
  //It's PA2
  if (flags & 0x04) {
    //strobe the     
    digitalWriteFast(PIN_PD7,CHANGE);
    clkcnt++;
    if (clkcnt > 2) {
      if (clkcnt == 11) {
        //Finished getting scancode
        clkcnt = 0;
        keyrdy = 1;
      } else if (digitalRead(DATAPin)) {
        scancode++;
        scancode = scancode << 1;      
        } else {
        scancode = scancode << 1;
        }
      } 
    }
}

void loop() {
  // put your main code here, to run repeatedly:
 //Serial.println(clockcnt);  
 if (keyrdy==1) {
    Serial.print(scancode);
    scancode=0;
    keyrdy=0;
 }
}
