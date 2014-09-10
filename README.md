# i3-dtags

Tool for using dynamic tags with i3 window manager.

## Description

A call to this tool will display a list of i3 workspaces in a dmenu, allowing
you to switch to a named workspace easily. Moreover, this script handles custom
fonts.

## Screenshot

![i3-dtags at work](http://microjoe.eu/media/projects/i3-dtags/screenshot.png)

## Requirements

This program requires the following tools to be installed on your system in
order to work:

 * i3
 * dmenu
 * sh

Moreover, you will need to install the following C library:

 * cJSON (you can install it from AUR with name `cjson-git`)

## Installation

Simply run the following commands:

```
$ make
$ sudo make install
```

## Configuration

You can had the following lines to your i3 configuration file in order to
use the script, use tags navigation and renaming them:

    :::bash
    # Show all tags and allow user to select one though dmenu
    bindsym $mod+w exec i3-dtags.sh '$font'

    # Renames a tag (optional)
    bindsym $mod+x exec i3-input -F 'rename workspace to %s' -P 'New name: ' -f '$font'

## Usage

Simply call the `dtags.sh` script by pressing your defined shortcut and then
type the first letters of the tag you want to go on, then tab and enter.
Moreover you can also type an unexisting name and a new tag with this name
will be automatically created by i3.

## Why using C?

And why mixing it with shell script?

First prototype was made out of Python code, but JSON parsing was too slow to
run on my computer so I decided to rewrite some parts in C using cJSON.

Meanwhile, I tried to rewrite the whole program in C using i3's IPC (with UNIX
local socket) and no noticeable performance improvement was observed so I
decided to stick with this mix of C and shell script.

**Hint :** do not try to rewrite this whole program in C, dealing with C
sockets, even if there are UNIX-local, is kinda hard and you will not get more
performance than piping the provided binaries from i3wm using bash.

## Copyright

i3-dtags is brought to you under WTFPL. For further informations read the
provided COPYING file.
