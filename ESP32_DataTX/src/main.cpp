/**
 * Generate data packet and transmits to receiver via UART.
 * '*' - 42
 * '#' - 35
 * '@' - 64
 * '$' - 36
*/

#include <Arduino.h>
#include "main.h"
#include "SerialData.h"
#include "DataFields.h"


// Data types //
typedef enum
{
  PACKETDATA1 = 0,
  PACKETDATA2
} PacketNumber_e;

PacketNumber_e txPacketNumber = PACKETDATA1;

// Global variables //
unsigned long previousMillis = 0;
bool state = txPacketNumber;
Packet1_t packet1;
Packet2_t packet2;

void setup()
{
  // Debug Serial
  Serial.begin(115200);

  // Hardware Serial for Receiver
  Serial2.begin(115200, SERIAL_8N1, RX2, TX2);

  // memset(&packet2, 0, sizeof(packet2));
  // packet2.packetType = 2;
}

void loop()
{
  unsigned long currentMillis = millis();
  if ((currentMillis - previousMillis) >= INTERVAL)
  {
    previousMillis = currentMillis;
    
    if (state == PACKETDATA1)
    {
      updatePacket1(&packet1);
      sendPacket1(&packet1);

      // Serial.print("PacketType = ");
      // Serial.write(packet1.packetType);
      // Serial.write('\n');
      // Serial.println(packet1.packetType, DEC);
      Serial.println("Packet1 sent");
    }

    if (state == PACKETDATA2)
    {
      updatePacket2(&packet2);
      sendPacket2(&packet2);

      /*Serial.print((uint8_t)packet2.packetType);          Serial.print(",");
      Serial.print(packet2.batteryID);                    Serial.print(",");
      Serial.print(packet2.batterySerialNo);              Serial.print(",");

      // iterate 27 slaves
      for(uint8_t i = 0; i < 2; i++)
      {
        Serial.print((uint8_t)packet2.slaves[i].slaveID); Serial.print(",");
        Serial.print(packet2.slaves[i].slaveCPUTemp);     Serial.print("\n");
        // iterate 4 cells in each slave
        for(uint8_t j = 0; j < 4; j++)
        {
          Serial.print((uint8_t)packet2.slaves[i].cells[j].cellID);     Serial.print(",");
          Serial.print(packet2.slaves[i].cells[j].cellVoltage);         Serial.print(",");
          Serial.print(packet2.slaves[i].cells[j].cellTemp);            Serial.print(",");
          Serial.print(packet2.slaves[i].cells[j].cellSOC);             Serial.print("\n");
        }
        Serial.print("\n");
      }*/
      //done
      
      Serial.println("Packet2 sent");
    }

    state ^= 1;
  }
}