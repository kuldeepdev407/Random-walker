#include<SFML/Graphics.hpp>
#include<iostream>

int main()
{
    srand((unsigned)time(NULL));
    //Initializing things
    sf::RenderWindow window(sf::VideoMode(600, 400), "Random Walker", sf::Style::Close | sf::Style::Titlebar);
    sf::Event events;
    sf::CircleShape point(1.0f);
    sf::Vector2f pos;
    point.setPosition(300,200);
    point.setFillColor(sf::Color::White);
    //window.clear(sf::Color::White);
    
    window.setVerticalSyncEnabled(true);
    while(window.isOpen())
    {
        //Events Handling
        while(window.pollEvent(events))
        {
            switch (events.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            default:
                break;
            }
        }
        
        //calculation
        pos = point.getPosition();
        int choice= rand()%4 + 1;
        switch (choice)
        {
        case 1: pos.x++;break;
        case 2: pos.x--;break;
        case 3: pos.y++;break;
        case 4: pos.y--;break;
        default:break;
        }
        point.setPosition(pos);
        
        //Drawing things
        //_sleep(4);
        window.draw(point);
        window.display();
    } 
    return 0;
}