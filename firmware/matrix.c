#include "matrix.h"
#include "quantum.h"

enum {
    ROW0 = 0,
    ROW1,
    ROW2,
    NUM_PHYSICAL_ROWS
};

static const pin_t row_pins[NUM_PHYSICAL_ROWS] = {GP2, GP4, GP3};
static const pin_t col_pins[MATRIX_COLS]        = {GP26, GP27, GP28};

#define BTN_ROW (MATRIX_ROWS - 1) // virtual row 3
#define BTN_COL 0

void matrix_init_custom(void) {
    for (uint8_t r = 0; r < NUM_PHYSICAL_ROWS; r++) {
        setPinInputHigh(row_pins[r]);
    }
    for (uint8_t c = 0; c < MATRIX_COLS; c++) {
        setPinInput(col_pins[c]);
    }
}

bool matrix_scan_custom(matrix_row_t current_matrix[]) {
    matrix_row_t new_matrix[MATRIX_ROWS] = {0};

    for (uint8_t c = 0; c < MATRIX_COLS; c++) {
        setPinOutput(col_pins[c]);
        writePinLow(col_pins[c]);
        matrix_io_delay();

        for (uint8_t r = 0; r < NUM_PHYSICAL_ROWS; r++) {
            if (!readPin(row_pins[r])) { // active low
                new_matrix[r] |= (MATRIX_ROW_SHIFTER << c);
            }
        }

        setPinInput(col_pins[c]);
    }

    matrix_io_delay();
    if (!readPin(row_pins[ROW0])) {
        new_matrix[BTN_ROW] |= (MATRIX_ROW_SHIFTER << BTN_COL);
    }

    bool changed = false;
    for (uint8_t r = 0; r < MATRIX_ROWS; r++) {
        if (current_matrix[r] != new_matrix[r]) {
            changed = true;
        }
        current_matrix[r] = new_matrix[r];
    }
    return changed;
}