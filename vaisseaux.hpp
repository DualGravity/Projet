#ifndef VAISSEAUX_HPP_INCLUDED
#define VAISSEAUX_HPP_INCLUDED
#include "Initialisation.hpp"

class Vaisseaux
{
	public:
	Vaisseaux(float px, float py, float vx,float vy, float ax,float ay, float angle);

	float getpx() const;
	float getpy() const;
	float getvx() const;
	float getvy() const;
	float getax() const;
	float getay() const;
	float getAngle() const;

	void setpx(float tpx);
	void setpy(float tpy);

	void turnLeft();
	void turnRight();
	void applyForce(float fx, float fy);
    void step(int pdt);

	private:
        float px, py;
        float vx, vy;
        float ax, ay;
        float angle;
};

#endif // VAISSEAUX_HPP_INCLUDED
