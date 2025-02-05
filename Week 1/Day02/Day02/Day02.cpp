#include <iostream>
#include <string>
#include <vector>
#include <Console.h>

bool postFix(std::string& hero)
{
    srand((unsigned int)time(NULL));
    int postFixNumber = rand() % 1000;
    hero = hero + "-" + std::to_string(postFixNumber);
    return postFixNumber % 2 == 0;
}

float average(const std::vector<int>& scores)
{
    //scores.push_back(5); //not allowed because it is marked as const
    float sum = 0;
    for (auto score : scores)
        sum += score;

    return sum / scores.size();
}

void print(const std::vector<int>& scores)
{
    std::cout << "----SCORES----\n";
    int index = 1;
    for (int score : scores)
        std::cout << index++ << ". " << score << "\n";
}

void printInfo(const std::vector<int>& scores)
{
    std::cout << "size: " << scores.size() << "\tcapacity: " << scores.capacity() << "\n";
}


int Sum(int n1, int n2)//pass by value
{
    return n1 + n2;
}

//when to use pass by reference?
//  - when passing objects (not simple data types)
//      for example: classes
//pass by reference prevents a copy
int Sum(std::vector<int>& numbers)
{
    int sum = 0;
    for (auto& number : numbers) 
        sum += number;
    return sum;
}

void FillGrades(std::vector<float>& course)
{
    for (size_t i = 0; i < 10; i++)
    {
        //rand() - returns an int from 0-32767
        //use % to limit ANY number to a range
        //  it returns the REMAINDER after dividing by the number
        course.push_back( rand() % 10001 / 100.0f );
    }
}

int main()
{
    int num1 = 10, num2 = 20;
    int sum = Sum(num1, num2);
    std::vector<int> nums{ 1,2,3,4,5,6,7,8 };
    sum = Sum(nums);
    std::vector<int> nums2{ 11,12,13,14,15,16,17,18 };
    sum = Sum(nums2);

    //number1 is a new name for num1
    int& number1 = num1;
    std::cout << num1 << "\n";
    number1 = 1;
    std::cout << num1 << "\n";


    /*
        ╔══════════════════════════════╗
        ║Parameters: Pass by Reference.║
        ╚══════════════════════════════╝
        Sends the variable itself to the method. The method parameter gives the variable a NEW name (i.e. an alias)

        NOTE: if the method assigns a new value to the parameter, the variable used when calling the method will change too.
            This is because the parameter is actually just a new name for the other variable.
    */
    std::string spider = "Spiderman";
    bool isEven = postFix(spider);
    std::string evenResult = (isEven) ? "TRUE" : "FALSE";
    std::cout << spider << "\n" << "Is Even postfix? " << evenResult << "\n";


    /*
        CHALLENGE 1:

            Write a method to fill the vector of floats with grades.
            1) pass it in by reference
            2) add 10 grades to the vector
            3) after calling the method, print the grades in main

    */

    std::vector<float> grades;
    FillGrades(grades);
    Console::WriteLine("\nPG2 2502", ConsoleColor::Green);
    for (int i = 0; i < grades.size(); i++)
    {
        Console::WriteLine(grades[i]);
    }
    std::cout << "\n\n";



    /*
        ╔══════════════════╗
        ║ const parameters ║
        ╚══════════════════╝
        const is short for constant. It prevents the variable from being changed in the method.

        This is the way you pass by reference and prevent the method from changing the variable.
    */
    std::vector<int> highScores;
    for (int i = 0; i < 10; ++i)
    {
        highScores.push_back(rand() % 5000);
        printInfo(highScores);//size: ?  capacity: ?
    }
    float avg = average(highScores);



    /*
        CHALLENGE 2:

            Write a method to calculate the stats on a vector of grades
            1) create a method to calculate the min, max. 
                pass the grades vector as a const reference. Use ref parameters for min and max.
            2) call the method in main and print out the min, max.

    */





    /*
        ╔═══════════╗
        ║ vector<T> ║
        ╚═══════════╝

        [  Removing from a vector  ]

        clear() - removes all elements from the vector
        erase(position) - removes the element at the position
        erase(starting position, ending position) - removes a range of elements. the end position is not erased.

    */
    print(highScores);

    //erase all scores < 2500

    print(highScores);



    /*
        CHALLENGE 3:

            Using the vector of grades you created.
            Remove all the failing grades (grades < 59.5).
            Print the grades.
    */





    /*
        ╔═══════════╗
        ║ vector<T> ║
        ╚═══════════╝

        
        size(): # of items that have been ADDED
        capacity(): length of the internal array
        reserve(n): presizes the internal array
    */
    std::vector<int> scores;
    scores.reserve(10); //makes the internal array to hold 10 items.

    printInfo(scores);
}