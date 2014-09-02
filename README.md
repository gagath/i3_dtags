# i3-dtags

Tool for using dynamic tags with i3 window manager.

## Description

A call to this tool will display a list of i3 workspaces in a dmenu, allowing
you to switch to a named workspace easily. Moreover, this script handles custom
fonts.

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

First prototype was made out of Python code, but it was too slow to run on my
computer so I decided to rewrite some parts in C. The next step would be to
avoid JSON and directly use the i3 API.

## Copyright

i3-dtags is brought to you under WTFPL. For further informations read the
provided COPYING file.
