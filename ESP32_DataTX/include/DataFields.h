#ifndef __DATA_FIELDS_H__
#define __DATA_FIELDS_H__

#include <Arduino.h>
#include "SerialData.h"

///////////////////////////////////////////////////
// MACROS
///////////////////////////////////////////////////
#define NO_OF_SLAVES        27
#define NO_OF_CELLS         4

/**
 * @brief Global function to update struct members.
 * 
 */
void updatePacket1(Packet1_t *);
void updatePacket2(Packet2_t *);


#endif /* __DATA_FIELDS_H__ */