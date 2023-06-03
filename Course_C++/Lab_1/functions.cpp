#include <iostream>
#include "functions.h"
#include <cmath>

void GetFractPartPointer(float *real) {
    (*real) = *real - std::floor(*real);
}

void GetFractPartReference(float &real) {
    real = real - std::floor(real);
}

void ReverseRealPointer(float *real) {
    (*real) *= -1;
}

void ReverseRealReference(float &real) {
    real *= -1;
}

void MoveSquarePointer(Rectangle *rect, Vector2D *to_move) {
    rect->position.x += to_move->x;
    rect->position.y += to_move->y;
}

void MoveSquareReference(Rectangle &rect, Vector2D &to_move) {
    rect.position.x += to_move.x;
    rect.position.y += to_move.y;
}

void ChangeRawsPointer(int **matrix, int rows, int cols, int r_1, int r_2) {
    r_1 -= 1;
    r_2 -= 1;

    for (int i = 0; i < rows; i++) {
        if (i == r_1) {
            for (int j = 0; j < cols; j++) {
                std::swap(matrix[i][j], matrix[r_2][j]);
            }
        }
    }
}

void ChangeRawsReference(int (&matrix)[3][3], int r_1, int r_2) {
    r_1 -= 1;
    r_2 -= 1;

    for (int i = 0; i < 3; i++) {
        if (i == r_1) {
            for (int j = 0; j < 3; j++) {
                std::swap(matrix[i][j], matrix[r_2][j]);
            }
        }
    }
}