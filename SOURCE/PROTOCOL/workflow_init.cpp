#include "application.h"
#include "can_device_protocol.h"

typedef enum{
    _WI_GET_APP_REV_0 ,
    _WI_GET_APP_REV_1,
    _WI_GET_APP_PARAM_0 ,
    _WI_GET_APP_PARAM_1,
    _WI_GET_APP_PARAM_2,
    _WI_VERIFY_PARAM_STORE_0,
    _WI_WRITE_PARAM_0,
    _WI_WRITE_PARAM_1,
    _WI_WRITE_PARAM_2,
    _WI_STORE_PARAM_0,
    _WI_STORE_PARAM_1,
    _WI_WRITE_DATA_0,
    _WI_WRITE_DATA_1,
    _WI_WRITE_DATA_2,
    _WI_GET_STATUS_0,
    _WI_GET_STATUS_1,
    _WI_GET_STATUS_2,
    _WI_APPINIT_COMPLETED,
}_WorflowInitSteps;


void deviceProtocol::workflowAPPINIT(void){
    static uint8_t idx;
    bool ris;    
    workflow = _WORKFLOW_APPINIT;


    // Waiting for the answer
    if(isDeviceCommunicationPending()){
        QTimer::singleShot(1,this, SLOT(workflowAPPINIT()));
        return;
    }

    switch(subWorkflow){        
        case _WI_GET_APP_REV_0: // Get Application Revision from the protocol registere
            if(!deviceAccessRegister(canDeviceProtocolFrame::READ_REVISION)){
                QTimer::singleShot(100,this, SLOT(workflowAPPINIT()));
                return;
            }

            subWorkflow++;
            QTimer::singleShot(10,this, SLOT(workflowAPPINIT()));
            return;

        case _WI_GET_APP_REV_1:
            if(!isDeviceCommunicationOk()){
                qDebug() << "REVISION FRAME TIMEOUT: " << getDeviceFrameErrorStr();
                subWorkflow--;
                QTimer::singleShot(100,this, SLOT(workflowAPPINIT()));
                return;
            }

            qDebug() << "DEVICE REVISION: " << (uchar) deviceRevisionRegister.d[0] << "." <<  deviceRevisionRegister.d[1] << "." << deviceRevisionRegister.d[2];

            subWorkflow = _WI_GET_APP_PARAM_0;
            QTimer::singleShot(0,this, SLOT(workflowAPPINIT()));
            break;

        case _WI_GET_APP_PARAM_0:
            idx = 0;
            subWorkflow++;
            QTimer::singleShot(0,this, SLOT(workflowAPPINIT()));
            return;

        case _WI_GET_APP_PARAM_1: // Read the parameters from the device
            if(idx >= PARAMETER_LEN){
                // Configuration read complted
                subWorkflow = _WI_VERIFY_PARAM_STORE_0;
                QTimer::singleShot(0,this, SLOT(workflowAPPINIT()));
                return;
            }

            if(!deviceAccessRegister(canDeviceProtocolFrame::READ_PARAM,idx)){
                qDebug() << "err0";
                QTimer::singleShot(100,this, SLOT(workflowAPPINIT()));
                return;
            }

            subWorkflow++;
            QTimer::singleShot(10,this, SLOT(workflowAPPINIT()));
            return;

        case _WI_GET_APP_PARAM_2:

            if(!isDeviceCommunicationOk()){
                qDebug() << "err1";
            }else{
                idx++;
            }

            subWorkflow--;
            QTimer::singleShot(100,this, SLOT(workflowAPPINIT()));
            break;

        case _WI_VERIFY_PARAM_STORE_0: // Verify if the parameters are set as expected

            if(WINDOW) WINDOW->updateParameters();
            qDebug() << "Upload Parameter completed";

            // Verifies if there are different values
            if(
                (deviceParamRegisters[0].d[0] != CONFIG->getParam<uchar>(PARAM_0,0)) ||
                (deviceParamRegisters[1].d[0] != CONFIG->getParam<uchar>(PARAM_1,0)) ||
                (deviceParamRegisters[2].d[0] != CONFIG->getParam<uchar>(PARAM_2,0)) ||
                (deviceParamRegisters[3].d[0] != CONFIG->getParam<uchar>(PARAM_3,0)) ||
                (deviceParamRegisters[4].d[0] != CONFIG->getParam<uchar>(PARAM_4,0)) ||
                (deviceParamRegisters[4].d[1] != CONFIG->getParam<uchar>(PARAM_4,1)) ||
                (deviceParamRegisters[5].d[0] != CONFIG->getParam<uchar>(PARAM_5,0)) ||
                (deviceParamRegisters[5].d[1] != CONFIG->getParam<uchar>(PARAM_5,1)) ||
                (deviceParamRegisters[6].d[0] != CONFIG->getParam<uchar>(PARAM_6,0)) ||
                (deviceParamRegisters[6].d[1] != CONFIG->getParam<uchar>(PARAM_6,1)) ||
                (deviceParamRegisters[7].d[0] != CONFIG->getParam<uchar>(PARAM_7,0)) ||
                (deviceParamRegisters[7].d[1] != CONFIG->getParam<uchar>(PARAM_7,1)) ||
                (deviceParamRegisters[8].d[0] != CONFIG->getParam<uchar>(PARAM_8,0)) ||
                (deviceParamRegisters[8].d[1] != CONFIG->getParam<uchar>(PARAM_8,1))
                ){
                    subWorkflow = _WI_WRITE_PARAM_0;

            }else subWorkflow = _WI_WRITE_DATA_0;

            QTimer::singleShot(0,this, SLOT(workflowAPPINIT()));
            break;

        case _WI_WRITE_PARAM_0:

            subWorkflow++;
            idx = 0;
            QTimer::singleShot(0,this, SLOT(workflowAPPINIT()));
            break;

        case _WI_WRITE_PARAM_1: // Write the parameters
            if(idx >= PARAMETER_LEN){
                // Store the parameters
                subWorkflow = _WI_STORE_PARAM_0;
                QTimer::singleShot(0,this, SLOT(workflowAPPINIT()));
                return;
            }

            if(idx == 0) ris = deviceAccessRegister(canDeviceProtocolFrame::WRITE_PARAM,idx,CONFIG->getParam<uchar>(PARAM_0,0));
            else if(idx == 1) ris = deviceAccessRegister(canDeviceProtocolFrame::WRITE_PARAM,idx,CONFIG->getParam<uchar>(PARAM_1,0));
            else if(idx == 2) ris = deviceAccessRegister(canDeviceProtocolFrame::WRITE_PARAM,idx,CONFIG->getParam<uchar>(PARAM_2,0));
            else if(idx == 3) ris = deviceAccessRegister(canDeviceProtocolFrame::WRITE_PARAM,idx,CONFIG->getParam<uchar>(PARAM_3,0));
            else if(idx == 4) ris = deviceAccessRegister(canDeviceProtocolFrame::WRITE_PARAM,idx,CONFIG->getParam<uchar>(PARAM_4,0), CONFIG->getParam<uchar>(PARAM_4,1));
            else if(idx == 5) ris = deviceAccessRegister(canDeviceProtocolFrame::WRITE_PARAM,idx,CONFIG->getParam<uchar>(PARAM_5,0), CONFIG->getParam<uchar>(PARAM_5,1));
            else if(idx == 6) ris = deviceAccessRegister(canDeviceProtocolFrame::WRITE_PARAM,idx,CONFIG->getParam<uchar>(PARAM_6,0), CONFIG->getParam<uchar>(PARAM_6,1));
            else if(idx == 7) ris = deviceAccessRegister(canDeviceProtocolFrame::WRITE_PARAM,idx,CONFIG->getParam<uchar>(PARAM_7,0), CONFIG->getParam<uchar>(PARAM_7,1));
            else if(idx == 8) ris = deviceAccessRegister(canDeviceProtocolFrame::WRITE_PARAM,idx,CONFIG->getParam<uchar>(PARAM_8,0), CONFIG->getParam<uchar>(PARAM_8,1));
            else ris = false;

            if(!ris){
                QTimer::singleShot(100,this, SLOT(workflowAPPINIT()));
                return;
            }

            subWorkflow++;
            QTimer::singleShot(10,this, SLOT(workflowAPPINIT()));
            return;

        case _WI_WRITE_PARAM_2:
            if(!isDeviceCommunicationOk()){
                subWorkflow --;
                QTimer::singleShot(100,this, SLOT(workflowAPPINIT()));
                return;
            }

            idx++;
            subWorkflow--;
            QTimer::singleShot(100,this, SLOT(workflowAPPINIT()));
            break;

        case _WI_STORE_PARAM_0: // Store parameter command
            if(!deviceAccessRegister(canDeviceProtocolFrame::STORE_PARAMS,0)){
                qDebug() << "STORE COMMAND NOT EXECUTED";
                subWorkflow = _WI_WRITE_DATA_0;
                QTimer::singleShot(1,this, SLOT(workflowAPPINIT()));
                break;
            }

            qDebug() << "PARAMETER STORING ..";
            subWorkflow++;
            QTimer::singleShot(100,this, SLOT(workflowAPPINIT()));
            break;

        case _WI_STORE_PARAM_1:
            if(!isDeviceCommunicationOk()){
                qDebug() << "STORE COMMAND FAILED";
            }else qDebug() << "PARAMETER SUCCESSFULLY STORED";

            subWorkflow = _WI_WRITE_DATA_0;
            QTimer::singleShot(0,this, SLOT(workflowAPPINIT()));

            break;

        case _WI_WRITE_DATA_0:
            qDebug() << "WRITE DATA REGISTERS";
            idx = 0;
            subWorkflow++;
            QTimer::singleShot(0,this, SLOT(workflowAPPINIT()));
            break;

        case _WI_WRITE_DATA_1: // DATA register update
            if(idx >= DATA_LEN){
                qDebug() << "DATA REGISTERS SUCCESSFULLY WRITTEN";
                if(WINDOW) WINDOW->updateData();
                subWorkflow =  _WI_GET_STATUS_0;
                QTimer::singleShot(0,this, SLOT(workflowAPPINIT()));
                return;
            }

            ris = deviceAccessRegister(canDeviceProtocolFrame::WRITE_DATA,idx,deviceDataRegisters[idx].d[0],deviceDataRegisters[idx].d[1],deviceDataRegisters[idx].d[2],deviceDataRegisters[idx].d[3]);
            if(!ris){
                QTimer::singleShot(100,this, SLOT(workflowAPPINIT()));
                return;
            }

            subWorkflow++;
            QTimer::singleShot(100,this, SLOT(workflowAPPINIT()));
            return;

        case _WI_WRITE_DATA_2:
            if(!isDeviceCommunicationOk()){
                subWorkflow --;
                QTimer::singleShot(100,this, SLOT(workflowAPPINIT()));
                return;
            }

            idx++;
            subWorkflow--;
            QTimer::singleShot(100,this, SLOT(workflowAPPINIT()));
            break;

        case _WI_GET_STATUS_0: // STATUS register update
            qDebug() << "GET STATUS REGISTERS";
            idx = 0;
            subWorkflow++;
            QTimer::singleShot(0,this, SLOT(workflowAPPINIT()));
            break;

        case _WI_GET_STATUS_1:
            if(idx >= STATUS_LEN){
                qDebug() << "STATUS REGISTERS SUCCESSFULLY WRITTEN";
                if(WINDOW) WINDOW->updateStatus();
                subWorkflow =  _WI_APPINIT_COMPLETED;
                QTimer::singleShot(0,this, SLOT(workflowAPPINIT()));
                return;
            }

            ris = deviceAccessRegister(canDeviceProtocolFrame::READ_STATUS,idx);
            if(!ris){
                QTimer::singleShot(100,this, SLOT(workflowAPPINIT()));
                return;
            }

            subWorkflow++;
            QTimer::singleShot(100,this, SLOT(workflowAPPINIT()));
            return;

        case _WI_GET_STATUS_2:
            if(!isDeviceCommunicationOk()){
                subWorkflow --;
                QTimer::singleShot(100,this, SLOT(workflowAPPINIT()));
                return;
            }

            idx++;
            subWorkflow--;
            QTimer::singleShot(100,this, SLOT(workflowAPPINIT()));
            break;

        case _WI_APPINIT_COMPLETED:
            subWorkflow =  0;
            qDebug() << "WORKFLOW INITIALIZATION COMPLETED";
            QTimer::singleShot(100,this, SLOT(workflowIDLE()));
            return;

    }
}
