#define CLKPin PIN_PA2 //D+
#define DATAPin PIN_PA3 //D-

bool dflag = false;
volatile byte clkcnt=0;
volatile int scancode=0;
volatile byte keyrdy=0;

void setup() {
  // put your setup code here, to run once:
  PORTA.PIN2CTRL  = 0b01001011; //INVEN = 0, INLVL=1 (TTL), PULLUPEN = 1, ISC=[2:0] = 3 trigger falling
  pinMode(DATAPin,INPUT_PULLUP);
  pinMode(PIN_PD7,OUTPUT);
  pinMode(PIN_PD6,OUTPUT);
  Serial.begin(115200);
  Serial.println("Test Begins:");
}

ISR(PORTA_PORT_vect) {
  byte flags = PORTA.INTFLAGS;
  PORTA.INTFLAGS = flags; //clear flags
  if (flags & 0x04) {
    dflag = digitalRead(DATAPin);
    if (clkcnt==11) {
          clkcnt = 0;
          keyrdy = 1;
          digitalWriteFast(PIN_PD7,CHANGE);
    } else {
           if (dflag) {
               scancode = scancode << 1;
               scancode++;
               digitalWriteFast(PIN_PD6,HIGH); 
               } else {
               scancode = scancode << 1;
               digitalWriteFast(PIN_PD6,LOW); 
               }
    }      
    clkcnt++;
    } 
}

void loop() {
  // put your main code here, to run repeatedly:
 //Serial.println(clockcnt);  
 if (keyrdy==1) {
    Serial.println(scancode,BIN);
    scancode=0;
    keyrdy=0;
 }
