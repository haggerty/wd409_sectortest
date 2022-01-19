#include <iostream>
#include <cstdlib>

int wd409( const char *filename , const char *outputfile);

using namespace std;

int main( int argc, char* argv[] )
{
  int nevents;

  if ( argc < 2 ) 
    {
      cerr << "usage: wd409 filename [outputfilename] " << endl;
      exit(1);
    } 
  else 
    {
      cerr << "file: " << argv[1] << endl;
    }
  
  if ( argc ==2  )
    {
      nevents = wd409( argv[1], argv[1] );
    }
  else if  ( argc ==3  )
    {
      nevents = wd409( argv[1], argv[2] );
    }

  return nevents;

}
