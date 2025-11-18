/*
#define _CRT_SECURE_NO_WARNINGS
#define QUIZ_MAX 10 //マクロ関数
#define QUIZ_TO_GUESS 5
#define CHOICE_MAX 4
#define SQR(x) ((x)*(x))
#include <iostream>
#include <cstring> // 文字列比較のために必要
#include <stdio.h>//標準入出力 (Standard Input Output) を扱うためのヘッダ。printf() や scanf() などの入出力関数ファイル操作(fopen, fclose, fread, fwrite など)
#include<stdlib.h>//標準ライブラリ (Standard Library) の汎用関数をまとめたヘッダ。動的メモリ確保 (malloc, free)乱数生成(rand, srand)プログラム終了(exit)
#include<conio.h> //コンソール入出力 (Console Input Output) を扱うヘッダ。getch() → キー入力を待つ（Enter不要）kbhit() → キーが押されたかどうかを判定
#include<Windows.h> //Windows API を使うためのヘッダSleep() → 指定ミリ秒だけ待機ウィンドウ操作、スレッド、ファイル、ネットワークなどの低レベル機能
#include<time.h>
using namespace std; //4-2 p136

//二問目　は当たった数の評価
//time_t
int main() {
    srand((unsigned int)time(NULL));
    int b = 5;
    cout << "the number below is Macro Test" << endl;
    int a = SQR(10);
    cout << a << "," << SQR(b) << endl << endl;

    char Q[QUIZ_MAX][200] = {
        {"「赤い惑星」と呼ばれる惑星はどれ？"}, //Q[0]
        {"『ロミオとジュリエット』を書いたのは誰？" }, //Q[1]
        {"日本の首都はどこ？"}, //Q[2]
        {"人間が主に吐き出す気体は？"}, //Q[3]
        {"地球上で最大の哺乳類は？"}, //Q[4]
        {"化学記号「O」はどの元素？"},
        {"第二次世界大戦が終わった年は？"},
        {"鍵盤が88ある楽器は？"},
        {"最も速い陸上動物は？"},
        {"世界最大の海洋は？"},
    };
    char Ans[QUIZ_MAX][200] = {
        {"火星"}, //QUIZ_MAX 1 [1028]
        {"ウィリアム・シェイクスピア" }, //QUIZ_MAX 2 [1028]
        {"東京"}, //QUIZ_MAX 3 [1028]
        {"二酸化炭素"}, //QUIZ_MAX 4 [1028]
        {"シロナガスクジラ"}, //QUIZ_MAX 5 [1028]
        {"酸素"},
        {"1945年"},
        {"ピアノ"},
        {"チーター"},
        {"太平洋"},
    };
    char Choices[QUIZ_MAX][4][200] = {
        {
            {"地球"}, //QUIZ_MAX 1 [0] [1000]各文字列の「長さ
            {"木星"}, //QUIZ_MAX 1 [1]
            {"火星"}, //QUIZ_MAX 1 [2]
            {"金星"}, //QUIZ_MAX 1 [3]
        },//QUIZA_MAX 1
        {
            {"マーク・トウェイン"}, //QUIZ_MAX 2 [0] [1000]各文字列の「長さ
            {"ジェーン・オースティン"}, //QUIZ_MAX 2 [1]
            {"チャールズ・ディケンズ"}, //QUIZ_MAX 2 [2]
            {"ウィリアム・シェイクスピア"}, //QUIZ_MAX 2 [3]
        },//QUIZA_MAX 2
        {
            {"名古屋"},
            {"京都"},
            {"東京"},
            {"大阪"},
        },//QUIZA_MAX 3cout
        {
            {"水素"},
            {"酸素"},
            {"二酸化炭素"},
            {"窒素"},
        },//QUIZA_MAX 4
        {
            {"カバ"},
            {"シロナガスクジラ"},
            {"ゾウ"},
            {"キリン"},
        },//QUIZA_MAX 5
        {
            {"オガネソン"},
            {"金"},
            {"酸素"},
            {"オスミウム"},
        },//QUIZA_MAX 6
        {
            {"1945年"},
            {"1950年"},
            {"1940年"},
            {"1939年"},
        },//QUIZA_MAX 7
        {
            {"ギター"},
            {"ピアノ"},
            {"バイオリン"},
            {"フルート"},
        },//QUIZA_MAX 8
        {
            {"ライオン"},
            {"レイハウンド"},
            {"馬"},
            {"チーター"},
        },//QUIZA_MAX 9
        {
            {"大西洋"},
            {"インド洋"},
            {"太平洋"},
            {"北極海"},
        },//QUIZA_MAX 10
    };
    int score = 0;
    bool GameOver = false;
    cout << "all questions will be " << QUIZ_TO_GUESS << " in a roll" << endl;
    char input[200];
    while (GameOver == false) {

        bool used[QUIZ_MAX] = { false }; // 出題済みフラグ

        for (int i = 0; i < QUIZ_TO_GUESS; ++i) {
            int random;
            do {
                random = rand() % QUIZ_MAX;
            } while (used[random]);

            used[random] = true;

            cout << Q[random] << endl;
            for (int j = 0; j < CHOICE_MAX; ++j) {
                cout << Choices[random][j] << endl;
            }
            cout << endl;
            time_t start = time(NULL);// 現在時刻を取得
            int limit = 10;
            cout << "残り時間: " << flush;
            while (true) {
                double elapsed = difftime(time(NULL), start);
                int remaining = (int)(limit - elapsed); // 小数を切り捨てて整数秒に

                //時間制限 time(NULL) → プログラムが動いている間、呼び出すたびに「現在の時刻」を返します。秒単位でどんどん増えていきます。
                if (remaining <= 0) {
                    cout << "時間切れ!" << endl;
                    break;
                }
                cout << remaining << "," << flush;
                Sleep(1000); //一秒待つ
                if (_kbhit()) {
                    cin >> input;
                    //strcmp関数が「0を返すと一致している」と判断できる理由は、関数の仕様
                    if (strcmp(input, Ans[random]) == 0) {
                        cout << "正解" << endl << endl;
                        score++;
                        break;
                    }
                    else if (strcmp(input, "a") == 0) {
                        cout << "答え: " << Ans[random] << endl;
                        cout << "もう一度入力してください。" << endl << endl;
                        start = time(NULL);
                    }
                    else {
                        cout << "不正解" << endl << endl;
                        break;
                    }
                }
            }
            cout << "スコア" << score << endl << endl;
        }
        if (score == QUIZ_TO_GUESS) {
            cout << "全問正解！すばらしい！" << endl;
        }
        else if (score >= 3) {
            cout << "よくできました！" << endl;
        }
        else {
            cout << "もっと頑張りましょう！" << endl;
        }
        char playAgain[2] = { '\0' };
        cout << " play again?" << endl;
        cout << "y : n " << endl;
        cin >> playAgain;
        while (true) {
            if (strcmp(playAgain, "y") == 0) {
                //whileに戻る
                score = 0;
                break;
            }
            else if (strcmp(playAgain, "n") == 0) {
                GameOver = true;
                break;
            }
            else {
                cout << " play again?" << endl;
                cout << "y : n " << endl;
                cin >> playAgain;
            }
        }
    }
}
*/