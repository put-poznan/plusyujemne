#include "util.h"

void RenderGE(const struct GameEntity entity)
{
	al_draw_bitmap(entity.bitmap, entity.Pos.x, entity.Pos.y, 0);
}


