# Dotus: Note Taking Utility
Dotus is a simple CLI utility which allows you to write, modify, delete, archive, and search through notes which are stored as single lines in a text file. The name Dotus comes from Herodotus, the ancient Greek historian, because Greek stuff is cool and programmery.

Use ***dotus help*** to display a usage guide.
## Philosophy
I generally prefer programs that skew towards extreme simplicity, even if it comes at the cost of convenience. As such, this program has a very small set of commands and some limitations that I don't intend to change. The user (me) is intended to use this limited functionality in whatever clever way they can think of to organize and keep track of their notes.
Such limitations include:
- Notes are all a single line long.
- Identifiers for notes are just their line number, which means its value is volatile and can't be referenced by other notes. I want note surfing to be based around keyword search rather than hyperlinks.
- The find command is limited to displaying exact matches of any number of given strings. I may or may not add a blacklisting option to this, we'll see how it goes.
## Configuration
The file path where notes are stored is #defined at the top of ***src/dotus.c***. As this is for my own personal use, I am sticking to my preference of configuration via source code rather than from a file or environment variable. That being said, the code is very short (less than 250 lines!) so you should be able to easily modify the overall functionality, as well as file paths, yourself.
