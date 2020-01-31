# Tasks generator

## How it works?

What script does, is creating a new file for the given task url inside of the [solutions](../solutions) directory and adding redirect url for the given task inside of the [readme](../readme.md) file. It also changes task empty check ([ ]) for the checked one ([x]).

So it basically fills all the data automatically and all I need to do is solve the task and paste my solution into already existing file.

W-what are you trying to say? Such process should take up to the minute per each task only? Emm... Well... yeah, but you know... I just like to automate things.

![The machine has taken over that process](important_readme_gif.gif)

## How to use

Install [requirements](requirements.txt)

With pip:

> pip install -r requirements.txt

Because the script uses Selenium to scrap the site data, you will also need to have your browser driver downloaded. **Make sure it’s in your environment PATH.**

#### Drivers:

- [Chrome](https://sites.google.com/a/chromium.org/chromedriver/downloads)
- [Edge](https://developer.microsoft.com/en-us/microsoft-edge/tools/webdriver/)
- [Firefox](https://github.com/mozilla/geckodriver/releases)
- [Safari](https://webkit.org/blog/6900/webdriver-support-in-safari-10/)

Script uses relative paths, so you should run it from inside of this directory.

> py add_task.py

Then just paste your desired task's url into the terminal and _voilà_.

## Why does it run so slow?

It takes around 4-5 seconds to finish the whole process.

Unfortunately, I couldn't use _urllib_ to scrap the site data, because I needed to run javascript to access the task details on the webpage. The site itself doesn't load up so quickly as well, so those are the main reasons. ~~Also because of my O(n<sup>3</sup>) algorithms~~.
