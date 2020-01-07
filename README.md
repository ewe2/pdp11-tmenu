pdp11-zterp
===========

This is a fork of [pdp11-tmenu](https://github.com/athornton/pdp11-tmenu)

From the original post:

> So I kind of wanted to put a general-purpose Z-machine interpreter on my
PiDP-11, so that people could play Infocom (and community) games on a real
terminal.

> Turns out there wasn't really one, so I ported the venerable ZIP (which I
have renamed "zterp" for obvious reasons) to 2.11BSD on the PDP-11, and I
also wrote a little utility I call "tmenu" to take a directory (and an
optional command applying to files in the directory) and make a numbered
menu, so that my guests who are not familiar with Actual Bourne Shell can
play games too.

> These things are at:

> [pdp11-zterp](https://github.com/athornton/pdp11-zterp)

> and

> [pdp11-tmenu](https://github.com/athornton/pdp11-tmenu/)

> Both are K&R C, and compile with the 2.11BSD system C compiler.

> My biggest disappointment is that the memory map of Trinity, my favorite
Infocom game, is weird and even though it's only a V5 game, I can't
allocate enough memory to start it.  Other than that, V5 and below seem to
work mostly fine; V8 is in theory supported but no game that I've tried has
little enough low memory that I can malloc() it using C on 2.11BSD.
