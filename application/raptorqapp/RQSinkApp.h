//
// Copyright (C) 2004 Andras Varga
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program; if not, see <http://www.gnu.org/licenses/>.
//

#ifndef __INET_RQSinkApp_H
#define __INET_RQSinkApp_H

#include "inet/common/INETDefs.h"
#include "inet/common/lifecycle/ILifecycle.h"
#include "inet/common/lifecycle/LifecycleOperation.h"
//#include "inet/transportlayer/contract/tcp/TCPSocket.h"
#include "inet/raptorqimplementation/rqtransportlayer/contract/raptorq/RQSocket.h"




namespace inet {

/**
 * Accepts any number of incoming connections, and discards whatever arrives
 * on them.
 */
class INET_API RQSinkApp : public cSimpleModule, public ILifecycle
{
  protected:
    long bytesRcvd;
    RQSocket socket;
    unsigned int opcode;

    unsigned int multiSrcGoupId;
    bool isMultiSourcingSink;
    //statistics:
    static simsignal_t rcvdPkSignalRQ;
    static simsignal_t fctRecordv1;

    cMessage *timeoutMsg = nullptr;
    // MOH: added
    simtime_t tStartAdded;
    simtime_t tEndAdded;
    bool firstDataReceived = true;
    bool isLongFlow;

    cGate *gateToRaptorQ;


    virtual void sendRequest();
    virtual void initialize(int stage) override;
    virtual int numInitStages() const override { return NUM_INIT_STAGES; }
    virtual void handleMessage(cMessage *msg) override;
    virtual void finish() override;
    virtual void refreshDisplay() const override;

    virtual void allReceivedCloseAllMultiSourcingConns(); // for multi sourcing


    virtual bool handleOperationStage(LifecycleOperation *operation, int stage, IDoneCallback *doneCallback) override
    { Enter_Method_Silent(); throw cRuntimeError("Unsupported lifecycle operation '%s'", operation->getClassName()); return true; }
};

} // namespace inet

#endif // ifndef __INET_RQSinkApp_H

