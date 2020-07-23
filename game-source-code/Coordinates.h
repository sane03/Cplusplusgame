#ifndef COORDINATES_H
#define COORDINATES_H

class Coordinates
{
public:
    float x = 0;
    float y = 0;

    bool operator==(const Coordinates& rhs)
    {
        return (x == rhs.x && y == rhs.y);
    }
    bool operator!=(const Coordinates& rhs)
    {
        return (x != rhs.x && y != rhs.y);
    }
    bool operator-(const Coordinates& rhs)
    {
        return ((x - rhs.x) && (y - rhs.y));
    }

    bool operator>(const Coordinates& rhs)
    {
        return (x > rhs.x && y > rhs.y);
    }

    bool operator<(const Coordinates& rhs)
    {
        return (x < rhs.x && y < rhs.y);
    }

    void reset()
    {
        x = 0;
        y = 0;
    }
    void set(float x, float y)
    {
        x = x;
        y = y;
    }
};

#endif
