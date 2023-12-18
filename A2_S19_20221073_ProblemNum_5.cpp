//File:A2_S19_20221073_problemNum_2.cpp
//Purpose:A list of up 10 players and their high scores.
//Author:Salma Gamal Kamel Mohamed Radwan.
//Section:S19.
//ID:20221073.
//TA:Mohamed Talet.
//Date: 5 Nov 2023.
// Q.5
#include <bits/stdc++.h>
using namespace std;

struct Player
{
    string name;
    int score;

    Player(const std::string &name, int score) : name(name), score(score) {}
};

bool compare(const Player &p1, const Player &p2)
{
    return p1.score > p2.score;
}

int main()
{
    vector<Player> playerList;

    while (true)
    {
        cout << "Menu:\n"
             << "(1) Add a new player and score .\n"
             << "(2) Print the top 10 names and scores .\n"
             << "(3) Get player's highest score .\n"
             << "(4) Exit .\n"
             << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string name;
            int score;

            cout << "Plaese enter player name: ";
            cin >> name;

            cout << "Plaese enter score: ";
            cin >> score;

            Player newPlayer(name, score);

            if (playerList.size() < 10)
                playerList.push_back(newPlayer);
            else
            {
                vector<Player>::iterator minScorePlayer = min_element(playerList.begin(), playerList.end(), compare);
                if (newPlayer.score > minScorePlayer->score)
                {
                    *minScorePlayer = newPlayer;
                }
            }

            break;
        }
        case 2:
        {
            sort(playerList.begin(), playerList.end(), compare);

            cout << "Top 10 players are:\n";
            for (const Player &player : playerList)
            {
                cout << player.name << " " << player.score << "\n";
            }

            break;
        }
        case 3:
        {
            string name;
            cout << "Enter player name: ";
            cin >> name;

            bool b = false;
            int highest_score = -1;

            for (const Player &player : playerList)
            {
                if (player.name == name)
                {
                    highest_score = max(highest_score, player.score);
                    b = true;
                }
            }

            if (b)
            {
                cout << "Player's highest score is : " << highest_score << "\n";
            }
            else
            {
                cout << "Player's name has not been input or is not in the top 10.\n";
            }

            break;
        }
        case 4:
        {
            return 0;
        }
        default:
        {
            cout << "Invalid choice. Please try again.\n";
            break;
        }
        }
    }

    return 0;
}
