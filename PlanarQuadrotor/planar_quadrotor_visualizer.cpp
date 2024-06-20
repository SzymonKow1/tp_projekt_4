#include "planar_quadrotor_visualizer.h"

PlanarQuadrotorVisualizer::PlanarQuadrotorVisualizer(PlanarQuadrotor *quadrotor_ptr): quadrotor_ptr(quadrotor_ptr) {}

/**
 * TODO: Improve visualizetion
 * 1. Transform coordinates from quadrotor frame to image frame so the circle is in the middle of the screen
 * 2. Use more shapes to represent quadrotor (e.x. try replicate http://underactuated.mit.edu/acrobot.html#section3 or do something prettier)
 * 3. Animate proppelers (extra points)
 */
void PlanarQuadrotorVisualizer::render(std::shared_ptr<SDL_Renderer> &gRenderer) {
    Eigen::VectorXf state = quadrotor_ptr->GetState();
    float q_x, q_y, q_theta;

    /* x, y, theta coordinates */
    q_x = state[0];
    q_y = state[1];
    q_theta = state[2];

    int SCREEN_WIDTH = 1280;
    int SCREEN_HEIGHT = 720;
    SDL_GetRendererOutputSize(gRenderer.get(), &SCREEN_WIDTH, &SCREEN_HEIGHT);

    int q_x_screen = q_x + (SCREEN_WIDTH/2);
    int q_y_screen = -q_y + (SCREEN_HEIGHT/2);

    SDL_SetRenderDrawColor(gRenderer.get(), 0xFF, 0x00, 0x00, 0xFF);
    filledCircleColor(gRenderer.get(), q_x_screen, q_y_screen, 10, 0xFF000000);
}