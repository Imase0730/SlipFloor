#pragma once

#include "GameMath.h"

// 円の情報
struct BoundingCircle
{
	// 中心
	Vector2D center;

	// 半径
	float radius;
};

// 円と円の衝突判定
inline bool IsCircleColliding(const BoundingCircle& a, const BoundingCircle& b)
{
	if (Length(a.center - b.center) <= a.radius + b.radius) return true;
	return false;
}

// 円と円が重ならない用に位置を補正する関数
inline void ResolveOverlap(BoundingCircle* a, BoundingCircle* b)
{
    Vector2D delta = b->center - a->center;
    float dist = Length(delta);
    float minDist = a->radius + b->radius;

    // ２つの円を重ならない用に移動する
    float overlap = minDist - dist;
    if (overlap > 0.0f)
    {
        Vector2D correction = Normalize(delta) * (overlap / 2.0f);
        a->center -= correction;
        b->center += correction;
    }
}
