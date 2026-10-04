#include <stdio.h>

typedef enum {
    REMAINDER_0,
    REMAINDER_1,
    REMAINDER_2,
    IDLE
} State;

typedef enum {
    BIT,
    ENTER
} EventType;

typedef struct Event {
    int value;
    EventType type;
} Event;

State process_event(State current_state, Event event) {
    switch(event.type) {
        case BIT: {
            if(current_state == IDLE) {
                return event.value == 0 ? REMAINDER_0 : REMAINDER_1;
            }

            int current_remainder = (int)current_state;

            return (State)((current_remainder * 2 + event.value) % 3);
            break;
        }

        case ENTER: {
            switch(current_state) {
                case IDLE: {
                    printf("Provide a value first\n");
                    break;
                }
                case REMAINDER_0: {
                    printf("DIVISIBLE\n");
                    break;
                }
                case REMAINDER_1: {
                    printf("NOT DIVISIBLE\n");
                    break;
                }
                case REMAINDER_2: {
                    printf("NOT DIVISIBLE\n");
                    break;
                }
            }

            return IDLE;
            break;
        }
    }
}

int main() {
    State current_state = IDLE;
    while(1) {
        char entry_bit;
        scanf("%c", &entry_bit);

        if(entry_bit != '0' && entry_bit != '1' && entry_bit != '\n') {
            printf("Invalid entry");
            while (getchar() != '\n');
            continue;
        }

        EventType event_type = (entry_bit == '0' || entry_bit == '1') ? BIT : ENTER;
        int value = entry_bit - '0';        

        Event event = { value, event_type };

        current_state = process_event(current_state, event);
    }

    return 0;
}