Slug Races!
============

In this assignment you pit your virtual pet slugs against one another.

There are several files that you need to download (so, you should
probably just use `git` if you aren't already). The only one you will
need to edit is `slugs.py`.

To run the slug race, execute `race.py`. This will run through up to
200 turns. This is sort of like a turn in a board game. On each turn,
your code has to decide which action the slug will take: Eat, Move, or
Rest.

What to Do
--------

You will edit a method called `next_round`. Your slug has two state
variables that you should use to determine what action you can take.

* `hunger` is a floating point number that ranges from 0.0 to
  10.0. When this dips below 0, your poor slug dies from
  starvation. You may replenish hunger by deciding to eat.

* `energy` is another floating point number in the same range. When it
  dips below zero, your slug is too tired to continue. You can
  replenish energy by resting.
  
Based on these two variables, your `next_round` method will return one
of the following variables:

* `Decisions.MOVE` has your slug trudge on forward. Doing so makes you
  hungry and takes energy. Note that your slug moves faster when it
  has more energy, but it also loses energy slightly faster when it
  has more energy. 

* `Decisions.EAT` causes your slug to pull over at a roadside cafe for
  a spot of lunch. Your slug won't move when it is eating but it will
  regain a small amount of energy.

* `Decisions.REST` is the sign that it is time to take a nap. The slug
  is out of commission for a few turns, but when it wakes up it has
  full energy and is all zippy fast.
 
The exact mathematical descriptions of these things are encoded in
`race.py`, and I encourage you to take a look there.

The Purpose Of This Assignment
---------

The goal with the slug race is to give you an amusing way of exploring
how you can design small passages of code to optimize some desired
outcome while maintaining some (vaguely) realistic constraints.

Your score depends on whether or not your slug passes the finish line
before it starves to death, or the maximum number of turns is
reached. You'll get 10/10 for finishing, but 0/10 for not
finishing. So this is an all-or-nothing arrangement. That's a lot of
pressure to put on an electronic slug, but I'm sure you'll do fine.

The _real_ fun starts when you realize that you can improve this by
planning things out, rather than idly messing around with parameters
(though, playing with params can also lead to insights too).

For example: could you use Calculus or linear algebra to find an
optimal strategy?

Maybe you find an optimal sequence of MOVE MOVE MOVE EAT MOVE REST
MOVE, (or something) that totally wins?

Or, maybe you could write another Python program that tries different
things a million times, and runs your poor slug through a million
races, and you record the best configurations.

We'll have an informal leaderboard. If you feel like entering your
slug in a class-wide competition, that can be arranged.
