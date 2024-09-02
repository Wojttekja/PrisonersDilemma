#include <iostream>

// true - cooperation
// false - defeat
int* game(bool Player1Decision, bool Player2Decision) {
    int* scores = new int[2];

    // mutual cooperation
    if (Player1Decision == true and Player2Decision == true) {
        scores[0] = 3;
        scores[1] = 3;
    }
    // Player 1 cooperates (gets punishment) player 2 defects (gets reward)
    else if (Player1Decision == true and Player2Decision == false) {
        scores[0] = 0;
        scores[1] = 5;
    }
    // Player 1 defects (gets reward) player 2 cooperates (gets punishment)
    else if (Player1Decision == false and Player2Decision == true) {
        scores[0] = 5;
        scores[1] = 0;
    }
    // mutual defection
    else {
        scores[0] = -1;
        scores[1] = -1;
    }
    return scores;
}

bool AlwaysDefect() {
    return false;
}

bool AlwaysCooperate() {
    return true;
}

int main() {
    int limit;
    std::cout << "How many turns would you like to play? ";
    std::cin >> limit;
    int score1 = 0, score2=0;
    int* temp;
    for (int i = 0; i < limit; i++) {
        temp = game(AlwaysCooperate(), AlwaysDefect());
        score1 += temp[0];
        score2 += temp[1];
    }

    std::cout << std::endl << "Strategy always cooperate score: " << score1;
    std::cout << std::endl << "Strategy always defect score: " << score2;

    return 0;
}
