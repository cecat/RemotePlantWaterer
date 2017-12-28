# RemotePlantWaterer

This is a very simple plant watering system that takes advantage of the Particle
Photon and Particle's cloud service that can be connected to (e.g.) IFTTT. You
could readily put a button on it or other controls, but this project assumes you're going
to issue commands via the Particle integration with IFTTT.

We use a Particle Photon and a 12v peristaltic dosing pump, e.g.,
https://www.amazon.com/gp/product/B0196LDFJQ/ref=oh_aui_search_detailpage?ie=UTF8&psc=1

Power it with a 12v >=1A DC power supply, e.g. with 5.5mm x 2.1mm (10mm long) connector, for
which you can buy a matching jack.

Copy and paste the source code into a sketch in the Particle IDE.  Make sure to search for and 
include the libraries that correspond to the #include files (Particle IDE will duplicate
the #include lines, so after you do the linking you can remove the dupes)
