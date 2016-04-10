#include "Initialisation.hpp"

#include "vaisseaux.hpp"
#include "corps.hpp"
#include "g_engine.hpp"
#include "corpsfix.hpp"


using namespace std;
using namespace sf;

int main()
{
    // Create the main window
    RenderWindow app(VideoMode(1200, 800), "Duel Gravity");
    app.setFramerateLimit(60);

    //Cretation class Gengine fen1 puis ajout de sprite
    G_engine fen1(&app);

    //Clock1
    sf::Clock clock1;

    //Reine des Neiges
    sf::Music music;
    music.openFromFile("Neige.wav");

    //World proprety
    b2Vec2 gravity(0.0f,9.8f);
    b2World world(gravity);

    //Obsttacle gerer par la classe corps box2d + sfml

	Corpsfix truc(&fen1,"cb.bmp",&world,600,500,100,100,0);
	Corpsfix truc1(&fen1,"cb.bmp",&world,800,300,100,100,0);
	Corpsfix truc2(&fen1,"cb.bmp",&world,1000,100,100,100,0);


	Corpsfix truc3(&fen1,"cb.bmp",&world,50,800,10000,100,0);
	Corpsfix truc4(&fen1,"cb.bmp",&world,150,800,100,100,0);
	Corpsfix truc5(&fen1,"cb.bmp",&world,250,800,100,100,0);
	Corpsfix truc6(&fen1,"cb.bmp",&world,350,800,100,100,0);
	Corpsfix truc7(&fen1,"cb.bmp",&world,450,800,100,100,0);
	Corpsfix truc8(&fen1,"cb.bmp",&world,550,800,100,100,0);
	Corpsfix truc9(&fen1,"cb.bmp",&world,650,800,100,100,0);
	Corpsfix truc10(&fen1,"cb.bmp",&world,750,800,100,100,0);
	Corpsfix truc11(&fen1,"cb.bmp",&world,850,800,100,100,0);
	Corpsfix truc12(&fen1,"cb.bmp",&world,950,800,100,100,0);
	Corpsfix truc13(&fen1,"cb.bmp",&world,1050,800,100,100,0);
	Corpsfix truc14(&fen1,"cb.bmp",&world,1150,800,100,100,0);



    //DYNAMIQUE
    Corps trucDyn(&fen1,"cb.bmp",&world,1,0.3f,0.9f,200,600,100,100,0);
    Corps trucDyn1(&fen1,"cb.bmp",&world,1,0.3f,0.9f,500,600,100,100,0);
    Corps trucDyn2(&fen1,"cb.bmp",&world,1,0.3f,0.9f,800,600,100,100,0);

    RectangleShape Shape(sf::Vector2f(50.0f,50.0f));
    Shape.setOrigin(25.0f,25.0f);
    Shape.setFillColor(sf::Color(1, 120, 200));

    b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(400.0f/SCALE,50.0f/SCALE);
	bodyDef.allowSleep = false;
	b2Body* body = world.CreateBody(&bodyDef);
	b2PolygonShape shape;
	shape.SetAsBox((50.0f/2)/SCALE,(50.0f/2)/SCALE);
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &shape;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.3f;
	fixtureDef.restitution = 0.5f;
	body->CreateFixture(&fixtureDef);

    //truc pour simulation box2d
	int32 velocityIterations = 10;
	int32 positionIterations = 10;

    bool yh;
    yh = true;

    Vaisseaux Vaisseaux1(600,400,0,0,0,0,0);

    float dt;//delta de temps

    // Start the game loop
    while (app.isOpen())
    {
        // Process events
        sf::Event event;
        while (app.pollEvent(event))
        {
            // Close window : exit
            if (event.type == Event::Closed)
                app.close();

            if (sf::Keyboard::isKeyPressed(Keyboard::R))
                music.play();
        }

        if (sf::Keyboard::isKeyPressed(Keyboard::Right))
        {
            Vaisseaux1.turnRight();
            body->ApplyLinearImpulse(b2Vec2(1,0), body->GetWorldCenter(),yh);
        }
        else if (sf::Keyboard::isKeyPressed(Keyboard::Left))
        {
            Vaisseaux1.turnLeft();
            body->ApplyLinearImpulse(b2Vec2(-1,0), body->GetWorldCenter(),yh);
        }
        else if (sf::Keyboard::isKeyPressed(Keyboard::Up))
        {
            Vaisseaux1.applyForce(0.0005,0);
            body->ApplyLinearImpulse(b2Vec2(0,-1), body->GetWorldCenter(),yh);
        }
        else if (sf::Keyboard::isKeyPressed(Keyboard::Down))
        {
           body->ApplyLinearImpulse(b2Vec2(0,1), body->GetWorldCenter(),yh);

        }
        else
        {
        }

        //gestion du dt
        sf::Time elapsed1 = clock1.restart();//redemmare et prend la valeur du temp ecoulée
        dt = elapsed1.asSeconds();           //temps en seconde

        Vaisseaux1.step(dt);
        world.Step(dt, velocityIterations, positionIterations);
        b2Vec2 position = body->GetPosition();
		float32 angle = body->GetAngle();

        Shape.setPosition(body->GetPosition().x * SCALE,body->GetPosition().y * SCALE);
        Shape.setRotation(angle * 180/b2_pi);
        trucDyn.actualise();
        trucDyn1.actualise();
        trucDyn2.actualise();


        // Clear screen
        app.clear();

        // Draw the sprite
        app.draw(Shape);
        fen1.affiche_sprites();

        // Update the window
        app.display();
    }

    return EXIT_SUCCESS;
}


