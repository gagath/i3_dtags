#!/bin/bash

i3-msg -t command move workspace $(i3-msg -t get_workspaces | i3-dtags | dmenu $*)

