#include "planete.hpp"


Planete::Planete(G_engine *t_gen,std::string t_name,b2World *t_world,float t_density,float t_friction,float t_restitution,float t_px,float t_py,float t_tx,float t_ty,float t_radius,float t_angledeg) :
Corps(t_gen,t_name,t_world,t_density,t_friction,t_restitution,t_px,t_py,t_tx,t_ty,t_angledeg),m_radius(t_radius)
{



    p_sprite->setOrigin(m_radius,m_radius);

    b2Fixture *fixtureA = p_dynamiquebody->GetFixtureList();
    p_dynamiquebody->DestroyFixture(fixtureA);

    firstPini();

    b2CircleShape pla;
    pla.m_radius = m_radius / SCALE;
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &pla;
	fixtureDef.density = m_density;
	fixtureDef.friction = m_friction;
	fixtureDef.restitution = m_restitution;
	p_dynamiquebody->CreateFixture(&fixtureDef);
}

Planete::~Planete()
{
    //appeler destruteur
}

float Planete::get_radius_gravitation()
{
    return (m_radius / SCALE * gravfac);
}

void Planete::firstPini()
{
    if (name == SUN_TEXTURE)
	{
        gravfac = SUN_GRAVIVITYFAC;
        p_sprite->setScale(sf::Vector2f(SUN_SCALE,SUN_SCALE));
        m_radius = m_radius * SUN_SCALE;

	}

	else if (name == MOON_TEXTURE)
	{
        gravfac = MOON_GRAVIVITYFAC;
        p_sprite->setScale(sf::Vector2f(MOON_SCALE,MOON_SCALE));
        m_radius = m_radius * MOON_SCALE;

	}
}

void Planete::secondPini()
{
    if (name == SUN_TEXTURE)
	{
        b2Vec2 mun;
        mun.x = 0;
        mun.y = 0;
        //p_dynamiquebody->SetLinearVelocity(mun);
        p_dynamiquebody->ApplyForce(mun,p_dynamiquebody->GetWorldCenter(),true);

	}

	else if (name == MOON_TEXTURE)
	{
        b2Vec2 mun;
        mun.x = 0;
        mun.y = 0;//000000;
        //p_dynamiquebody->SetLinearVelocity(mun);
        p_dynamiquebody->ApplyForce(mun,p_dynamiquebody->GetWorldCenter(),true);

	}

}
