#include "DataFields.h"

void updatePacket1(Packet1_t *obj)
{    
    obj->packetType             = 1;
    strncpy(obj->batterySerialNo, BATTERY_SERIAL_NO, sizeof(obj->batterySerialNo));
    strncpy(obj->batteryID, BATTERY_ID, sizeof(obj->batteryID));
    obj->batteryType            = 160;
    obj->batteryStatus          = 17;
    obj->chargerStatus          = 0;
    obj->minVolt                = 3377;     // in mV, div by 1000
    obj->maxVolt                = 3343;     // in mV, div by 1000
    obj->packVolt               = 47163;    // div by 128 for volts
    obj->packMeasureVolt        = 0.0f;
    obj->measuredSOC            = 0.0f;
    obj->minTemp                = 23.0f;
    obj->maxTemp                = 25.0f;

    // trigger 2
    obj->batteryCurrent         = 348;      // div by 1024 for amperes
    obj->batterySOC             = 100;
    obj->batterySOH             = 98;
    obj->currentShunt           = 825;      // TODO
    obj->socShunt               = 100;      // TODO
    obj->error                  = 0;
    obj->error2                 = 0;
    obj->balancingError         = 0;

    for(uint8_t i = 0; i < 10; i++)
        obj->balancingErrorCells[i] = 0;
    for(uint8_t i = 0; i < 5; i++)
        obj->balancingErrorPacks[i] = 0;    

    // // trigger 3
    obj->rectifierPowerIn               = 0;        // in kW
    obj->rectifierPowerOut              = 0;        // in kW
    obj->rectifierCurrentIn             = 0;
    obj->rectifierCurrentOut            = 2933;     // div by 1024 for amperes
    obj->rectifierVoltagePhA            = 53900;    // div by 128 for volts
    obj->rectifierVoltagePhB            = 54348;    // div by 128 for volts
    obj->rectifierVoltagePhC            = 54067;    // div by 128 for volts
    obj->rectifierVoltageOut            = 46410;    // div by 128 for volts
    obj->rectifierAmbientTemeperature   = 27;
    obj->rectifierError1                = 0;        // in char
    obj->rectifierError2                = 0;        // in char
    obj->inverterCurrent                = 37;       // div by 5 for amperes in
    obj->inverterVoltage                = 224;
    obj->inverterError                  = 0;
    obj->inverterTempAmbient            = 0;
    obj->inverterTempHeatSink           = 27;
    obj->bCycle                         = 12;
    obj->partialDischargeAH             = 51066;

    // trigger 4
    obj->restoredErrorBMS1              = 256;
    obj->restoredErrorBMS2              = 0;
    obj->restoredErrorInverter          = 64;
    obj->restoredErrorRectifier1        = 0;
    obj->restoredErrorRectifier2        = 0;
    obj->lastDCCurrentErrorValue        = 0;
}

void updatePacket2(Packet2_t *obj)
{
    obj->packetType                 = 2;        // in char
    strncpy(obj->batterySerialNo, BATTERY_SERIAL_NO, sizeof(obj->batterySerialNo));
    strncpy(obj->batteryID, BATTERY_ID, sizeof(obj->batteryID));

    for(uint8_t i = 0; i < NO_OF_SLAVES; i++)   
    {
        // slave 1 to 27
        obj->slaves[i].slaveID                      = (i + 1);
        obj->slaves[i].slaveCPUTemp                 = 30;
        for(uint8_t j = 0; j < NO_OF_CELLS; j++)
        {
            // cells 1 to 4
            obj->slaves[i].cells[j].cellID          = (j + 1);   
            obj->slaves[i].cells[j].cellVoltage     = 3313;
            obj->slaves[i].cells[j].cellTemp        = 25;
            obj->slaves[i].cells[j].cellSOC         = -10;
        }
    }
}


