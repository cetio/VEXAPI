/*----------------------------------------------------------------------------*/
/** @file    v5_apigraphics.c.obj
  * @brief   Private API header decompiled by cet
*//*--------------------------------------------------------------------------*/

#ifndef V5_APIGRAPHICS_H  // Header guard to prevent multiple inclusions
#define V5_APIGRAPHICS_H

#ifdef __cplusplus
extern "C" {
#endif

uint32_t* vexDisplayOffscreenBufferGet(uint32_t width, uint32_t height, uint32_t pixelSize);
void vexDisplayOffscreenBufferDestroy(uint32_t* buffer);
void vexDisplayOffscreenBufferPixelSet(uint32_t* buffer, uint32_t x, uint32_t y, uint32_t color);
uint32_t vexDisplayOffscreenBufferPixelGet(uint32_t* buffer, uint32_t x, uint32_t y);
void vexDisplayOffscreenBufferRectDraw(uint32_t* buffer, uint32_t x, uint32_t y, uint32_t width, uint32_t height);
void vexDisplayOffscreenBufferRectFill(uint32_t* buffer, uint32_t x, uint32_t y, uint32_t width, uint32_t height);
void vexDisplayOffscreenBufferScrollH(uint32_t* buffer, uint32_t pixels);
void vexDisplayOffscreenBufferBlit(uint32_t* buffer, uint32_t x, uint32_t y, uint32_t width, uint32_t height)

#ifdef __cplusplus
}
#endif

#endif // V5_APIGRAPHICS_H