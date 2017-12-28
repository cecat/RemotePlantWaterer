# RemotePlantWaterer

This is a very simple plant watering system that takes advantage of the Particle Photon and Particle's cloud service that can be connected to (e.g.) IFTTT. You could readily put a button on it or other controls, but this project assumes you're going to issue commands via the Particle integration with IFTTT.

This project assumes you are reasonably familiar with Particle and IFTTT.

## Hardware
I use a Particle Photon and a 12v peristaltic dosing pump, e.g., https://www.amazon.com/gp/product/B0196LDFJQ/ref=oh_aui_search_detailpage?ie=UTF8&psc=1

Power it with a 12v >=1A DC power supply, e.g. with 5.5mm x 2.1mm (10mm long) connector, for which you can buy a matching jack.

## Particle & IFTTT Notes
Copy and paste the source code into a sketch in the Particle IDE.  Make sure to search for and include the libraries that correspond to the #include files (Particle IDE will duplicate the #include lines, so after you do the linking you can remove the dupes)

On IFTTT you will associated your Particle account. Here for instance you can create a an applet where THIS is a time of day (select date/time, daily at noon) and for the "THAT" you select Particle "Call a function."  Here you will see your photon (if it is running) and the parse funciton, e.g. if your photon is named "rainmaker" then you will select "parse on "rainmaker"" with input "ON"

## Practical Stuff

The particle sketch is set up so that the pump will automatically turn itself off after 900000ms (15 min).  If you want a different runTime just set it here and then flash your photon.

If you slightly bend the terminals at the back of the pump it will fit very nicely into a <uxcell 3.27"x2.28"x1.3"(83mmx58mmx33mm) ABS Junction Box Electric Project Enclosure> project box.  With a dremel or equiv you can cut a hole in the box lid to slide the pump in up to its collar.

The pump has short in/out tubes attached, which nicely slide into standard aquarium air pump tubing. You'll want to buy some connectors in case you want to extend or split via T-connectors. To water an area, such as a planter box, you can cap the tube and use a needle to poke holes through every inch or two, creating a soaker hose.

Depending on how hard your water is these will start to plug up after a few weeks, and the pump is very strong so it will either pop your end cap out (however you closed the end of the tube) or it will pop the whole tube off at the pump.
