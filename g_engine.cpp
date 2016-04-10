#include"g_engine.hpp"


G_engine::G_engine(sf::RenderWindow *t_app) :
p_app(t_app)
{
}
G_engine::~G_engine()
{
    for (int i=0; i<de_sprite.size(); ++i)
     {
        delete de_sprite.at(i);
     }
}
void G_engine::affiche_sprites()
{
     for (int i=0; i<de_sprite.size(); ++i)
     {
        p_app->draw(*de_sprite.at(i));
     }

}

sf::Sprite* G_engine::create_sprite(std::string name,float t_px,float t_py,float t_angle)
{
    sf::Sprite *p_sprite; //pointer vers sprite

    m_px = t_px;
    m_py = t_py;
    m_angle = t_angle;

    p_sprite = new sf::Sprite;//allocation dynamique

    //Gestion du sprite
    m_texture.loadFromFile(name);          //chargement de la texture
    p_sprite->setTexture(m_texture);       //appliquation de la texture au sprite
    sf::Vector2u vec = m_texture.getSize();//veteur pour connaitre taille de la texture
    p_sprite->setOrigin(vec.x/2,vec.y/2);  //orignie au milieu du sprite
    p_sprite->setPosition(m_px,m_py);      //position du sprite
    p_sprite->setRotation(m_angle);        //rotation du sprite

    de_sprite.push_back(p_sprite);         //ajout du sprite deque (liste)
    return p_sprite;                       //return pointer pour que la classe que corps soit lier avec ce sprite

}

sf::Sprite G_engine::get_sprite()
{
    //return *p_sprite;
}

