#include <stdio.h>

typedef enum {
    IDLE,
    EVEN,
    ODD
} State;

typedef enum {
    DIGIT,
    ENTER
} EventType;

typedef struct Event {
    int value;
    EventType type;
} Event;

State process_event(State current_state, Event event) {
    if(event.type == DIGIT) {
        return event.value % 2 == 0 ? EVEN : ODD;
    }

    if(event.type == ENTER) {
        if(current_state == IDLE) {
            printf("Invalid entry, provide a number first\n");
            return IDLE;
        }

        if(current_state == ODD || current_state == EVEN) {
            printf("%s\n", current_state == EVEN ? "EVEN" : "ODD");
            return IDLE;
        }
    }
}

int main() {
    State current_state = IDLE;
    while(1) {
        char entry;
        scanf("%c", &entry);

        if(!(entry >= '0' && entry <= '9') && entry != '\n') {
            printf("Invalid entry");
            while (getchar() != '\n');
            continue;
        }

        EventType event_type = (entry >= '0' && entry <= '9') ? DIGIT : ENTER;
        int value = entry - '0';

        Event event = { value, event_type };

        current_state = process_event(current_state, event);
    }

    return 0;
}