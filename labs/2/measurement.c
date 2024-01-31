#include "measurement.h"

#include "timer.h"

uint16_t raw_add_32_int(volatile int32_t a, volatile int32_t b) {
    uint16_t start = timer_start();

    // store result is not needed, but cant find a way otherwise with O3
    // optimization
    volatile int32_t c = a + b;

    return timer_stop(start);
}

uint16_t raw_add_64_int(volatile int64_t a, volatile int64_t b) {
    uint16_t start = timer_start();

    // store result is not needed, but cant find a way otherwise with O3
    // optimization
    volatile int64_t c = a + b;

    return timer_stop(start);
}

uint16_t raw_mul_32_int(volatile int32_t a, volatile int32_t b) {
    uint16_t start = timer_start();

    // store result is not needed, but cant find a way otherwise with O3
    // optimization
    volatile int32_t c = a * b;

    return timer_stop(start);
}

uint16_t raw_mul_64_int(volatile int64_t a, volatile int64_t b) {
    uint16_t start = timer_start();

    // store result is not needed, but cant find a way otherwise with O3
    // optimization
    volatile int64_t c = a * b;

    return timer_stop(start);
}

uint16_t raw_div_32_int(volatile int32_t a, volatile int32_t b) {
    uint16_t start = timer_start();

    if (b != 0) {
        volatile int32_t c = a / b;  // store it to prevent optmizations from
                                     // removing it, there must be a better way
    }

    return timer_stop(start);
}

uint16_t raw_div_64_int(volatile int64_t a, volatile int64_t b) {
    uint16_t start = timer_start();

    if (b != 0) {
        volatile int64_t c = a / b;  // store it to prevent optmizations from
                                     // removing it, there must be a better way
    }

    return timer_stop(start);
}

uint16_t raw_cpy_8_byte_struct(void) {
    volatile struct bytes_8 src = {};
    for (int i = 0; i < 2; i++) {
        src.data[i] = get_pseudo_rand_uint32();
    }

    uint16_t start = timer_start();
    volatile struct bytes_8 dst = src;
    return timer_stop(start);
}

uint16_t raw_cpy_128_byte_struct(void) {
    volatile struct bytes_128 src = {};
    for (int i = 0; i < 32; i++) {
        src.data[i] = get_pseudo_rand_uint32();
    }

    uint16_t start = timer_start();
    volatile struct bytes_128 dst = src;
    return timer_stop(start);
}

uint16_t raw_cpy_1024_byte_struct(void) {
    volatile struct bytes_1024 src = {};
    for (int i = 0; i < 256; i++) {
        src.data[i] = get_pseudo_rand_uint32();
    }

    uint16_t start = timer_start();
    volatile struct bytes_1024 dst = src;
    return timer_stop(start);
}

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

uint16_t test_add_32_int(void) {
    int32_t a = (int32_t)get_pseudo_rand_uint32();
    int32_t b = (int32_t)get_pseudo_rand_uint32();

    // init with a valid number
    uint16_t result = raw_add_32_int(a, b);

    for (int i = 0; i < 100; i++) {
        // rolling avg
        result = (result + raw_add_32_int(a, b)) / 2;
    }

    return result;
}

uint16_t test_add_64_int(void) {
    int64_t a = (int64_t)get_pseudo_rand_uint64();
    int64_t b = (int64_t)get_pseudo_rand_uint64();

    // init with a valid number
    uint16_t result = raw_add_64_int(a, b);

    for (int i = 0; i < 100; i++) {
        // rolling avg
        result = (result + raw_add_64_int(a, b)) / 2;
    }

    return result;
}

uint16_t test_mul_32_int(void) {
    int32_t a = (int32_t)get_pseudo_rand_uint32();
    int32_t b = (int32_t)get_pseudo_rand_uint32();

    // init with a valid number
    uint16_t result = raw_mul_32_int(a, b);

    for (int i = 0; i < 100; i++) {
        // rolling avg
        result = (result + raw_mul_32_int(a, b)) / 2;
    }

    return result;
}

uint16_t test_mul_64_int(void) {
    int64_t a = (int64_t)get_pseudo_rand_uint64();
    int64_t b = (int64_t)get_pseudo_rand_uint64();

    // init with a valid number
    uint16_t result = raw_mul_64_int(a, b);

    for (int i = 0; i < 100; i++) {
        // rolling avg
        result = (result + raw_mul_64_int(a, b)) / 2;
    }
    return result;
}

uint16_t test_div_32_int(void) {
    int32_t a = (int32_t)get_pseudo_rand_uint32();
    int32_t b = (int32_t)get_pseudo_rand_uint32();

    // init with a valid number
    uint16_t result = raw_div_32_int(a, b);

    for (int i = 0; i < 100; i++) {
        // rolling avg
        result = (result + raw_div_32_int(a, b)) / 2;
    }

    return result;
}

uint16_t test_div_64_int(void) {
    int64_t a = (int64_t)get_pseudo_rand_uint64();
    int64_t b = (int64_t)get_pseudo_rand_uint64();

    // init with a valid number
    uint16_t result = raw_div_64_int(a, b);

    for (int i = 0; i < 100; i++) {
        // rolling avg
        result = (result + raw_div_64_int(a, b)) / 2;
    }

    return result;
}

uint16_t test_cpy_8_byte_struct(void) {
    // init with a valid number
    uint16_t result = raw_cpy_8_byte_struct();

    for (int i = 0; i < 100; i++) {
        // rolling avg
        result = (result + raw_cpy_8_byte_struct()) / 2;
    }
    return result;
}

uint16_t test_cpy_128_byte_struct(void) {
    // init with a valid number
    uint16_t result = raw_cpy_128_byte_struct();

    for (int i = 0; i < 100; i++) {
        // rolling avg
        result = (result + raw_cpy_128_byte_struct()) / 2;
    }
    return result;
}

uint16_t test_cpy_1024_byte_struct(void) {
    // init with a valid number
    uint16_t result = raw_cpy_1024_byte_struct();

    for (int i = 0; i < 100; i++) {
        // rolling avg
        result = (result + raw_cpy_1024_byte_struct()) / 2;
    }
    return result;
}
