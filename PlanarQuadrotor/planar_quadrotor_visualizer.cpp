
#include "planar_quadrotor_visualizer.h"

PlanarQuadrotorVisualizer::PlanarQuadrotorVisualizer(PlanarQuadrotor *quadrotor_ptr): quadrotor_ptr(quadrotor_ptr) {}


void PlanarQuadrotorVisualizer::render(std::shared_ptr<SDL_Renderer> &gRenderer) 
{
    Eigen::VectorXf state = quadrotor_ptr->GetState();
    float q_x, q_y, q_theta;

    q_x = state[0];
    q_y = state[1];
    q_theta = state[2];


    SDL_GetRendererOutputSize(gRenderer.get(), &SCREEN_WIDTH, &SCREEN_HEIGHT);

    int q_x_screen = q_x + (SCREEN_WIDTH/2);
    int q_y_screen = -q_y + (SCREEN_HEIGHT/2);

    SDL_Surface* surface = SDL_CreateRGBSurface(0, 20, 200, 32, 0, 0, 0, 0);
    SDL_FillRect(surface, nullptr, SDL_MapRGB(surface->format, 0, 0, 100));
    
    SDL_Texture* texture = SDL_CreateTextureFromSurface(gRenderer.get(), surface);

    SDL_Rect destination;
    drawRect(&destination, q_x_screen - 50, q_y_screen - 10, quadRotorWIdth, quadrotorHeight);

    SDL_Rect leftBridge;
    drawRect(&leftBridge, q_x_screen - 50, q_y_screen - 20, 4, 20);

    SDL_Rect rightBridge;
    drawRect(&rightBridge, q_x_screen + 46, q_y_screen - 20, 4, 20);



    SDL_RenderCopyEx(gRenderer.get(), texture, NULL, &destination, q_theta, NULL, SDL_FLIP_NONE);
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);



    SDL_SetRenderDrawColor(gRenderer.get(), 0xFF, 0x00, 0x00, 0xFF);
    SDL_RenderFillRect(gRenderer.get(), &leftBridge);
    SDL_RenderFillRect(gRenderer.get(), &rightBridge);
    drawProppeler(q_x_screen - 69, q_y_screen - 20, gRenderer);
    drawProppeler(q_x_screen + 29, q_y_screen - 20, gRenderer);



   
}
void PlanarQuadrotorVisualizer::drawRect(SDL_Rect *rect, int x, int y, int w, int h) 
{
    rect->x = x; 
    rect->y = y;
    rect->w = w;
    rect->h = h;
}
void PlanarQuadrotorVisualizer::drawProppeler(int x, int y, std::shared_ptr<SDL_Renderer> &gRenderer)
{
    SDL_Rect proppeler;
    drawRect (&proppeler, x, y, 40, 4);

    SDL_Surface* surface = SDL_CreateRGBSurface(0, 40, 4, 32, 0, 0, 0, 0);
    SDL_FillRect(surface, nullptr, SDL_MapRGB(surface->format, 0, 100, 0));
    
    SDL_Texture* texture = SDL_CreateTextureFromSurface(gRenderer.get(), surface);

    rotation += 4;

    SDL_RenderCopyEx(gRenderer.get(), texture, NULL, &proppeler, rotation, NULL, SDL_FLIP_NONE);
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}
