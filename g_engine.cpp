#include"g_engine.hpp"


G_engine::G_engine(sf::RenderWindow *t_app) :
p_app(t_app)
{
    view_factor = 1;

    p_view = new sf::View(sf::FloatRect(0, 0, 2400, 1600));
    p_view->zoom(20);
    p_app->setView(*p_view);

    font.loadFromFile("GROBOLD.ttf");
    text.setFont(font);
    text.setString("TRUC POUR FAIRE THECNIQUE");
    text.setCharacterSize(18);
    text.setColor(sf::Color::White);
}
G_engine::~G_engine()
{

    delete p_view;
    for (int i=0; i<de_sprite.size(); ++i)  //boucle pour afficher tout les sprite de la liste
     {
        delete de_texture.at(i);
        delete de_sprite.at(i);
     }
}
void G_engine::affiche_sprites()
{
    // Clear screen
    p_app->clear();
    for (int i=0; i<de_sprite.size(); ++i) //boucle pour suprimer tout les sprites en allocation dynamique
    {

        //de_sprite.at(i)->setTexture(*de_texture.at(i));
        p_app->draw(*de_sprite.at(i));

    }
    affiche_Texte();
    // Update the window
    p_app->display();

}
sf::Sprite* G_engine::create_sprite(std::string name,float t_px,float t_py,float t_angle)
{
    sf::Sprite *p_sprite;
    sf::Texture *p_texture;

    p_texture = new sf::Texture;            //allocation dynamique des Textures
    p_sprite = new sf::Sprite;              //allocation dynamique des sprites

    //Gestion du sprite
    //sf::Texture m_texture;
    p_texture->loadFromFile(name);          //chargement de la texture
    p_sprite->setTexture(*p_texture);       //appliquation de la texture au sprite
    sf::Vector2u vec = p_texture->getSize();//veteur pour connaitre taille de la texture
    p_sprite->setOrigin(vec.x/2,vec.y/2);   //orignie au milieu du sprite
    p_sprite->setPosition(t_px,t_py);       //position du sprite
    p_sprite->setRotation(t_angle);         //rotation du sprite

    de_texture.push_back(p_texture);        //ajout de la texeture deque (liste)  //A revoir pour aptimiser (utiliser plusieur fois
    de_sprite.push_back(p_sprite);          //ajout du sprite deque (liste)
    return p_sprite;                        //return pointer pour que la classe que corps soit lier avec ce sprite

}

void G_engine::Changeview(float factor,sf::Vector2f t_vec)
{
    g_vec = t_vec;
    p_view->setCenter(g_vec);
    view_factor = factor;
    p_view->zoom(view_factor);
    p_app->setView(*p_view);

    sf::Vector2f a_vec;
    a_vec.x = -200;
    a_vec.y = -200;
    a_vec =  a_vec + g_vec;
    text.setScale((p_view->getSize().x)/1200,(p_view->getSize().y)/800);
    text.setPosition(a_vec);

}

void G_engine::affiche_Texte()
{
    //affichage FPS
    sf::Time FPS = clock.restart();
    float time = 1 / FPS.asSeconds();
    time = round(time);
    std::ostringstream oss;
    oss << time;
    std::string str_FPS = oss.str();

    //position
    float posx = g_vec.x;
    float posy = g_vec.y;
    posx = round(posx);
    posy = round(posy);
    std::ostringstream px;
    px << posx;
    std::string str_POSX = px.str();
    std::ostringstream py;
    py << posy;
    std::string str_POSY = py.str();


    std::string str;
    std::string str_Tfps("FPS : ");
    std::string str_Tpx("\n PX : ");
    std::string str_Tpy("\n PY : ");
    str = str_Tfps + str_FPS + str_Tpx + str_POSX + str_Tpy + str_POSY;
    text.setString(str);

    p_app->draw(text);

}

