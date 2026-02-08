# kata "Simple Edits"
text:
```
With a editor you can scrooll the
page, move the cursor, delete lines, nisret
characters, and more, while results of
your edits as you make tham.
Since they allow you to make changes
as you read through a file, much as
you would edit a printed copy,
screen editors are very popular.
```

kata:
- ESC
- `1G`
- `2w`, `i`, type "screen ", ESC, `4w`, `3l`, `x`
- `j`, `W`, `cw`, type "insert", ESC
- `j`, `2b`, `i`, type "seeing ", ESC
- `j`, `2h`, `r`, type 'e'
- `j`, `0`, `r`, type 's'
- `2j`, `$`, `r`, type '.'
- `j`, `0`, `r`, type 'S'
- `$`, `x`
- `dd`, `2k`, `P`
