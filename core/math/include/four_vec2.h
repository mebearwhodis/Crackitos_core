﻿#ifndef CRACKITOS_PHYSICS_MATH_FOUR_VEC2_H_
#define CRACKITOS_PHYSICS_MATH_FOUR_VEC2_H_

#include <array>
#include <cassert>

#include "vec2.h"
#include "commons.h"

namespace crackitos_core::math
{
    template <typename T>
    struct FourVec2
    {
        std::array<T, 4> x{};
        std::array<T, 4> y{};

        FourVec2() = default;

        constexpr FourVec2(std::initializer_list<Vec2<T>> vectors)
        {
            assert(vectors.size() == 4 && "FourVec2 requires 4 vectors");
            auto it = vectors.begin();
            for (int i = 0; i < 4; i++)
            {
                x[i] = it->x;
                y[i] = it->y;
                ++it;
            }
        }

        explicit constexpr FourVec2(const std::array<Vec2<T>, 4>& vec)
        {
            for (int i = 0; i < 4; i++)
            {
                x[i] = vec[i].x;
                y[i] = vec[i].y;
            }
        }

        FourVec2<T> operator+(const FourVec2<T>& other) const;
        FourVec2<T> operator-(const FourVec2<T>& other) const;
        FourVec2<T> operator-() const; //Opposite
        FourVec2<T> operator*(const crackitos_core::commons::fp scalar) const; //Multiply by scalar
        FourVec2<T> operator*(const std::array<T, 4> scalars) const; //Multiply by 4 scalars
        FourVec2<T> operator/(const crackitos_core::commons::fp scalar) const; //Divide by scalar
        std::array<crackitos_core::commons::fp, 4> Dot(const FourVec2<T>& other) const; //Dot
        std::array<crackitos_core::commons::fp, 4> SquareMagnitude() const; //SquareMagnitude
        std::array<crackitos_core::commons::fp, 4> Magnitude() const; //Magnitude/Sqrroot
        FourVec2<T> Normalize() const; //Normalize
    };

    using FourVec2i = FourVec2<int32_t>;
    using FourVec2f = FourVec2<crackitos_core::commons::fp>;

    //TODO + LTO, use nodiscard, constexpr where needed

    //Specialization for physics923::commons::fp
    template <>
    FourVec2f FourVec2<crackitos_core::commons::fp>::operator+(const FourVec2f& other) const;
    template <>
    FourVec2f FourVec2<crackitos_core::commons::fp>::operator-(const FourVec2f& other) const;
    template <>
    FourVec2f FourVec2<crackitos_core::commons::fp>::operator-() const;
    template <>
    FourVec2f FourVec2<crackitos_core::commons::fp>::operator*(const crackitos_core::commons::fp scalar) const;
    template <>
    FourVec2f FourVec2<crackitos_core::commons::fp>::operator*(
        const std::array<crackitos_core::commons::fp, 4> scalars) const;
    template <>
    FourVec2f FourVec2<crackitos_core::commons::fp>::operator/(const crackitos_core::commons::fp scalar) const;
    template <>
    std::array<crackitos_core::commons::fp, 4> FourVec2<crackitos_core::commons::fp>::Dot(
        const FourVec2f& other) const;
    template <>
    std::array<crackitos_core::commons::fp, 4> FourVec2<crackitos_core::commons::fp>::SquareMagnitude() const;
    template <>
    std::array<crackitos_core::commons::fp, 4> FourVec2<crackitos_core::commons::fp>::Magnitude() const;
    template <>
    FourVec2f FourVec2<crackitos_core::commons::fp>::Normalize() const;
} // namespace math
#endif // CRACKITOS_PHYSICS_MATH_FOUR_VEC2_H_
