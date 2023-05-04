#include "entity.h"
#include "combat.h"
#include "button.h"
#include "gameWorld.h"
#include "menu.h"
#include "tiles.h"
#include "walking.h"
#include "battleSprites.h"
const sf::Time TIME_PER_FRAME = sf::seconds(1.f / 60.f);

// starts the clock

int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(1600, 900), "SFML window");
    window.setFramerateLimit(60);
    // Load a sprite to display
    spriteWalk character(spriteSelection[1]);
    character.charSprite.scale(sf::Vector2f(4.f, 4.f));
    srand(time(NULL));
    Paladin myPaladin;
    WhiteMage myWhiteMage;
    BlackMage myBlackMage;
    Fighter myFighter;
    sf::Font font;
    if (!font.loadFromFile("Final-Fantasy.ttf"))
    {
    }
    sf::Clock clock;
    // starts the clock
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    // starts the clock
    GameWorld gameWorld;
    for (int i = 0; i < gameWorld.gridLength; i++)
    {
        for (int j = 0; j < gameWorld.gridLength; j++)
        {
            gameWorld.gameTiles[i][j]->sprite.scale(sf::Vector2f(4.f, 4.f));
        }
    }
    while (window.isOpen())
    {
        timeSinceLastUpdate += clock.restart();
        characterWalking(character, myPaladin, myWhiteMage, myBlackMage, myFighter, window, font, 1);
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // Clear screen
        while (timeSinceLastUpdate > TIME_PER_FRAME)
        {
            timeSinceLastUpdate -= TIME_PER_FRAME;
        }
        for (int i = 0; i < gameWorld.gridLength; i++)
        {
            for (int j = 0; j < gameWorld.gridLength; j++)
            {
                window.draw(gameWorld.gameTiles[i][j]->sprite);
            }
        }
        window.draw(character.charSprite);
        window.display();
        window.clear();
        // sf::sleep(start + TIME_PER_FRAME - clock.getElapsedTime());
    }
    return EXIT_SUCCESS;
}