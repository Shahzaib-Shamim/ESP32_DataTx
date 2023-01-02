#include "SerialData.h"

/**
 * @brief Data packet format:
 * HEADER_LSB HEADER_MSB BYTE1 BYTE2 BYTE3 ... BYTEN FOOTER_LSB FOOTER_MSB
 * 
 * Header, Footer     Dec value
 * '*'                42
 * '#'                35
 * '@'                64
 * '$'                36
*/

// Global variables //

void sendPacket1(Packet1_t *obj)
{
    uint32_t checksumPacket1 = 0;
    uint8_t *ptrChecksumPacket1;
    uint8_t *ptrPacket1 = (uint8_t *)obj;

    Serial2.write('*');
    Serial2.write('#');
    Serial2.write(lowByte(sizeof(*obj)));   // LowByte
    Serial2.write(highByte(sizeof(*obj)));  // HighByte

    ptrChecksumPacket1 = (uint8_t *)&checksumPacket1;
    checksumPacket1 = 0;

    for (uint8_t i = 0; i < sizeof(*obj); i++)
    {
        Serial2.write(*(ptrPacket1));
        // Serial2.print(*(ptrPacket1), DEC);
        checksumPacket1 += *(ptrPacket1);
        ptrPacket1++;
    }
    Serial2.write(*(ptrChecksumPacket1)++);
    Serial2.write(*(ptrChecksumPacket1)++);
    Serial2.write(*(ptrChecksumPacket1)++);
    Serial2.write(*ptrChecksumPacket1);
    Serial2.write('@');
    Serial2.write('$');
    // Serial.println("P1 Length " + String(sizeof(*obj)));
    // checksumPacket1 = 0;
}

void sendPacket2(Packet2_t *obj)
{
    uint32_t checksumPacket2 = 0;
    uint8_t *ptrChecksumPacket2;
    uint8_t *ptrPacket2 = (uint8_t *)obj;
    
    Serial2.write('*');
    Serial2.write('#');
    Serial2.write(lowByte(sizeof(*obj)));   // LowByte
    Serial2.write(highByte(sizeof(*obj)));  // HighByte
    
    ptrChecksumPacket2 = (uint8_t *)&checksumPacket2;
    checksumPacket2 = 0;

    for (uint16_t i = 0; i < sizeof(*obj); i++)
    {
        Serial2.write(*(ptrPacket2));
        checksumPacket2 += *(ptrPacket2);
        ptrPacket2++;
    }   
    Serial2.write(*(ptrChecksumPacket2)++);
    Serial2.write(*(ptrChecksumPacket2)++);
    Serial2.write(*(ptrChecksumPacket2)++);
    Serial2.write(*ptrChecksumPacket2);
    Serial2.write('@');
    Serial2.write('$');
    // Serial.println("P2 Length " + String(sizeof(*obj)));
    // checksumPacket2 = 0;
}
