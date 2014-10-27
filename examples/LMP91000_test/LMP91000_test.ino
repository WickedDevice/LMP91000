#include <Wire.h>
#include "LMP91000.h"

LMP91000 lmp91000;

void setup(void){
      Serial.begin(115200);
      Serial.println("LMP91000 Test");
      Wire.begin();
      
      // initialize the slot select pins to "not selected"
      pinMode(7, OUTPUT);  digitalWrite(7, LOW);
      pinMode(9, OUTPUT);  digitalWrite(9, LOW);
      pinMode(10, OUTPUT); digitalWrite(10, LOW);      
      digitalWrite(9, HIGH); // select CO
      
      // settings for CO
      uint8_t res = lmp91000.configure( 
            LMP91000_TIA_GAIN_350K | LMP91000_RLOAD_10OHM,
            LMP91000_REF_SOURCE_EXT | LMP91000_INT_Z_20PCT 
                  | LMP91000_BIAS_SIGN_POS | LMP91000_BIAS_1PCT,
            LMP91000_FET_SHORT_DISABLED | LMP91000_OP_MODE_AMPEROMETRIC                  
      );
      
      Serial.print("Config Result: ");
      Serial.println(res);
      
      Serial.print("STATUS: ");
      Serial.println(lmp91000.read(LMP91000_STATUS_REG),HEX);
      Serial.print("TIACN: ");
      Serial.println(lmp91000.read(LMP91000_TIACN_REG),HEX);
      Serial.print("REFCN: ");
      Serial.println(lmp91000.read(LMP91000_REFCN_REG),HEX);
      Serial.print("MODECN: ");
      Serial.println(lmp91000.read(LMP91000_MODECN_REG),HEX);                  
      
}

void loop(void){

}
