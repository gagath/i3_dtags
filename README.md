# i3-dynamic-tags

Tool for using dynamic tags with i3 window manager.

A call to this tool will display a list of i3 workspaces in a dmenu, allowing
you to switch to a named workspace easily. Moreover, this script handles custom
fonts.

## Requirements

This program requires the following tools to be installed on your system :

 * i3
 * sh
 * python 3
 * dmenu

## Configuration

You can had the following lines to your i3 configuration file in order to
use the script, use tags navigation and renaming them :

```
# Show all tags and allow user to select one though dmenu
bindsym $mod+w exec ~/path/to/dtags.sh '$font'

# Renames a tag
bindsym $mod+x exec i3-input -F 'rename workspace to %s' -P 'New name: ' -f '$font'
```
