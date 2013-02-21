#
# slug.py
#
# This is your implementation file. There is only one method provided:
# next_round. You are free to create additional methods and member
# variables that help your slug cruise along at superslugic
# speeds. The only requirement is that next_round must return one of
# the Decision types (MOVE, REST, EAT).

from decisions import Decisions
from base_slug import BaseSlug
from random import randint

class Slug(BaseSlug):
    def next_round(self):
        '''
        The slug race program calls this method every turn. Your job
        is to decide which action your slug should take by returning
        one of the following values:

        * Decisions.MOVE: Your slug keeps on going, but this spends
          some energy and also makes your slug hungry.

        * Decisions.REST: Slug takes a nap. When it wakes up it has
          full energy, but it didn't move for a while.

        * Decisions.EAT: Your slug eats some food instead of resting
          or moving. This improves the slug's hunger situation.

        '''
        return Decisions.MOVE # Replace this with your master plan.

