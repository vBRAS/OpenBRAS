/***********************************************************************
	Copyright (c) 2017, The OpenBRAS project authors. All rights reserved.

	Redistribution and use in source and binary forms, with or without
	modification, are permitted provided that the following conditions are
	met:

	  * Redistributions of source code must retain the above copyright
		notice, this list of conditions and the following disclaimer.

	  * Redistributions in binary form must reproduce the above copyright
		notice, this list of conditions and the following disclaimer in
		the documentation and/or other materials provided with the
		distribution.

	  * Neither the name of OpenBRAS nor the names of its contributors may
		be used to endorse or promote products derived from this software
		without specific prior written permission.

	THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
	"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
	LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
	A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
	HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
	SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
	LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
	DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
	THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
	(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
	OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

**********************************************************************/

#ifndef CPACKETDHCPSINK_H
#define CPACKETDHCPSINK_H

#include "aceinclude.h"
#include <stdint.h>
#include <unordered_map>
#include "CDHCPSession.h"
#include "CDHCPServer.h"

class CPacketDhcpSink:public IDPDKPacketProcessSink
{
    CPacketDhcpSink();
    ~CPacketDhcpSink();
    uint8_t m_maxport;
    DHCPPortList m_DHCPPortList;
    struct udp_hdr*  getDHCPPacket(struct rte_mbuf *);
public:
    void OnPortInit(uint8_t maxport) ;
    void OnPortInfo(uint8_t portid, char mac[6], char *devname);
    void OnLCorePacket(char *pkt, size_t pktsize, uint8_t port, uint32_t lcore_id);
    CDHCPServer *m_CDhcpServer;
};


#endif //CPACKETDHCPSINK_H
