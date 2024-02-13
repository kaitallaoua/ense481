#include "stm32f10x.h"
uint16_t taylor_series_timing(void);
// a uint32 takes four bytes


uint8_t get_pseudo_rand_uint8(void);
uint32_t get_pseudo_rand_uint32(void);
uint64_t get_pseudo_rand_uint64(void);

uint16_t std_sin_timing(void);
uint16_t sin_run(int32_t a);
uint16_t taylor_series_run(int32_t a);
