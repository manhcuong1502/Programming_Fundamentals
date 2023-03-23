/*
    * Ho Chi Minh City University of Technology
    * Faculty of Computer Science and Engineering
    * Initial code for Assignment 0
    * Programming Fundamentals Spring 2021
    * Author: Nguyen Thanh Nhan
    * Date: 08.02.2021
*/

//The library here is concretely set, students are not allowed to include any other libraries.
#ifndef firstFight_h
#define firstFight_h

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

bool checkPrimeNum(int n){
    return n == 2 || n == 3 || n == 5 || n == 7;
}

void checkHP(int& HP1, int& HP2) {
    if (HP1 > 1000) HP1 = 1000;
    else if (HP1 < 0) HP1 = 0;
    if (HP2 > 1000) HP2 = 1000;
    else if (HP2 < 0) HP2 = 0;
}

int getReady(int& HP, const int& ID, int& M, const int& E1){
    //Complete this function to gain point on task 1
    if (E1 < 100 || E1 > 500) return -999;
    if (E1 <= 199){
        if (ID == 1){
            HP += 75;
        }
        else if (ID == 0){
            int h = (E1 - 100) % 64;
            int j = HP % 100;
            if (j > h){
                if (M % 2 == 1 && HP >= 500 && M >= 300){
                    M -= 300;
                    HP += 50;
                }
                if (M % 2 == 0 && M >= 200){
                    M -= 200;
                    HP += 25;
                }
            }
        }
        if (HP > 1000) HP = 1000;
        return HP + M;
    }
    else if (E1 <= 299 && E1 > 199){
        switch (E1 % 4 + 1){
            case 1:
                if (M >= 190 && (M % 2 || ID)){
                    M -= 190;
                    HP += 5;
                }
                break;
            case 2:
                if (M >= 195 && (!(M % 2) || ID)){
                    M -= 195;
                    HP += 7;
                }
                break;
            case 3:
                if (M >= 200 && (M % 2 || ID)){
                    M -= 200;
                    HP += 9;
                }
                break;
            case 4:
                if (M >= 205 && (!(M % 2) || ID)){
                    M -= 205;
                    HP += 11;
                }
                break;
        }
        if (HP > 1000) HP = 1000;
        if (M < 0) M = 0;
        return HP + M;
    }
    else if (E1 <= 399 && E1 > 299){
        float a = 0;
        if (checkPrimeNum(E1 % 10)){
            a = 2 * (E1 % 10);
        }
        else a = 1;
        if (HP >= 600){
            if (checkPrimeNum(HP % 10) && M >= 500){
                if (ID == 1) HP += 200;
                else HP += ceilf((float)(HP) * 2 * a / 100);
                M -= 500;
            }
            else if (!checkPrimeNum(HP % 10) && M >= 300){
                HP += ceilf((float)(HP) * a / 100);
                M -= 300;
            }
        }
        if (HP > 1000) HP = 1000;
        return HP + M;
    }
    else if (E1 <= 499 && E1 > 399){
        if (E1 % 5 == 0) HP = ceilf((float)(HP) *0.9 );
        return HP + M;
    }
    else if (E1 == 500){
        HP = ceilf((float)(HP) - HP * 0.25);
        M = ceilf((float)(M) - M * 0.25);
        return HP + M;
    }
    return 0;
}

int fight(int& HP1, int& HP2, const int& ID1, const int& ID2, int battle = 1){
    if (ID1 == 1 && ID2 == 2) return 0;
    else if (ID1 == 1) {
        HP2 = 0;
        return 1;
    }
    else if (ID2 == 2){
        if (battle == 1) HP1 = 0;
        return -1;
    }
    else{
        int u = ceilf((float)(2 * HP1 * HP2) / (float)(HP1 + HP2));
        int HP = HP1;
        HP1 = HP1 - abs(HP2 - u);
        HP2 = HP2 - abs(HP - u);
        if (HP1 < 0) HP1 = 0;
        if (HP2 < 0) HP2 = 0;
        if (HP1 - HP2 > 0) return 1;
        else if (HP1 - HP2 < 0) return -1;
        else return 0;
    }
}

int firstBattle(int& HP1, int& HP2, const int& ID1, const int& ID2, const int& E2){
    //Complete this function to gain point on task 2
    int result = 0;
    if (E2 < 100 || E2 > 499) return -999;
    if (E2 <= 199){
        HP1 = ceilf((float)(HP1) * 1.1);
        HP2 = ceilf((float)(HP2) * 1.3);
    }
    else if (E2 <= 299 && E2 > 199){
        HP1 = ceilf((float)(HP1) * 1.7);
        HP2 = ceilf((float)(HP2) * 1.2);
    }
    else if (E2 <= 399 && E2 > 299){
        if (E2 >= 350) HP1 += (E2 % 100);
        else HP1 += 30;
    }
    else if (E2 <= 499 && E2 > 399){
        HP2 = ceilf((float)(HP2) * 0.8);
        HP1 = ceilf((float)(HP1) * 1.3);
        
        if (HP1 > 1000) HP1 = 1000;
        
        HP1 = ceilf((float)(HP1) / 2);
    }
    checkHP(HP1, HP2);
    result = fight(HP1, HP2, ID1, ID2);
    int tmpHP1 = HP1;
    HP1 = ceilf((float)(tmpHP1) * 0.8);
    
    return result;
}

int secondBattle(int& HP1, int& HP2, const int& ID1, const int& ID2, const int& E3){
    //Complete this function to gain point on task 3
    if ((E3 < 100) || (E3 > 299)) return -999;
    HP1 = ceilf((float)(HP1) * 1.4);
    if (ID1 == 1) HP1 *= 2;
    HP2 = ceilf((float)(HP2) * 1.6);
    checkHP(HP1, HP2);
    int tmpHP = HP1;
    if (E3 >= 100 && E3 <= 199){
        if (ID2 == 0) HP2 = ceilf((float)(HP2) * 0.95);
    }
    else if (E3 > 199){
        if (ID2 == 0) HP2 = ceilf((float)(HP2) * 0.95);
        return 0;
    }
    int result = fight(HP1, HP2, ID1, ID2, 2);
    if (result == -1) HP1 = tmpHP;
    return result;
}

int finalBattle(int& HP1, int& HP2, const int& ID1, const int& ID2, const int& E4){
    //Complete this function to gain point on task 4
    if ((E4 < 100) || (E4 > 299)) return -999;
    if (E4 <= 199){
        if (ID2 == 2) HP2 = ceilf((float)(HP2) * 0.3);
        else HP2 = ceilf((float)(HP2) * 0.1);
        return 0;
    }
    else {
        HP2 = 0;
        return 1;
    }
}

#endif /* firstFight_h */
