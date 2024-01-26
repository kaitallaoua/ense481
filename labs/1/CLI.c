#include "CLI.h"

#include "usart.h"

// size is number of chars/bytes
void CLI_transmit(char p_data[], unsigned int size) {
    for (int i = 0; i < (int)size; i++) {
        send_byte(p_data[i], 5);
    }
}

// size: return only when 'size' amount of chars/bytes have been read
void CLI_receive() {
    // attempt to fill entire buffer, waiting for user to type command

    // while the interrupt is enabled, we need to wait... block untill then
    while ((USART2->CR1 & USART_CR1_RXNEIE) == USART_CR1_RXNEIE)
        ;
}

void refresh_screen(unsigned int should_init) {
    if (should_init) {
        CLI_transmit(CLEAR_SCREEN, strlen(CLEAR_SCREEN));
    } else {
        CLI_transmit(SAVE_CURSOR_POS, strlen(SAVE_CURSOR_POS));
    }

    CLI_transmit(POSITION_CURSOR, strlen(POSITION_CURSOR));

    if (should_init) {
        CLI_transmit(MAKE_SCROLL, strlen(MAKE_SCROLL));
    }

    // what to actually update at the top
    uint8_t led_state_number = get_led_state();
    if (led_state_number == 0) {
        CLI_transmit(led_state_off, strlen(led_state_off));
    } else if (led_state_number == 1) {
        CLI_transmit(led_state_on, strlen(led_state_on));
    }
    CLI_transmit("\n\n\n\n\n\n\n", strlen("\n\n\n\n\n\n\n"));

    if (!should_init) {
        CLI_transmit(RESTORE_CURSOR_POS, strlen(RESTORE_CURSOR_POS));
    }
}

void flush_buff(char p_data[], unsigned int size) {
    for (int i = 0; i < (int)size; i++) {
        p_data[i] = NULL;
    }
}
