# RemotePlantWaterer

This is a very simple plant watering system that takes advantage of the Particle Photon and Particle's cloud service that can be connected to (e.g.) IFTTT. You could readily put a button on it or other controls, but this project assumes you're going to issue commands via the Particle integration with IFTTT (and thus you're reasonably familiar with Particle integrations and IFTTT).

## Hardware
I use a Particle Photon and a [12v peristaltic dosing pump](https://www.amazon.com/Kamoer-Peristaltic-Hydroponics-Nutrient-Analytical/dp/B07GWJ78FN/ref=sr_1_6?crid=3D1H5LUMBXEHO&dchild=1&keywords=peristaltic+pump&qid=1599927556&s=industrial&sprefix=peristaltic+%2Cindustrial%2C174&sr=1-6)

Power it with a 12v >=1A DC power supply, e.g. with 5.5mm x 2.1mm (10mm long) connector and socket like [this](https://www.amazon.com/QTEATAK-Adapter-Connector-Dustproof-Waterproof/dp/B07VTZX2RK/ref=sr_1_10?dchild=1&keywords=5.5mm+power+jack&qid=1599927686&sr=8-10).

The pump is controlled with a FeatherWing non-latching mini-relay which is a bit overkill ($8).  In my 3rd device I switched to an H-Bridge (motor driver), which is $2-3 and smaller (the FeatherWing is bigger than the Photon, so makes things a bit tight in the box).

## Particle & IFTTT Notes
Copy and paste the source code into a sketch in the Particle IDE.  Make sure to search for and include the libraries that correspond to the #include files (Particle IDE will duplicate the #include lines, so after you do the linking you can remove the dupes)

On IFTTT you will link to your Particle account. Here for instance you can create an applet where THIS is a time of day (select date/time, daily at noon) and for the "THAT" you select Particle "Call a function."  Here you will see your photon (if it is running) and the parse function, e.g. if your photon is named "rainmaker" then you will select "parse" on "rainmaker"" with input "ON"

## Practical Stuff

The particle sketch is set up so that the pump will automatically turn itself off after 900000ms (15 min).  If you want a different runTime just set it here and then flash your photon.

If you slightly bend the terminals at the back of the pump it will fit very nicely into a project box like [this](https://www.amazon.com/Awclub-Waterproof-Dustproof-Transparent-100mmx68mmx50mm/dp/B07C9BBH7G/ref=psdc_495308_t5_B072FS3W7X).  With a dremel or equiv you need to cut a hole in the box lid to slide the pump in up to its collar.  You'll also need to drill a hole in the side for your power plug.

The pump has short in/out tubes attached, which nicely slide into standard aquarium air pump tubing. You may want to buy some connectors in case you want to extend or split via T-connectors. To water an area, such as a planter box, you can cap the tube and use a small nail to poke holes through every inch or two, creating a soaker hose.

Depending on how hard your water is these will start to plug up after a few weeks, and the pump is very strong so it will either pop your end cap out (however you closed the end of the tube) or it will pop the whole tube off at the pump.  Unfortunately this pump is not quite hefty enough to drive the common Rainbird type watering systems.  But one could use this system to power a solenoid rather than a pump if you wanted to use a standard water supply...
