#!/bin/bash

i3-msg workspace $(i3-msg -t get_workspaces | i3-dtags | dmenu "$@")

