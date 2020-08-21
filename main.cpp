#include <iostream>
#include <string>
#include <cstdlib>
#include <list>
#include <algorithm>
#include <fstream>
#include "highFiveHiring.h"

using namespace std;

class Room
{
    string intro;
    public:
    bool empty = false;
    void setIntro(string intro){
        this->intro = intro;
    }
    void printIntro(){
        std::cout<<intro;
    }
};

class Cache
{
    std::list<int> content;
    public:
    void addObject(int objectId){
        content.push_back(objectId);
    }
    bool searchCache(int objectId){
        bool containingElement = (std::find(content.begin(),content.end(),objectId)!=content.end());
    }
};

class Person
{
public:
    skills skill;
    int highfives;
    int sumSkills(){
        return this->skill.programming_skills+this->skill.social_skills+this->skill.friday_bar_skills;
    }
    void printSkills(){
        std::cout << "Programming ";
        std::cout << skill.programming_skills << std::endl;
        std::cout << "Friday bar skills ";
        std::cout << skill.friday_bar_skills << std::endl;
        std::cout << "Social skills ";
        std::cout << skill.social_skills << std::endl;
    }

    void setSkills(skills skill){
        this->skill.programming_skills  = skill.programming_skills;
        this->skill.social_skills       = skill.social_skills;
        this->skill.friday_bar_skills   = skill.friday_bar_skills;
    }
};


class Avatar : public Person
{
    public:
        Cache cache;
        void addHighFives(int highFivePoints){
            this->highfives = this->highfives + highFivePoints;
        }
};

class Bot: public Person
{
    public:
        void randomizeSkills(skills skill){
            this -> skill.programming_skills = rand() % 10;
            this -> skill.friday_bar_skills  = rand() % 10;
            this -> skill.social_skills      = rand() % 20;
        }
};

class Game
{
    private:
        int userInput;
        Bot bots[NUMBER_OF_BOTS];
        Room rooms[NUMBER_OF_ROOMS];
        object objects[NUMBER_OF_OBJECTS];
        Avatar player_avatar;

    public:
    Game()
    {
        //setup bots
        for(int i = 0; i < sizeof(bots)/ sizeof(bots[0]); i++){
                bots->randomizeSkills(bots[i].skill);
        }

        //setup objects
        objects[FORK].id = FORK;
        objects[FORK].highFives = 2;

        objects[COOKIE].id = COOKIE;
        objects[COOKIE].highFives = 5;

        objects[SWORD].id = SWORD;
        objects[SWORD].highFives = 10;

        //setup rooms
        rooms[START_ROOM].setIntro(initialRoomMessage);
        rooms[FORK_ROOM].setIntro(forkRoomMessage);
        rooms[COOKIE_ROOM].setIntro(cookieRoomMessage);
        rooms[PYTHON_ROOM].setIntro(pythonRoomMessage);
    }

    void inputSkills(){
        skills skill;
        std::cout << "What is your skill set?" << std::endl;
        std::cout << "Programming: ";
        std::cin >> skill.programming_skills;
        std::cout << "Social skills: ";
        std::cin >> skill.social_skills;
        std::cout << "Friday bar skills: ";
        std::cin >> skill.friday_bar_skills;
        player_avatar.setSkills(skill);
    }

    bool calculateWin(){
        int bestBot;
        int temp;
        bestBot = bots[0].sumSkills();
        for(int i = 1; i < NUMBER_OF_BOTS; i++){
                if((temp = bots[i].sumSkills())>bestBot){
                    bestBot=temp;
            }
        }
        return (player_avatar.sumSkills()) > bestBot;
    }

    void moveToPython(){
        bool exit = false;
        if(rooms[PYTHON_ROOM].empty){
            std::cout << "Why are you in this room? it's empty!\n Press 1 to get back to the rooms with the doors 3\n";
            std::cin>>userInput;
            if(userInput == 1) {
                moveToInitialRoom();
            }
        }else{
            rooms[PYTHON_ROOM].printIntro();
        }
        while(!exit){
            std::cin>>userInput;
            switch(userInput){
                case 1:
                    exit = true;
                    moveToInitialRoom();
                    break;
                case 5:
                    if(player_avatar.cache.searchCache((objects[SWORD].id))){
                        std::cout << "You have the fork already no need to upset the dragon! - go back to the room with the doors! - quickly\n";
                    }
                    else if(player_avatar.cache.searchCache(objects[COOKIE].id)){
                        player_avatar.cache.addObject(objects[SWORD].id);
                        player_avatar.addHighFives(objects[SWORD].highFives);
                        std::cout << "Great! You got the C# sword (the sharpest sword in the realm!), and earned " << objects[SWORD].highFives <<" highfives!!\n";
                        exit = true;
                    }else{
                        std::cout << "You need to give it the git cookie, then it will settle down! - tsk it's in room number "<<COOKIE_ROOM<<"\n";
                    }
                    break;
            }
        }
        std::cout << "\nEven though you got the C# sword (the sharpest sword in the realm), you might still loose the job to one of the evil bots!\n"
                     "Let's see if they got more points then you...";
        if(calculateWin()){
            std::cout << winningMessage;
        }else{
            std::cout << "\n\nSomeone else apparently beat you to the mark.. better luck next time!";
        }
    }

    void moveToCookie(){
        bool exit = false;
        if(rooms[COOKIE_ROOM].empty){
            std::cout << "Why are you in this room? it's empty!\n Press 1 to get back to the rooms with the doors2\n";
            std::cin>>userInput;
            if(userInput == 1) {
                moveToInitialRoom();
            }
        }else{
            rooms[COOKIE_ROOM].printIntro();
        }
        while(!exit){
            std::cin>>userInput;
            switch(userInput){
                case 1:
                    exit = true;
                    moveToInitialRoom();
                    break;
                case 5:
                    if(player_avatar.cache.searchCache((objects[COOKIE].id))){
                        std::cout << "You have the cookie already go back to the room with the doors! - quickly!\n";
                    }
                    else if(player_avatar.cache.searchCache(objects[FORK].id)){
                        player_avatar.cache.addObject(objects[COOKIE].id);
                        rooms[COOKIE_ROOM].empty = true;
                        player_avatar.addHighFives(objects[COOKIE].highFives);
                        std::cout << "Fantastic! - you got the cookie! only you need a dragons apatite to eat it!\n"
                                     "You are rewarded with "<<objects[COOKIE].highFives<<" highfives!\n";

                    }else{
                        std::cout << "You need to get the git fork for that! - tsk look inside room number "<<FORK_ROOM<<"\n";
                    }
                    break;
            }
        }
    }

    void moveToFork(){
        bool exit = false;
        if(rooms[FORK_ROOM].empty){
            std::cout << "Why are you in this room? it's empty!\n Press 1 to get back to the rooms with the doors1\n";
            std::cin>>userInput;
            if(userInput == 1) {
                moveToInitialRoom();
            }
        }else{
            rooms[FORK_ROOM].printIntro();
        }
        while(!exit){
            std::cin>>userInput;
            switch(userInput){
                case 1:
                    exit = true;
                    moveToInitialRoom();
                    break;
                case 5:
                    if(player_avatar.cache.searchCache((objects[FORK].id))){
                        std::cout << "You have the fork already go back to the room with the doors! - quickly!\n";
                    }else{
                        player_avatar.cache.addObject(objects[FORK].id);
                        rooms[FORK_ROOM].empty = true;
                        player_avatar.addHighFives(objects[FORK].highFives);
                        std::cout << "Good job! - now you are the proud owner of the git fork! a powerfull tool for all developers\n"
                                     "and you earned "<<objects[FORK].highFives<<" highfives!\n";
                    }
                    break;
            }
        }
    }

    void moveToInitialRoom(){
            rooms[START_ROOM].printIntro();
            std::cin>>userInput;
            if(userInput==COOKIE_ROOM) {
                moveToCookie();
            }
            if(userInput==FORK_ROOM) {
                moveToFork();
            }
            if(userInput==3) {
                moveToPython();
        }
    }

    void printInitialMessage(){
        std:cout<<startMessage;
    }
    void printIntro(){
        std::cout<<afterSkillInput;
    }

    void startGame(){
        printInitialMessage();
        inputSkills();
        printIntro();
        moveToInitialRoom();
    }

};

int main() {
    Game game;
    int userInput;
    string l;
    ifstream logo ("../gameName.txt");
    if(logo.is_open()) {
        while(getline(logo,l)){
            cout << l << "\n";
        }
        logo.close();
    }
    std::cin>>userInput;
    if(userInput == 1){game.startGame();}
    return 0;
}
