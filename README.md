ReasonML + P5 
----------

This is an experimental repository looking to combine the static-type checking and functional-ness of [ReasonML](https://reasonml.github.io/) with the creativity and fun of the [P5 library](https://p5js.org/). 

There are quite a few workarounds - the separate `Window.re` file brings the core functions from P5 into Reason using the Foreign Function Interface (FFI). Importantly it also gets the window object and sets the functions `draw` and `setup` which would normally happen by P5 and overloaded by simply declaring these in the Javascript file. 

This experiment also uses [ParcelJS](https://parceljs.org/) to bundle up the application. 

Running the Repo
---------------

It should be as simple as (providing you `npm` and all of the dependencies including parcel) - this builds everything using `bsb` and bundles it up.

```
npm run build 
npm run parcel
```

You can then open `./dist/index.html`. This requires internet access to get the P5 library from the CDN (you could replace this with a local copy for offline fun).

You can run `npm run clean` to tidy everything again afterwards. 