#!/bin/sh

i3-msg workspace $(i3-msg -t get_workspaces | python -c "import json; [print(w['name']) for w in json.loads(input())]" | dmenu -fn $1)
