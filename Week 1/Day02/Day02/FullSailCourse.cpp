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

void FullSailCourse::CalculateStats(const std::vector<float>& course, float& min, float& max) const
{
    min = max = 0;
    if (course.size() > 0)
    {
        min = max = course[0];
        for(int i=1;i<course.size();i++)
        {
            max = std::max(course[i], max);
            min = std::min(course[i], min);
            //if (course[i] > max) max = course[i];
            //if (course[i] < min) min = course[i];
        }
    }
}
