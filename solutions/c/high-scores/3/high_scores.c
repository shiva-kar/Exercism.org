#include "high_scores.h"
#include <stdint.h>

int32_t latest(const int32_t *scores, size_t scores_len){
    return scores[scores_len - 1];
}

int32_t personal_best(const int32_t *scores, size_t scores_len){
    int32_t best = INT32_MIN;
    for (size_t i = 0; i < scores_len; ++i) {
        if (scores[i] > best) best = scores[i];
    }
    return best;
}

size_t personal_top_three(const int32_t *scores, size_t scores_len, int32_t *output){
    int32_t first  = INT32_MIN;
    int32_t second = INT32_MIN;
    int32_t third  = INT32_MIN;

    for (size_t i = 0; i < scores_len; ++i) {
        int32_t score = scores[i];
        if (score >= first) {
            third  = second;
            second = first;
            first  = score;
        } else if (score >= second) {
            third  = second;
            second = score;
        } else if (score > third) {
            third = score;
        }
    }

    output[0] = first;
    output[1] = second;
    output[2] = third;

    return scores_len >= 3 ? 3 : scores_len;
}