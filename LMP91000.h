#ifndef LMP91000_H
#define LMP91000_H

#if defined(ARDUINO) && ARDUINO >= 100
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

#include <Wire.h>

#define LMP91000_I2C_ADDRESS          (0x48)    /* Device Address */
#define LMP91000_STATUS_REG           (0x00)    /* Read only status register */
#define LMP91000_LOCK_REG             (0x01)    /* Protection Register */
#define LMP91000_TIACN_REG            (0x10)    /* TIA Control Register */
#define LMP91000_REFCN_REG            (0x11)    /* Reference Control Register*/
#define LMP91000_MODECN_REG           (0x12)    /* Mode Control Register */

// LOCK register bitfield definition
#define LMP91000_WRITE_LOCK           (0x01) //default
#define LMP91000_WRITE_UNLOCK         (0x00)

// STATUS register bitfield definition
#define LMP91000_READY                (0x01)
#define LMP91000_NOT_READY            (0x00)

// TIACN register bitfield definition
#define LMP91000_TIA_GAIN_EXT         (0x00) //default
#define LMP91000_TIA_GAIN_2P75K       (0x04)
#define LMP91000_TIA_GAIN_3P5K        (0x08)
#define LMP91000_TIA_GAIN_7K          (0x0C)
#define LMP91000_TIA_GAIN_14K         (0x10)
#define LMP91000_TIA_GAIN_35K         (0x14)
#define LMP91000_TIA_GAIN_120K        (0x18)
#define LMP91000_TIA_GAIN_350K        (0x1C)
#define LMP91000_RLOAD_10OHM          (0X00)        
#define LMP91000_RLOAD_33OHM          (0X01)
#define LMP91000_RLOAD_50OHM          (0X02)
#define LMP91000_RLOAD_100OHM         (0X03) //default

// REFCN register bitfield definition
#define LMP91000_REF_SOURCE_INT       (0x00) //default
#define LMP91000_REF_SOURCE_EXT       (0x80) 
#define LMP91000_INT_Z_20PCT          (0x00)
#define LMP91000_INT_Z_50PCT          (0x20) //default
#define LMP91000_INT_Z_67PCT          (0x40)
#define LMP91000_INT_Z_BYPASS         (0x60)
#define LMP91000_BIAS_SIGN_NEG        (0x00) //default
#define LMP91000_BIAS_SIGN_POS        (0x10)
#define LMP91000_BIAS_0PCT            (0x00) //default
#define LMP91000_BIAS_1PCT            (0x01) 
#define LMP91000_BIAS_2PCT            (0x02) 
#define LMP91000_BIAS_4PCT            (0x03) 
#define LMP91000_BIAS_6PCT            (0x04) 
#define LMP91000_BIAS_8PCT            (0x05) 
#define LMP91000_BIAS_10PCT           (0x06) 
#define LMP91000_BIAS_12PCT           (0x07) 
#define LMP91000_BIAS_14PCT           (0x08) 
#define LMP91000_BIAS_16PCT           (0x09) 
#define LMP91000_BIAS_18PCT           (0x0A) 
#define LMP91000_BIAS_20PCT           (0x0B) 
#define LMP91000_BIAS_22PCT           (0x0C) 
#define LMP91000_BIAS_24PCT           (0x0D) 

// MODECN register bitfield definition
#define LMP91000_FET_SHORT_DISABLED   (0x00) //default
#define LMP91000_FET_SHORT_ENABLED    (0x80)
#define LMP91000_OP_MODE_DEEP_SLEEP   (0x00) //default
#define LMP91000_OP_MODE_GALVANIC     (0x01)
#define LMP91000_OP_MODE_STANDBY      (0x02)
#define LMP91000_OP_MODE_AMPEROMETRIC (0x03)
#define LMP91000_OP_MODE_TIA_OFF      (0x06)
#define LMP91000_OP_MODE_TIA_ON       (0x07)


#define LMP91000_NOT_PRESENT          (0xA8)    // arbitrary library status code


class LMP91000 {

public:
      LMP91000();
      uint8_t status(void);
      uint8_t lock();
      uint8_t unlock();
      uint8_t configure(uint8_t _tiacn, uint8_t _refcn, uint8_t _modecn);
      uint8_t write(uint8_t reg, uint8_t data);
      uint8_t read(uint8_t reg);           
private:
};

#endif
