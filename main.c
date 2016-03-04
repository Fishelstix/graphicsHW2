#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

int main() {

  screen s;

  color c;
  c.red = 0;
  c.green = 0;
  c.blue = MAX_COLOR;

  clear_screen(s);

  struct matrix *edges;
  struct matrix *transform;

  edges = new_matrix(4, 1);
  
  add_edge(edges, 0, 300, 0, 25, 400, 0);
  add_edge(edges, 50, 300, 0, 25, 400, 0);
  add_edge(edges, 10, 340, 0, 40, 340, 0);
  add_edge(edges, 50, 400, 0, 75, 350, 0);
  add_edge(edges, 100, 400, 0, 75, 350, 0);
  add_edge(edges, 75, 350, 0, 75, 300, 0);
  add_edge(edges, 100, 400, 0, 125, 350, 0);
  add_edge(edges, 150, 400, 0, 125, 350, 0);
  add_edge(edges, 125, 350, 0, 125, 300, 0);
  add_edge(edges, 200, 400, 0, 200, 300, 0);
  add_edge(edges, 200, 300, 0, 250, 300, 0);
  add_edge(edges, 250, 300, 0, 250, 400, 0);
  add_edge(edges, 250, 400, 0, 275, 350, 0);
  add_edge(edges, 275, 350, 0, 300, 400, 0);
  add_edge(edges, 300, 400, 0, 300, 300, 0);
  add_edge(edges, 300, 300, 0, 325, 400, 0);
  add_edge(edges, 350, 300, 0, 325, 400, 0);
  add_edge(edges, 310, 340, 0, 340, 340, 0);
  add_edge(edges, 350, 300, 0, 350, 400, 0);
  add_edge(edges, 400, 400, 0, 350, 400, 0);
  add_edge(edges, 400, 300, 0, 400, 400, 0);
  add_edge(edges, 400, 300, 0, 350, 300, 0);
  scalar_mult(1.25, edges);


  draw_lines(edges,s,c);
  
  int i;
  for(i=0; i<20; i++){
    scalar_mult(0.75, edges);
    draw_lines(edges,s,c);
  }

  display(s);
  save_extension(s, "matrix.png");

  
  free_matrix( transform );
  free_matrix( edges );
}  
