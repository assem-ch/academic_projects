#!/usr/bin/perl


use strict;
use warnings;

## Problems:
# forloop condition must be "greater or equal" then the max of the two arrays lengths: $i <= ($#v1_parts, $#v2_parts)[$#v1_parts < $#v2_parts]
# must create a checking state variable:
# - initialized by 0 (equal):   my $myreturn = 0;
# - and quit the loop sooner as it gets to value 1 or -1 (greater or less): $myreturn = - 1; last;
# - return that variable and remove all other returns:  return $myreturn;


# this function compares two version strings
# in the form '4.0' and '3.0.1' and returns
# -1 if the first version is less than the second
# 0 if the versions are equal
# 1 if the first version is greater than the second
sub versionChecker
{
 my $v1 = shift;

 my $v2 = shift;

 print $v1." and ".$v2."\n";

   my @v1_parts = split (/\./, $v1);
 my @v2_parts = split (/\./, $v2);

   my $myreturn = 0;
 
   for( my $i = 0; $i <= ($#v1_parts, $#v2_parts) [$#v1_parts < $#v2_parts]; $i++ ) 
 {

    if( $v1_parts[$i] < $v2_parts[$i] )
    {
       $myreturn = - 1; last;
    }
    elsif( $v1_parts[$i] > $v2_parts[$i] )
    {
       $myreturn = 1; last;
    }
 }
   # equal !
 return $myreturn;
}


print versionChecker("4.2", "4.2.1")."\n";


exit 0;
