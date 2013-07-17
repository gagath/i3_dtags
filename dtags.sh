#!/bin/sh

i3-msg workspace $(i3-msg -t get_workspaces | ~/dev/i3-dynamic-tags/dtags | dmenu -fn $1)
