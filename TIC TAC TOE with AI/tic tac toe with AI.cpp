#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <time.h>
#include <string>

using namespace std;
void board(char data[]);
void playerXprint(int user_input, char data[]);
void playerOprint(int user_input, char data[]);
bool checkwin(char data[]);
bool switchcase_for_X(int user_input, char data[]);
bool switchcase_for_O(int user_input, char data[]);
void return_exit();
//Main function
int main() {
  system("cls");
  char date[9];
  _strdate(date);
  cout << "\t\t\t\t\t*Game Menu*\t\n";
  cout << "1. Play\n";
  cout << "2. Game Results\n";
  cout << "3. Quit\n";
  int input;
  cin >> input;
  if (input == 1) {
    //play game
    return_back: system("cls");
    cout << "\t\t\t\t\tPlease Select the Game Mode\t\n";
    cout << "1. Play with Computer\n";
    cout << "2. Play with Other Player\n";
    cout << "3. Go Back\n";
    int input2;
    cin >> input2;
    if (input2 == 1) {
      //play with computer
      system("cls");
      cout << "\t\tPlease select difficulty\n";
      cout << "1. Easy\n";
      cout << "2. Medium\n";
      cout << "3. Hard\n";
      cout << "4. Go Back\n";
      int level;
      cin >> level;
      if (level == 1) {
        //easy level
        string name;
        cout << "Enter your name: ";
        cin >> name;
        char data[9] = {
          '1',
          '2',
          '3',
          '4',
          '5',
          '6',
          '7',
          '8',
          '9'
        };
        board(data);
        int user_input;
        for (int i = 1; i <= 10; i++) {
          if (i == 10) {
            cout << "==>>Match Drawn.";
            ofstream file;
            file.open("data.txt", ios::out | ios::app);
            file << name << " " << "Computer" << " " << "Match Drawn" << " " << "Easy" << " " << date << "\n";
            return_exit();
          }
          if (i % 2 != 0) {
            cout << "Player X turn: ";
            cin >> user_input;
            playerXprint(user_input, data);
            if (checkwin(data)) {
              board(data);
              cout << "==>Player X won.";
              ofstream file;
              file.open("data.txt", ios::out | ios::app);
              file << name << " " << "Computer" << " " << name << " " << "Easy" << " " << date << "\n";
              file.close();
              return_exit();
            }
          } else if (i % 2 == 0) {
            try_again: user_input = rand() % 9 + 1;
            int index;
            switch (user_input) {
            case 1:
              index = 0;
              break;
            case 2:
              index = 1;
              break;
            case 3:
              index = 2;
              break;
            case 4:
              index = 3;
              break;
            case 5:
              index = 4;
              break;
            case 6:
              index = 5;
              break;
            case 7:
              index = 6;
              break;
            case 8:
              index = 7;
              break;
            case 9:
              index = 8;
              break;
            }
            if (data[index] != 'X' && data[index] != 'O') {
              data[index] = 'O';
            } else {
              goto try_again;
            }
            if (checkwin(data)) {
              board(data);
              cout << "==>Player O Computer won.";
              ofstream file;
              file.open("data.txt", ios::out | ios::app);
              file << name << " " << "Computer" << " " << "Computer" << " " << "Easy" << " " << date << "\n";
              file.close();
              return_exit();
            }
          }
          board(data);
        }
      } else if (level == 2) {
        //medium level
        cout<<"Not yet implemented!";
        return_exit();
      } else if (level == 3) {
      	//hard levels
      	cout<<"Not yet implemented!";
      	return_exit();
      } else if (level == 4) {
        //Go back
        goto return_back;
      }
    } else if (input2 == 2) {
      //play with other player
      string player_1, player_2;
      cout << "Enter Player 1 (X) Name: ";
      cin >> player_1;
      cout << "Enter Player 2 (O) Name: ";
      cin >> player_2;
      char data[9] = {
        '1',
        '2',
        '3',
        '4',
        '5',
        '6',
        '7',
        '8',
        '9'
      };
      board(data);
      int user_input;
      for (int i = 1; i <= 10; i++) {
        if (i == 10) {
          cout << "==>>Match Drawn.";
          ofstream file;
          file.open("data.txt", ios::out | ios::app);
          file << player_1 << " " << player_2 << " " << "Match Drawn" << " " << "None" << " " << date << "\n";
          file.close();
          return_exit();
        }
        if (i % 2 != 0) {
          cout << "Player X turn: ";
          cin >> user_input;
          playerXprint(user_input, data);
          if (checkwin(data)) {
            board(data);
            cout << "==>Player X won.";
            ofstream file;
            file.open("data.txt", ios::out | ios::app);
            file << player_1 << " " << player_2 << " " << player_1 << " " << "None" << " " << date << "\n";
            file.close();
            return_exit();
          }
        } else if (i % 2 == 0) {
          cout << "Player O turn: ";
          cin >> user_input;
          playerOprint(user_input, data);
          if (checkwin(data)) {
            board(data);
            cout << "==>Player O won.";
            ofstream file;
            file.open("data.txt", ios::out | ios::app);
            file << player_1 << " " << player_2 << " " << player_2 << " " << "None" << " " << date << "\n";
            file.close();
            return_exit();
          }
        }
        board(data);
      }
    } else if (input2 == 3) {
      //go back
      main();
    }
  }
  else if (input == 2) {
    //game results
    string player1, player2, winner, level, date1;
    ifstream open_file;
    open_file.open("data.txt", ios:: in | ios::binary);
    int i = 0;

    cout << "\t\tPlayer 1|" << " " << "Player2|" << " " << "Winner|" << " " << "Level|" << " " << "Date|";
    cout << "\n\t\t=======================================\n";
    while (open_file >> player1 >> player2 >> winner >> level >> date1) {
      cout << "\t\t" << player1+","<< " " << player2+","<< " " << winner+"," << " " << level+"," << " " << date1 << "\n";
    }
    open_file.close();
  } else if (input == 3) {
    //quit
    exit(0);
  }
  return 0;
}
//Board function 
void board(char data[]) {
  system("cls");
  cout << "\t\t\tTick-Tac-Toe\n\n";
  cout << "\t\tPlayer 1 [X] ----- Player 2 [O]\n\n";
  cout << "\t     |     |        " << endl;
  cout << "\t  " << data[0] << "  |  " << data[1] << "  |  " << data[2] << endl;
  cout << "\t_____|_____|_____" << endl;
  cout << "\t     |     |        " << endl;
  cout << "\t  " << data[3] << "  |  " << data[4] << "  |  " << data[5] << endl;
  cout << "\t_____|_____|_____" << endl;
  cout << "\t     |     |        " << endl;
  cout << "\t  " << data[6] << "  |  " << data[7] << "  |  " << data[8] << endl;
  cout << "\t     |     |        " << endl;
}

//Print X function
void playerXprint(int user_input, char data[]) {
  switch (user_input) {
  case 1:
    if (switchcase_for_X(user_input, data))
      break;
  case 2:
    if (switchcase_for_X(user_input, data))
      break;
  case 3:
    if (switchcase_for_X(user_input, data))
      break;
  case 4:
    if (switchcase_for_X(user_input, data))
      break;
  case 5:
    if (switchcase_for_X(user_input, data))
      break;
  case 6:
    if (switchcase_for_X(user_input, data))
      break;
  case 7:
    if (switchcase_for_X(user_input, data))
      break;
  case 8:
    if (switchcase_for_X(user_input, data))
      break;
  case 9:
    if (switchcase_for_X(user_input, data))
      break;
  default:
    system("cls");
    board(data);
    cout << "Player X turn: ";
    cin >> user_input;
    playerXprint(user_input, data);
    break;
  }
}
//print O function
void playerOprint(int user_input, char data[]) {
  switch (user_input) {
  case 1:
    if (switchcase_for_O(user_input, data))
      break;
  case 2:
    if (switchcase_for_O(user_input, data))
      break;
  case 3:
    if (switchcase_for_O(user_input, data))
      break;
  case 4:
    if (switchcase_for_O(user_input, data))
      break;
  case 5:
    if (switchcase_for_O(user_input, data))
      break;
  case 6:
    if (switchcase_for_O(user_input, data))
      break;
  case 7:
    if (switchcase_for_O(user_input, data))
      break;
  case 8:
    if (switchcase_for_O(user_input, data))
      break;
  case 9:
    if (switchcase_for_O(user_input, data))
      break;
  default:
    system("cls");
    board(data);
    cout << "Player O turn: ";
    cin >> user_input;
    playerXprint(user_input, data);
    break;
  }
}
//checkwin for both players
bool checkwin(char data[]) {

  if (data[0] == data[1] && data[1] == data[2]) {
    return true;
  } else if (data[3] == data[4] && data[4] == data[5]) {
    return true;
  } else if (data[6] == data[7] && data[7] == data[8]) {
    return true;
  } else if (data[0] == data[3] && data[3] == data[6]) {
    return true;
  } else if (data[1] == data[4] && data[4] == data[7]) {
    return true;
  } else if (data[2] == data[5] && data[5] == data[8]) {
    return true;
  } else if (data[0] == data[4] && data[4] == data[8]) {
    return true;
  } else if (data[2] == data[4] && data[4] == data[6]) {
    return true;
  } else
    return false;

}

//check if the index is already taken or not for X	
bool switchcase_for_X(int user_input, char data[]) {
  int index;
  switch (user_input) {
  case 1:
    index = 0;
    break;
  case 2:
    index = 1;
    break;
  case 3:
    index = 2;
    break;
  case 4:
    index = 3;
    break;
  case 5:
    index = 4;
    break;
  case 6:
    index = 5;
    break;
  case 7:
    index = 6;
    break;
  case 8:
    index = 7;
    break;
  case 9:
    index = 8;
    break;
  }
  if (data[index] != 'X' && data[index] != 'O') {
    data[index] = 'X';
    return true;
  } else {
    cout << "Already Taken! ";
    cout << "Input Again: ";
    cin >> user_input;
    playerXprint(user_input, data);
  }
}

//check if the index is already taken or not for O	
bool switchcase_for_O(int user_input, char data[]) {
  int index;
  switch (user_input) {
  case 1:
    index = 0;
    break;
  case 2:
    index = 1;
    break;
  case 3:
    index = 2;
    break;
  case 4:
    index = 3;
    break;
  case 5:
    index = 4;
    break;
  case 6:
    index = 5;
    break;
  case 7:
    index = 6;
    break;
  case 8:
    index = 7;
    break;
  case 9:
    index = 8;
    break;
  }
  if (data[index] != 'X' && data[index] != 'O') {
    data[index] = 'O';
    return true;
  } else {
    cout << "Already Taken! ";
    cout << "Input Again: ";
    cin >> user_input;
    playerOprint(user_input, data);
    return false;
  }
}

//exit function
void return_exit() {
  bool entry = false;
  cout << "Press 0 To exit: ";
  cin >> entry;
  if (entry == false) {
    exit(0);
  }
}
