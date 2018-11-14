#ifndef VEC_H
#define VEC_H


class Vec
{
    public:
        int x_component;
        int y_component;
        int z_component;
        Vec(int x, int y, int z);
        Vec(int x, int y);
    static void vector_add(Vec vector1, Vec Vector2);
        virtual ~Vec();

    protected:

    private:
};

#endif // VEC_H
