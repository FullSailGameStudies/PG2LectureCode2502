#include "FullSailCourse.h"
#include <Console.h>

//const methods cannot change data of the class
void FullSailCourse::PrintGrades(const std::string& className, const std::vector<float>& course) const
{
    //name_ = className;
    //SetName(className);//cannot change class variables
    std::string name = className;//can change local variables
    Console::WriteLine("\n" + className, ConsoleColor::Green);
    for (int i = 0; i < course.size(); i++)
    {
        Console::WriteLine(course[i]);
    }
    std::cout << "\n\n";
}
