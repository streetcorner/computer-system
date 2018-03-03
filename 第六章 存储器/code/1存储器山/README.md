The memory mountain
===================

# Usage

just type `make plot` and enjoy the show.

dependencies:
- gcc
- python2
- matplotlib/numpy

# Implementation

The program `benchmark.c`  runs the actual function from  the book and
measures its execution time:

    data_t test()
    {
        data_t result=0;
        size_t i;
        for( i=0; i<count; i += stride )
        {
            result += data[i];
        }
        return result;
    }
    
