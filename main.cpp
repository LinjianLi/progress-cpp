#include <iostream>
#include <unistd.h>
#include "ProgressBar.hpp"

/* Example usage of ProgressBar */
int main() {
    const int total = 10000;

    /*
     * Define a progress bar that has a total of 10000,
     * a width of 70, shows `=` to indicate completion
     * and a blank space for incomplete
     */
    ProgressBar pb(total, 70);

    for (int i = 0; i < total; i++) {
        ++pb; // record the tick

        usleep(200); // simulate work

        // display the bar only at certain steps
        if (i % 10 == 0)
            pb.display();
    }

    // tell the bar to finish
    pb.done();

    std::cout << "Done!" << std::endl;
    return 0;
}