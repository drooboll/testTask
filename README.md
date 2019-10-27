# This repository contains files of test program for 2GIS.
There are two solutions:
- Complex one;
- Simple one.

Complex one is more OOP-like, its features are described below:
- Simple addition of *Workers*, like existing *Counter*, *Hasher* or *Helper*.
- Simple modification of flags (info concentrated in one class / object).
- Various checksum algorithm (simple sum, xor and crc32 (output is equal to POSIX's chksum)).

Simple one is just simple :)
It has no additional features (only that features that described in task).

### Program arguments
Both programs do have arguments, described bellow:
- -f &lt;file&gt;; specifies filename/path to file;
- -m &lt;mode&gt;; specifies work mode; 'words' for words counting (specified by -v flag), or 'checksum' to calc checksum;
- -v &lt;word&gt;; specifies a word to count in file;
- -h prints help.

Complex one has additional -a flag. Its value could be 'SUM', 'HEX', 'CRC32' to specify checksum algorithm when in 'checksum 'mode. If there's no flag or it's not set, 'SUM' algorithm will be used.
Also there's a *long-help* flag, --help. Works absolutely like -h flag.

### Bugs
- *&lt;file&gt;*, *&lt;mode&gt;*, *&lt;word&gt;* cannot starts with '-' symbol :(
