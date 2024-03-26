// includes
  ...

// function prototypes
  ...

int main() 
{
  ... variable declarations
  ...

  gfx_open( ... );

  while (1) {
    c = gfx_wait();
    gfx_clear();
    if (c == '1') {    // Sierpinski Triangle   
        ... set up some variables
        ...
        ... call a recursive function  
    } else if (c == '2') {   // Shrinking Squares  
        ... set up some variables
        ...
        ... call a recursive function  
    } ...
      ...
      ...
      ...
    } else if (c == '8') {   // Spiral of Spirals 
        ... set up some variables
        ...
        ... call a recursive function  
    } else if (c == 'q') { 
        break;
    } else {
        ...
    }
  }

  return 0;
}

// all functions go here
//  (or placed in a separate file if you wish to split)
  ...
  ...

