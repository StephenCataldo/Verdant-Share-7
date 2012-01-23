Verdant Share modules (rideshare will be published first; taxi-match and roomshare are used internally at VerdantEvent but are not modules 2011/5)
are designed for a conference (like a DrupalCon) where people create a 
Drupal account for the event and then need to figure out their travel to the
event  (Content Profile, at least for now, is required).

Uses flags, views and cck to create chart and map (gmap)
views of people who need to share a ride/taxi/room.  There are many depedencies
on (hopefully) common modules including Content Profile to give each person
one share of each type.  

The basic flow from a devel perspective:
* There is a cck type for rideshare, 
set as a content_profile, meaning each signed
in user gets one instance of that type.
* Users should be encouraged to have Contact module settings left on,
or things won't really work well.
* The form for editing their instance can be on a profile page, a popup (not
yet implemented but easy), or my preference a block on the view of other
people's posts.
* There are two views of other people's posts: a map, and a chart.  Flags
are used heavily to allow sorting.  

From a user's perspective: go to the link for ridesharing and you'll see
both a form for your post and everyone else's post.  Optional to have users
create their post when they sign up for the conference.

The intention is that these will be standardized
enough to be easy to edit: add or subtract fields to the cck-type or
to the view.  I'm interested to hear what other people do with the module.

Admin tip:
* The views use Exposed Forms, which I don't intent to be visible to be users
but are great to use as an admin tuning the view parameters.
* The dates exposed forms gave me lots of problems, and I haven't dealt with
them yet -- the "four hour window" goes an extra day in theory, and merely
seems to more or less work, right now.

Help and advice are very welcome!  

Carpool Module: What's Here



	1.	Views
	⁃	map
	⁃	chart
	2.	Input
	⁃	Alternate: popup instead of block?
	⁃	Default Time: Custom value for From date:  
	⁃	Content Profile.  You could probably change this to work with other setups… please write it up if you do!
	3.	Settings
	⁃	set the date, location of the event
	⁃	admin mode: unhide the hidden views exposed forms

Questions
	•	Should I put locations as a field, or as part of the cck (seems fine either way, no?)

Late in Dev Process
	•	create css file with at least blanks, or suggestions, for formatting
	•	Trying to get distance working, currently aimed to have the argument for the nid of the current user to set the locations that everything else is based on… no luck
	•	Permissions for anonymous = no rideshare

Future Version Wish-List
	•	Currently, the views use a 4-hour window for matching arrivals and departures.  Make it controllable.
	•	Timezones.  Very subtle: if you drive from one timezone to another, each trip starts in a different timezone.   Not sure what I want it to do yet, never mind how to program it.  On second thought, the best time for matching is the at-event time not the at-home time (especially for long trips with short carpools), so just use the event timezone (no timezone). ?.

History:
Opensource from VerdantEvent.com
First used at gmic2010.verdantevent.com
Based on SpaceShare.com system.


Added GIT on 4/29/2011
