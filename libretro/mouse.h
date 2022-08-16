#ifndef _WINX68K_MOUSE_H
#define _WINX68K_MOUSE_H

#include <stdint.h>
#include "common.h"

extern	int	MousePosX;
extern	int	MousePosY;
extern	uint8_t	MouseStat;
extern	uint8_t	MouseSW;

void Mouse_Init(void);
void Mouse_Event(int wparam, float dx, float dy);
void Mouse_SetData(void);
void Mouse_StartCapture(int flag);
void Mouse_ChangePos(void);

#endif /* _WINX68K_MOUSE_H */
