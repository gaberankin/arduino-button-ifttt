# arduino-button-ifttt
code that backs a button that fires a web request, in this case specifically to hit an endpoint at maker.ifttt.com

This project came about because I own a few LIFX lights in my home, and was getting tired of telling my google home to turn the lights on and off (or pulling my phone out of my pocket to access the app).  Voice control is great and all, but we aren't to the point of just saying "lights" to have the lights go on and off yet - we have to call out the assistant by name before we can tell it what to do.

I also realized that I had an [Adafruit feather HUZZAH](https://www.adafruit.com/product/2821) laying around thanks to the fact that I subscribe to the [Adabox](https://www.adafruit.com/adabox/) (if you have some disposable income to burn and an interest in the internet-of-things, I recommend it), and also realized that because it has WiFi connectivity, I already had all the tools at my disposal without having to drop any extra cash.

## TODO
1) implement hardware interrupt
2) change the onboard LED states so that the lights aren't on all the time (they're bright and keep me awake at night!)
