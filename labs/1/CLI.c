#include "CLI.h"

#include "usart.h"
void print_time(uint16_t time) {
			char* temp = convertIntegerToChar(time);
			CLI_transmit("\n\ntime: ", strlen("\n\ntime: "));
			CLI_transmit(temp, strlen(temp));
			free(temp);
	
}

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

		/*
    // what to actually update at the top
    uint8_t led_state_number = get_led_state();
    if (led_state_number == 0) {
        CLI_transmit(led_state_off, strlen(led_state_off));
    } else if (led_state_number == 1) {
        CLI_transmit(led_state_on, strlen(led_state_on));
    }
    CLI_transmit("\n\n\n\n\n\n\n", strlen("\n\n\n\n\n\n\n"));
		*/
		
    if (!should_init) {
        CLI_transmit(RESTORE_CURSOR_POS, strlen(RESTORE_CURSOR_POS));
    }
}

void flush_buff(char p_data[], unsigned int size) {
    for (int i = 0; i < (int)size; i++) {
        p_data[i] = NULL;
    }
}

// from geeksforgeeks how to convert given number to char array
char* convertIntegerToChar(int N)
{
 
    // Count digits in number N
    int m = N;
    int digit = 0;
    while (m) {
 
        // Increment number of digits
        digit++;
 
        // Truncate the last
        // digit from the number
        m /= 10;
    }
 
    // Declare char array for result
    char* arr;
 
    // Declare duplicate char array
    char arr1[digit];
 
    // Memory allocation of array
    arr = (char*) malloc(digit);
 
    // Separating integer into digits and
    // accommodate it to character array
    int index = 0;
    while (N) {
 
        // Separate last digit from
        // the number and add ASCII
        // value of character '0' is 48
        arr1[++index] = (N % 10) + '0';
 
        // Truncate the last
        // digit from the number
        N /= 10;
    }
 
    // Reverse the array for result
    int i;
    for (i = 0; i < index; i++) {
        arr[i] = arr1[index - i];
    }
 
    // Char array truncate by null
    arr[i] = '\0';
 
    // Return char array
    return (char*)arr;
}
