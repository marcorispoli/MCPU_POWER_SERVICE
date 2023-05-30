#ifndef DEVICE_PROTOCOL_H
#define DEVICE_PROTOCOL_H

#include "QObject"
#include "can_device_protocol.h"
#include "can_bootloader_protocol.h"

/*!
 * \defgroup  deviceModule Device Protocol implementation
 *
 *
 */


class deviceProtocol: public canDeviceProtocol
{
    Q_OBJECT

public:
    explicit deviceProtocol();
    ~deviceProtocol(){};

    // Workflow handling
    typedef enum{
        _WORKFLOW_NONE = 0,
        _WORKFLOW_BOOTINIT,
        _WORKFLOW_APPINIT,
        _WORKFLOW_IDLE,
        _WORKFLOW_BOOTLOADER,
    }PROTOCOL_WORKFLOW_e;

    void connectDevice(void){

    }

    typedef enum{
        STATUS_SYSTEM = 0,
        STATUS_BATTERY,
        STATUS_ARM,
        STATUS_LEN
    }PROTOCOL_STATUS_ENUM_e;

    typedef enum{
        DATA_OUTPUTS = 0,
        DATA_LEN
    }PROTOCOL_DATA_ENUM_e;

    typedef enum{
        POWER_ON_OFF_DELAY = 0,
        HARDWARE_POWER_OFF_TIME,
        KEEP_ALIVE_POWER_OFF,
        SOFT_POWER_OFF_DELAY,
        LOW_BATT_LEVELS,
        BODY_ROTATION_LOCK_TIME,
        PEDALBOARD_LOCK_TIME,
        MANUAL_ROT_LOCK_TIME,
        XRAY_BUTTON_LOCK_TIME,
        PARAMETER_LEN
    }PROTOCOL_PARAMS_ENUM_e;

    typedef enum{
        EXECUTE_ABORT = 0,
        EXECUTE_POWER_ON_OFF,
        ACTIVATE_MOTORS,
        LAST_PROTOCOL_COMMAND
    }PROTOCOL_COMMANDS_ENUM_e;

    typedef enum{
        ACTIVATE_BOOTLOADER = LAST_PROTOCOL_COMMAND,

    }BOOTLOADERL_COMMANDS_ENUM_e;

    typedef enum{
        NO_COMMAND = 0,
        ACTIVATE_ARM,
        ACTIVATE_BODY,
        ACTIVATE_LIFT,
        ACTIVATE_ARM_LIFT
    }PROTOCOL_MOTORS_COMMAND_ENUM_e;


    // Protocol commands
    inline void requestBootloaderActivation(void) {if(bootloaderPresent) execCmd = ACTIVATE_BOOTLOADER;}
    inline void requestSoftPowerOff(void){execCmd = EXECUTE_POWER_ON_OFF;};
    inline void requestAbort(void){abortCmd = true;};
    void requestArm(int16_t cAng){
        execCmd = ACTIVATE_MOTORS;
        execParam[0] = ACTIVATE_ARM;
        execParam[1] = (uint16_t) cAng & 0xFF;
        execParam[2] = (uint16_t) cAng >> 8;
        execParam[3] = 0;

    };

    inline canDeviceProtocolFrame::CAN_REGISTER_t getParam(uint8_t data){return deviceParamRegisters[data];};
    inline canDeviceProtocolFrame::CAN_REGISTER_t getData(uint8_t data){return deviceDataRegisters[data];};
    inline canDeviceProtocolFrame::CAN_REGISTER_t getStatus(uint8_t data){return deviceStatusRegisters[data];};
    void setData(uint8_t idx, uint8_t data, uint8_t mask, bool stat){
        uchar b = deviceDataRegisters[idx].d[data] &=~ mask;
        if(stat) deviceDataRegisters[idx].d[data] = b | mask;
        else deviceDataRegisters[idx].d[data] = b;
    };


signals:


public slots:


private slots:

    void workflowAPPINIT(void);
    void workflowBOOTINIT(void);
    void workflowIDLE(void);
    void workflowBOOTLOADER(void);

public:
    uchar execCmd;
    uchar execParam[4];
    bool  abortCmd;

protected:



private:
    PROTOCOL_WORKFLOW_e workflow;
    uchar subWorkflow;
    uchar sequence;
    bool  rxOk;
    bool bootloaderPresent;



};
#endif // DEVICE_PROTOCOL_H
