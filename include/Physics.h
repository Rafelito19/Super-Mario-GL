#ifndef PHYSICS_H
#define PHYSICS_H


class Physics
{

const int pixels_per_meter=64;
const int gravity= -9.8;
int velocity_X=0;
int velocity_y=0;

    public:
        Physics();
        virtual ~Physics();

    protected:

    private:
};

#endif // PHYSICS_H
