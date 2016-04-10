#include "corps.hpp"

Corps::Corps(G_engine *t_gen,std::string name,b2World *t_world,float t_density,float t_friction,float t_restitution,float t_px,float t_py,float t_tx,float t_ty,float t_angledeg) :
m_density(t_density),m_friction(t_friction),m_restitution(t_restitution),m_px(t_px),m_py(t_py),m_tx(t_tx),m_ty(t_ty),m_world(t_world),m_gen(t_gen),m_angledeg(t_angledeg)
{
    //crée et place le sprite dans le G_engine et recupére le pointer vers le son sprite
    p_sprite = m_gen->create_sprite(name,m_px,m_py,m_angledeg);
    p_sprite->setOrigin(50,50);
    //p_sprite->getTextureRect()

    //Crée l'objet Box2d Dynamique
    /*b2BodyDef DynamiqueBody;
	groundBodyDef2.position.Set(m_px/SCALE,m_py/SCALE);
	m_groundBody2 = m_world->CreateBody(&groundBodyDef2);
	b2PolygonShape groundBox2;
	groundBox2.SetAsBox((m_tx/2)/SCALE,(m_ty/2)/SCALE);
	m_groundBody2->CreateFixture(&groundBox2, 0.0f);*/

	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(m_px/SCALE,m_py/SCALE);
	bodyDef.allowSleep = false;
	m_dynamiquebody = m_world->CreateBody(&bodyDef);
	b2PolygonShape shape;
	shape.SetAsBox((m_tx/2)/SCALE,(m_ty/2)/SCALE);
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &shape;
	fixtureDef.density = m_density;
	fixtureDef.friction = m_friction;
	fixtureDef.restitution = m_restitution;
	m_dynamiquebody->CreateFixture(&fixtureDef);
}

Corps::~Corps()
{
    //detruire plein de trucs
}

void Corps::actualise()
{
    p_sprite->setPosition(m_dynamiquebody->GetPosition().x * SCALE,m_dynamiquebody->GetPosition().y * SCALE);
    p_sprite->setRotation(m_dynamiquebody->GetAngle() * 180/b2_pi);
}
