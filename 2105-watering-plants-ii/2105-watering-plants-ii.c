int minimumRefill(int* plants, int plantsSize, int capacityA, int capacityB) {
    int left = 0, right = plantsSize - 1;
    int waterA = capacityA;
    int waterB = capacityB;
    int refills = 0;

    while (left < right) {
        if (waterA < plants[left]) {
            refills++;
            waterA = capacityA;
        }
        waterA -= plants[left];
        left++;

        if (waterB < plants[right]) {
            refills++;
            waterB = capacityB;
        }
        waterB -= plants[right];
        right--;
    }

    // If both meet at the same plant
    if (left == right) {
        if ((waterA >= waterB ? waterA : waterB) < plants[left]) {
            refills++;
        }
    }

    return refills;
}