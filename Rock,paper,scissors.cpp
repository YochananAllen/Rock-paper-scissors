// Rock,paper,scissors.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Name: Yochanan Allen 
//Write a program that lets the user play the game of Rock, Paper, Scissors against the computer. The program should work as follows:
//1. When the program begins, a random number in the range of 1 through 3 is generated.If the number is 1, then the computer has chosen rock.If the number is 2, then the computer has chosen paper.If the number is 3, then the computer has chosen scissors. (Don’t display the computer’s choice yet.)
//2. The user enters his or her choice of “rock”, “paper”, or “scissors” at the keyboard. (You can use a menu if you prefer.)
//3. The computer’s choice is displayed.
//4. A winner is selected according to the following rules :
//• If one player chooses rock and the other player chooses scissors, then rock wins. (The rock smashes the scissors.)
//• If one player chooses scissors and the other player chooses paper, then scissors wins. (Scissors cuts paper.)
//• If one player chooses paper and the other player chooses rock, then paper wins. (Paper wraps rock.)
//• If both players make the same choice, the game must be played again to determine the winner.
//Be sure to divide the program into functions that perform each major task.


#include <iostream>
#include <string>

using namespace std;


int getComputerChoice() {
    return (rand() % 3 + 1);  
}


string choiceToString(int choice) {
    if (choice == 1) return "rock";
    else if (choice == 2) return "paper";
    else return "scissors";
}


string getUserChoice() {
    string userChoice;
    while (true) {
        cout << "Enter your choice (rock, paper, or scissors): ";
        cin >> userChoice;
        if (userChoice == "rock" || userChoice == "paper" || userChoice == "scissors") {
            break;
        }
        else {
            cout << "Invalid choice. Please enter 'rock', 'paper', or 'scissors'." << endl;
        }
    }
    return userChoice;
}


string determineWinner(string userChoice, string computerChoice) {
    if (userChoice == computerChoice) {
        return "tie";
    }
    else if ((userChoice == "rock" && computerChoice == "scissors") ||
        (userChoice == "scissors" && computerChoice == "paper") ||
        (userChoice == "paper" && computerChoice == "rock")) {
        return "user";
    }
    else {
        return "computer";
    }
}


void playGame() {
    while (true) {
        
        int computerChoiceNum = getComputerChoice();
        string computerChoice = choiceToString(computerChoiceNum);

        
        string userChoice = getUserChoice();

        
        cout << "\nComputer chose " << computerChoice << "." << endl;
        cout << "You chose " << userChoice << "." << endl << endl;

       
        string winner = determineWinner(userChoice, computerChoice);

        if (winner == "tie") {
            cout << "It's a tie! Let's play again." << endl;
        }
        else if (winner == "user") {
            cout << "You win!" << endl;
            break;
        }
        else {
            cout << "Computer wins!" << endl;
            break; 
        }
    }
}

int main() {
    cout << "Welcome to Rock, Paper, Scissors!" << endl;
    playGame();

    return 0;
}
