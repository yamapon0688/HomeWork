#include	<iostream>
#include	<cstdlib>
#include	<ctime>
using namespace std;
/*
enum Asset {
	Sherp,
	Space,
	Player,
	Warp,
	Goal,
	LineBreak,
};

const char* map[] = { "\
######################\n\
#                   P#\n\
#   #         #      #\n\
#      #         #   #\n\
#    #      #        #\n\
#                    #\n\
#        #     #     #\n\
#G                   #\n\
######################", //ステージ1
"#####################\n\
#          P         #\n\
#                    #\n\
#       #  #   #     #\n\
#                    #\n\
#    #    #  #       #\n\
#  #              #  #\n\
#    #               #\n\
#      #    #     #  #\n\
#                    #\n\
#          W         #\n\
######################\n", //ステージ2(A)
"######################\n\
#  W                 #\n\
#       #       #    #\n\
#                    #\n\
#     #     #    #   #\n\
#                    #\n\
#       #       #    #\n\
#   #       #        #\n\
#                    #\n\
#       #        #   #\n\
#                    #\n\
#           G        #\n\
######################\n",//ステージ2(B)
"######################\n\
#   P                 #\n\
#      #         #    #\n\
#         #     #     #\n\
#          #   #      #\n\
# #     #    #   # K# #\n\
#   ###        #  ##  #\n\
#        #            #\n\
#     #      #     #  #\n\
#                     #\n\
#                W    #\n\
#######################\n",//ステージ3(A)
"#######################\n\
#               W      #\n\
#                      #\n\
#   ####     ###    ## #\n\
#        #       ##    #\n\
#                      #\n\
#      G               #\n\
########################\n" };//ステージ3(B)

static void InputField();
static void Load(const char* map, const char* map2, bool& change);
static bool Operation(Asset* asset, Asset* asset2, int size, int size2, bool& change);
static void ReLoad(Asset* asset, Asset* asset2, int size, int size2, int moveidx, bool sign, bool& move, bool& change, bool& judge);

int main() {
	InputField();
}

static void InputField() {
	int stage;
	bool change = true;

	cout << "ステージを選択してください。(1 or 2)>" << flush;
	cin >> stage;

	if (stage == 1) {
		change = false;
		Load(map[stage - 1], map[stage - 1], change);
	}
	else {
		Load(map[stage - 1], map[stage], change);
	}
}

static void Load(const char* map, const char* map2, bool& change) {
	cout << map << endl;

	int idx = 0;
	int size = 0;
	int size2 = 0;

	for (int i = 0; map[i] != '\0'; i++) {
		size++;
	}

	Asset* asset = new Asset[size];

	if (change) {
		for (int i = 0; map2[i] != '\0'; i++) {
			size2++;
		}
	}

	Asset* asset2 = new Asset[size2];
	const char* save = map;

	while (*map) {
		switch (*map) {
		case '#':
			asset[idx] = Sherp; break;
		case ' ':
			asset[idx] = Space; break;
		case 'P':
			asset[idx] = Player; break;
		case 'W':
			asset[idx] = Warp; break;
		case 'G':
			asset[idx] = Goal; break;
		case '\n':
			asset[idx] = LineBreak; break;
		}

		map++;
		idx++;
	}

	if (change) {
		idx = 0;
		while (*map2) {
			switch (*map2) {
			case '#':
				asset2[idx] = Sherp; break;
			case ' ':
				asset2[idx] = Space; break;
			case 'P':
				asset2[idx] = Player; break;
			case 'W':
				asset2[idx] = Warp; break;
			case 'G':
				asset2[idx] = Goal; break;
			case '\n':
				asset2[idx] = LineBreak; break;
			}

			map2++;
			idx++;
		}
	}

	change = false;

	while (Operation(asset, asset2, size, size2, change)) {

	}

	delete[]asset;
	delete[]asset2;
}

static bool Operation(Asset* asset, Asset* asset2, int size, int size2, bool& change) {
	char choice;
	bool move = true;
	bool GoalJudge = false;

	do {
		cout << "動く方向を選択してください。(横:a(左) or d(右)、縦:w(上) or s(下))>" << flush;
		cin >> choice;
	} while (choice != 'a' && choice != 'd' && choice != 'w' && choice != 's');

	if (!change) {
		switch (choice) {
		case 'a':
			ReLoad(asset, asset2, size, size2, 1, false, move, change, GoalJudge); break;
		case 'd':
			ReLoad(asset, asset2, size, size2, 1, true, move, change, GoalJudge); break;
		case 'w':
			ReLoad(asset, asset2, size, size2, 23, false, move, change, GoalJudge); break;
		case 's':
			ReLoad(asset, asset2, size, size2, 23, true, move, change, GoalJudge); break;
		}
	}
	else {
		switch (choice) {
		case 'a':
			ReLoad(asset, asset2, size, size2, 1, false, move, change, GoalJudge); break;
		case 'd':
			ReLoad(asset, asset2, size, size2, 1, true, move, change, GoalJudge); break;
		case 'w':
			ReLoad(asset, asset2, size, size2, 23, false, move, change, GoalJudge); break;
		case 's':
			ReLoad(asset, asset2, size, size2, 23, true, move, change, GoalJudge); break;
		}
	}

	if (GoalJudge) {
		return false;
	}
	else {
		return true;
	}
}

static void ReLoad(Asset* asset, Asset* asset2, int size, int size2, int moveidx, bool sign, bool& move, bool& change, bool& judge) {
	static const Asset Save = Warp;
	static bool warpchange = false;

	if (!change) {
		if (sign) {
			for (int i = 0; i < size; i++) {
				if (move && asset[i] == Player && asset[i + moveidx] != Sherp) {
					if (asset[i + moveidx] == Goal) {
						judge = true;
					}
					else if (asset[i + moveidx] == Warp) {
						asset[i] = Space;
						change ? change = false : change = true;
						warpchange = true;
					}
					else {
						move = false;
						Asset save = asset[i + moveidx];
						asset[i + moveidx] = asset[i];
						asset[i] = save;

						if (warpchange) {
							asset[i] = Save;
							warpchange = false;
						}
					}
				}
			}
		}
		else {
			for (int i = 0; i < size; i++) {
				if (move && asset[i] == Player && asset[i - moveidx] != Sherp) {
					if (asset[i - moveidx] == Goal) {
						judge = true;
					}
					else if (asset[i - moveidx] == Warp) {
						asset[i] = Space;
						change ? change = false : change = true;
						warpchange = true;
					}
					else {
						move = false;
						Asset save = asset[i - moveidx];
						asset[i - moveidx] = asset[i];
						asset[i] = save;

						if (warpchange) {
							asset[i] = Save;
							warpchange = false;
						}
					}
				}
			}
		}
	}
	else {
		if (sign) {
			for (int i = 0; i < size2; i++) {
				if (move && asset2[i] == Player && asset2[i + moveidx] != Sherp) {
					if (asset2[i + moveidx] == Goal) {
						judge = true;
					}
					else if (asset2[i + moveidx] == Warp) {
						asset2[i] = Space;
						change ? change = false : change = true;
						warpchange = true;
					}
					else {
						move = false;
						Asset save = asset2[i + moveidx];
						asset2[i + moveidx] = asset2[i];
						asset2[i] = save;

						if (warpchange) {
							asset2[i] = Save;
							warpchange = false;
						}
					}
				}
			}
		}
		else {
			for (int i = 0; i < size2; i++) {
				if (move && asset2[i] == Player && asset2[i - moveidx] != Sherp) {
					if (asset2[i - moveidx] == Goal) {
						judge = true;
					}
					else if (asset2[i - moveidx] == Warp) {
						asset2[i] = Space;
						change ? change = false : change = true;
						warpchange = true;
					}
					else {
						move = false;
						Asset save = asset2[i - moveidx];
						asset2[i - moveidx] = asset2[i];
						asset2[i] = save;

						if (warpchange) {
							asset2[i] = Save;
							warpchange = false;
						}
					}
				}
			}
		}
	}

	if (change && warpchange) {
		for (int i = 0; i < size2; i++) {
			if (asset2[i] == Warp) {
				asset2[i] = Player;
			}
		}
	}
	else if (!change && warpchange) {
		for (int i = 0; i < size; i++) {
			if (asset[i] == Warp) {
				asset[i] = Player;
			}
		}
	}

	if (!judge) {
		if (change) {
			for (int i = 0; i < size2; i++) {
				switch (asset2[i]) {
				case Sherp:
					cout << "#" << flush; break;
				case Space:
					cout << ' '; break;
				case Player:
					cout << "P" << flush; break;
				case Warp:
					cout << "W" << flush; break;
				case Goal:
					cout << "G" << flush; break;
				case LineBreak:
					cout << endl; break;
				}
			}
		}
		else {
			for (int i = 0; i < size; i++) {
				switch (asset[i]) {
				case Sherp:
					cout << "#" << flush; break;
				case Space:
					cout << ' '; break;
				case Player:
					cout << "P" << flush; break;
				case Warp:
					cout << "W" << flush; break;
				case Goal:
					cout << "G" << flush; break;
				case LineBreak:
					cout << endl; break;
				}
			}
		}
	}
	else {
		cout << "Goal!!" << endl;
	}
}
*/