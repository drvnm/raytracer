#pragma once

class Color
{
    int m_R;
    int m_G;
    int m_B;

public:
    Color(int R, int G, int B)
    {
        m_R = R;
        m_G = G;
        m_B = B;
    }

    Color();
    ~Color();
};