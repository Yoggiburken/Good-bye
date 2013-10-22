#!/usr/bin/perl

use File::Slurp;
open(MYFILE, ">>../src/resources.txt");
my $file = read_file("../src/resources.txt");

$str = scalar @ARGV;
printf "$str\n";
for($i=0; $i<scalar @ARGV; $i++) {
	if(-e "../resources/$ARGV[$i]") {
		print "File: $ARGV[$i] found\n";
		if(index($file, $ARGV[$i]) >= 0) {
			print "File: already contains $ARGV[i]\n\n";
		} else {
			my $FILETYPE;
			my $FILEEXTENSION;
			if(index($ARGV[$i], ".png") > 0) {
				$FILETYPE = "TEXTURE";
				$FILEEXTENSION = ".png";
			} elsif(index($ARGV[$i], ".wav") > 0) {
				$FILETYPE = "SOUND";
				$FILEEXTENSION = ".wav";
			} elsif(index($ARGV[$i], ".mp3") > 0) {
				$FILETYPE = "SOUND";
				$FILEEXTENSION = ".mp3";
			} elsif(index($ARGV[$i], ".ttf") > 0) {
				$FILETYPE = "FONT";
				$FILEEXTENSION = ".ttf";
			}
			print "File: added $FILETYPE $ARGV[$i]\n\n";

			$wordlength = 30;
			print MYFILE $FILETYPE;
			$wordlength	= $wordlength - length($FILETYPE);
			for($j=0; $j<$wordlength; $j++) {
				print MYFILE " ";
			}

			$rowlength 	= 80;
			print MYFILE "../resources/$ARGV[$i]";
			$rowlength 	= $rowlength - length("../resources/$ARGV[$i]");
			for($j=0; $j<$rowlength; $j++) {
				print MYFILE " ";
			}
			$ARGV[$i] =~ s/$FILEEXTENSION//;
			print MYFILE "$ARGV[$i]\n";
		}
	} else {
		print "File: $ARGV[$i] not found";
	}
}
