#pragma once
#include <string>
#include <vector>

class FullSailCourse
{
public:
	void PrintGrades(const std::string& className, const std::vector<float>& course) const;

	void SetName(const std::string& name) { name_ = name; }
	const std::string& GetName() const { return name_; }
	
private:
	std::string name_;
};

