#pragma once
#include "Tool.h"
#include <string>

class Person :
    public Tool
{
private:
    std::string Name;


public:
    std::string GetName();
    void SetName(std::string newName);




};

