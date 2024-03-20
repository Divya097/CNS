#include <stdio.h>

#define STATE_SIZE 1600 // Size of the state matrix in bits
#define LANE_SIZE 64     // Size of a lane in bits
#define CAPACITY_SIZE 512 // Capacity portion size in bits
#define ROUNDS 24        // Total number of rounds in SHA-3 permutation

// Function to calculate the number of rounds needed for diffusion
int diffusionRounds() {
    int capacity_lanes = CAPACITY_SIZE / LANE_SIZE;
    int state_lanes = STATE_SIZE / LANE_SIZE;
    int zero_lanes = state_lanes - capacity_lanes;

    int rounds = 0;
    int remaining_zero_lanes = zero_lanes;

    while (remaining_zero_lanes > 0) {
        remaining_zero_lanes = (remaining_zero_lanes * (state_lanes - remaining_zero_lanes)) / state_lanes;
        rounds++;
    }

    return rounds;
}

int main() {
    int rounds = diffusionRounds();
    printf("Number of rounds needed for diffusion: %d\n", rounds);
    return 0;
}
