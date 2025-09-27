#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <unistd.h> // for usleep
using namespace std;

int main() {
    srand(time(0));
    const int width = 5;
    const int height = 10;
    vector<vector<char>> road(height, vector<char>(width, ' '));
    int carPos = width / 2;
    int score = 0;
    char move;

    while(true) {
        // generate obstacle in the first row
        for(int i=0; i<width; i++) road[0][i] = ' ';
        int obstaclePos = rand() % width;
        road[0][obstaclePos] = 'X';

        // display road
        system("clear"); // clear screen
        for(int i=0; i<height; i++) {
            for(int j=0; j<width; j++) {
                if(i == height-1 && j == carPos) cout << 'C'; // C = car
                else cout << road[i][j];
            }
            cout << endl;
        }
        cout << "Score: " << score << endl;

        // check collision
        if(road[height-1][carPos] == 'X') {
            cout << "Game Over!\n";
            break;
        }

        // get user input
        cout << "Move (A=left, D=right, Q=quit): ";
        cin >> move;
        move = toupper(move);

        if(move == 'A') carPos = max(0, carPos-1);
        else if(move == 'D') carPos = min(width-1, carPos+1);
        else if(move == 'Q') {
            cout << "Game exited.\n";
            break;
        }

        // move road down
        for(int i=height-1; i>0; i--)
            road[i] = road[i-1];

        score++;
        usleep(300000); // pause 0.3 seconds
    }

    return 0;
}
