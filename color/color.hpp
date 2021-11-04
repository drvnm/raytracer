#pragma once

/* 
Pretty straight forward class, i just needed something that could represent a RGB specified color.
*/
class Color
{

public:
    int m_r;
    int m_g;
    int m_b;
    
    Color(int R, int G, int B); // Constructor
    Color(); // Default Constructor
};

