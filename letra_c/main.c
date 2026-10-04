#include <stdio.h>

typedef enum {
    s0,
    s1,
    s2,
    s3
} State;

State process_event(State current_state, int value) {
    switch(current_state) {
        case s0: {
            if(value == 0) return s0;
            return s1;
            break;
        }

        case s1: {
            if(value == 0) return s2;
            return s1;
            break;
        }

        case s2: {
            if(value == 0) return s0;
            return s3;
            break;
        }

        case s3: {
            if(value == 0) return s2;
            printf("Sequence found\n");
            return s1;
            break;
        }
    }
}

int main() {
    State current_state = s0;
    while(1) {
        char entry_bit;
        scanf("%c", &entry_bit);

        if(entry_bit == '\n') {
            continue;
        }

        if(!(entry_bit == '0' || entry_bit == '1')) {
            printf("Invalid entry\n");
            current_state = s0;
            while (getchar() != '\n');
            continue;
        }
        int value = entry_bit - '0';

        current_state = process_event(current_state, value);
    }

    return 0;
}