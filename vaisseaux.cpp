#include "vaisseaux.hpp"

Vaisseaux::Vaisseaux(G_engine *t_gen,std::string t_name,b2World *t_world,float t_density,float t_friction,float t_restitution,float t_px,float t_py,float t_tx,float t_ty,float t_angledeg,
float t_puissance,float t_vitesserot) :
Corps(t_gen,t_name,t_world,t_density,t_friction,t_restitution,t_px,t_py,t_tx,t_ty,t_angledeg), m_puissance(t_puissance),m_vitesserot(t_vitesserot)
{
    p_dynamiquebody->SetAngularDamping(5);

    b2Vec2 mun;
	mun.x = 0;
    mun.y = 0;
    p_dynamiquebody->SetLinearVelocity(mun);
}

Vaisseaux::~Vaisseaux()
{
    //appeler destruteur
}

void Vaisseaux::applyForce(float cmb)
{
    b2Vec2 vec;
    vec.x = cos(p_dynamiquebody->GetAngle()-(M_PI/2)) * m_puissance * cmb;
    vec.y = sin(p_dynamiquebody->GetAngle()-(M_PI/2)) * m_puissance * cmb;
    p_dynamiquebody->ApplyLinearImpulse(vec,p_dynamiquebody->GetWorldCenter(),true);
}
void Vaisseaux::turnLeft()
{
    p_dynamiquebody->ApplyAngularImpulse(-m_vitesserot,true);
}
void Vaisseaux::turnRight()
{
    p_dynamiquebody->ApplyAngularImpulse(m_vitesserot,true);
}



