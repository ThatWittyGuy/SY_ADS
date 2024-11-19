// There are n people in a line queuing to buy tickets, where the 0th person is at the front of the line and the (n - 1)th person is at the back of the line.
// You are given a 0-indexed integer array tickets of length n where the number of tickets that the ith person would like to buy is tickets[i].
// Each person takes exactly 1 second to buy a ticket. A person can only buy 1 ticket at a time and has to go back to the end of the line (which happens instantaneously) in order to buy more tickets. If a person does not have any tickets left to buy, the person will leave the line.
// Return the time taken for the person initially at position k (0-indexed) to finish buying tickets. Input: tickets = [2,3,2], k = 2
// Output: 6

#include <stdio.h>
int timeToBuyTickets(int* tickets, int ticketsSize, int k) {
    int time = 0;
    while (tickets[k] > 0) {
        // Process each person in the queue
        for (int i = 0; i < ticketsSize; i++) {
            if (tickets[i] > 0) {
                tickets[i]--; // This person buys a ticket
                time++;        // Increment time for each ticket bought
            }
        }
    }
    return time;
}
int main() {
    int tickets[] = {2, 3, 2};
    int k = 2;
    int ticketsSize = sizeof(tickets) / sizeof(tickets[0]);
    int result = timeToBuyTickets(tickets, ticketsSize, k);
    printf("Time taken for person %d to finish buying tickets: %d\n", k, result);
    return 0;
}
