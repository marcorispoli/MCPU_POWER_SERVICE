#include "application.h"
#include "can_device_protocol.h"


deviceProtocol::deviceProtocol(void):canDeviceProtocol(Application::DEVICE_ID, Application::IP_CAN_ADDRESS, Application::CAN_PORT)
{

    canDeviceProtocolFrame::CAN_REGISTER_t reg0;
    reg0.d[0] = 0;
    reg0.d[1] = 0;
    reg0.d[2] = 0;
    reg0.d[3] = 0;

    // Creates the register structure
    for(int i=0; i< STATUS_LEN; i++) deviceStatusRegisters.append(reg0);
    for(int i=0; i< DATA_LEN; i++) deviceDataRegisters.append(reg0);
    for(int i=0; i< PARAMETER_LEN; i++) deviceParamRegisters.append(reg0);


    execCmd = 0;
    abortCmd = false;
    bootloaderPresent = false;

    workflow = _WORKFLOW_NONE;
    subWorkflow = 0;
    QTimer::singleShot(100,this, SLOT(workflowBOOTINIT()));

}


