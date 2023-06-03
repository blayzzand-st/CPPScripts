#ifndef COURSE_C___FUNCTIONS_H
#define COURSE_C___FUNCTIONS_H

struct Vector2D {
    float x;
    float y;
};

struct Rectangle {
    Vector2D position;
    Vector2D scale;
};

void GetFractPartPointer(float *real);
void GetFractPartReference(float &real);

void ReverseRealPointer(float *real);
void ReverseRealReference(float &real);

void MoveSquarePointer(Rectangle *rect, Vector2D *to_move);
void MoveSquareReference(Rectangle &rect, Vector2D &to_move);

void ChangeRawsPointer(int **matrix, int rows, int cols, int r_1, int r_2);
void ChangeRawsReference(int (&matrix)[3][3], int r_1, int r_2);

#endif
