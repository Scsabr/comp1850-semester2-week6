#ifndef byref_header
#define byref_header

#include <stdio.h>
#include <stdlib.h>

#define GRID_SIZE 21 // 21x21 grid for -10 to +10 range

// Function prototypes
void draw_grid(char **grid);
char **initialize_grid(void);
void add_point(char **grid, int x, int y);
void move_point(int *x, int *y, int dx, int dy);
void reflect_point(int *x, int *y, char axis);
void swap_coords(int *x, int *y);
#endif