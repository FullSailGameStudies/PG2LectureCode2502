﻿// Day05.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "Console.h"
#include "Input.h"
#include <iomanip>

enum class Weapon
{
    Sword, Axe, Spear, Mace
};

/// <summary>
/// Searches a vector for a number using the linear search algorithm.
/// </summary>
/// <param name="nums">The vector to search in.</param>
/// <param name="searchNumber">The number to search for.</param>
/// <returns>-1 if not found. the index of the number if found.</returns>
int LinearSearch(const std::vector<int>& nums, int searchNumber)
{
    for (int i = 0; i < nums.size(); i++)
    {
        if (searchNumber == nums[i])
        {
            return i;
        }
    }
    return -1;//NOT FOUND
}

void PrintGrades(const std::map<std::string, double>& grades)
{
    Console::WriteLine("\n\nPG2 2502", ConsoleColor::Green);
    for (auto& [name,grade] : grades)
    {
        std::cout << std::setw(7) << std::right;
        //ternary operator. shorthand for if-else block
        // (condition) ? trueblock : falseblock;
        ConsoleColor color = 
            (grade < 59.5) ? ConsoleColor::Red :
            (grade < 69.5) ? ConsoleColor::Yellow :
            (grade < 79.5) ? ConsoleColor::Blue :
            (grade < 89.5) ? ConsoleColor::Cyan :
            ConsoleColor::Green;
        Console::Write(grade, color);
        std::cout << " " << name << "\n";
    }
    std::cout << "\n\n";
}


int main()
{
    /*
        ╔═════════╗
        ║Searching║
        ╚═════════╝

        There are 2 ways to search a vector: linear search or binary search

        CHALLENGE:

            write a method to linear search the numbers list.
                The method should take 2 parameters: vector of ints to search, int to search for.
                The method should return -1 if NOT found or the index if found.

            The algorithm:
                1) start at the beginning of the vector
                2) compare each item in the vector to the search item
                3) if found, return the index
                4) if reach the end of the vector, return -1 which means not found

    */
    std::vector<int> numbers = { 0,1,2,3,4,5,6 };
    int searchNumber = -1;
    int index = LinearSearch(numbers, searchNumber);
    if (index < 0) std::cout << "\nNOT FOUND!\n";
    else std::cout << "found at index " << index << "\n";



    /*
        ╔═══════════════════╗
        ║ map<TKey, TValue> ║
        ╚═══════════════════╝

        [  Creating a map  ]

        map<TKey, TValue>  - an associative collection.
            TKey is a placeholder for the type of the keys.
            TValue is a placeholder for the type of the values.

        When you want to create a map variable,
            1) replace TKey with whatever type of data you want to use for the keys
            2) replace TValue with the type you want to use for the values


        [  Adding items to a map  ]

        There are 2 ways to add items to a map:
        1) using the insert method.
        2) using [key] = value
    */
    std::map<Weapon, int> dorasBackpack;//will store the counts of each kind of weapon

    //returns an iterator and a bool. 
    //if the key is already in the map, it will NOT insert it -- the bool will be false.
    auto inserted = dorasBackpack.insert(std::make_pair(Weapon::Sword, 5));
    if (inserted.second == false) //meaning not inserted
        std::cout << "The key was already in the map. It was not inserted.\n";
    else
        std::cout << "The key was inserted in the map.\n";

    dorasBackpack[Weapon::Axe] = 3;
    dorasBackpack[Weapon::Axe] = 7;//simply overwrites the value if the key is already in the map



    std::map<std::string, float> menu;
    //2 ways to add to a map:
    //1) easy way. map[key] = value;
    //2) hard way. map.insert(keyvaluepair);

    menu["French Fries"] = 1.50f;
    menu["Milkshake"] = 8.99f;
    menu["Milkshake"] = 6.99f;//overwrites

    std::pair<std::string, float> menuPair = 
        std::make_pair("Cheese burger", 5.99f);
    auto result = menu.insert(menuPair);
    menuPair.second = 4.99;
    result = menu.insert(menuPair);//will NOT overwrite
    if (result.second == false)
        std::cout << "the item is already on the menu.\n";

    std::cout << "\n\nPG2 Cafe\n";
    for (auto& [menuItem,menuPrice] : menu)
    {
        std::cout << std::setw(15) << std::left;
        std::cout << menuItem;
        std::cout << std::setw(7) << std::right;
        std::cout << menuPrice << "\n";
    }
    std::cout << "\n\n";

    auto foundMenuItem = menu.find("Dino Nuggies");
    if (foundMenuItem == menu.end()) //not found
        std::cout << "Dino Nuggies is not on the menu. WHY?!?!\n";

    foundMenuItem = menu.find("Cheese burger");
    if (foundMenuItem != menu.end())
    {
        float oldPrice = foundMenuItem->second;
        //2 ways to update a value
        //1) map[key] = newvalue
        //2) iterator->second = newvalue;
        foundMenuItem->second *= 1.10f;
        std::cout << "Cheese burger used to costs " << oldPrice << "\n";
        std::cout << "Now it costs " << foundMenuItem->second << "!! Thanks Putin!\n\n";

        //foundMenuItem->second << "\n";
    }
    /*
        CHALLENGE:

            Create a map that stores names (string) and grades. 
            Call the variable grades.
            Add students and grades to your map.

    */
    std::map<std::string, double> grades;

    srand(time(NULL));
    std::vector<std::string> students{
"Gabriel","Gabe","Alexavier","Kennedy","Ariana","Kaleb","Abigail","Christopher","Diego",
"Steven","Ethan","Jose","Kameti","Emmanuel","Dominic","Reid","Ronnie","Ruby Rose","Philicity",
"Marcos","Giezi","Daniel","Noah"
    };
    for (auto& student : students)
    {
        grades[student] = rand() % 10001 / 100.0;
    }

    PrintGrades(grades);






    /*
        ╔═══════════════════╗
        ║ map<TKey, TValue> ║
        ╚═══════════════════╝

        [  Looping over a map  ]

        You should use a ranged-based for loop when needing to loop over the entire map.

    */
    for (auto const& [key, val] : dorasBackpack) //requires C++ 20
    {
        switch (key)
        {
        case Weapon::Sword:
            std::cout << "Sword: ";
            break;
        case Weapon::Axe:
            std::cout << "Axe: ";
            break;
        case Weapon::Spear:
            std::cout << "Spear: ";
            break;
        case Weapon::Mace:
            std::cout << "Mace: ";
            break;
        default:
            break;
        }
        std::cout << val << "\n";
    }


    /*
        CHALLENGE:

            Loop over your grades map and print each student name and grade.

    */



    /*
        ╔═══════════════════╗
        ║ map<TKey, TValue> ║
        ╚═══════════════════╝

        [  Checking for a key in a map  ]

        use the find method to check if the key is in the map

        will return map.end() if NOT found.

    */
    std::map<Weapon, int>::iterator foundIter = dorasBackpack.find(Weapon::Mace);
    if (foundIter == dorasBackpack.end()) //meaning it was NOT found
    {
        std::cout << "Dora did not find any maces.\n";
    }
    else
    {
        //can safely grab the value for the key
        std::cout << "Dora found " << foundIter->second << " Maces\n";
    }







    /*
        ╔═══════════════════╗
        ║ map<TKey, TValue> ║
        ╚═══════════════════╝

        [  Updating a value for a key in a map  ]

        To update an exisiting value in the map, use the [ ]


    */
    dorasBackpack[Weapon::Axe] = 1;//updates the count for the axe



    /*
        CHALLENGE:

            look for a specific student in the map.
            If the student is found, print out the student's grade
            else print out a message that the student was not found
   
        CHALLENGE:

            Pick any student and curve the grade (add 5) that is stored in the grades map

    */
    do
    {
        std::string studentName = Input::GetString("Name of student to curve: ");
        if (studentName.empty()) break;

        studentName[0] = std::toupper(studentName[0]);
        auto foundStudent = grades.find(studentName);
        if (foundStudent != grades.end())
        {
            std::cout << studentName << " had a grade of " << foundStudent->second;
            foundStudent->second = std::min(100.0, foundStudent->second + 5);
            std::cout << ". Now the grade is " << foundStudent->second << "!\n";
        }
        else
            std::cout << studentName << " is not in PG2 this month.\n";

        PrintGrades(grades);

    } while (true);

    do
    {
        std::string studentName = Input::GetString("Name of student to drop: ");
        if (studentName.empty()) break;

        studentName[0] = std::toupper(studentName[0]);
        auto foundStudent = grades.find(studentName);
        if (foundStudent != grades.end())
        {
            std::cout << studentName << " had a grade of " << foundStudent->second;
            grades.erase(foundStudent);
            std::cout << ". The student has been dropped.\n";
        }
        else
            std::cout << studentName << " is not in PG2 this month.\n";

        PrintGrades(grades);

    } while (true);
}