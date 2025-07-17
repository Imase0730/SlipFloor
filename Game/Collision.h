#pragma once

#include "GameMath.h"

// �~�̏��
struct BoundingCircle
{
	// ���S
	Vector2D center;

	// ���a
	float radius;
};

// �~�Ɖ~�̏Փ˔���
inline bool IsCircleColliding(const BoundingCircle& a, const BoundingCircle& b)
{
	if (Length(a.center - b.center) <= a.radius + b.radius) return true;
	return false;
}

// �~�Ɖ~���d�Ȃ�Ȃ��p�Ɉʒu��␳����֐�
inline void ResolveOverlap(BoundingCircle* a, BoundingCircle* b)
{
    Vector2D delta = b->center - a->center;
    float dist = Length(delta);
    float minDist = a->radius + b->radius;

    // �Q�̉~���d�Ȃ�Ȃ��p�Ɉړ�����
    float overlap = minDist - dist;
    if (overlap > 0.0f)
    {
        Vector2D correction = Normalize(delta) * (overlap / 2.0f);
        a->center -= correction;
        b->center += correction;
    }
}
