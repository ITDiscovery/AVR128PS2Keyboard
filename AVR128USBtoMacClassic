#include <PS2KeyAdvanced.h>
#define DATAPIN PIN_PA3
#define IRQPIN  PIN_PA2
#define MAC_DATA_PIN PIN_PF1
#define MAC_CLOCK_PIN PIN_PF0
#define MAC_MOUSE_BUTTON PIN_PD7 //Pin 7 (SW-) 
#define MAC_MOUSE_X2 PIN_PC0 //Pin 4 (X2)
#define MAC_MOUSE_Y1 PIN_PC1 //Pin 9 (Y1) 
#define MAC_MOUSE_X1 PIN_PC2 //Pin 5 (X1)
#define MAC_MOUSE_Y2 PIN_PC3 //Pin 8 (Y2)

uint16_t lookup[120][3] =

/* Unshifted MacClassic - Make
    `     1 2 3 4 5 6 7 8 9 0 - = <BKSP>
   <TAB>  Q W E R T Y U I O P [ ] \
   <CAPS> A S D F G H J K L ; ' <ENTER>
   <SHFT> Z X C V B N M , .  / <SHFT> 
   <CTRL> <STRT>   <SPACE> <STRT>  <CTRL>  */
  {  
  {64,0x64},   {49,0x24},{50,0x26},{51,0x28},{52,0x2A},{53,0x2E},{54,0x2C},{55,0x34},{56,0x38},{57,0x32},{48,0x3A},{60,0x36},{95,0x30},{284,0x66},
  {285,0x60},  {81,0x18},{87,0x1A},{69,0x1C},{82,0x1E},{84,0x22},{89,0x20},{85,0x40},{73,0x44},{79,0x3E},{80,0x46},{93,0x42},{94,0x3C},{92,0x54},
  {4355,0x00}, {65,0x01},{83,0x02},{68,0x04},{70,0x06},{71,0x0A},{72,0x08},{74,0x4C},{75,0x50},{76,0x4A},{91,0x52},{58,0x4E},{286,0x48},
  {16646,0x70},{90,0x0C},{88,0x0E},{67,0x10},{86,0x12},{66,0x16},{78,0x5A},{77,0x5C},{59,0x56},{61,0x5E},{62,0x58},{16647,0x70},
  {8456,0x74}, {780,0x6E},{287,0x62},{781,0x68}, {8457,0x74},{270,0x7C},


  /* Unshifted MacClassic - Break
    `     1 2 3 4 5 6 7 8 9 0 - = <BKSP>
   <TAB>  Q W E R T Y U I O P [ ] \
   <CAPS> A S D F G H J K L ; ' <ENTER>
   <SHFT> Z X C V B N M , .  / <SHFT> 
   <CTRL> <STRT>   <SPACE> <STRT>  <CTRL>  */
  {32832,0xE4},   {32817,0xA4},{32818,0xA6},{32819,0xA8},{32820,0xAA},{32821,0xAE},{32822,0xAC},{32823,0xB4},{32824,0xB8},{32825,0xB2},{32816,0xBA},{32828,0xB6},{32863,0xB0},{33052,0xE6},
  {33053,0xE0},  {32849,0x98},{32855,0x9A},{32837,0x9C},{32850,0x9E},{32852,0xA2},{32857,0xA0},{32853,0xC0},{32841,0xC4},{32847,0xBE},{32848,0xC6},{32861,0xC2},{32862,0xBC},{32860,0xD4},
  {33027,0x80}, {32833,0x81},{32851,0x82},{32836,0x84},{32838,0x86},{32839,0x8A},{32840,0x88},{32842,0xCC},{32843,0xD0},{32844,0xCA},{32859,0xD2},{32826,0xCE},{33054,0xC8},
  {33030,0xF0},{32858,0x8C},{32856,0x8E},{32835,0x90},{32854,0x92},{32834,0x96},{32846,0xDA},{32845,0xDC},{32827,0xD6},{32829,0xDE},{32830,0xD8},{33031,0xF0},
  {33032,0xF4}, {33036,0xEE},{33055,0xE2},{33037,0xE8}, {33033,0xF4}, {33038,0xFC}

};

PS2KeyAdvanced keyboard;
byte tabletop;
boolean mousestate = HIGH;


byte readByte() {
  byte b = 0;
  for (byte i = 0; i < 8; i++) {
    digitalWrite(MAC_CLOCK_PIN, LOW);
    delayMicroseconds(180);
    digitalWrite(MAC_CLOCK_PIN, HIGH);
    delayMicroseconds(80);
    b = (b << 1) | digitalRead(MAC_DATA_PIN);
    delayMicroseconds(140);
  }
  //Serial.println(b, HEX);
  //Serial.println(" -> ");
  return b;
}

void sendByte(byte b) {
  for (byte m = 128; m > 0; m >>= 1) {
    digitalWrite(MAC_DATA_PIN, !(b & m) ? LOW : HIGH);
    delayMicroseconds(40);
    digitalWrite(MAC_CLOCK_PIN, LOW);
    delayMicroseconds(120);
    digitalWrite(MAC_CLOCK_PIN, HIGH);
    delayMicroseconds(170);
  }
  digitalWrite(MAC_DATA_PIN, HIGH);
  //Serial.print(b, HEX);
  //Serial.println(" <- ");
}

byte readCmd() {
  pinMode(MAC_DATA_PIN, INPUT_PULLUP);
  delayMicroseconds(20);  
  while (digitalRead(MAC_DATA_PIN) != LOW);
  delayMicroseconds(400); // this is apparently required so we don't lose the first digit
  byte cmd = readByte();
  while (digitalRead(MAC_DATA_PIN) != HIGH);
  pinMode(MAC_DATA_PIN, OUTPUT);
  delayMicroseconds(20);
  return cmd;
}

byte readKey() {
  if( keyboard.available( ) ) {
    // read the next key
    uint16_t c = keyboard.read( );
    //Serial.print("Keyout=");
    //Serial.print(c);
    //Serial.print(" ");
    if (c==278) {
        Serial.println("Mouse Right");
        Quad(MAC_MOUSE_X1, MAC_MOUSE_X2);
        return 0;        
    } else if (c==277) {
        Serial.println("Mouse Left");
        Quad(MAC_MOUSE_X2, MAC_MOUSE_X1);
        return 0;        
    } else if (c==279) {
        Serial.println("Mouse Up");
        Quad(MAC_MOUSE_Y1, MAC_MOUSE_Y2);
        return 0;        
    } else if (c==280) {
        Serial.println("Mouse Down");
        Quad(MAC_MOUSE_Y2, MAC_MOUSE_Y1);
        return 0;
    } else if (c==281) {
        if (mousestate == HIGH) {
          Serial.println("Mouse Hold");
          mousestate = LOW;
          digitalWrite(MAC_MOUSE_BUTTON,LOW);
        } else {
          Serial.println("Mouse Release");
          mousestate = HIGH;
          digitalWrite(MAC_MOUSE_BUTTON,HIGH);
        }
        return 0;
    } else if (c==282) {
        Serial.println("Mouse Button");
        digitalWrite(MAC_MOUSE_BUTTON,LOW);
        delay(100);
        digitalWrite(MAC_MOUSE_BUTTON,HIGH);
        return 0;
    } else {
      Serial.print("Keycode=");
      Serial.print(c);
      uint16_t e = 0;
      while (lookup[e][0] != c and e < tabletop) {
        e++;
      }
      Serial.print(" lookup[");
      Serial.print(e);
      Serial.print("][1] = ");
      if (e < tabletop) {
        Serial.println(lookup[e][1],HEX);
        return lookup[e][1];  
      }
      else Serial.println("Not Found");
      return 0;
     }
   }
   return 0;
}

void setup() {
  Serial.begin(115200);
  // Configure the keyboard
  keyboard.begin(DATAPIN,IRQPIN);
  Serial.println("Test Begins");
  pinMode(MAC_CLOCK_PIN, OUTPUT);
  pinMode(MAC_DATA_PIN, INPUT_PULLUP);
  pinMode(MAC_MOUSE_BUTTON, OUTPUT);
  digitalWrite(MAC_MOUSE_BUTTON, HIGH);
  pinMode(MAC_MOUSE_X1, OUTPUT);
  pinMode(MAC_MOUSE_X2, OUTPUT);
  pinMode(MAC_MOUSE_Y1, OUTPUT);
  pinMode(MAC_MOUSE_Y2, OUTPUT);

  // This template has 89 entries
  tabletop = 118;
  delay(100);
  //sendByte(0x7B);
}

void loop() {
  byte mcmd = readCmd();
  byte keyout;
  switch (mcmd) {
    case 0x00:
      keyout = readKey();
      if (keyout > 0) {
        // Send Keypress
        sendByte(keyout);
      } else {
        sendByte(0x7B);
      }    
    // Inquiry for keypress
    case 0x10: //inquiry
      keyout = readKey();
      if (keyout > 0) {
        // Send Keypress
        sendByte(keyout);
      } else {
        sendByte(0x7B);
      }
      break;
    case 0x14: // instant
      keyout = readKey();
      if (keyout > 0) {
        sendByte(keyout);
      }  else {
        sendByte(0x7B);
      }
      break;
    case 0x16: // model number M0110
      sendByte(0x09);
      break;
    case 0x36: // test
      sendByte(0x7d);
      break;
  }
}

void Quad (int porta, int portb) {
  Serial.print(porta);
  Serial.print(" ");
  Serial.println(portb);
  for (int b = 0; b < 5; b++) {
     //Phase 1
     digitalWrite(porta,HIGH);
     digitalWrite(portb,HIGH);
     delay(3);
     //Phase 2
     digitalWrite(porta,HIGH);
     digitalWrite(portb,LOW);
     delay(3);  
     //Phase 3
     digitalWrite(porta,LOW);
     digitalWrite(portb,LOW);
     delay(3);  
     //Phase 4
     digitalWrite(porta,LOW);
     digitalWrite(portb,HIGH);
     delay(3);  
  }
  digitalWrite(porta,LOW);
  digitalWrite(portb,LOW);
}
