#pragma once
#include<Windows.h>

class Consol_parameter
{
public:
    static void SetColor(int text, int background);
  
    static void SetPosition(int x, int y);
    
        
private:
    static HANDLE hStdOut;
};

