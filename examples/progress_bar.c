#include <stdio.h>
#include "libs/utils/progress_bar.h"

int main() {
    ProgressBar bar;
    int total_steps = 100;
    progress_bar_init(&bar, total_steps, 50);  // 50-character wide progress bar

    for (int step = 0; step <= total_steps; step++) {
        progress_bar_update(&bar, step);
        // Simulate work with a delay
        usleep(50000); // Sleep for 50 milliseconds (or adjust as needed)
    }

    progress_bar_finish(&bar, "Process Complete!");
    return 0;
}
