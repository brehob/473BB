#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#include <io.h>
#include <fcntl.h>
#include <sys/stat.h>


int main() {

  const char num[] = "38";

  char buf[ 0x200 ];
  const char gpio_export[] = 	"/sys/class/gpio/export";
  const char gpio_direction[] = "/sys/class/gpio/gpio%s/direction";
  const char gpio_value[] = 	"/sys/class/gpio/gpio%s/value";
  const char direction[] = 	"out";

  FILE* f = fopen( gpio_export, "w" );
printf( "%p: %s\n", f, gpio_export );
  fwrite( num, sizeof( char ), strlen( num ), f );
printf( "hi\n" );
  fclose( f );

  sprintf( buf, gpio_direction, num );
printf( "%s\n", buf );
  f = fopen( buf, "w" );
  fwrite( direction, sizeof( *direction ), strlen( direction ), f );
  fclose( f );

  sprintf( buf, gpio_value, num );
printf( "%s\n", buf );
  int fd = open( buf, O_WRONLY );
  while( 1 ) {
    write( fd, "1", 1 );
    write( fd, "0", 1 );
    write( fd, "1", 1 );
    write( fd, "0", 1 );
  }

  return EXIT_SUCCESS;

}



