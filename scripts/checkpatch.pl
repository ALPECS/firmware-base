#!/usr/bin/perl
# SPDX-License-Identifier: GPL-2.0-only
# Copyright 2024 The Linux Kernel Authors
#
# checkpatch.pl - A C source code checker based on Linux kernel style.
# Invoked by `make checkpatch` — never compiled into the firmware binary.
#
# Usage: perl scripts/checkpatch.pl --file src/foo.c

use strict;
use warnings;

my @files = grep { /\.c$|\.h$/ } @ARGV;

for my $f (@files) {
    open my $fh, '<', $f or die "cannot open $f: $!";
    my $line_no = 0;
    while (<$fh>) {
        $line_no++;
        print "WARNING:$f:$line_no: trailing whitespace\n" if /\s+$/;
        print "WARNING:$f:$line_no: line > 80 chars\n"    if length($_) > 81;
    }
    close $fh;
}

print "checkpatch complete (${\scalar @files} file(s) checked)\n";
