#!/bin/bash

if [ ! -z "$1" ]; then
    # Use custom font if provided
    i3-msg workspace $(i3-msg -t get_workspaces | i3-dtags | dmenu -fn "$1")
else
    i3-msg workspace $(i3-msg -t get_workspaces | i3-dtags | dmenu)
fi

