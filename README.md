# i3-dynamic-tags

Tool for using dynamic tags with i3 window manager.

A call to this tool will display a list of i3 workspaces in a dmenu, allowing
you to switch to a named workspace easily. Moreover, this script handles custom
fonts.

## Requirements

This program requires the following tools to be installed on your system in
order to work :

 * i3
 * dmenu
 * sh

Moreover, you will need to install the following library :

 * cJSON

## Configuration

You can had the following lines to your i3 configuration file in order to
use the script, use tags navigation and renaming them :

```
# Show all tags and allow user to select one though dmenu
bindsym $mod+w exec ~/path/to/dtags.sh '$font'

# Renames a tag (optional)
bindsym $mod+x exec i3-input -F 'rename workspace to %s' -P 'New name: ' -f '$font'
```

## How-to

Simply call the `dtags.sh` script by pressing your defined shortcut and then
type the first letters of the tag you want to go on, then tab and enter.
Moreover you can also type an unexisting name and a new tag with this name
will be automatically created by i3.
