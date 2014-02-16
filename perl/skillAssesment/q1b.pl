#!/usr/bin/perl


use strict;
use warnings;


sub comma_split { 

	my $mystring = $_[0];
	my @words = $mystring =~ m/("[^"]+"|[^,]+)(?:,\s*)?/g;

 	return @words;
}
  
my $phrase = 'hello, world, matt';
my @values = comma_split($phrase);

print "example1:\n";
foreach my $v (@values) {
    print "$v\n";
}

my $phrase = 'hello,"world, yo",matt';
my @values = comma_split($phrase);

print "example2:\n";
foreach my $v (@values) {
    print "$v\n";
}

my $phrase = 'one,two,"three,three and a half",           four              ,"five, five and a half",six';
my @values = comma_split($phrase);

print "example3:\n";
foreach my $v (@values) {
    print "$v\n";
}
exit 0;
