int timeRequiredToBuy(int* tickets, int ticketsSize, int k) {
    int time = 0;
    int target = tickets[k];

    for(int i = 0; i < ticketsSize; i++) {
        if(i <= k) {
            time += (tickets[i] < target) ? tickets[i] : target;
        } else {
            time += (tickets[i] < target - 1) ? tickets[i] : (target - 1);
        }
    }

    return time;
}
