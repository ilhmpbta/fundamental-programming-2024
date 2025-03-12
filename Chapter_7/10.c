#include <stdio.h>

/*
The results from the mayor's race have been reported by each precinct as 
follows:
Precinct     A           B           C           D
1           192         48          206         37
2           147         90          312         21
3           186         12          121         38
4           114         21          408         39
5           267         13          382         29
 Write a program to do the following:
    a.  Display the table with appropriate labels for the rows and columns.
    
    b.  Compute and display the total number of votes received by each candidate and the percentage of the total votes cast.
    
    c.  If any one candidate received over 50% of the votes, the program should display a message declaring that candidate the winner.
    
    d.  If no candidate received 50% of the votes, the program should display a message declaring a runoff between the two candidates receiving the highest number of votes; the two candidates should be identified by their letter names.
    
    e.  Run the program once with the data shown and once with candidate C receiving only 108 votes in Precinct 4
*/

void displayResults(int vote[5][4]){
    int totalVotes = 0;
    int candidateVotes[4] = {0};

    printf("Precinct\tA\tB\tC\tD\n");
    for (int i = 0; i < 5; i++){
        printf("%d\t\t", i + 1);
        for (int j = 0; j < 4; j++){
            printf("%d\t", vote[i][j]);
            candidateVotes[j] += vote[i][j];
            totalVotes += vote[i][j];
        }
        printf("\n");
    }

    printf("\nTotal votes for candidates:\n");
    for (int j = 0; j < 4; j++) {
        printf("Candidate %c: %d votes (%.2f%%)\n", 'A' + j, candidateVotes[j], (candidateVotes[j] / (float)totalVotes) * 100);
    }

    int winner = -1;
    for (int j = 0; j < 4; j++){
        if (candidateVotes[j] > totalVotes / 2){
            winner = j;
            break;
        }
    }

    if (winner != -1){
        printf("Candidate %c wins with more than 50%% of the votes!\n", 'A' + winner);
    }
    else{
        int first = 0, second = 1;

        if (candidateVotes[second] > candidateVotes[first]) {
            int temp = first;
            first = second;
            second = temp;
        }

        for (int j = 2; j < 4; j++) {
            if (candidateVotes[j] > candidateVotes[first]) {
                second = first;
                first = j;
            } else if (candidateVotes[j] > candidateVotes[second]) {
                second = j;
            }
        }

        printf("Runoff between Candidate %c and Candidate %c\n", 'A' + first, 'A' + second);
    }
}

int main(){
        int voteSet1[5][4] = {
        {192, 48, 206, 37},   // Precinct 1
        {147, 90, 312, 21},   // Precinct 2
        {186, 12, 121, 38},   // Precinct 3
        {114, 21, 408, 39},   // Precinct 4
        {267, 13, 382, 29}    // Precinct 5
    };

    int voteSet2[5][4] = {
        {192, 48, 206, 37},   // Precinct 1
        {147, 90, 312, 21},   // Precinct 2
        {186, 12, 121, 38},   // Precinct 3
        {114, 21, 108, 39},   // Modified for candidate C in Precinct 4 to be 108
        {267, 13, 382, 29}    // Precinct 5
    };

    // For the first case with data as per the question
    printf("Results for the first case:\n");
    displayResults(voteSet1);
    printf("\n");

    // For the second case where candidate C has 108 votes in precinct 4
    printf("Results for the second case:\n");
    displayResults(voteSet2);

    return 0;
}