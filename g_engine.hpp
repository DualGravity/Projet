#ifndef G_ENGINE_HPP_INCLUDED
#define G_ENGINE_HPP_INCLUDED

#include "Initialisation.hpp"

class G_engine
{
	public:
	G_engine(sf::RenderWindow *t_app);
	~G_engine();
	void affiche_sprites();
	sf::Sprite* create_sprite(std::string name,float t_px,float t_py,float t_angle);
	void Changeview(float factor,sf::Vector2f t_vec);

	void affiche_Texte();

	protected:
	sf::RenderWindow *p_app;
	sf::Clock clock;
	sf::Text text;
	sf::Font font;
	sf::Vector2f g_vec;
	std::deque <sf::Texture*> de_texture;
	std::deque <sf::Sprite*> de_sprite;
	sf::View *p_view;
	float view_factor;



};

#endif // G_ENGINE_HPP_INCLUDED


