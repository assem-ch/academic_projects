#!/usr/bin/perl


use strict;


sub writeOut
{
 my $message = shift;
 my $option = shift;      #optional
   if( $option eq 'STDERR' )
 {
    select STDERR;
    print  $message . "\n";
 }
 else
 {
    print $message . "\n";
 }
}

sub getUUID
{
  my $option = shift;     #optional


  my $uuid = "8f5de6fd-5f97-4b27-be35-861c3bbbb1f1";


  if( $option eq 'nodash' )
  {
     $uuid =~ s/-//g;
  }


  return $uuid;
}

writeOut(getUUID(),"STDERR");

print getUUID('nodash')."\n";

exit 0;
