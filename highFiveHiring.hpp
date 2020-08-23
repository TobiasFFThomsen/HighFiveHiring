//
// Created by tobias on 8/20/20.
//
#include <string>
using namespace std;
#ifndef HELLO_WORLD_HIGHFIVEHIRING_H
#define HELLO_WORLD_HIGHFIVEHIRING_H

#define NUMBER_OF_ROOMS 4
#define NUMBER_OF_OBJECTS 3
#define NUMBER_OF_BOTS 10
#define FORK 0
#define COOKIE 1
#define SWORD 2
#define START_ROOM   0
#define FORK_ROOM    2
#define COOKIE_ROOM  1
#define PYTHON_ROOM  3

struct skills {
    int programming_skills;
    int social_skills;
    int friday_bar_skills;
};

struct object {
    int id;
    int highFives;
};

string startMessage   = "Welcome to the game of highfive hiring!\n"
                        "In this game you will need all the competences you can get from past experience, to win the job.\n"
                        "There are evil candidate bots, that are after the same position as you, and if you are unlucky they might just win.\n";

string afterSkillInput = "\nLooks like youre ready to take your deepest plunge so far in the vast C called plusplus. \n"
                        "Here you will enter the dungeons of highfive hiring. \n"
                        "Grow thy gills and show them highfive skills!\n"
                        "\nIf you Want to be a resident in Unity-lands, \n"
                        "Highfive hiring requires you to to get your act together \n"
                        "and conquer the great great python++ bashelisk.\n"
                        "You will obtain the C# sword that residents use to\n"
                        "compile their way through future obstacles in Unity land.\n"
                        "Hopefully you will also gain some high-five points along the way to increase your chances!\n";



string pythonRoomMessage =  "\nAh the great big python bashelisk! with a strange appetite for cookies!\n"
                            "- And it is guarding a sword! - the C#-sword (the sharpest sword in the realm)\n"
                            "Press (high)-5 to give the cookie to the dragon and get the sword - or 1 to go back to the rooms with the doors\n";

string cookieRoomMessage = "\nSo you Call yourself the Duke of jobject oriented programming?\n"
                           "Heres a cookie you cant swallow!\n"
                           "Press (high)-5 to pick up the cookie with the git fork! - or 1 to go back to the rooms with the doors\n";


string forkRoomMessage = "\nYour in a room with a mysterious fork in it, and there is a sign reading\n"
                         "\"Behold the great git fork!! This fork will help you in your further endeavours\"\n"
                         "Press (high)-5 to pick it up! - or 1 to go back to the rooms with the doors\n";

string initialRoomMessage = "\nYou find yourself in a cave deep in the C of plusplus, and you see three doors\n"
                            "Press 1 2 or 3 to see what lies behind the doors\n";


string winningMessage     = "\nYOU WON THE JOB!"
                            "\n\nSo the queen of jobject oreoented programming you say. Maybe a little long? How about we call you Ms. Jobs?\n";



#endif //HELLO_WORLD_HIGHFIVEHIRING_H
