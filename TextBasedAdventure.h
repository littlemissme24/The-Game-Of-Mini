#pragma once
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <Windows.h>
#include <fstream>

using namespace std;
int game2(std::string usrname);
void Tylerville();
void TylerHouse();
void stage1();
void stage2();
void stage3();
void stage4(int& jewelry, int& dollars);
void darkAlley();
void attackRobber(int& pHealth, int& tHealth);
void robberKnockedOut();
void searchBody();
void missionUpdate();
void end();
void writeLineToFile(string);
