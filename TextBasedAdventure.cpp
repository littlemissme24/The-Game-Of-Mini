#include "TextBasedAdventure.h"
//Functions

int input;
int stages[5] = { 1, 0, 0, 0, 0 };
//strings that are called upon during text.
string userName;
string qUpdates;
string qStages;
int dollars;
int jewelry;

int game2(std::string usrname) {

    srand(unsigned(time(NULL)));

    system("cls");
    cout << "\n 1. Play" << endl;
    cout << "\n 2. Exit" << endl;
    cout << "\n> ";
    cin >> input; 
    //cout << "May I get your name please? " << endl;
    //user inputs their characters name here.
    userName = usrname;
    writeLineToFile("Player's Name: " + userName);
    cout << "Hello " << userName << ", you will be going on a mission. Good luck!" << endl;
    Sleep(4000);
    //switch allows variable to be tested on a list of values.
    switch (input) {
        //case is the value on the list.
    case 1:
        qUpdates = "Mission Started";
        qStages = "Talk to Tyler at his house";
        missionUpdate();

        Tylerville();

    case 2:
        exit(0);

    }
}

void Tylerville() {
    //Clears screen, making it look cleaner and not jumbled up.
    system("cls");
    cout << "\n You are in Tylerville. Where do you go?" << endl;
    cout << "\n 1. Tyler's House" << endl;
    cout << "\n 2. Down the dark alley" << endl;
    cout << "\n> ";
    //user inputs here.
    cin >> input;
    switch (input) {

    case 1:
        TylerHouse();

    case 2:
        darkAlley();

    }
}

void TylerHouse() {
    //if this answer is chosen, this outcome will be called upon.
    if (stages[0] == 1) {
        system("cls");
        cout << "\n Tyler: Hey! I'm in need of some help. Can you please help me?" << endl;
        cout << "\n 1. What can I help you with?" << endl;
        cout << "\n 2. I've got other things to do." << endl;
        cout << "\n> ";
        cin >> input;
        switch (input) {

        case 1:
            stage1();

        case 2:
            system("cls");
            cout << "\n Ok, let me know when you are free." << endl;
            cout << "\n ";
            system("pause");
            Tylerville();

        }
    }

    if (stages[1] == 1) {
        stage2();
    }

    if (stages[2] == 1) {
        stage3();
    }

    else {
        stage4(jewelry, dollars);
    }
}
//different stages of story
void stage1() {

    system("cls");
    cout << "\n So I have alot of jewelry in my room that has been passed down in my family for many generations." << endl;
    cout << "\n I had hopes of selling them soon! " << endl;
    cout << "\n ";
    system("pause");

    system("cls");
    cout << "\n I was having a walk and on my way back I noticed my door was open and I saw a torn piece of cloth caught on the door." << endl;
    cout << "\n The cloth matched the hoodie of this sketchie guy that I saw. " << endl;
    cout << "\n ";
    system("pause");

    system("cls");
    cout << "\n I saw him walking down a very dark alley." << endl;
    cout << "\n ";
    system("pause");

    system("cls");
    cout << "\n I'd go after him myself, but I don't got nothing to defend myself with." << endl;
    cout << "\n 1. Ok, I can go question him for you." << endl;
    cout << "\n 2. I'm not the type of person to go do these type of things for strangers, sorry." << endl;
    cout << "\n> ";
    cin >> input;
    switch (input) {

    case 1:
        stages[0] = 0;
        stages[2] = 1;
        system("cls");
        cout << "\n Thank you so much! Let me know if anything changes." << endl;
        cout << "\n ";
        system("pause");

        qUpdates = "Mission updated";
        qStages = "Question the sketchie guy in the dark alley.";
        missionUpdate();

        Tylerville();

    case 2:
        stages[0] = 0;
        stages[1] = 1;
        system("cls");
        cout << "\n Maybe I should get some help." << endl;
        cout << "\n ";
        system("pause");
        Tylerville();

    }
}
//different stages of story
void stage2() {

    system("cls");
    cout << "\n Anything knew?" << endl;
    cout << "\n 1. Yes, I think I can help." << endl;
    cout << "\n 2. I don't think I can do this for you." << endl;
    cout << "\n> ";
    cin >> input;
    switch (input) {

    case 1:
        stages[0] = 0;
        stages[1] = 0;
        stages[2] = 1;
        system("cls");
        cout << "\n Thank you so much! Let me know if anything changes." << endl;
        cout << "\n ";
        system("pause");

        qUpdates = "Mission updated";
        qStages = "Question the sketchie guy in the dark alley.";
        missionUpdate();

        Tylerville();

    case 2:
        system("cls");
        cout << "\n Darn it. Maybe I can find someone else then, or if you change your mind come talk to me." << endl;
        cout << "\n ";
        system("pause");
        Tylerville();

    }
}
//different stages of story
void stage3() {

    system("cls");
    cout << "\n Any word on my jewelry?" << endl;
    cout << "\n 1. None yet." << endl;
    cout << "\n> ";
    cin >> input;
    switch (input) {

    case 1:
        system("cls");
        cout << "\n Hopefully my jewelry isn't far with you lolly gaggin' around all day." << endl;
        cout << "\n ";
        system("pause");
        Tylerville();

    }
}
//different stages of story
void stage4(int& dollars, int& jewelry) {

    system("cls");
    cout << "\n Any word on my jewelry?" << endl;
    cout << "\n 1. Oh yeah, I got it all right here." << endl;
    cout << "\n 2. Yeah, but the guy almost killed me!" << endl;
    cout << "\n> ";
    cin >> input;

    system("cls");
    cout << "\n Oh my gosh, thank you so much! " << endl;
    cout << "\n Here, I gotta pay you back!" << endl;
    cout << "\n ";
    system("pause");

    jewelry = 0;
    system("cls");
    cout << "\n Item removed - Tyler's jewelry." << endl;
    cout << "\n ";
    system("pause");
    //adds "dollars" to users inventory.
    dollars = dollars + 100;
    system("cls");
    cout << "\n Item added - 300 dollars" << endl;
    cout << "\n ";
    system("pause");

    qUpdates = "Mission Complete";
    qStages = " ";
    missionUpdate();

    end();

}

void darkAlley() {

    int pHealth;
    int tHealth;
    int tDamage;
    int turn;

    if (stages[0] == 1 || stages[1] == 1) {
        system("cls");
        cout << "\n I must've made a wrong turn." << endl;
        cout << "\n ";
        system("pause");
        Tylerville();
    }

    system("cls");
    cout << "\n Sketchie Hoodie Guy: You better get outta here pal!" << endl;
    cout << "\n 1. You know anything about a butt load of jewelry?" << endl;
    cout << "\n 2. My bad, didn't mean to disturb you." << endl;
    cout << "\n> ";
    cin >> input;
    switch (input) {

    case 1:
        system("cls");
        cout << "\n He'll never get em' back!" << endl;
        cout << "\n ";
        system("pause");

        pHealth = rand() % 40 + 80;
        tHealth = rand() % 20 + 40;

        turn = rand() % 2;

        if (turn == 1) {
            system("cls");
            cout << "\n Sketchie Hoodie Guy has the first turn." << endl;
            cout << "\n ";
            system("pause");

            tDamage = rand() % 5 + 10;

            pHealth = pHealth - tDamage;
            system("cls");
            cout << "\n Sketchie Hoodie Guy punches you for " << tDamage << " damage!" << endl;
            cout << "\n ";
            system("pause");

        }

        else {
            system("cls");
            cout << "\n You have the first turn." << endl;
            cout << "\n ";
            system("pause");
        }

        attackRobber(pHealth, tHealth);

    case 2:
        system("cls");
        cout << "\n That's what I thought." << endl;
        cout << "\n ";
        system("pause");
        Tylerville();

    }
}

void attackRobber(int& pHealth, int& tHealth) {

    int pDamage;
    int tDamage;
    //randamizes the amount of damage.
    pDamage = rand() % 10 + 10;
    tDamage = rand() % 5 + 10;

    system("cls");
    cout << "\n Your health: " << pHealth << endl;
    cout << "\n Sketchie Hoodie Guy's health:  " << tHealth << endl;
    cout << "\n What's your next move?" << endl;
    cout << "\n 1. Attack Sketchie Hoodie Guy" << endl;
    cout << "\n 2. Run away" << endl;
    cout << "\n> ";
    //user inputs what action they will take.
    cin >> input;
    switch (input) {

    case 1:
        //subtracts health with damage.
        tHealth = tHealth - pDamage;
        system("cls");
        cout << "\n You attack Sketchie Hoodie Guy for " << pDamage << " damage!" << endl;
        cout << "\n ";
        system("pause");

        if (tHealth < 1) {
            system("cls");
            cout << "\n You knocked the Sketchie Hoodie Guy out!" << endl;
            cout << "\n ";
            system("pause");
            robberKnockedOut();
        }
        //subtracts health with damage.
        pHealth = pHealth - tDamage;
        system("cls");
        cout << "\n Sketchie Hoodie Guy kicks you for " << tDamage << " damage!" << endl;
        cout << "\n ";
        system("pause");
        //shows the outcome if your health drops below 1
        if (pHealth < 1) {
            system("cls");
            cout << "\n You were knocked out by the Sketchie Hoodie Guy!" << endl;
            cout << "\n ";
            system("pause");
            exit(0);
        }

        attackRobber(pHealth, tHealth);

    case 2:
        system("cls");
        cout << "\n Trying to run away didn't work." << endl;
        cout << "\n ";
        system("pause");
        attackRobber(pHealth, tHealth);

    }
}

void robberKnockedOut() {
    //updates the users objective.
    qUpdates = "Mission updated";
    qStages = "Get Tyler's Jewelry";
    missionUpdate();

    system("cls");
    cout << "\n What do you do next?" << endl;
    cout << "\n 1. Search the Sketchie Hoodie Guy" << endl;
    cout << "\n 2. Walk out the dark alley" << endl;
    cout << "\n> ";
    cin >> input;
    switch (input) {

    case 1:
        searchBody();

    case 2:
        Tylerville();

    }
}

void searchBody() {

    int dollars;
    int jewelry;
    dollars = 20;
    jewelry = 1;
    stages[2] = 0;
    stages[3] = 1;

    system("cls");
    cout << "\n You found 60 bucks and all of Tyler's jewelry!" << endl;
    cout << "\n ";
    system("pause");

    qUpdates = "Mission updated";
    qStages = "Take the jewelry back to Tyler";
    missionUpdate();

    return;

}

void missionUpdate() {

    system("cls");
    cout << "\n " << qUpdates << " - Tyler's family jewelry" << endl;
    cout << "\n ";
    system("pause");

    if (qStages != " ") {
        system("cls");
        cout << "\n " << qStages << endl;
        cout << "\n ";
        system("pause");
    }

    return;

}
//The ending of the game.
void end() {

    system("cls");
    cout << "\n Thanks for playing my game!" << endl;
    cout << "\n ";
    system("pause");
    game2(userName);

}

void writeLineToFile(string) {
    std::ofstream myFileObject("SaveGameProgress");
    myFileObject << "User Name Saved\n";
    myFileObject.close();
}