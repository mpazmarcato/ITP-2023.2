#include <stdio.h>
#include <stdlib.h>

void compute_votes(int n, int votes[n], int *most_voted, int *second_most_voted) {
    int count[11] = {0}; 
    
    for (int i = 0; i < n; i++) {
        if (votes[i] >= 1 && votes[i] <= 10) {
            count[votes[i]]++;
        }
    }

    *most_voted = 1; 
    *second_most_voted = 2; 
    
    for (int i = 1; i <= 10; i++) {
        if (count[i] > count[*most_voted]) {
            *second_most_voted = *most_voted;
            *most_voted = i;
        } else if (count[i] > count[*second_most_voted] && i != *most_voted) {
            *second_most_voted = i;
        }
    }
}

int main() {
    int n;
    int most_voted;
    int second_most_voted;
    scanf("%d", &n);

    int *votes = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &votes[i]);
    }

    compute_votes(n, votes, &most_voted, &second_most_voted);

    printf("%d %d\n", most_voted, second_most_voted);

    free(votes); 

    return 0;
}