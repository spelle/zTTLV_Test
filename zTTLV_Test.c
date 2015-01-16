/*
 * zTTLV_Test.c
 *
 *  Created on: Jan 7, 2015
 *      Author: sherpa
 */
#include "zTTLV_Buffer.h"

#include <stdio.h>

int main( )
{
	uint8_t ui8 ;

	uint8_t ui8Array[50] ;
	zTTLV_Buffer_t zTTLV_Buffer = { 0, sizeof(ui8Array), ui8Array } ;

	uint8_t ui8Array2[10] ;
	zTTLV_Buffer_t zTTLV_Buffer2 = { 0, sizeof(ui8Array2), ui8Array2 } ;

	char    aChar   = 'A' ;
	uint8_t anUInt8 = 255 ;
	int8_t  anInt8  = -1  ;
	uint16_t anUInt16 = 0x0A0A ;
	int16_t  anInt16  = -1  ;

	zTTLV_Item_t zTTLV_Item = { 11, CHAR, sizeof(char), {&aChar} } ;

	zTTLV_Initialize( & zTTLV_Buffer, sizeof(ui8Array) ) ;
	zTTLV_Initialize( & zTTLV_Buffer2, sizeof(ui8Array2) ) ;

	zTTLV_Put( & zTTLV_Buffer, zTTLV_Item ) ;

	zTTLV_Item.zTag = 22 ;
	zTTLV_Item.zType= UINT8 ;
	zTTLV_Item.zLength = sizeof(uint8_t) ;
	zTTLV_Item.zValue.pUInt8 = &anUInt8 ;
	zTTLV_Put( & zTTLV_Buffer, zTTLV_Item ) ;

	zTTLV_Item.zTag = 33 ;
	zTTLV_Item.zType= INT8 ;
	zTTLV_Item.zLength = sizeof(int8_t) ;
	zTTLV_Item.zValue.pInt8 = &anInt8 ;
	zTTLV_Put( & zTTLV_Buffer, zTTLV_Item ) ;

	zTTLV_Item.zTag = 44 ;
	zTTLV_Item.zType= UINT16 ;
	zTTLV_Item.zLength = sizeof(uint16_t) ;
	zTTLV_Item.zValue.pUInt16 = &anUInt16 ;
	zTTLV_Put( & zTTLV_Buffer, zTTLV_Item ) ;
	zTTLV_Put( & zTTLV_Buffer2, zTTLV_Item ) ;

	zTTLV_Item.zTag = 55 ;
	zTTLV_Item.zType= INT16 ;
	zTTLV_Item.zLength = sizeof(int16_t) ;
	zTTLV_Item.zValue.pInt16 = &anInt16 ;
	zTTLV_Put( & zTTLV_Buffer, zTTLV_Item ) ;
	zTTLV_Put( & zTTLV_Buffer2, zTTLV_Item ) ;

	zTTLV_Item.zTag = 66 ;
	zTTLV_Item.zType= ZTTLV_BUFFER ;
	zTTLV_Item.zLength = zTTLV_Buffer2.current_Position ;
	zTTLV_Item.zValue.pzTTLV_Buffer = &zTTLV_Buffer2 ;
	zTTLV_Put( & zTTLV_Buffer, zTTLV_Item ) ;

	for( ui8 = 0 ; ui8 < zTTLV_Buffer.total_Length ; ui8++ )
	{
		fprintf( stdout, "zTTLV_Buffer[%d]=%d\n", ui8, zTTLV_Buffer.pzTTLV_Buffer[ui8] ) ;
	}

	return 0 ;
}
