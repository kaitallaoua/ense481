#include "stm32f10x.h"
// a uint32 takes four bytes
uint16_t raw_add_32_int(int32_t a, int32_t b);
uint16_t raw_add_64_int(int64_t a, int64_t b);

uint16_t raw_mul_32_int(int32_t a, int32_t b);

uint16_t raw_mul_64_int(int64_t a, int64_t b);

uint16_t raw_div_32_int(int32_t a, int32_t b);
uint16_t raw_div_64_int(volatile int64_t a, volatile int64_t b);

uint16_t raw_cpy_8_byte_struct(void);
uint16_t raw_cpy_128_byte_struct(void) ;
uint16_t raw_cpy_1024_byte_struct(void) ;


struct bytes_8 {
		uint32_t data[2]; // 4 * 2 = 8 bytes

};

struct bytes_128 {
		uint32_t data[32]; // 4 * 32 = 128 bytes

};

struct bytes_1024 {
		uint32_t data[256]; // 4 * 256 = 1024 bytes

};


uint8_t get_pseudo_rand_uint8(void);
uint32_t get_pseudo_rand_uint32(void);
uint64_t get_pseudo_rand_uint64(void);

uint16_t test_add_32_int(void);

uint16_t test_add_64_int(void);

uint16_t test_mul_32_int(void);

uint16_t test_mul_64_int(void);

uint16_t test_div_32_int(void);

uint16_t test_div_64_int(void);

uint16_t test_cpy_8_byte_struct(void);

uint16_t test_cpy_128_byte_struct(void);

uint16_t test_cpy_1024_byte_struct(void);
