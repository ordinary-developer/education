Steps to reproduce:
- get the js ini file from [here](https://github.com/npm/ini/blob/main/lib/ini.js)
- in the `ini.js` file delete (or comment) the block with `module.exports`
- in the `ini.js` file put the `export` keyword before the `encode` and `decode` function declarations
