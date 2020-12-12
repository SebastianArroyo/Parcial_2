#ifndef CANION_1_H
#define CANION_1_H
#define G 9.8

class canion_1
{
private:
    float Xo;
    float Yo;
    float Vo;
    float Vox;
    float Voy;
    float angulo;
    float rad;

public:

    canion_1(float Xo_,float Yo_,float rad_);

    float getXo() const;
    float getYo() const;
    float getRad() const;

};

#endif // CANION_1_H
