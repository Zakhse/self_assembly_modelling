#ifndef SELF_ASSEMBLY_MODELLING_RANDOMIZER_WITH_SENTINEL_SHIFT_H
#define SELF_ASSEMBLY_MODELLING_RANDOMIZER_WITH_SENTINEL_SHIFT_H

#include <random>

// https://martin.ankerl.com/2018/12/08/fast-random-bool/
template<typename U, typename Rng>
class RandomizerWithSentinelShift {
public:
    bool operator()(Rng &rng) {
        if (__builtin_expect((1 == m_rand), 0))
            m_rand = std::uniform_int_distribution<U>{}(rng) | s_mask_left1;

        bool const ret = m_rand & 1;
        m_rand >>= 1;
        return ret;
    }

private:
    static constexpr const U s_mask_left1 = U(1) << (sizeof(U) * 8 - 1);
    U m_rand = 1;
};

#endif //SELF_ASSEMBLY_MODELLING_RANDOMIZER_WITH_SENTINEL_SHIFT_H
