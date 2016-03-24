#include "vaisseaux.hpp"
#include <cmath>
Vaisseaux::Vaisseaux(float px, float py, float vx,float vy, float ax,float ay, float angle) : px(px), py(py), angle(angle),vx(vx),vy(vy),ax(ax),ay(ay) {}

void Vaisseaux::step(int dt)
{

    vx += ax * dt;
    vy += ay * dt;
    px += vx * dt;
    py += vy * dt;

    ax = 0;
    ay = 0;


}
void Vaisseaux::applyForce(float fx, float fy)
{
    /*ax += fx;
    ay += fy;*/
    float speed;
    speed = fx;

    ax += cos((angle + 90) * M_PI / 180.0) * speed;
    ay += sin((angle + 90) * M_PI / 180.0) * speed;
}
float Vaisseaux::getpx() const
{

    return px;

}
void Vaisseaux::setpx(float tpx)
{

    px = tpx;

}
float Vaisseaux::getpy() const
{
    return py;
}
void Vaisseaux::setpy(float tpy)
{
    py = tpy;
}
float Vaisseaux::getvx() const
{

    return vx;

}
float Vaisseaux::getvy() const
{

    return vy;

}
float Vaisseaux::getAngle() const
{

    return angle;

}
void Vaisseaux::turnLeft()
{

    angle -= 2.2f;

}
void Vaisseaux::turnRight()
{

    angle += 2.2f;

}

