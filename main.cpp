#define SDL_MAIN_HANDLED

#include <iostream>
#include <vector>

#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>

int main(int argc, char *argv[])
{
    SDL_Window* win;
    SDL_Renderer* renderer;

    unsigned int windowWidth = 0;
    unsigned int windowHeight = 0;

    unsigned int charWidht = 100;
    unsigned int charHeight = 200;
    float positionX = 0;
    float positionY = 0;
    float velocityY = 0;
    float velocityX = 0;
    float walkSpeed = 0;
    bool onGround = false;
    const float airAccelerrationReduction = 0.3;
    const float gravity = 10;
    const float jumpForce = 800;
    const float walkMaxSpeed = 4000;
    const float walkAcceleration = 1000;
    const float walkDesceleration = 3000;

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cerr << SDL_GetError();
        return 1;
    }

    win = SDL_CreateWindow("Character",
                           positionX,
                           positionY,
                           charWidht,
                           charHeight,
                           SDL_WINDOW_BORDERLESS | SDL_WINDOW_ALWAYS_ON_TOP
                           );

    SDL_SetWindowResizable(win, SDL_FALSE);

    renderer = SDL_CreateRenderer(win, 0, 0);

    SDL_DisplayMode DM;
    SDL_GetCurrentDisplayMode(0, &DM);
    windowWidth = DM.w;
    windowHeight = DM.h;

    unsigned int lastTime = 0;
    while(true) {
        SDL_RenderClear(renderer);

        float deltaTime = (SDL_GetTicks64() - lastTime) / 1000.0f;
        if(deltaTime == 0) {
            SDL_Delay(1);
            deltaTime = (SDL_GetTicks64() - lastTime) / 1000.0f;
        }
        lastTime = SDL_GetTicks64();
        SDL_Event e;

        velocityY += gravity;
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) goto quit_game;
        }

        const Uint8 *state = SDL_GetKeyboardState(NULL);
        if(state[SDL_SCANCODE_D]) {
            walkDirection = 1;
            walking = true;
        } else if (state[SDL_SCANCODE_A]) {
            walkDirection = -1;

            walking = true;
        }else{
            walkDirection = 0;
            walking = false;
        }

        if(state[SDL_SCANCODE_SPACE]) {
            if(onGround) velocityY = -jumpForce;
        }

        float accelerationReducion = onGround ? 1 : airAccelerrationReduction;
        if (!walking ) {
            if(walkSpeed > 0) {
                walkSpeed -= walkDesceleration * deltaTime * accelerationReducion;
                if (walkSpeed < 0) walkSpeed = 0;
            } else {
                walkSpeed += walkDesceleration * deltaTime  * accelerationReducion;
                if (walkSpeed > 0) walkSpeed = 0;
            }

        } else {
            if(walkSpeed * walkDirection> 0) {
                walkSpeed += walkAcceleration * walkDirection * deltaTime * accelerationReducion;
                if(walkSpeed > walkMaxSpeed) walkSpeed = walkMaxSpeed;
            }  else {
                walkSpeed += walkDesceleration * walkDirection * deltaTime * accelerationReducion;
                if(walkSpeed > walkMaxSpeed) walkSpeed = walkMaxSpeed;
            }


        }

        velocityX = walkSpeed;

        positionY += velocityY  * deltaTime;
        positionX += velocityX  * deltaTime;

        if(positionX < 0) {
            velocityX = 0;
            positionX = 0;
        }
        if(positionY < 0){
            velocityY = 0;
            positionY = 0;
        }
        if(positionX > windowWidth - charWidht) {
            positionX = windowWidth - charWidht;
            velocityX = 0;
        }
        if(positionY > windowHeight - charHeight) {
            positionY = windowHeight - charHeight;
            velocityY = 0;
            onGround = true;
        } else {
            onGround = false;
        }

        SDL_SetWindowPosition(win, positionX, positionY);
        SDL_RenderPresent(renderer);
    }
    quit_game:

    return 0;
}

