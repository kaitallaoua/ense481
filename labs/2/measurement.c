#include "measurement.h"
#include "math.h"
#include "trig.h"
#include "timer.h"




uint8_t get_pseudo_rand_uint8(void) {
    // pretty obvious bad random number, we dont have hw generator built in
    // good enough for this game, since the entropy will come from the "random"
    // times that people complete the tasks in. make to use least significant
    // bits as possible since they vary the most
    return DWT->CYCCNT & 0xFF;
}

uint32_t get_pseudo_rand_uint32(void) {
    // uint8 is reasonabley random enough, copy that over for the remaining bits
    uint8_t rand8 = get_pseudo_rand_uint8();
    uint32_t rand32 =
        (rand8 << 24u) | (rand8 << 16u) | (rand8 << 8u) | (rand8 << 0u);
    return rand32;
}

uint64_t get_pseudo_rand_uint64(void) {
    uint32_t rand32 = get_pseudo_rand_uint32();
    uint64_t rand64 = rand32 * rand32;  // good enough
    return rand64;
}



uint16_t taylor_series_run(int32_t a) {
	uint16_t start = timer_start();
	int32_t temp = taylor_series_sin(a);
	return timer_stop(start);
}

uint16_t sin_run(int32_t a) {
	
		uint16_t start = timer_start();
		double temp = sin( (double) a);
	return timer_stop(start);
	
	
}


uint16_t taylor_series_timing(void) {
    int32_t a = (int32_t)get_pseudo_rand_uint32();

    // init with a valid number
    uint16_t result = taylor_series_run(a);

    for (int i = 0; i < 100; i++) {
        // rolling avg
        result = (result + taylor_series_run(a)) / 2;
    }

    return result;
}

uint16_t std_sin_timing(void) {
	  int32_t a = (int32_t)get_pseudo_rand_uint32();

    // init with a valid number
    uint16_t result = sin_run(a);

    for (int i = 0; i < 100; i++) {
        // rolling avg
        result = (result + sin_run(a)) / 2;
    }

    return result;
	
	
}

