#ifndef SMW_COOP_PRESENTATION_H
#define SMW_COOP_PRESENTATION_H
#include "coop_machine.h"
/* character selects the actor's colors (0 Mario, 1 Luigi, 2 recolored). */
void SmwCoopCaptureVisual(CoopVisual *visual,uint32_t character);
void SmwCoopCaptureMount(CoopMountVisual *visual,int x,int y);
void SmwCoopCaptureFireball(CoopFireball *fireball,int x,int y);
void SmwCoopPresentationLatch(void);
void SmwCoopPresentationPrepare(void);
#endif
