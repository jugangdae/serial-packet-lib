#ifndef __PACKET_H__
#define __PACKET_H__

#include<stdint.h>
#include"packet_user.h"
#include"packet_define.h"

typedef struct __Packet{

	uint8_t header;
#ifdef LENGTH
	uint8_t length;
#endif
	Payload *payload;
#ifdef ENDBYTE
	uint8_t endByte;
#endif
#ifdef CRC8
	uint8_t *crc;
#else
	uint16_t *crc;
#endif

	struct __Packet (*create)();
	void (*delete_)();
}Packet;

typedef struct __Payload{
#ifdef COMMAND8
	uint8_t *command;
#else
	uint16_t *command;
#endif
	UserData *data;
	struct __Payload (*create)();
	void (*delete_)();
}Payload;

Packet createPacket(Packet * pk);
void deletePacket(Packet * pk);

uint8_t getPacketHeader(Packet * pk);
void setPacketHeader(Packet * pk, uint8_t h);

uint8_t getPacketLength(Packet * pk);
void setPacketLength(Packet * pk, uint8_t l);

uint8_t getPacketEndByte(Packet * pk);
void setPacketEndByte(Packet * pk, uint8_t b);

uint8_t getPacketCrc(Packet * pk);
void setPacketCrc(Packet * pk, uint8_t c);

Payload createPayload(Payload * pl);
void deletePayload(Payload * pl);

uint8_t getPayloadCmd(Payload * pl);
void setPayloadCmd(Payload * pl, uint8_t c);

#endif