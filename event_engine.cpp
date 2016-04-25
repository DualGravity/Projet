#include"event_engine.hpp"

using namespace sf;

Event_engine::Event_engine(sf::RenderWindow *t_app,Worldengine *t_world) :
p_app(t_app),p_world(t_world)
{
}
Event_engine::~Event_engine()
{
}

void Event_engine::step()
{
        // Process events
        sf::Event event;
        while (p_app->pollEvent(event))
        {
            // Close window : exit
            if (event.type == Event::Closed)
                p_app->close();
        }


        //Gstion du zoom
        if (sf::Keyboard::isKeyPressed(Keyboard::T))
            p_world->changeview(0.96f);

        if (sf::Keyboard::isKeyPressed(Keyboard::Y))
            p_world->changeview(1.04f);

        //Gstion du DEPLACEMENT
        if (sf::Keyboard::isKeyPressed(Keyboard::D))
            p_world->controlV1(6);

        else if (sf::Keyboard::isKeyPressed(Keyboard::Q))
            p_world->controlV1(4);

        else if (sf::Keyboard::isKeyPressed(Keyboard::Z))
            p_world->controlV1(8);

        else if (sf::Keyboard::isKeyPressed(Keyboard::S))
            p_world->controlV1(5);


        //Gstion du DEPLACEMENT
        if (sf::Keyboard::isKeyPressed(Keyboard::Right))
            p_world->controlV2(6);

        else if (sf::Keyboard::isKeyPressed(Keyboard::Left))
            p_world->controlV2(4);

        else if (sf::Keyboard::isKeyPressed(Keyboard::Up))
            p_world->controlV2(8);

        else if (sf::Keyboard::isKeyPressed(Keyboard::Down))
            p_world->controlV2(5);


}
