#!/usr/bin/perl


use strict;
use warnings;

## Problems:
# the condition of while must be "less or equal"
# the second argument in the recursion function should be a  pre-increment ++$num_ or the program will fall in a deep recursion

# this function takes two numbers and using a novel
# but not very efficient recursive algorithm
# finds the value 2^X where X is the argument by
# counting the number of recursions that take place

sub two_to_the_power
{
 my $num = shift;
 my $num_ = shift;


 $num_ = 1 if( !$num_ );


 my $total = 1;


 while( $num_ <= $num )
 {
    $total += two_to_the_power( $num, ++$num_ );
 }


 return $total;
}

print two_to_the_power(10)."\n";

exit 0;
