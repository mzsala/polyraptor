
#ifndef __INET_RQVIRTUALDATASENDQUEUE_H
#define __INET_RQVIRTUALDATASENDQUEUE_H

#include "../RQSendQueue.h"

namespace inet {

namespace raptorq {

/**
 * Send queue that manages "virtual bytes", that is, byte counts only.
 * It uses the length() field of the messages only, everything else is
 * ignored.
 *
 * @see RQVirtualDataRcvQueue
 */
class INET_API RQVirtualDataSendQueue : public RQSendQueue
{
  protected:
    uint32 begin;    // 1st sequence number stored
    uint32 end;    // last sequence number stored +1

  public:
    /**
     * Ctor
     */
    RQVirtualDataSendQueue();

    /**
     * Virtual dtor.
     */
    virtual ~RQVirtualDataSendQueue();

    /**
     *
     */
    virtual void init(uint32 startSeq) override;

    /**
     * Returns a string with the region stored.
     */
    virtual std::string info() const override;

    /**
     *
     */
    virtual void enqueueAppData(cPacket *msg) override;

    /**
     *
     */
    virtual uint32 getBufferStartSeq() override;

    /**
     *
     */
    virtual uint32 getBufferEndSeq() override;

    /**
     *
     */
    virtual RQSegment *createSegmentWithBytes(uint32 fromSeq, ulong numBytes) override;

    /**
     *
     */
    virtual void discardUpTo(uint32 seqNum) override;
};

} // namespace raptorq

} // namespace inet

#endif // ifndef __INET_RQVIRTUALDATASENDQUEUE_H

