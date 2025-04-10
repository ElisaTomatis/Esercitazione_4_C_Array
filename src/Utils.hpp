#pragma once
#include <string>

std::string ArrayToString(const size_t& n,
                          const double* const v,
                          int precision = 2);

bool ExportPortfolioResult(const std::string& outputFilePath,
                           double S,
                           double V,
                           double R,
                           const size_t n,
                           const double* const w,
                           const double* const r);