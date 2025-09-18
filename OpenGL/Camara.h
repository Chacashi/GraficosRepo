#pragma once
class Camara
{
public:
    virtual void ApplyView() = 0;             
    virtual void Keyboard(unsigned char key) = 0; 
    virtual ~Camara() = default;
};

