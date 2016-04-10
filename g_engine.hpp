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
	sf::Sprite get_sprite();


	private:
	sf::RenderWindow *p_app;
	sf::Texture m_texture;
	std::deque <sf::Sprite*> de_sprite;

	std::string name;
	float m_px, m_py, m_angle;



};

#endif // G_ENGINE_HPP_INCLUDED
