#include "high_scores.h"

int32_t latest(const int32_t *scores, size_t scores_len){
    return scores[scores_len - 1];
}

int32_t personal_best(const int32_t *scores, size_t scores_len){
    int32_t best = scores[0];
    for (size_t i = 1; i < scores_len; ++i) {
        int32_t score = scores[i];
        if (score > best) { best = score; }
    }
    return best;
}

size_t personal_top_three(const int32_t *scores, size_t scores_len, int32_t *output){
    int32_t first = 0;
    int32_t second = 0;
    int32_t third = 0;
    
    for (size_t i = 0; i < scores_len; ++i) {
        int32_t score = scores[i];

        if (score >= first) {
            third = second;
            second = first;
            first = score;
        }
        else if (score >= second) {
            third = second;
            second = score;
        }
        else if (score > third) { third = score; }
    }
    output[0] = first;
    output[1] = second;
    output[2] = third;

    if (scores_len >= 3)
        return 3;
    return scores_len;
}