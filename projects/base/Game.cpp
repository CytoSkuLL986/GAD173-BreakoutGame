//This Script will be split into a more organized collection of scripts

#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

//defining the parameters for the new Window, ball, and paddle to be created for the game.
constexpr int windowWidth{ 800 }, windowHeight{ 600 };

constexpr float ballRadius{ 10.f }, ballVelocity{ 8.f };
constexpr float paddleWidth{ 60.f }, paddleHeight{ 20.f }, paddleVelocity{ 6.f };

//Structure containing information used for the creation of the ball object in the game.
struct Ball
{
    CircleShape shape;
    Vector2f velocity{ -ballVelocity, -ballVelocity };

    Ball(float mX, float mY)
    {
        shape.setPosition(mX, mY);
        shape.setRadius(ballRadius);
        shape.setFillColor(Color::Red);
        shape.setOrigin(ballRadius, ballRadius);
    }

    //Update function for the ball object, which moves the created 'ball' and has parameters in place to stop the ball
    //from getting outside the view of the created game window. Here we are also helping the ball 'understand' which
    //of it's sides has 'collided' with the window edges, so that the ball can travel in the opposite direction
    //to the collision.
    void update()
    {
        shape.move(velocity);

        if (left() < 0)
            velocity.x = ballVelocity;
        else if (right() > windowWidth)
            velocity.x = -ballVelocity;

        if (top() < 0)
            velocity.y = ballVelocity;
        else if (bottom() > windowHeight)
            velocity.y = -ballVelocity;
    }

    //definitions for each of the functions used within the above Update function. These are useful because they allow
    //us to define more accurate 'edges' for the ball object. These have to be done manually since the created object
    //itself does not have a collider of a circular shape, rather, the ball's centerpoint(Origin) would defaultly be
    //used for the excecution of the above function. Leaving this as is would create the effect of the ball partially 
    //leaving the screen (game window) before continuing to bounce away from the 'collision point' (because the Origin
    //is at the center of the circular ball 'image').
    float x() { return shape.getPosition().x; }
    float y() { return shape.getPosition().y; }
    float left() { return x() - shape.getRadius(); }
    float right() { return x() + shape.getRadius(); }
    float top() { return y() - shape.getRadius(); }
    float bottom() { return y() + shape.getRadius(); }
};

//Information for the paddle object to be created.
struct Paddle
{

    RectangleShape shape;
    Vector2f velocity;


    Paddle(float mX, float mY)
    {
        shape.setPosition(mX, mY);
        shape.setSize({ paddleWidth, paddleHeight });
        shape.setFillColor(Color::Red);
        shape.setOrigin(paddleWidth / 2.f, paddleHeight / 2.f);
    }

    //Update function for the paddle that allows us to move the paddle with the defined keys (and stopping when keys
    //are no longer pressed).
    void update()
    {
        shape.move(velocity);

        if (Keyboard::isKeyPressed(Keyboard::Key::Left) && left() > 0)
            velocity.x = -paddleVelocity;
        else if (Keyboard::isKeyPressed(Keyboard::Key::Right) &&
            right() < windowWidth)
            velocity.x = paddleVelocity;


        else
            velocity.x = 0;
    }

    //The functions made that allow us to make the paddle 'percieve' its surroundings; we are defining the edges of the
    //rectangular paddle shape we created, so that we can use those instead of the shape's origin point for example,
    //Which would not encompass the full length of the shape.
    float x() { return shape.getPosition().x; }
    float y() { return shape.getPosition().y; }
    float left() { return x() - shape.getSize().x / 2.f; }
    float right() { return x() + shape.getSize().x / 2.f; }
    float top() { return y() - shape.getSize().y / 2.f; }
    float bottom() { return y() + shape.getSize().y / 2.f; }
};

//Below, we are creating objects of the ball, paddle (at a prescribed location in window), and then creating the 
//previously defined window. We are also drawing (rendering) all of these.
//We are also calling the update finctions for each of the these.
    
//The game loop: This is where all the necessary components instantiated, updated and drawn over and over, until the
//program will be exited using the Escape Key, as defined (or by closing the program window).
int main()
{
    Ball ball{ windowWidth / 2, windowHeight / 2 };


    Paddle paddle{ windowWidth / 2, windowHeight - 50 };

    RenderWindow window{ {windowWidth, windowHeight}, "Arkanoid - 5" };
    window.setFramerateLimit(60);

    while (true)
    {
        window.clear(Color::Black);

        if (Keyboard::isKeyPressed(Keyboard::Key::Escape)) break;

        ball.update();
        paddle.update();

        window.draw(ball.shape);
        window.draw(paddle.shape);
        window.display();
    }

    return 0;
}