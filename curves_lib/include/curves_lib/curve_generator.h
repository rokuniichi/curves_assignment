#pragma once

#include "curve.h"

#include <random>
#include <vector>

struct CurveGenerator
{
public:
	int GenerateRandomInteger(const int min, const int max);
	std::vector<std::shared_ptr<Curve>> GenerateRandomCurves(const int count, const double min, const double max);
private:
	const enum CurveType { circle, ellipse, helix };
	const std::mt19937 seed = std::mt19937(std::random_device{}());;
};