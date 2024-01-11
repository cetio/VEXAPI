/*----------------------------------------------------------------------------*/
/** @file    v5_apijump.c.obj
  * @brief   Private API header decompiled by cet
*//*--------------------------------------------------------------------------*/

#ifndef V5_APIJUMP_H  // Header guard to prevent multiple inclusions
#define V5_APIJUMP_H

#ifdef __cplusplus
extern "C" {
#endif

uint32_t  vexCompetitionStatus( void );
int vexDevicesGetNumber( void );
int vexDevicesGetNumberByType(int type);
uint32_t** vexDevicesGet( void );
uint32_t* vexDeviceGetByIndex(uint32_t index)
uint32_t vexDeviceGetStatus(uint32_t device);
int vexDeviceGetTimestamp( void );
int vexDeviceGetTimestampByIndex(uint32_t index);
int vexDeviceButtonStateGet( void );
uint32_t* vexDisplayErase( void );
uint32_t* vexDisplayScroll(uint32_t x, uint32_t y);
uint32_t* vexDisplayScrollRect(uint32_t x, uint32_t y, uint32_t width, uint32_t height);
uint32_t* vexDisplayCopyRect(uint32_t* buffer, uint32_t sourceX, uint32_t sourceY, uint32_t destWidth, uint32_t destHeight);
uint32_t* vexDisplayPixelSet(uint32_t x, uint32_t y, uint32_t color);
uint32_t* vexDisplayPixelClear(uint32_t x, uint32_t y);
uint32_t* vexDisplayLineDraw(uint32_t startX, uint32_t startY, uint32_t endX, uint32_t endY, uint32_t color);
uint32_t* vexDisplayLineClear(uint32_t startX, uint32_t startY, uint32_t endX, uint32_t endY, uint32_t color);
uint32_t* vexDisplayRectDraw(uint32_t x, uint32_t y, uint32_t width, uint32_t height);
uint32_t* vexDisplayRectClear(uint32_t x, uint32_t y, uint32_t width, uint32_t height);
uint32_t* vexDisplayCircleFill(uint32_t centerX, uint32_t centerY, uint32_t radius, uint32_t color);
uint32_t* vexDisplayCircleClear(uint32_t centerX, uint32_t centerY, uint32_t radius);
uint32_t* vexDisplayCircleDraw(uint32_t* buffer, uint32_t centerX, uint32_t centerY, uint32_t radius);
uint32_t* vexDisplayRectFill(uint32_t x, uint32_t y, uint32_t sideLength, uint32_t color);
uint32_t* vexDisplayRectClear(uint32_t x, uint32_t y, uint32_t sideLength);
uint32_t* vexDisplayRectDraw(uint32_t* buffer, uint32_t x, uint32_t y, uint32_t sideLength);
void vexDisplayPrintf( int32_t xpos, int32_t ypos, uint32_t bOpaque, const char *format, ... );
void vexDisplayString( const int32_t nLineNumber, const char *format, ... );
void vexDisplayStringAt( int32_t xpos, int32_t ypos, const char *format, ... );
void vexDisplayBigString( const int32_t nLineNumber, const char *format, ... );
void vexDisplayBigStringAt( int32_t xpos, int32_t ypos, const char *format, ... );
void vexDisplaySmallStringAt( int32_t xpos, int32_t ypos, const char *format, ... );
void vexDisplayCenteredString( const int32_t nLineNumber, const char *format, ...);
void vexDisplayBigCenteredString( const int32_t nLineNumber, const char *format, ...);
void vexDeviceGenericRadioTransmit(uint32_t index, uint8_t* buffer, int32_t length);


#ifdef __cplusplus
}
#endif

#endif // V5_APIJUMP_H
