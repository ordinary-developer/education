### CORS policy
To start Chrome correctly:
- close all Chrome instances
  (a new Chrome instance will not parse cmd line parameters if there is already at least one running instance)
- start the Chrome
  `%path_to_chrome_bin% --allow-file-access-from-files`
- open your html file
  (it must have something like this: `<script type="module" src="%path_to_js%"></script>`)

_Note:_
For seeing real parameters in Chrome open the url: `chrome://version`