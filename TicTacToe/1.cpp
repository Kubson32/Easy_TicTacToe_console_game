#include<iostream>
#include<string>
#include <array>

using namespace std;

void board(char place[9]) {
	
	cout << endl << "\t " << place[0] << " | " << place[3] << " | " << place[6] << endl;

	for (int j = 1; j < 3; j++) {
		cout << "\t----------- " << endl;

		cout << "\t " << place[j] << " | " << place[j + 3] << " | " << place[j + 6] << endl;
	}
	cout << endl;
}

void start_board(char place[9]) {
	for (int i = 0; i < 9; i++) {
		place[i] = i + 49;
	}
	board(place);
}

void clear_board(char place[9]) {

	for (int i = 0; i < 9; i++) {
		place[i] = 32;
	}
}

void Oturn(int Oplace, char place[9], bool Xt, bool Ot) {

	while (place[Oplace] == 79 || place[Oplace] == 88) {

		cout << "This place is not empty!" << endl << "Choose other place:" << endl;
		cin >> Oplace;
	}
	place[Oplace] = 79;
	board(place);
	
	Xt = true;
	Ot = false;
	
}

void Xturn(int Xplace, char place[9], bool Xt, bool Ot) {

	while (place[Xplace] == 79 || place[Xplace] == 88) {

		cout << "This place is not empty!" << endl << "Choose other place:" << endl;
		cin >> Xplace;
	}
	place[Xplace] = 88;
	board(place);

	Xt = false;
	Ot = true;
}

bool Xwins(bool Xwin, char place[9]) {
	Xwin = false;
	if (place[0] == 88 && place[1] == 88 && place[2] == 88) {
		Xwin = true;
		cout << "X wins!";
	}
	else if (place[3] == 88 && place[4] == 88 && place[5] == 88) {
		Xwin = true;
		cout << "X wins!";
	}
	else if (place[6] == 88 && place[7] == 88 && place[8] == 88) {
		Xwin = true;
		cout << "X wins!";
	}
	else if (place[0] == 88 && place[3] == 88 && place[6] == 88) {
		Xwin = true;
		cout << "X wins!";
	}
	else if (place[1] == 88 && place[4] == 88 && place[7] == 88) {
		Xwin = true;
		cout << "X wins!";
	}
	else if (place[2] == 88 && place[5] == 88 && place[8] == 88) {
		Xwin = true;
		cout << "X wins!";
	}
	else if (place[0] == 88 && place[4] == 88 && place[8] == 88) {
		Xwin = true;
		cout << "X wins!";
	}
	else if (place[2] == 88 && place[4] == 88 && place[6] == 88) {
		Xwin = true;
		cout << "X wins!";
	}
	return Xwin;
}

bool Owins(bool Owin, char place[9]) {
	Owin = false;
	if (place[0] == 79 && place[1] == 79 && place[2] == 79) {
		Owin = true;
		cout << "O wins!";
	}
	else if (place[3] == 79 && place[4] == 79 && place[5] == 79) {
		Owin = true;
		cout << "O wins!";
	}
	else if (place[6] == 79 && place[7] == 79 && place[8] == 79) {
		Owin = true;
		cout << "O wins!";
	}
	else if (place[0] == 79 && place[3] == 79 && place[6] == 79) {
		Owin = true;
		cout << "O wins!";
	}
	else if (place[1] == 79 && place[4] == 79 && place[7] == 79) {
		Owin = true;
		cout << "O wins!";
	}
	else if (place[2] == 79 && place[5] == 79 && place[8] == 79) {
		Owin = true;
		cout << "O wins!";
	}
	else if (place[0] == 79 && place[4] == 79 && place[8] == 79) {
		Owin = true;
		cout << "O wins!";
	}
	else if (place[2] == 79 && place[4] == 79 && place[6] == 79) {
		Owin = true;
		cout << "O wins!";		
	}
	return Owin;
}

int main() {
	char place[9];

	int Oplace;
	int Xplace;

	bool O = true;
	bool X = false;
	bool Xwin = false;
	bool Owin = false;

	cout << "Welcome to TicTacToe game!" << endl;

	cout << "Numbers on the board:" << endl;

	start_board(place);

	clear_board(place);	

	int num = 0;
	
	while (Xwin == false || Owin == false) {
		if (O) {
			cout << "O turn: ";
			cin >> Oplace;
			Oturn(Oplace-1, place, X, O);
			O = false;
			X = true;
			
			if (Owins(Owin, place)) {
				break;
			}
			
		}
		else if(X){
			cout << "X turn: ";
			cin >> Xplace;
			Xturn(Xplace-1, place, X, O);
			O = true;
			X = false;
			
			if (Xwins(Xwin, place)) {
				break;
			}
		}
		num++;

		if (num == 9) {
			cout << "End game! No one wins!";
			break;
		}
		
	}

	return 0;
}