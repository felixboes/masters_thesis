#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <gmpxx.h>

int main(int argc, char** argv)
{
    int maximum_p = 10;
    int maximum_q = 8;
    if( argc > 1 )
    {
        maximum_p = atoi(argv[1]);
    }
    if( argc > 2 )
    {
        maximum_q = atoi(argv[2]);
    }
    else
    {
        std::cout << "Usage: " << argv[0] << " 'maximum number of columns' 'maximum number of rows'" << std::endl;
        std::cout << "Using the values: " << maximum_q << " resp. " << maximum_p << std::endl;
        std::cout << std::endl;
    }
    std::vector< std::vector< mpq_class > > a; // Stores the coefficients a_{p,k} that define A(p,q).
    for( int i = 0; i <= maximum_p; ++i )
    {
        a.emplace_back( std::vector< mpq_class >( maximum_p+1, 0 ) );
    }
    a[2][1] = 1;

    // Use the recursive description to determine the a_{p,k}
    for( int k = 1; k <= maximum_p-1; ++k )
    {
        for( int l = 1; l < k; ++l )
        {
            a[k+1][k] -= a[k+1][l];
        }
        
        for( int p = k+2; p <= maximum_p; ++p )
        {
            a[p][k] = mpq_class(-p+1) / mpq_class (p-1-k) * (2*a[p-1][k] + a[p-2][k]);
        }
    }
    
    // Compute and print the values A(p,q)
    for (int p = 2; p <= maximum_p ; ++p )
    {
        mpq_class result(0);
        std::cout << "$A(" << p << ",q)$";
        for( int q = 1; q <= std::min(maximum_q, maximum_p); ++q )
        {            
            result = a[p][1];
            for( int k = 2; k <= maximum_p; ++k )
            {
                result += a[p][k] * pow(k,q-1);
            }
            std::cout << " & " << result;
        }
        std::cout << " \\\\" << std::endl;
        std::cout << "\\hline" << std::endl;
    }
    return 0;
}

