#!/usr/bin/perl


use strict;
use warnings;


sub comma_split { 

 	return split(',', $_[0]);
}
  
my $phrase = 'hello, world, matt';
my @values = comma_split($phrase);

foreach my $v (@values) {
    print "$v\n";
}

exit 0;
