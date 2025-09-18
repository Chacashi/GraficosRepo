#include "DirectionLight.h"

void DirectionLight::apply()
{
    if (!enabled) return;
    applyCommonColors();
    GLfloat pos[4] = { -direction.x, -direction.y, -direction.z, 0.0f };
    glLightfv(glld, GL_POSITION, pos);
}
