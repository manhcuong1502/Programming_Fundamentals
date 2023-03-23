
//
// Created by Nhan Nguyen on 01/03/2021.
//
#ifndef MONGOL_H
#define MONGOL_H

// The library here is concretely set, students are not allowed to include any other libraries.

string readyForBattle(const string ID[], const int NID, const string input1[], const int N1);
int decode(const string A, const string B);
string findRoute(const string input3);
string decodeVfunction(const string A, const string B);
string findBetrayals(const string input5[], const int N5);
int attack(const string input6[]);
int calculateNoOfWaitingDays(const string input7Str, const string input7Matrix[], const int k);

////////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER HERE
////////////////////////////////////////////////////////////////////////////

string revStr(string s, int n = 1) {
    int length = (int)s.length();
    string temp;
    for (int i = length - 1; i > -1; i -= n) {
        if (n == 2) temp.push_back(s[i - 1]);
        temp.push_back(s[i]);
    }
    return temp;
}
string readyForBattle(const string ID[], const int NID, const string input1[], const int N1)
{
    char deCode[4][7] = { {'E', 'F', 'G', 'H', 'I', 'J', 'K'},
                          {'L', 'M', 'N', 'O', 'P', 'Q', 'R'},
                          {'#', 'T', 'U', 'V', 'W', 'X', 'Y'},
                          {'@', 'A', 'S', 'Z', 'B', 'C', 'D'} };
    string* result = new string[N1];
    for (int i = 0; i < N1; i++) {
        int idx = 0;
        int ins = 0;
        char lt = '!';
        while (idx < (int)input1[i].length()) {

            int row = 2 * (input1[i][idx] - '0') + input1[i][idx + 1] - '0';
            int col = 0;
            while (input1[i][idx] != ' ' && idx < (int)input1[i].length()) {
                col += 1;
                idx += 2;
            }
            col = (col % 7 == 0) ? 7 : (col % 7);
            col--;
            result[i].push_back(deCode[row][col]);
            if (input1[i][idx] == '\0' && (deCode[row][col] == '@' || deCode[row][col] == '#')) {
                result[i].pop_back();
            }

            if (deCode[row][col] == '#' || deCode[row][col] == '@' || input1[i][idx] == '\0') {
                if (ins) {
                    if (lt == '#') {
                        result[i].erase(ins - 1, 1);
                        int last_pos = (int)result[i].length() - 1;
                        if (input1[i][idx] != '\0') last_pos--;
                        char addLt = result[i][last_pos];
                        addLt = (addLt == 'Z') ? 'A' : (addLt + 1);
                        if (input1[i][idx] == '\0') result[i].push_back(addLt);
                        else {
                            result[i].pop_back();
                            result[i].push_back(addLt);
                            result[i].push_back(deCode[row][col]);
                        }
                    }
                    else {
                        int nLt = (int)result[i].length() - ins;
                        if (input1[i][idx] != '\0') {
                            nLt -= 1;
                        }
                        string str = revStr(result[i].substr(ins, nLt));
                        result[i].erase(ins - 1, nLt + 2);
                        if (input1[i][idx] != '\0') {
                            str += deCode[row][col];
                        }
                        result[i] += str;
                    }
                }
                lt = deCode[row][col];
                ins = (int)result[i].length();

            }
            if (input1[i][idx] != '\0') idx++;
        }
    }

    int special_character = 0;
    for (int i = 0; i < NID; i++) {
        int THD = (int)ID[i].find("THD");
        if (ID[i].find("VUA") == 0) {
            special_character = 1;
            break;
        }
        else if (THD > 0 && THD < (int)ID[i].length() - 3) {
            special_character = 2;
            break;
        }
    }
    if (special_character == 1) {
        for (int i = 0; i < N1; i++) {
            string str;
            if (result[i].length() % 2) {
                str = revStr(result[i]);
            }
            else {
                str = revStr(result[i], 2);
            }
            int j = 0;
            while (result[i][j] != '\0') {
                result[i][j] = (str[j] > result[i][j]) ? str[j] : result[i][j];
                j++;
            }
        }
    }
    else if (special_character == 2) {
        for (int i = 0; i < N1; i++) {
            string str;
            int j = 0;
            while (result[i][j] != '\0') {
                if (j % 3 != 0) {
                    str += result[i][j];
                }
                j++;
            }
            int n = (int)str.length();
            for (int k = 0; k < n - 1; k++) {
                for (j = k + 1; j < n; j++) {
                    if (str[k] > str[j]) {
                        char temp = str[k];
                        str[k] = str[j];
                        str[j] = temp;
                    }
                }
            }
            result[i] = str;
        }
    }
    string output;
    for (int i = 0; i < N1; i++) {
        output = output + result[i] + " ";
    }
    output.pop_back();
    delete [] result;
    return output;
}

int decode(const string A, const string B)
{
    int len = (int)B.length();
    int result = 0;
    int stop = (int)A.length() - len + 1;
    for (int i = 0; i < stop; i++) {
        if (A[i] == B[0] && A.substr(i, len) == B) {
            result++;
        }
    }
    return result;
}
string findRoute(const string input3)
{
    string ins = input3;
    int x = 0;
    int y = 0;
    int N = atoi(ins.c_str());
    ins.erase(0, ins.find(' ') + 1);
    int B = atoi(ins.c_str());
    ins.erase(0, ins.find(' ') + 1);
    if (B < 0) {
        B = -B;
        for (int i = 0; i < B; i++) {
            ins += ins.front();
            ins.erase(0, 1);
        }
    }
    else if (B > 0) {
        for (int i = 0; i < B; i++) {
            ins = ins.back() + ins;
            ins.pop_back();
        }
    }
    char direction[4] = { 'U', 'D', 'L', 'R' };
    for (int i = 0; i < (int)ins.length(); i++) {
        int newDirect = abs(N - 2 * i);
        switch (ins[i]) {
        case 'U':
        {
            newDirect %= 4;
            break;
        }
        case 'D':
        {
            newDirect = (newDirect + 1) % 4;
            break;
        }
        case 'L':
        {
            newDirect = (newDirect + 2) % 4;
            break;
        }
        case 'R':
        {
            newDirect = (newDirect + 3) % 4;
            break;
        }
        }
        switch (direction[newDirect]) {
        case 'U':
        {
            y++;
            break;
        }
        case 'D':
        {
            y--;
            break;
        }
        case 'L':
        {
            x--;
            break;
        }
        case 'R':
        {
            x++;
            break;
        }
        }
    }
    return "(" + to_string(x) + "," + to_string(y) + ")";
}
string decodeVfunction(const string A, const string B)
{
    if (A == "0" || B == "0") return "0";
    int vA = (int)count(A.begin(), A.end(), 'V');
    int vB = (int)count(B.begin(), B.end(), 'V');
    int n = vA * vB;
    string result = "V(0)";
    while (n > 1) {
        result = "V(" + result + ")";
        n--;
    }
    return result;
}
string findBetrayals(const string input5[], const int N5)
{
    int score[26];
    int Char[26];
    for (int i = 0; i < 26; i++) {
        Char[i] = i;
    }
    for (int i = 0; i < 26; i++) {
        score[i] = 0;
    }
    for (int i = 0; i < N5; i++) {
        int j = 0;
        int len = (int)input5[i].length();
        while (j < len) {
            score[input5[i][j] - 'A'] += (len - j);
            j++;
        }
    }
    for (int k = 0; k < 25; k++) {
        for (int j = k + 1; j < 26; j++) {
            if (score[k] > score[j] || (score[k] == score[j] && Char[k] < Char[j])) {
                int temp = Char[k];
                Char[k] = Char[j];
                Char[j] = temp;
                int temp1 = score[k];
                score[k] = score[j];
                score[j] = temp1;
            }
        }
    }
    string result;
    result.push_back(Char[25] + 'A');
    result.push_back(Char[24] + 'A');
    result.push_back(Char[23] + 'A');
    return result;
}
int attack(const string input6[])
{
    int result = -1;
    int count = 0;
    for (int i = 0; i < 10; i++) {
        int tmp_count = 0;
        for (int j = 0; j < 10; j++) {
            if (input6[i][j] == '2') {
                tmp_count = -1;
                break;
            }
            if (input6[i][j] == '0')
                tmp_count++;
        }
        if (tmp_count >= count) {
            count = tmp_count;
            result = i;
        }
    }
    return result;
}
int calculateNoOfWaitingDays(const string input7Str, const string input7Matrix[], const int k)
{
    string ins = input7Str;
    int N7 = atoi(ins.c_str());
    ins.erase(0, ins.find(' ') + 1);
    long int V = atoi(ins.c_str());
    ins.erase(0, ins.find(' ') + 1);
    int i = atoi(ins.c_str());
    ins.erase(0, ins.find(' ') + 1);
    int j = atoi(ins.c_str());
    int* arr = new int[N7 * N7];
    long int ** matrix = new long int* [k];
    for (int a = 0; a < k; a++) {
        matrix[a] = new long int[N7 * N7];
        string mat = input7Matrix[a];
        for (int b = 0; b < (N7 * N7); b++) {
            matrix[a][b] = atoi(mat.c_str());
            mat.erase(0, mat.find(' ') + 1);
        }
    }
    for (int M = 0; M < k - 1; M++) {
        for (int x = 0; x < N7; x++) {
            for (int y = 0; y < N7; y++) {
                arr[N7 * x + y] = 0;
                for (int z = 0; z < N7; z++)
                    arr[N7 * x + y] = arr[N7 * x + y] + matrix[M][N7 * x + z] * matrix[M + 1][N7 * z + y];
            }
        }
        for (int x = 0; x < N7 * N7; x++) {
            matrix[M + 1][x] = arr[x];
        }
    }
    long int R;
    long int D = matrix[k - 1][N7 * i + j];
    if (D < 0 && D % V != 0){
        int tmp = D / V;
        tmp --;
        R = D - (tmp * V);
    }
    else R = D % V;
    delete [] arr;
    for (int i = 0; i < k; i++){
        delete [] matrix[i];
    }
    delete [] matrix;
    return R;
}

#endif /* MONGOL_H */