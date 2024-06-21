
#include <memory>

#include <SDL.h>
#include <SDL2_gfx/SDL2_gfxPrimitives.h>
#include "planar_quadrotor.h"

class PlanarQuadrotorVisualizer {
private:
    PlanarQuadrotor *quadrotor_ptr;
    int SCREEN_WIDTH = 1280;
    int SCREEN_HEIGHT = 720;
    int quadrotorHeight = 20;
    int quadRotorWIdth = 100;
    float rotation;
public:
    PlanarQuadrotorVisualizer(PlanarQuadrotor *quadrotor_ptr);
    void render(std::shared_ptr<SDL_Renderer> &gRenderer);
    void drawRect(SDL_Rect*, int, int, int, int);
    void drawProppeler(int, int, std::shared_ptr<SDL_Renderer> &gRenderer);

};