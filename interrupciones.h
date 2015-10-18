#include "curses.h"
#include "instrucciones.h"
#include <stdint.h>

void NVIC(uint32_t *registro,int *Banderas,uint8_t *SRAM,uint8_t *interrupciones,int *Indicador);

void PUSH_LOCAL(uint32_t *registro,uint8_t *SRAM,uint8_t banderas);

void POP_LOCAL(uint32_t *registro,uint8_t *SRAM,int *Banderas);
