// Day11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Car.h"
#include <vector>
#include <fstream>
#include "Console.h"
#include "Input.h"

int main()
{
    std::cout << "Gone in 60 Seconds!\n";//https://carbuzz.com/features/beyond-eleanor-gone-in-60-seconds-car-names#:~:text=The%20Complete%20List%20Of%20Gone%20In%2060%20Seconds,8%201961%20Porsche%20Speedster%20-%20%22Natalie%22%20More%20items

    Car myCar(2025, "Tesla", "Cybertruck");
    //1) open the file
    std::string path = "garage.csv";
    std::ofstream outFile(path);
    char delimiter = '$';
    if (outFile.is_open())
    {
        //2) write to the file
        myCar.SerializeCSV(outFile, delimiter);
    }
    else
        std::cout << path << " could not be opened.\n";

    //3) close the file
    outFile.close();


    std::vector<Car> garage;
    garage.push_back(Car(1967, "Ford", "Shelby Mustang GT500"));
    garage.push_back(Car(1956, "Ford", "T Bird"));
    garage.push_back(Car(1961, "Porsche", "Speedster"));
    garage.push_back(Car(1965, "Pontiac", "GTO"));
    garage.push_back(Car(1969, "Plymouth", "Hemi Cuda"));

    path = "jaysGarage.csv";
    std::ofstream jaysFile(path);
    if (jaysFile.is_open())
    {
        int index = 0;
        for (auto& car : garage)
        {
            car.SerializeCSV(jaysFile, delimiter);
            if(index++ != garage.size()-1)
                jaysFile << "\n";
        }
    }
    else
        std::cout << path << " could not be opened.\n";
    jaysFile.close();

    int index = 0;
    for (auto& car : garage)
    {
        car.SerializeCSV(std::cout, '\t');
        if (index++ != garage.size() - 1)
            std::cout << "\n";
    }

    /*
        ╔═════════════╗
        ║ Serializing ║
        ╚═════════════╝

        Saving the state (data) of objects

        Lecture Code: serialize the vector of Cars to a file.
            Data Format:
                separates cars. EX: car1|car2|car3
                separates data inside a car. EX: 1967;Ford;Shelby Mustang GT500

    */



    /*
        ╔═══════════════╗
        ║ Deserializing ║
        ╚═══════════════╝

        Recreating the objects from the saved state (data) of objects

        Lecture Code:
            Open the file
            Read in each line
            split each line to get each car
            split each car to get the car details

    */

    Car oldRide("1908$Ford$ModelA", delimiter);
    path = "garage.csv";
    std::ifstream inFile(path);
    if (inFile.is_open())
    {
        std::string line;
        std::getline(inFile, line);
        Car todaysRide(line, delimiter);
        std::cout << "\n\n" << todaysRide.vehicleInformation() << "\n";
    }
    else
        std::cout << path << " could not be opened.\n";
    inFile.close();

    path = "jaysGarage.csv";
    std::ifstream jaysInFile(path);
    std::vector<Car> newGarage;
    if (jaysInFile.is_open())
    {
        while (!jaysInFile.eof())
        {
            std::string carLine;
            //read a line
            std::getline(jaysInFile, carLine);

            //create a car using the line
            Car nextCar(carLine, delimiter);

            //store the car in the vector
            newGarage.push_back(nextCar);
        }
    }
    else
        std::cout << path << " could not be opened.\n";
    jaysInFile.close();

    std::cout << "\n\nJay's Garage\n";
    for (auto& car : newGarage)
    {
        std::cout << car.vehicleInformation() << '\n';
    }
}